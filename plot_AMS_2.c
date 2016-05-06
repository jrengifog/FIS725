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
int main(){

TString filename="data_tree.root";
TFile *f = new TFile(filename);
TTree *t = (TTree*)f->Get("Data");

TH2F * H2 = new TH2F("H2","Energy vs TOF; ChargeTOF ; Energy (GeV)",30,0,30,600,0,6000);
t ->Draw("energy:chargetof>>H2","chargetof>0");
TCanvas * C1 = new TCanvas("C1","png2",800,500);
TH1D * H2c = H2 -> ProfileX();
	
//C1->Divide(1,2);
//C1->cd(1);

H2-> SetMarkerStyle(8);
H2-> SetMarkerSize(0.4);
H2-> SetMarkerColor(2);
H2-> Draw();
C1 -> SetLogy();
C1 -> Modified();
C1 -> Update();
C1->SaveAs("Chargeofenergy.png");
//C1->cd(2);
TCanvas * C2 = new TCanvas("C2","otro",800,500);
H2c-> Draw();
C2->SaveAs("Chargeofenergyprofile.png");

}