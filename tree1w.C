void tree1w(){

 //create a tree file tree1.root - create the file, the Tree and a few branches
 TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("basic2.C","");
   dir.ReplaceAll("/./","/");  

  TFile f("tree1.root","recreate");
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
}