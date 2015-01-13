#ifndef TFRSUSEREVENT_H
#define TFRSUSEREVENT_H
#include "Go4Event/TGo4EventElement.h"
#include "Go4EventServer/TGo4TreeSource.h"
#include "Go4EventServer/TGo4FileSource.h"

class TFRSUserProc;

class TFRSUserEvent : public TGo4EventElement {
   public:
      TFRSUserEvent();
      TFRSUserEvent(Text_t * name);
      virtual ~TFRSUserEvent();
      /**
       * Method called by the event owner (analysis step) to fill the
       * event element from the set event source. Event source can
       * be the source of the analysis step (if this is a raw event) 
       * or the event processor (if this is a reduced event).
       */
      virtual Int_t Fill();

      /**
       * Method called by the event owner (analysis step) to clear the
       * event element.
       */
      virtual void Clear(Option_t *t="");  
      
      virtual Int_t Init();  

   private:
      TFRSUserProc   *fxProc;  //! Don't put this to file

   ClassDef(TFRSUserEvent,1)         
};

#endif //TFRSUSEREVENT_H

