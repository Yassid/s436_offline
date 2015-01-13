#ifndef TFRSDATA_H
#define TFRSDATA_H

#include <TObject.h>

class TFRSAnlEvent;
class TFRSCalibrEvent;
class TFRSSortEvent;
class TFRSUnpackEvent;

class TFRSData : public TObject{
 private:  
  

  //CALIBRATION PART! 23:50  21072014 Yassid

   UInt_t calibr_freeTrig;
   UInt_t calibr_acptTrig;
   UInt_t calibr_mon_inc[64];

      Int_t         calibr_seconds;
      Int_t         calibr_tenthsecs;
      Int_t         calibr_hundrethsecs;	//mik
      Int_t         calibr_extraction_cycle;
      Int_t         calibr_coin[16];
      Float_t       calibr_seetram;
  

  // TPC part
  Float_t calibr_tpc_csum[6][4];

  Int_t calibr_tpc_x0raw[6];
  Int_t calibr_tpc_x1raw[6];
  Int_t calibr_tpc_yraw[6];

  Float_t calibr_tpc_x[6];
  Float_t calibr_tpc_y[6];
  Bool_t calibr_b_tpc_csum[6][4];
  Bool_t calibr_b_tpc_xy[6];

  //Only TPCs 21 & 22 @S2 (after target)
  Float_t calibr_tpc_x_s2_foc;
  Float_t calibr_tpc_y_s2_foc;
  Float_t calibr_tpc_angle_x_s2;
  Float_t calibr_tpc_angle_y_s2;
  //TPCs 5 & 6 @S4
  Float_t calibr_tpc_x_s4_foc;
  Float_t calibr_tpc_y_s4_foc;
  Float_t calibr_tpc_angle_x_s4;
  Float_t calibr_tpc_angle_y_s4;
  
  //TPCs 23 & 24 @ S2 target
  Float_t       calibr_tpc_x_s2_target;
  Float_t       calibr_tpc_y_s2_target;
  
  Float_t       calibr_tpc_sc21_x;      /* SC21 x                    */
  Float_t       calibr_tpc_sc41_x;      /* SC41 x                    */
  Float_t       calibr_tpc_sc21_y;      /* SC21 y                    */
  Float_t       calibr_tpc_sc41_y;      /* SC41 y                    */

     // ETAP scaler - > Yassid 13-01-2015 17:58 JST 
      Int_t calibr_etap_scaler[64];
      Int_t calibr_etap_scaler_increase[64];
      Float_t calibr_etap_scaler_normalized[64];

      Int_t calibr_mh_scaler[64];
      Int_t calibr_mh_scaler_increase[64];
      Float_t calibr_mh_scaler_normalized[64];


       //---ETAP-MWDC-Fitting---- Yassid 13-01-2015 18:06 JST 
 	Int_t calibr_mwdc_numtrack, calibr_mwdc_numtrack_estimate[2];
  	Float_t calibr_mwdc_chi2,calibr_mwdc_x,calibr_mwdc_y;
  	Float_t calibr_mwdc_a,calibr_mwdc_b,calibr_mwdc_res[16];
  	Float_t calibr_mwdc_res_ex[16];
  	Float_t calibr_mwdc_chi2_test[2],calibr_mwdc_x_test[2],calibr_mwdc_y_test[2];
  	Float_t calibr_mwdc_a_test[2],calibr_mwdc_b_test[2], calibr_mwdc_res_test[2][8];

        Float_t calibr_focal_plane;
        Int_t calibr_qdcvalid;

  //---ETAP-SCI---//
  Float_t calibr_sci_qdc[16][2];
  Float_t calibr_sci_tdc[16][2];
  Int_t calibr_sci_ml[16][2];
  Int_t calibr_sci_mt[16][2];
  Float_t calibr_sci_t0_tdc[16][2];
  Float_t calibr_sci_time[16][2];
  Float_t calibr_sci_timeave[16];
  Float_t calibr_sci_timedif[16];
  Float_t calibr_sci_de[16]; 

   //--------------
  Float_t calibr_tof_21l_41l,calibr_tof_21r_41r, calibr_tof_21_41;
  Float_t calibr_tof_41l_42l,calibr_tof_41r_42r, calibr_tof_41_42;


