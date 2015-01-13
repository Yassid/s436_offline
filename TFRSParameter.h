#ifndef TFRSPARAMETER_H
#define TFRSPARAMETER_H

#include "Go4StatusBase/TGo4Parameter.h"

class TFRSParameter : public TGo4Parameter {
   public:
      TFRSParameter();  
      TFRSParameter(const char* name); 
      virtual ~TFRSParameter();
      virtual Int_t Print(Text_t * n, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter *);
      
      Bool_t        fill_raw_histos; // fill raw histograms in unpack step
      Bool_t        after_run176;    // adapt cable-swapping at run176
      
      // MON Part
      Int_t         max_scaler;
      
      // common FRS part
      
      Float_t       dist_focS2;      /* All distances from    */
      Float_t       dist_MW21;       /*       TS3QT33         */
      Float_t       dist_MW22;       /*                       */
      Float_t       dist_SC21;	     /*        in mm          */
      Float_t       dist_SC22;       /*        in mm          */
      Float_t       dist_TPC3;
      Float_t       dist_TPC4;
  
                                     /*-----------------------*/
                                     /*    distances  S4      */
                                     /*-----------------------*/
      Float_t       dist_focS4;      /* All distances from    */
      Float_t       dist_MW41;       /*      HFSQT13          */
      Float_t       dist_MW42;       /*                       */
      Float_t       dist_MW43;       /*                       */
      Float_t       dist_SC41;       /*        in mm          */
      Float_t       dist_SC42;       /*        in mm          */
      Float_t       dist_SC43;       /*        in mm          */
      Float_t       dist_itag_42;    /*        in mm          */
      Float_t       dist_itag_43;    /*        in mm          */
      Float_t       dist_itag_stopper;/*        in mm          */
      Float_t       dist_TPC1;
      Float_t       dist_TPC2;      
      Float_t       dist_TPC5;
      Float_t       dist_TPC6;
 
      Float_t       dist_MUSICa1;    /*  MUSIC(window-anode1) */
      Float_t       dist_MUSICa2;    /*  MUSIC(window-anode2) */
      Float_t       dist_MUSICa3;    /*  MUSIC(window-anode3) */
      Float_t       dist_MUSICa4;    /*  MUSIC(window-anode4) */
      Float_t       dist_MUSIC1;     /*  MUSIC1               */
      Float_t       dist_MUSIC2;     /*  MUSIC2               */
      Float_t       dist_MUSIC3;     /*  MUSIC3               */


                                     /*-----------------------*/
                                     /*    distances not used */
                                     /*-----------------------*/
      Float_t       dist_focS8;      /* All distances from    */
      Float_t       dist_MW81;       /*       TS????          */
      Float_t       dist_MW82;       /*                       */
      Float_t       dist_SC81;       /*        in mm          */
      

      Float_t       dispersion[7];   /* d* Disp. S0-S2,S2-S4  */
      Float_t       magnification[7]; 
      Float_t       bfield[7];       /* D1/D2 D3/D4 Feld      */
      Float_t       rho0[7];         /* S2/4 Sollbahnradius s */
      
      Float_t       primary_z;       /* Z of primary beam     */
      Float_t       offset_z;
      Float_t       offset_z2;
      Float_t       offset_z3;
      
		Float_t		  a2AoQCorr;  /* Correction of AoQ based on S2 angle in x */
		Float_t		  a4AoQCorr;  /* Correction of AoQ based on S4 angle in x */

   ClassDef(TFRSParameter,1)
};

// *************************************************************************

class TMWParameter : public TGo4Parameter {
   public:
      TMWParameter();  
      TMWParameter(const char* name); 
      virtual ~TMWParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
      
      Float_t       x_factor[13];    /*  MWPC calibration        */
      Float_t       x_offset[13];    /*  mm                        */
      Float_t       y_factor[13];    /*                          */
      Float_t       y_offset[13];    /*  mm                        */
   
      Float_t       gain_tdc[5][13]; /* 14.09.05 CN+AM  TDC calibration ns/ch */
   ClassDef(TMWParameter,1)
};

// *************************************************************************

class TTPCParameter : public TGo4Parameter {
   public:
      TTPCParameter();  
      TTPCParameter(Text_t* name); 
      virtual ~TTPCParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
      
      Float_t       x_factor[6][2];     /* [mm/ch]                  */
      Float_t       x_offset[6][2];     /*                          */
      Float_t       y_factor[6][4];     /* [mm/ch]                  */
      Float_t       y_offset[6][4];     /*                          */
      
