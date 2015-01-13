#ifndef TFRSANLEVENT_H
#define TFRSANLEVENT_H

#include "Go4Event/TGo4EventElement.h"

class TFRSAnlProc;
class TGo4FileSource;

class TFRSAnlEvent: public TGo4EventElement {
   public:
      TFRSAnlEvent();
      TFRSAnlEvent(const char* name);
      ~TFRSAnlEvent();
      virtual Int_t Init();
      virtual Int_t Fill();
      virtual void Clear(Option_t *t="");
      
   private:

      TFRSAnlProc *fxProc;        //! This is processor
      TGo4FileSource *fxFileSrc;  //! This is file source

   ClassDef(TFRSAnlEvent,1)
};

#endif //TFRSANLEVENT_H

