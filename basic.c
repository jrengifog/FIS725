#include "Riostream.h"
void basic() {
//  Read data from an ascii file and create a root file with an histogram and an ntuple.
//   see a variant of this macro in basic2.C
//Author: Rene Brun


// read file $ROOTSYS/tutorials/tree/basic.dat
// this file has 3 columns of float data
   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("basic.C","");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%Jpsi.csv",dir.Data()));

Float_t px1, py1, pz1;
Float_t px2, py2, pz2;
Float_t E1,E2;
Int_t nlines = 0;
   TFile *f = new TFile("basic.root","RECREATE");
 //  TH1F *h1 = new TH1F("h1","Masa",100,-4,4);
   TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","px1:py1:pz1");
   TNtuple *ntuple2 = new TNtuple("ntuple2","data from ascii file","px2:py2:pz2");
   while (1) {
      in >> px1 >> py1 >> pz1;
      in >> px1 >> py1 >> pz1;
	  
 //     if (!in.good()) break;
 //     if (nlines < 5) printf("px1=%8f, py1=%8f, pz1=%8f\n","px2=%8f, py2=%8f, pz2=%8f\n",px1,py1,pz1,px2,py2,pz2);
//      h1->Fill(x);
      ntuple->Fill(px1,py1,pz1);
      ntuple2->Fill(px2,py2,pz2);
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}
 