      Float_t 	    tdc1_factor[32];
      Float_t 	    tdc2_factor[32];
      
   ClassDef(TTPCParameter,1)
};
// *************************************************************************

class TMWDCParameter : public TGo4Parameter {
   public:
      TMWDCParameter();  
      TMWDCParameter(const char* name); 
      virtual ~TMWDCParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
     
      //----------- V1742 Unpack -------------
      Int_t v1742cellcorrection_enable;
      char  filename_v1742cellcorrectiontable[100];
      Int_t  v1742cellcorrection[32][1024];
      Int_t v1742cellcorrection_offset;
      Int_t v1742q_begin[32];
      Int_t v1742q_end[32];
      Int_t v1742baseline_begin[32];
      Int_t v1742baseline_end[32];
      Float_t v1742t_threshold[32];
      Float_t v1742valid_threshold[32];
      // for fadc
      Int_t min_t2141, min_t4142, max_t2141, max_t4142, plot_factor;

      //----------------
      //  Parameters used in SortProc
      Int_t plane_num[16][4]; //1st index = i_module, 2nd = i_ch_group 
      Int_t wire_group[16][4];

      //----------------
      //  Parameters used in CalibrProc  
      char plane_name[16][32];
      Float_t zpos[16],center_id[16],plane_angle[16],plane_sign[16];
      char filename_etap_setting[100];
      char filename_dtdx_table[100];
      Int_t   dt0[16], dtmin[16];
      Float_t dtdx_table[16][500];
      Float_t test;   /* ADC gains */
      Bool_t  b_selfcorr1;     /* 1 => Music1 x correction */
      Int_t tracking_level;
      
      Int_t first_event;
      Float_t focal_z;
      Float_t focal_a;
      Float_t focal_aa;
      Float_t focal_y;

      //------------------
      //     ETAP Scaler
      Int_t maxcount_v830;
      Int_t num_ch_v830;
      Int_t imod_v830[32];
      Int_t ich_v830[32];
      char  name_v830[32][64];
      Int_t i_v830_normalization;
      //
      // Messhuette
      char  name_v830_mh[32][64];
      Int_t imod_v830_mh[32];
      Int_t ich_v830_mh[32];
      //------------------
      //     ETAP SCI
      Int_t num_sci, sci_num_channel[16];
      char sci_name[16][32];
      char sci_channel_name[16][2][32];
      Int_t imod_v1742_sci[16][2];
      Int_t ich_v1742_sci[16][2];
      Int_t imod_v792_sci[16][2];
      Int_t ich_v792_sci[16][2];
      Int_t imod_v1290_sci[16][2];
      Int_t ich_v1290_sci[16][2];
      Float_t sci_q0[16][2];



      //----------------------
      //  Etaprime focus parameter
      Float_t l_mwdc_s4foc, angle_s4foc;
      Float_t l_mwdc_sc41, l_mwdc_hirac, l_mwdc_torch, l_mwdc_sc42;
      


      //------------------
      //    ETAP V1290 other 
      char  name_v1290_other[16][32];
      Int_t imod_v1290_other[16];
      Int_t ich_v1290_other[16];
      Int_t i_T0_v1290[2];
      Int_t num_ch_v1290_other;


      //-----------------
      //      mini
      char mini_channel_name[2][32];
      Int_t imod_v1742_mini[2];
      Int_t ich_v1742_mini[2];     
      Int_t imod_v792_mini[2];
      Int_t ich_v792_mini[2];
      Int_t imod_v1290_mini[2];
      Int_t ich_v1290_mini[2];
      char filename_mini_pecalibraion[100];
      Float_t mini_pe_calib[2][2];
      

      //-----------------
      //      HIRAC
      char hirac_channel_name[8][32];
      Int_t imod_v1742_hirac[8]; 
      Int_t ich_v1742_hirac[8];     
      Int_t imod_v792_hirac[8];
      Int_t ich_v792_hirac[8];
      Int_t imod_v1290_hirac[8];
      Int_t ich_v1290_hirac[8];
      char filename_hirac_pecalibraion[100];
      Float_t hirac_pe_calib[8][2];
      Float_t hirac_xpos[8];


      //-----------------
      //      TORCH
      char torch_channel_name[6][32];
      Int_t imod_v1742_torch[6];     
      Int_t ich_v1742_torch[6];     
      Int_t imod_v792_torch[6];
      Int_t ich_v792_torch[6];
      Int_t imod_v1290_torch[6];
      Int_t ich_v1290_torch[6];
      char filename_torch_pecalibraion[100];
      Float_t torch_pe_calib[6][2];
      Float_t torch_xpos[8];
      

