#ifndef TFRSCALIBREVENT_H
#define TFRSCALIBREVENT_H

#include "Go4Event/TGo4EventElement.h"

class TFRSCalibrProc;
class TGo4FileSource;

class TFRSCalibrEvent : public TGo4EventElement {
   public:
      TFRSCalibrEvent();
      TFRSCalibrEvent(const char* name);
      virtual ~TFRSCalibrEvent();
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
     
		//Scalers
		UInt_t freeTrig;
		UInt_t acptTrig;
		UInt_t mon_inc[64];

      // MON part
      Int_t         seconds;
      Int_t         tenthsecs;
			Int_t         hundrethsecs;	//mik
      Int_t         extraction_cycle;
      Int_t         coin[16];
		Float_t       seetram;
      
      // MW part
      Float_t       mw_xsum[13];     /*                          */
      Float_t       mw_ysum[13];     /*                          */
      
      Float_t       mw_x[13];        /*                          */
      Float_t       mw_y[13];        /*                          */
      Float_t       mw_wire[13];     /* special for Helmut       */

      Float_t       z_x_s2;          
      Float_t       z_y_s2;          
      Float_t       z_x_s4;          
      Float_t       z_y_s4;          
      Float_t       z_x_s8;          
      Float_t       z_y_s8;          
 
      Bool_t        b_mw_xsum[13];   /*  wc on sum               */
      Bool_t        b_mw_ysum[13];   /*                          */

      Float_t       focx_s2;         /*  FRS foci                */  
      Float_t       focy_s2;         /*                          */  
      Float_t       focx_s4;         /*                          */  
      Float_t       focy_s4;         /*                          */  
      Float_t       focx_s8;         /*  FRS foci                */  
      Float_t       focy_s8;         /*                          */
      Float_t       angle_x_s2;      /*                          */
      Float_t       angle_y_s2;      /*                          */
      Float_t       angle_x_s4;      /*                          */
      Float_t       angle_y_s4;      /*                          */
      Float_t       angle_x_s8;      /*                          */
      Float_t       angle_y_s8;      /*                          */

      // TPC part
      Int_t tpc_csum[6][4];
      Float_t tpc_x[6];
      Float_t tpc_y[6];
      Bool_t b_tpc_csum[6][4];
      Bool_t b_tpc_xy[6];

      //TPCs 3 & 4 @ S2 focus
      Float_t tpc_x_s2_foc;
      Float_t tpc_y_s2_foc;
      Float_t tpc_angle_x_s2_foc;
      Float_t tpc_angle_y_s2_foc;
   
      //TPCs 5 & 6 @ s4 focus
      Float_t tpc_x_s4;
      Float_t tpc_y_s4;
      Float_t tpc_angle_x_s4;
      Float_t tpc_angle_y_s4;

      //TPCs 5 & 6 @ S4 Solid H2 target
      Float_t tpc_x_s4_target1;
      Float_t tpc_y_s4_target1;
  

      //TPCs 1 & 2 @ S4 Second Target
      Float_t tpc_x_s4_target2;
      Float_t tpc_y_s4_target2;
      Float_t tpc_angle_x_s4_target2;
      Float_t tpc_angle_y_s4_target2;


      Float_t       tpc_sc21_x;      /* SC21 x                    */
      Float_t       tpc_sc41_x;      /* SC41 x                    */
      Float_t       tpc_sc21_y;      /* SC21 y                    */
      Float_t       tpc_sc41_y;      /* SC41 y                    */


      Float_t       sc21_x;          /* SC21                     */
      Float_t       sc22_x;          /* SC22 (LAND finger)       */
      Float_t       sc41_x;          /* SC41                     */
      Float_t       itag_stopper_x;  /* ITAG Stopper             */
      Float_t       sc42_x;          /* SC42                     */
      Float_t       sc43_x;          /* SC43                     */
      Float_t       sc21_y;          /* tracked SC21 Y pos       */
      Float_t       sc41_y;          /* SC41 Y                   */
      Float_t       sc42_y;          /* SC42 Y                   */
      Float_t       sc43_y;          /* SC43 Y                   */
      Float_t       sc81_x;          /* SC81          positions  */
      
