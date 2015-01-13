#include "TFRSData.h"
#include "TFRSAnlEvent.h"
#include "TFRSCalibrEvent.h"
#include "TFRSSortEvent.h"
#include "TFRSUnpackEvent.h"
#include "Riostream.h"


TFRSData::TFRSData(){
  //
  //
  //
}

TFRSData::~TFRSData(){
  //
  //
  //

}
void TFRSData::Fill(TFRSAnlEvent* anal, TFRSCalibrEvent* calibr){
  //
  //
  //



  // TPC part
  for(Int_t i=0;i<6;i++)   
    for(Int_t j=0;j<4;j++)   
      calibr_tpc_csum[i][j] = calibr->tpc_csum[i][j];
  // for(Int_t i=0;i<6;i++) calibr_tpc_x0raw[i] = calibr->tpc_x0_raw[i];
  // for(Int_t i=0;i<6;i++) calibr_tpc_x1raw[i] = calibr->tpc_x1_raw[i];
  //for(Int_t i=0;i<6;i++) calibr_tpc_yraw[i] = calibr->tpc_y_raw[i];
  for(Int_t i=0;i<6;i++) calibr_tpc_x[i] = calibr->tpc_x[i];
  for(Int_t i=0;i<6;i++) calibr_tpc_y[i] = calibr->tpc_y[i];
  for(Int_t i=0;i<6;i++)   
    for(Int_t j=0;j<4;j++)   
      calibr_b_tpc_csum[i][j] = calibr->b_tpc_csum[i][j];
  for(Int_t i=0;i<6;i++) calibr_b_tpc_xy[i] = calibr->b_tpc_xy[i];


  //TPCs 1 & 2 @S2 (after target) Yassid 22072014 for S436-S437 TPC1 and TPC2 (vacuum) are used
  //calibr_tpc_x_s2_foc = calibr->tpc_x_s2_foc;
  // calibr_tpc_y_s2_foc = calibr->tpc_y_s2_foc;
  // calibr_tpc_angle_x_s2 = calibr->tpc_angle_x_s2;
  // calibr_tpc_angle_y_s2 = calibr->tpc_angle_y_s2;
  //TPCs 5 & 6 @S4
  // calibr_tpc_x_s4_foc = calibr->tpc_x_s4_foc;
  // calibr_tpc_y_s4_foc = calibr->tpc_y_s4_foc;
  // calibr_tpc_angle_x_s4 = calibr->tpc_angle_x_s4;
  // calibr_tpc_angle_y_s4 = calibr->tpc_angle_y_s4;

  // calibr_tpc_x_s2_target = calibr->tpc_x_s2_target;
  // calibr_tpc_y_s2_target = calibr->tpc_y_s2_target;

  // calibr_tpc_sc21_x = calibr->tpc_sc21_x;
  // calibr_tpc_sc41_x = calibr->tpc_sc41_x;
  // calibr_tpc_sc21_y = calibr->tpc_sc21_y;
  // calibr_tpc_sc41_y = calibr->tpc_sc41_y;

}

