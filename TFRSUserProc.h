#ifndef TFRSUSERPROCESSOR_H
#define TFRSUSERPROCESSOR_H

#include "Go4EventServer/TGo4MbsEvent.h"
#include "Go4Analysis/TGo4Analysis.h"
#include "Go4Event/TGo4EventElement.h"

#include "TFRSBasicProc.h"

class TFRSUserEvent;

class TFRSAnlEvent;
class TFRSCalibrEvent;
class TFRSSortEvent;
class TFRSUnpackEvent;

class TTree;
class TFile;
class TFRSData;


class TFRSUserProc : public TFRSBasicProc {
   public:
     TFRSUserProc() ;
     TFRSUserProc(Text_t * name);
     virtual ~TFRSUserProc() ;
  
     void FRSUserProc(TFRSUserEvent* target);
  
   private:

     TFile* outFile;    //! The ROOT File
     TTree* theTree;    //! Tree with the relevant information
     TFRSData* theData; //! Data


   ClassDef(TFRSUserProc,1)
};

#endif //TFRSUSERPROCESSOR_H