      Float_t       music1_x1;       /* parameters to calibrate  */
      Float_t       music1_x2;       /* parameters to calibrate  */
      Float_t       music1_x3;       /* parameters to calibrate  */
      Float_t       music1_x4;       /* parameters to calibrate  */
      Float_t       music2_x;        /* MUSIC1,2 positions       */


      // ETAP scaler 
      Int_t etap_scaler[64];
      Int_t etap_scaler_increase[64];
      Float_t etap_scaler_normalized[64];

      Int_t mh_scaler[64];
      Int_t mh_scaler_increase[64];
      Float_t mh_scaler_normalized[64];
      

  //------ETAP-MWDC------//
  Int_t mwdc_numhit[16];
  Float_t mwdc_tot[16][64];
  Float_t mwdc_time[16][64];
  Float_t mwdc_time_wMaxToT[16];
  Int_t mwdc_wireid[16][64];
  Float_t mwdc_wirepos[16][64];
  Float_t mwdc_length[16][64];
  

  //---ETAP-MWDC-Fitting----
  Int_t mwdc_numtrack, mwdc_numtrack_estimate[2];
  Float_t mwdc_chi2,mwdc_x,mwdc_y;
  Float_t mwdc_a,mwdc_b,mwdc_res[16];
  Float_t mwdc_res_ex[16];
  Float_t mwdc_chi2_test[2],mwdc_x_test[2],mwdc_y_test[2];
  Float_t mwdc_a_test[2],mwdc_b_test[2], mwdc_res_test[2][8];

  Float_t focal_plane;

  // Etaprime QDC valid check (for v1742)
  Int_t qdcvalid;

  //---ETAP-SCI---//
  Float_t sci_qdc[16][2];
  Float_t sci_tdc[16][2];
  Int_t sci_ml[16][2];
  Int_t sci_mt[16][2];
  Float_t sci_t0_tdc[16][2];
  Float_t sci_time[16][2];// need parameters
  Float_t sci_timeave[16];// need parameters
  Float_t sci_timedif[16];// need parameters
  Float_t sci_de[16]; // need parameters

  
  //--------------
  Float_t tof_21l_41l,tof_21r_41r, tof_21_41;
  Float_t tof_41l_42l,tof_41r_42r, tof_41_42;

  //---ETAP-miniHIRAC---//
  Float_t mini_qdc[2];
  Float_t mini_tdc[2];
  Float_t mini_time[2];// need parameters
  Float_t mini_pe[2];  // need parameters
  Float_t mini_pesum;  // need parameters
  Int_t   mini_numhit; // need parameters

  //---ETAP-HIRAC---//
  Float_t hirac_qdc_raw[8];
  Float_t hirac_qdc_base[8];
  Float_t hirac_qdc_cor[8];
  Float_t hirac_pe[8];  // need parameters
  Float_t hirac_tdc_raw[8];
  Float_t hirac_tdc_t0cor[8]; 
  Float_t hirac_tdc_cor[8]; //need parametrs
  Float_t hirac_pesum;  
  Float_t hirac_x;  // need parameters
  Int_t   hirac_numhit; 

  //---ETAP-TORCH---//
  Float_t torch_qdc[6];
  Float_t torch_tdc[6];
  Float_t torch_time[6];  // need parameters
  Float_t torch_pe[6];  // need parameters
  Float_t torch_pesum;  // need parameters
  Float_t torch_x;  // need parameters
  Int_t   torch_numhit; // need parameters

  //s436 particle identification
  Bool_t b_pi[5]; //1-4: each condition, 5:or

 private:
      TFRSCalibrProc *fxProc;  //! Don't put this to file
      TGo4FileSource *fxFileSrc;  //! This is file source

   ClassDef(TFRSCalibrEvent,1)         
};

#endif //TFRSCALIBREVENT_H

