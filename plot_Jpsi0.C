
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
#include "Riostream.h"



void plot_Jpsi0(){

 //create a tree file tree1.root - create the file, the Tree and a few branches
 TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("plot_Jpsi0.C","");
   dir.ReplaceAll("/./","/");  

TFile f("plot_Jpsi0.root","recreate");  
TTree*t1=new TTree("t1","a simple Tree with simple variables");
Float_t px1, py1, pz1;
Float_t px2, py2, pz2;
Float_t E1,E2;

TBranch*newBranch=t1->Branch("px1", &px1,"px1/F");
TBranch*newBranch1=t1->Branch("py1", &py1,"py1/F");
TBranch*newBranch2=t1->Branch("pz1", &pz1,"pz1/F");
TBranch*newBranch3=t1->Branch("px2", &px2,"px2/F");
TBranch*newBranch4=t1->Branch("py2", &py2,"py2/F");
TBranch*newBranch5=t1->Branch("pz2", &pz2,"pz2/F");
TBranch*newBranch6=t1->Branch("E1", &E1,"E1/F");
TBranch*newBranch7=t1->Branch("E2", &E1,"E2/F");
for(Long64_t i=0; i<100; i++){
newBranch->Fill();
newBranch1->Fill();
newBranch2->Fill();
newBranch3->Fill();
newBranch4->Fill();
newBranch5->Fill();
newBranch6->Fill();
newBranch7->Fill();
}
 /*

crear un tree:
TTree*tree=new TTree("tree","");
Float_t new_v
TBranch*bewBranch=tree->Branch("new_v", &new_v,"new_v/F");
for(Long64_t i=0; i<100; i++){
new_v=gRandom->Gaus(0,1);
newBranch->Fill();
}
tree->Write("",TObject::KOverwrite);

//----------------------------------------
  TFile f("plot_Jpsi.root","recreate");
   TTree t1("t1","a simple Tree with simple variables");
  
Float_t px1, py1, pz1;
Float_t px2, py2, pz2;
Float_t E1,E2;

t1.Branch("px1",&px1);
t1.Branch("py1",&py1);
t1.Branch("pz1",&pz1);
t1.Branch("px2",&px2);
t1.Branch("py2",&py2);
t1.Branch("pz2",&pz2);
t1.Branch("E1",&E1);
t1.Branch("E2",&E2);  
//fill the tree
t1.Fill();
   //save the Tree heade; the file will be automatically closed
   //when going out of the function scope
   t1.Write();
*/
}
