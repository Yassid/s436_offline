#define s437_ascii_cxx
#include "s437_ascii.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void s437_ascii::Loop()
{


  ofstream *out=new ofstream("out_ascii.txt");

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(jentry%1000==0)cout<<" Dumping data into txt... :"<<jentry<<endl;

      *out<<FRSCalibrEvent_mwdc_x<<"      "<<FRSCalibrEvent_mwdc_y<<"      "<<FRSCalibrEvent_mwdc_a<<"      "<<FRSCalibrEvent_mwdc_b<<"      "<<FRSCalibrEvent_sci_qdc[4][0]<<"      "<<FRSCalibrEvent_sci_qdc[4][1]<<"      "<<FRSCalibrEvent_sci_qdc[6][0]<<"      "<<FRSCalibrEvent_sci_qdc[6][1]<<"      "<<FRSCalibrEvent_sci_qdc[7][0]<<"      "<<FRSCalibrEvent_sci_qdc[7][1]<<"      "<<FRSCalibrEvent_sci_qdc[8][0]<<"      "<<FRSCalibrEvent_sci_qdc[8][1]<<"      "<<FRSCalibrEvent_sci_tdc[4][0]<<"      "<<FRSCalibrEvent_sci_tdc[4][1]<<"      "<<FRSCalibrEvent_sci_tdc[6][0]<<"      "<<FRSCalibrEvent_sci_tdc[6][1]<<"      "<<FRSCalibrEvent_sci_tdc[7][0]<<"      "<<FRSCalibrEvent_sci_tdc[7][1]<<"      "<<FRSCalibrEvent_sci_tdc[8][0]<<"      "<<FRSCalibrEvent_sci_tdc[8][1]<<"      "<<FRSCalibrEvent_sci_tdc[9][0]<<"      "<<FRSCalibrEvent_sci_tdc[10][0]<<"      "<<FRSCalibrEvent_mh_scaler[6]<<"      "<<FRSCalibrEvent_mh_scaler[10]<<"      "<<FRSCalibrEvent_mh_scaler[11]<<"      "<<FRSCalibrEvent_mh_scaler[13]<<"      "<<FRSCalibrEvent_mh_scaler[14]<<"      "<<FRSCalibrEvent_mh_scaler[15]<<endl;
      

      

   }
}
