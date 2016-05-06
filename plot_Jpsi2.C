

void plot_Jpsi2( )
{
TTree *d= new TTree("d","");
d->ReadFile("Jpsi.csv");			

	//histogramas
TH1F *m1 = new TH1F("m1","m1",90,50,160);
TH1F *m2 = new TH1F("m2","m2",90,50,160);
TH1F *mT = new TH1F("mT","mT",90,1.5,5.5);
	
	//Masas con c=1 y aumentando la escala de los E1 y E2

d->Draw("1000*sqrt(E1^2-px1^2-py1^2-pz1^2)>>m1");
d->Draw("1000*sqrt(E2^2-px2^2-py2^2-pz2^2)>>m2");
d->Draw("sqrt((E1+E2)^2-(px1+px2)^2-(py1+py2)^2-(pz1+pz2)^2)>>mT");

TCanvas * C1 = new TCanvas("C1","png3",800,500);
gStyle->SetOptStat(0);
C1->Divide(2,1,0.02,0.03);
//graf.cd(1);

m1->SetLineColor(4);
m2->SetLineColor(2);
m1 -> SetTitle("Masas de muones; Masa; Eventos");
//m2-> SetTitle("Masa2; Masa; Eventos");
m2-> Draw();
m1->Draw("same");
gPad -> SetLogy();

leg = new TLegend(0.10,0.60,0.57,0.75);
leg->SetLineColor(0);
leg->SetFillColor(0);
leg->SetFillStyle(0);
leg->AddEntry(m2,"m2","lep");
leg->AddEntry(m1,"m1","lep");
leg->Draw();

TCanvas * C2 = new TCanvas("C2","png4",800,500);
mT->SetLineColor(kGreen+4);
mT -> SetTitle("Masa errores; W (GeV/c^{2} ) ; eventos");
mT -> Draw("E1");

C2->SaveAs("JpsiParte2tarea.C");
C1->SaveAs("JpsiParte2tarea.png");

}