void TFRSData::Fill(TFRSAnlEvent* anal, TFRSCalibrEvent* calibr, TFRSSortEvent *sort, TFRSUnpackEvent *unpack){
  //
  //
  //
  Fill(anal, calibr);



  
   // scaler readings
   for(Int_t i=0;i<16;i++) sort_sc_long[i] = sort->sc_long[i];
   
   // SEETRAM calib IC energy
 //  sort_ic_de = sort->ic_de;      
 //  sort_pattern = sort->pattern;
  
    
   
   // TPC part //(HAPOL-25/03/06) 6 TPCs each one with 2 delay lines each!!
   for(Int_t i=0;i<6;i++) {
     for(Int_t j=0;j<2;j++) {   
       sort_tpc_l[i][j] = sort->tpc_l[i][j];
       sort_tpc_r[i][j] = sort->tpc_r[i][j];
       sort_tpc_lt[i][j] = sort->tpc_lt[i][j];
       sort_tpc_rt[i][j] = sort->tpc_rt[i][j];
     }
     
       // [index][anode_no]
     for(Int_t j=0;j<4;j++) {   
       sort_tpc_dt[i][j] = sort->tpc_dt[i][j];
       sort_tpc_a[i][j] = sort->tpc_a[i][j];
     }
   }

    for(Int_t i=0;i<16;i++) {
      sort_mwdc_numhit[i]=sort->mwdc_numhit[i];
      for(Int_t j=0;j<64;j++) {
      sort_mwdc_wireid[i][j]=sort->mwdc_wireid[i][j];
      sort_mwdc_tot[i][j]=sort->mwdc_tot[i][j];
      sort_mwdc_time[i][j]=sort->mwdc_time[i][j];
      sort_mwdc_time_trail[i][j]=sort->mwdc_time_trail[i][j];
      }
    }

    // sort_etapsci_t[16][2]; 
    //  sort_etapsci_t_trail[16][2];      
    //  sort_etapsci_q[16][2];       




   // SCI part
 //  sort_de_11d = sort->de_11d;      
 //  sort_de_11u = sort->de_11u;      
 //  sort_de_21l = sort->de_21l;      
 //  sort_de_21r = sort->de_21r;      
 //  sort_de_41l = sort->de_41l;      
 //  sort_de_41r = sort->de_41r;      
 //  sort_de_21ld = sort->de_21ld;     
 //  sort_de_21rd = sort->de_21rd;     
  
 //  sort_dt_11d_11u = sort->dt_11d_11u;  
 //  sort_dt_22d_22u = sort->dt_22d_22u;  
 //  sort_dt_21l_21r = sort->dt_21l_21r;  
 //  sort_dt_41l_41r = sort->dt_41l_41r;  
 //  sort_dt_11d_21l = sort->dt_11d_21l;  
 //  sort_dt_11u_21r = sort->dt_11u_21r;  
 //  sort_dt_21l_41l = sort->dt_21l_41l;  
 //  sort_dt_21r_41r = sort->dt_21r_41r;  
 

  

//UNPACK PART!

  


   for(Int_t i=0;i<21;i++) {
     for(Int_t j=0;j<32;j++) {   
       unpack_vme0[i][j] = unpack->vme0[i][j]; 
       unpack_vme1[i][j] = unpack->vme1[i][j];
      
     }
   }     
    
  unpack_qlength = unpack->qlength;      
  unpack_qtype = unpack->qtype;        
  unpack_qsubtype = unpack->qsubtype;     
  unpack_qdummy = unpack->qdummy;       
  unpack_qtrigger = unpack->qtrigger;     
  unpack_qevent_nr = unpack->qevent_nr;    

  

   for(Int_t i=0;i<16;i++) {
       unpack_amsc_length[i]=unpack->amsc_length[i];     
       unpack_amsc_error[i]=unpack->amsc_error[i];       
       unpack_amsc_itry[i]=unpack->amsc_itry[i];  
     for(Int_t j=0;j<64;j++) {
       unpack_amscl[i][j]=unpack->amscl[i][j];      
       unpack_amsct[i][j]=unpack->amsct[i][j];       
       
     }
   }



    for(Int_t i=0;i<2;i++) {
       unpack_v1290_length[i]=unpack->v1290_length[i]; 
       unpack_v1290_itry[i]=unpack->v1290_length[i]; 
       for(Int_t j=0;j<32;j++) {
	 unpack_v1290l[i][j]=unpack->v1290l[i][j];  
	 unpack_v1290t[i][j]=unpack->v1290t[i][j]; 
     }
    } 


     for(Int_t i=0;i<32;i++) {
      unpack_v830n[i]=unpack->v830n[i];             
     }

     unpack_v830_length=unpack->v830_length;     
     unpack_v830_itry=unpack->v830_itry;    

   
    for(Int_t i=0;i<2;i++) {   
       unpack_v792_length[i]=unpack->v792_length[i]; 
       unpack_v792_itry[i]=unpack->v792_length[i]; 
      for(Int_t j=0;j<16;j++) {
	unpack_v792q[i][j]=unpack->v792q[i][j];
      }
    }

    for(Int_t i=0;i<32;i++) {
         unpack_v775t[i];
    }


         unpack_v775_length=unpack->v775_length; 
         unpack_v775_itry=unpack->v775_itry; 


    for(Int_t i=0;i<32;i++){
      unpack_v1742q[i]=unpack->v1742q[i];    
      unpack_v1742baseline[i]=unpack->v1742baseline[i];      
      unpack_v1742t[i]=unpack->v1742t[i];      
      unpack_v1742valid[i]=unpack->v1742valid[i];    
    }

      unpack_v1742_length=unpack->v1742_length;       
      unpack_v1742_itry=unpack->v1742_itry;         



}


void TFRSData::Clear(){
  //
  //
  //


}

ClassImp(TFRSData);
