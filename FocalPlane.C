#include "TFRSCalibrEvent.h"
#include "TH2F.h"
#include "TFile.h"
#include "TString.h"
#include "TTree.h"
#include "TChain.h"
#include "Riostream.h"
#include <vector>

void FocalPlaneList(std::vector<TString> name_in, Long64_t nb=0)
{
  //TFile* f = new TFile(name_in);
  TFRSCalibrEvent* event = 0;
  
  //TTree* t = (TTree*) f->Get("CalibrxTree");
  TChain* t = new TChain("CalibrxTree");
  for(unsigned int nfile = 0;nfile<name_in.size();++nfile)
    {
      t->AddFile(name_in[nfile]);
    }

  t->SetCacheSize(30000000);
  t->AddBranchToCache("*");
  t->SetBranchAddress("FRSCalibrEvent.",&event);
  
  Long64_t Nevents = nb != 0 ? nb : t->GetEntries();
  cout<<"N :"<<Nevents<<endl;

  //t->Show(10);

  Long64_t count = 0;
  TH2F* h_focalX = new TH2F("h_focalX","h_focalX",1000,-600,400,17000,-100,70);
  TH2F* h_xA = new TH2F("h_xA","h_xA",1000,-100,100,1000,-20,20);
  TH2F* h_yB = new TH2F("h_yB","h_yB",1000,-100,100,1000,-20,20);
  TH2F* h_FA = new TH2F("h_FA","h_FA",1000,-100,100,1000,-20,20);
  TH2F* h_focalY = new TH2F("h_focalY","h_focalY",1000,-40,40,1000,-100,100);

  for(Long64_t i = 0; i<Nevents;++i)
    {
//       if(i%500!=0)
// 	continue;
      ++count;
      if(count%10000==1)
	cout<<"current event#"<<count<<endl;
      t->GetEntry(i);

      if(event->mwdc_chi2>6)
	continue;

      int numhit_total;
      numhit_total = (event->mwdc_numhit[0]+event->mwdc_numhit[1]+event->mwdc_numhit[2]+event->mwdc_numhit[3]+event->mwdc_numhit[4]+event->mwdc_numhit[5]+event->mwdc_numhit[6]+event->mwdc_numhit[7]+event->mwdc_numhit[8]+event->mwdc_numhit[9]+event->mwdc_numhit[10]+event->mwdc_numhit[11]+event->mwdc_numhit[12]+event->mwdc_numhit[13]+event->mwdc_numhit[14]+event->mwdc_numhit[15]);

      if(numhit_total!=16)
	continue;

      double mw_x = event->mwdc_x;
      double mw_a = event->mwdc_a;

      double mw_y = event->mwdc_y;
      double mw_b = event->mwdc_b;
      
      
      for(int j=1;j<h_focalX->GetXaxis()->GetNbins();++j)
	{
	  double temp_z = h_focalX->GetXaxis()->GetBinCenter(j);
	  double temp_x = mw_x+mw_a*temp_z;
	  
	  h_focalX->Fill(temp_z,temp_x);
	}
      for(int j=1;j<h_focalY->GetXaxis()->GetNbins();++j)
	{
	  double temp_z = h_focalY->GetXaxis()->GetBinCenter(j);
	  double temp_y = mw_y+mw_b*temp_z;
	  
	  h_focalY->Fill(temp_z,temp_y);
	}

      h_xA->Fill(mw_x,1000.*mw_a);     
      h_yB->Fill(mw_y,1000.*mw_b);     
      h_FA->Fill(event->focal_plane,1000.*mw_a);
      
      
    }

//   TH2F* h_hough2 = new TH2F("h_hough2","h_hough2",1100,-10,1,1000,-100,100);

 
//   for(int j=1;j<h_focalX->GetXaxis()->GetNbins();++j)
//     {
//       for(int k=1;k<h_focalX->GetYaxis()->GetNbins();++k)
// 	{
	    
// 	  double temp_z = h_focalX->GetXaxis()->GetBinCenter(j);
// 	  double temp_x = h_focalX->GetYaxis()->GetBinCenter(k);
// 	  double binC = h_focalX->GetBinContent(j,k);
// 	  if(binC>1000)
// 	    {
	            
// 	      for(int i=1;i<h_hough2->GetXaxis()->GetNbins();++i)
// 		{
// 		  double temp_a = h_hough2->GetXaxis()->GetBinCenter(i);
// 		  double temp_x2 = temp_x-temp_a*temp_z;
// 		  h_hough2->Fill(temp_a,temp_x2);
// 		}  
// 	    }
// 	}
//     }





  TFile* f = new TFile("TrialFocal.root","RECREATE");
  f->cd();
  
  h_focalX->Write();//SaveAs("TrialFocal.root");
  h_focalY->Write();
  //h_hough2->Write();
  h_xA->Write();
  h_FA->Write();
  h_yB->Write();
  f->Close();
}



void FocalPlane()
{
  std::vector<TString> name_files;
  
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0109_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0110_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0111_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0112_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0113_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0114_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0115_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0116_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0117_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0118_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0119_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0120_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0121_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0122_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0123_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0124_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0125_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0126_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0127_CAL.root");
  //name_files.push_back("/d/frs03/s437/temp_root/Carbon_Extracted/pd14Jul0128_CAL.root");
  
  
  name_files.push_back("/d/frs03/s437/temp_root/Carbon_lmd110-114_CAL.root");
  name_files.push_back("/d/frs03/s437/temp_root/Carbon_lmd115-119_CAL.root");
  name_files.push_back("/d/frs03/s437/temp_root/Carbon_lmd120-124_CAL.root");
  name_files.push_back("/d/frs03/s437/temp_root/Carbon_lmd125-127_CAL.root");



//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0248_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0249_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0250_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0251_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0252_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0253_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0254_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0255_CAL.root");
//   name_files.push_back("/d/frs03/s437/temp_root/pd14Jul0256_CAL.root");


  FocalPlaneList(name_files);
  
}