      //-----------------
      ClassDef(TMWDCParameter,1)

};
 
// -------------------------------------------------------------------------

class TMUSICParameter : public TGo4Parameter {
   public:
      TMUSICParameter();  
      TMUSICParameter(const char* name); 
      virtual ~TMUSICParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
      
      Int_t         e1_off[8];       /* ADC offsets              */
      Float_t       e1_gain[8];      /* ADC gains                */ 
      Int_t         e2_off[8];       /* ADC offsets              */
      Float_t       e2_gain[8];      /* ADC gains                */ 
      Int_t         e3_off[4];       /* ADC offsets              */
      Float_t       e3_gain[4];      /* ADC gains                */ 
      Bool_t        b_selfcorr1;     /* 1 => Music1 x correction */
                                     /* 0 => MW41,MW42 x corr.   */
      Float_t       pos_a1[7];       /* pos. corr. de(i) ->  (1) */
                                     /*            de_cor(i)     */
      
   ClassDef(TMUSICParameter,1)
};

// -------------------------------------------------------------------------

class TSCIParameter : public TGo4Parameter {
   public:
      TSCIParameter();  
      TSCIParameter(const char* name); 
      virtual ~TSCIParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
      
      Float_t       le_a[2][12];     /* dE-left   shift,gain     */
      Float_t       re_a[2][12];     /* dE-right  shift,gain     */
      Float_t       le_veto_a[2][3]; /* veto dE-left  shift,gain */
      Float_t       re_veto_a[2][3]; /* veto dE-right shift,gain */

      Float_t       tac_factor[8];   /* TAC factor               */
      Float_t       tac_off[8];      /* TAC offset               */
      Float_t       x_a[7][12];      /* pos. corr. de(i) ->  (1) */
      Float_t       y5_a[7];         /* pos. corr. de(i) ->  (1) */

      Float_t       tof_bll2;        /* [ps/channel]             */
      Float_t       tof_brr2;        /* [ps/channel]             */
      Float_t       tof_a2;          /* shift [channels]         */
      Float_t       tof_bll3;        /* [ps/channel]             */
      Float_t       tof_brr3;        /* [ps/channel]             */
      Float_t       tof_a3;          /* shift [channels]         */
      
   ClassDef(TSCIParameter,1)
};

// -------------------------------------------------------------------------

class TIDParameter : public TGo4Parameter {
   public:
      TIDParameter();  
      TIDParameter(const char* name); 
      virtual ~TIDParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);
      
      Int_t         x2_select;       /* 1=> x2 position from MWs */
                                     /* 0=> x2 position from SCI */
                                     /* 2=> x2 position from TPC */
      Int_t         x4_select;       /* 1=> x4 pos.from MWs      */
                                     /* 0=> x4 pos.from ...      */
                                     /* 2=> x4 pos.from MUSIC    */
      Int_t         x8_select;       /* 1=> x8 pos.from MWs      */
                                     /* 0=> x8 pos.from ...      */
                                     /* 2=> x8 pos.from MUSIC    */
      Float_t       id_tofoff2;      /* Tof offset S2-S4 [ps]    */
      Float_t       id_tofoff3;      /* Tof offset S2-S8 [ps]    */
      Float_t       id_path2;        /* Flight path/c S2-S4 [ps] */
      Float_t       id_path3;        /* Flight path/c S2-S8 [ps] */
      Float_t       id_tofcorr2;     /* Tof correction for x4    */
      Float_t       id_tofcorr3;     /* Tof correction for x8    */

      Float_t       vel_a[4];
      Float_t       vel_a2[4];
      Float_t       vel_a3[4];
      
   ClassDef(TIDParameter,1)
};


// SI parameters
class TSIParameter : public TGo4Parameter {
   public:
      TSIParameter();  
      TSIParameter(const char* name); 
		virtual ~TSIParameter();
      virtual Int_t Print(Text_t*, Int_t);
      virtual Bool_t UpdateFrom(TGo4Parameter*);

      Float_t si_factor1;
      Float_t si_factor2;
      Float_t si_offset1;
      Float_t si_offset2;
      
		Float_t dssd_offset[32];
		Float_t dssd_factor[32];
    
   ClassDef(TSIParameter,1)
   };   

#endif //TFRSPARAMETER_H