  //SORT PART! --------------------------------------------------------------------------------------
  
        
      Int_t sort_mwdc_numhit[16];
      Int_t sort_mwdc_wireid[16][64];
      Int_t sort_mwdc_tot[16][64];
      Int_t sort_mwdc_time[16][64];
      Int_t sort_mwdc_time_trail[16][64];

     
      Int_t sort_etapsci_t[16][2]; // [i_sci][i_LR]
      Int_t sort_etapsci_t_trail[16][2];      
      Int_t sort_etapsci_q[16][2];      
            
     
      Int_t sort_hirac_t[8];
      Int_t sort_hirac_t_trail[8];
      Int_t sort_hirac_q[8];   

    
      Int_t sort_torch_t[8];
      Int_t sort_torch_t_trail[8];
      Int_t sort_torch_q[8];  

     
      Int_t sort_mini_t[2];
      Int_t sort_mini_t_trail[2];
      Int_t sort_mini_q[2];

    
      Int_t sort_etap_scaler[32];


      // TPC part //(HAPOL-25/03/06) 6 TPCs each one with 2 delay lines each!!
      Int_t tpc_l[6][2];
      Int_t tpc_r[6][2];
      Int_t tpc_lt[6][2];
      Int_t tpc_rt[6][2];

      // [index][anode_no]
      Int_t tpc_dt[6][4];
      Int_t tpc_a[6][4];

  // scaler readings 
  UInt_t         sort_sc_long[32];      //signed 31-bit integer    
  
  // SEETRAM calib IC energy 
  Int_t         sort_ic_de;					 
  Int_t         sort_pattern; 
  
                          
  
   // TPC part //(HAPOL-25/03/06) 6 TPCs each one with 2 delay lines each!! 
   Int_t sort_tpc_l[6][2]; 
   Int_t sort_tpc_r[6][2]; 
   Int_t sort_tpc_lt[6][2]; 
   Int_t sort_tpc_rt[6][2]; 
  
   // [index][anode_no] 
   Int_t sort_tpc_dt[6][4]; 
   Int_t sort_tpc_a[6][4]; 
  
   // SCI part 
  
  
            
   Int_t         dt_11d;          // TDC SCI11 Right            
   Int_t         dt_21l;          // TDC SCI21 left            
   Int_t         dt_21r;          // TDC SCI21 right           
   Int_t         dt_41l;          // TDC SCI41 left            
   Int_t         dt_41r;          // TDC SCI41 right           
  
  
   //UNPACK PART! 
 
   //*********** FRS Crates ****************

  UInt_t unpack_vme0[21][32];     // values from 0..4095 should be, 
  // first row (index = 0) not used 
  UInt_t unpack_vme1[21][32];     // values from 0..4095 should be, 
 

    //-------- TENSOR-ETAP crate
      // amsc
      Int_t unpack_amscl[16][64];        // AMSC [i_mod][i_ch]
      Int_t unpack_amsct[16][64];        // AMSC [i_mod][i_ch]
      Int_t unpack_amsc_length[16];      // AMSC [i_mod]
      Int_t unpack_amsc_error[16];       // AMSC [i_mod]
      Int_t unpack_amsc_itry[16];        // AMSC [i_mod]
      // v830
     
      Int_t unpack_v830n[32];         // v830 (scaler) value
      Int_t unpack_v830_length;       // data length
      Int_t unpack_v830_itry;         // itry  
      // v1290
      Int_t unpack_v1290l[2][32];  
      Int_t unpack_v1290t[2][32]; 
      Int_t unpack_v1290_length[2]; 
      Int_t unpack_v1290_itry[2]; 
      // v792
      Int_t unpack_v792q[2][16];
      Int_t unpack_v792_length[2]; 
      Int_t unpack_v792_itry[2]; 
      // v775 
      Int_t unpack_v775t[32];
      Int_t unpack_v775_length; 
      Int_t unpack_v775_itry; 
      //-----------------------------------------------

      
      //-------- fADC crate  --------------------------
      Float_t unpack_v1742q[32];      // V1742_TEST
      Float_t unpack_v1742baseline[32];      // V1742_TEST
      Float_t unpack_v1742t[32];      // V1742_TEST
      Int_t   unpack_v1742valid[32];      // V1742_TEST
      Int_t   unpack_v1742_length;       // data length
      Int_t   unpack_v1742_itry;         // itry   
      //-----------------------------------------------


        Int_t         unpack_qlength;         /* From event header     */
        Int_t         unpack_qtype;           /*                       */
        Int_t         unpack_qsubtype;        /*                       */
        Int_t         unpack_qdummy;          /*                       */
        Int_t         unpack_qtrigger;        /*                       */
        Int_t         unpack_qevent_nr;       /*                       */
  

 public:
  TFRSData();
  virtual ~TFRSData();
  

  void Fill(TFRSAnlEvent* anal, TFRSCalibrEvent* calibr);
  void Fill(TFRSAnlEvent* anal, TFRSCalibrEvent* calibr, TFRSSortEvent *sort, TFRSUnpackEvent *unpack);
  virtual void Clear();
  
  ClassDef(TFRSData,1);
};

#endif //TFRSDATA_H
