#ifndef TFRSSORTEVENT_H
#define TFRSSORTEVENT_H

#include "Go4Event/TGo4EventElement.h"

class TFRSSortProc;
class TGo4FileSource;

class TFRSSortEvent : public TGo4EventElement {
   public:
      TFRSSortEvent();
      TFRSSortEvent(const char* name);
      virtual ~TFRSSortEvent();
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
      
      
      // MON part
      
      // time stamp data  
      Int_t         ts_id;                                
      Int_t         ts_word[3];
      Long64_t      timestamp;  // absolute time stamp value
      Double_t      timespill;  // relative time from start of the spill 
      Double_t      timespill2;  // relative time from start of the spill does not reset at end extraction
      Int_t         pattern;
      Int_t         trigger;

      // scaler readings     
      UInt_t sc_long[32];
      UInt_t sc_long2[32];

     
      // part of MW parameter
      Int_t         mw_an[13];       /*  anode time              */
      Int_t         mw_xl[13];       /*  Rohdaten                */
      Int_t         mw_xr[13];       /*                          */
      Int_t         mw_yu[13];       /*                          */ 
      Int_t         mw_yd[13];       /*                          */

      // Etaprime-MWDC //
      Int_t mwdc_numhit[16];
      Int_t mwdc_wireid[16][64];
      Int_t mwdc_tot[16][64];
      Int_t mwdc_time[16][64];
      Int_t mwdc_time_trail[16][64];

      // Etaprime-SCI // 
      Int_t etapsci_t[16][2]; // [i_sci][i_LR]
      Int_t etapsci_t_trail[16][2]; 
      Int_t etapsci_mt[16][2];  
      Int_t etapsci_ml[16][2]; 
      Int_t etapsci_q[16][2];      
      Int_t etapsci_t0_t[16][2];
      Int_t etapsci_t0_t_trail[16][2];
      
      // Etaprime-HIRAC 
      Int_t hirac_t[8];
      Int_t hirac_t_trail[8];
      Int_t hirac_q[8];   

      // Etaprime-TORCH
      Int_t torch_t[8];
      Int_t torch_t_trail[8];
      Int_t torch_q[8];  

      // Etaprime-miniHIRAC
      Int_t mini_t[2];
      Int_t mini_t_trail[2];
      Int_t mini_q[2];

      // Etaprime-scaler
      Int_t etap_scaler[32];
      Int_t mh_scaler[32];

      // TPC part //(HAPOL-25/03/06) 6 TPCs each one with 2 delay lines each!!
      Int_t tpc_l[6][2];
      Int_t tpc_r[6][2];
      Int_t tpc_lt[6][2];
      Int_t tpc_rt[6][2];

      // [index][anode_no]
      Int_t tpc_dt[6][4];
      Int_t tpc_a[6][4];


      
      // SCI part
      Int_t         de_21l;          /* dE SCI21 left            */  
      Int_t         de_21r;          /* de SCI21 right           */ 
      Int_t         de_41l;          /* dE SCI41 left            */
      Int_t         de_41r;          /* dE SCI41 right           */
      Int_t         de_41u;          /* dE SCI41 up              */
      Int_t         de_41d;          /* dE SCI41 down            */
      Int_t         de_42l;          /* de SCI42 left            */
      Int_t         de_42r;          /* de SCI42 right           */
      Int_t         de_21ld;         /* dE SCI21 left delayed    */  
      Int_t         de_21rd;         /* de SCI21 right delayed   */ 
      Int_t         de_v1l;          /* dE veto1 left            */  
      Int_t         de_v1r;          /* de veto1 right           */ 
      Int_t         de_v2l;          /* dE veto2 left            */
      Int_t         de_v2r;          /* dE veto2 right           */
      Int_t         de_v3;           /* dE veto3                 */


                                

   private:
      TFRSSortProc   *fxProc;     //! This is processor
      TGo4FileSource *fxFileSrc;  //! This is file source
      
   ClassDef(TFRSSortEvent,1)         
};

#endif //TFRSSORTEVENT_H

