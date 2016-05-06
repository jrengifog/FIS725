#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>

#include <TString.h>
#include <TMath.h>
#include <TFile.h>
#include <TStyle.h>
#include <TH2D.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TProfile2D.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TLegend.h>
#include <TLeaf.h>
#include <TChain.h>
#include <TGraphErrors.h>

//Variable
const Double_t binning[75] = {0.5, 0.65, 0.82, 1.01, 1.22, 1.46, 1.72, 2.00, 2.31, 2.65, 3.00, 3.36, 3.73, 4.12, 4.54, 5.00, 5.49, 6.00, 6.54, 7.10, 7.69, 8.30, 8.95, 9.62, 10.3, 11.0, 11.8, 12.6, 13.4, 14.2, 15.1, 16.1, 17.0, 18.0, 19.0, 20.0, 21.1, 22.2, 23.4, 24.6, 25.9, 27.2, 28.7, 30.2, 31.8, 33.5, 35.4, 37.3, 39.4, 41.6, 44.0, 46.6, 49.3, 52.3, 55.6, 59.1, 63.0, 67.3, 72.0, 77.4, 83.4, 90.2, 98.0, 107.0, 118.0, 132.0, 149.0, 170.0, 198.0, 237.0, 290.0, 370.0, 500.0, 700.0, 1000.0};

int main(){

TString filename="data_tree.root";
TFile *f = new TFile(filename);
TTree *t = (TTree*)f->Get("Data");

//Histograms parte 1.1
TH1F * energyb = new TH1F("energyb","energyb",74,binning);
TH1F * corte1 = new TH1F("corte1","corte1",74,binning);
TH1F * corte2 = new TH1F("corte2","corte2",74,binning);

	t-> Draw("energy>>energyb");
	t-> Draw("energy>>corte1","betahval>0.5");
	t-> Draw("energy>>corte2","inside_tracker==1 && trchisqx>0 && trchisqx<10 && trchisqy>0 && trchisqy<10");

//Define Efficiency objects for both cuts
	TEfficiency * eff_corte1 = new TEfficiency( (const TH1) corte1, (const TH1) energyb);
	TEfficiency * eff_corte2 = new TEfficiency( (const TH1) corte2, (const TH1) energyb);
	eff_corte1 -> Paint();
	eff_corte2 -> Paint();
	TGraphAsymmErrors * gcorte2 = eff_corte1->GetPaintedGraph();
	TGraphAsymmErrors * gcorte1 = eff_corte2->GetPaintedGraph();
	

TCanvas * C1 = new TCanvas("C1","png",800,500);	
TH1F * hframe = C1->DrawFrame(0,0,1100,1);
hframe->SetTitle("Eficiencias Cortes; Energy [GeV]; Efficiency");
C1->SetLogx();
C1->SetGridx();
C1->SetGridy();
C1->SetFillColor(0);
gcorte1->SetFillColor(0);
gcorte1->SetLineWidth(2);
gcorte1->SetLineColor(3);
gcorte2->SetLineWidth(2);
gcorte2->SetLineColor(4);
gcorte1->Draw("P");
gcorte2->Draw("P");


leg = new TLegend(0.10,0.60,0.57,0.75);
leg->SetLineColor(0);
leg->SetFillColor(0);
leg->SetFillStyle(0);
//leg->SetHeader("<Xmax> vs. Energy");
leg->AddEntry(gcorte1,"BetaHval > 0.5","lep");
leg->AddEntry(gcorte2,"Tracker & 0<Tr#Chi^{2}_{x}<10 & 0<Tr#Chi^{2}_{y}<10","lep");
leg->Draw();

C1->SaveAs("Eficiencia_AMS.png");
}