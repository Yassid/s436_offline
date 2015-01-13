#include "TFRSUserProc.h"
#include "TFRSAnlEvent.h"
#include "TFRSCalibrEvent.h"
#include "TFRSUserEvent.h"
#include "TFRSSortEvent.h"
#include "TFRSUnpackEvent.h"

#include "TTree.h"
#include "TFile.h"
#include "TFRSData.h"

#include "TFRSParameter.h"
#include "TVector3.h"

TFRSUserProc::TFRSUserProc() : TFRSBasicProc("FRSUserProc") {
}

TFRSUserProc::TFRSUserProc(Text_t * name) : TFRSBasicProc(name) {



//HAPOL - 21/06/11
  //Here I have the frs unpack, sort, calib, ... So, it is a nice point for 
  //making the Tree storing all info (creating a kinda offline go4)
  //TFile for storing the info
  
  
  cout <<  endl <<  endl 
       << "***************** OFFLINE OUTPUT! ******************* " 
       << endl<< endl;
  
  //outFile = new TFile("/home/daq/Desktop/s436/offline/outFile.root","RECREATE");
  outFile = new TFile("./outFile.root","RECREATE");
  outFile->cd();
  if(!outFile->IsOpen())
    cout<<"File not created sucessfully-->"<<this<<endl;
    theTree = new TTree("The_FRS_Anal_Tree","FRS_Tree");
  
  if(!theTree)
    cout<<"Tree not created sucessfully-->"<<this<<endl;

   theData = new TFRSData();
   if(!theData)
  cout<<"Data not created sucessfully-->"<<this<<endl;

   //theTree->Branch("theData","TFRSData",&theData,128000,99);
  theTree->Branch("theData","TFRSData",&theData,256000,99);

  cout <<  endl <<  endl 
       << "***************************************************** " 
       << endl<< endl;
  //END OF HAPOL - 11/05/06
 
}

TFRSUserProc::~TFRSUserProc() {
  //HAPOL - 21/06/2011
  outFile->Write();
  outFile->Close();
}

void TFRSUserProc::FRSUserProc(TFRSUserEvent* target) {
    target->SetValid(kFALSE);  // by default output event rejected
 
    // HAPOL - 21/06/2011

    
    //const 
    TFRSAnlEvent   *source = dynamic_cast<TFRSAnlEvent*>    (GetInputEvent());
    //const 
    TFRSCalibrEvent *calib = dynamic_cast<TFRSCalibrEvent*> (GetInputEvent("Analysis"));
    //const 
    TFRSSortEvent *sort = dynamic_cast<TFRSSortEvent*>      (GetInputEvent("Calibr"));
    //const 
    TFRSUnpackEvent *unpack = dynamic_cast<TFRSUnpackEvent*>(GetInputEvent("Sort"));
    
    if( !source || !calib || !sort || !unpack ) {
      static bool warned = false;
      if( !warned )
        cout << "no source or calib event - bad cast?" << endl;
      warned = true;
      return;
    }

    theData->Fill(source,calib,sort,unpack);
    theTree->Fill();
    Int_t fill=theTree->GetEntries(); 
     if(fill%1000==0) cout<<"Filling e436 FRS tree: "<<fill<<endl;

    target->SetValid(kTRUE); // if all actors are present, accept event...
    
}

ClassImp(TFRSUserProc);
