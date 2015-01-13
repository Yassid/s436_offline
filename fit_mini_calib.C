 // for fitting LED calibration data
#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"

void fit_mini_calib(){
  TH1I *hist[2];
  double pedestal_estimate[2], gain_estimate[2] ;
  double ped[2]={};
  double ped_err[2]={};
  double gain[2]={};
  double gain_err[2]={};
  TCanvas *c0=new TCanvas("c0","c0",100,0,600,750);
  c0->Divide(1,2);
		
  //-------- need to edit here -------------------
  hist[0]= newVMEv792q10_00_00__1 ;  pedestal_estimate[0]=400.;  gain_estimate[0]=50.; //1
  hist[1]= newVMEv792q10_01_00__2 ;  pedestal_estimate[1]=380.;  gain_estimate[1]=30.; //2
  //----------------------------------------------

  //----- Fit each histogram & Draw -----
  for(int i=0; i<2; i++){
	double result[4];
	c0->cd(i+1);
	fit_spectrum(hist[i], pedestal_estimate[i], gain_estimate[i],result);
	ped[i]     = result[0];	
	ped_err[i] = result[1];
	gain[i]    = result[2];
	gain_err[i]= result[3];
  } 
  
  //----- print result -----
  fprintf(stderr,"MINI_CALIBRATION_TABLE_BEGIN\n");
  for(int i=0; i<2; i++){
	fprintf(stderr,"%d %f %f %f %f\n",i ,ped[i], ped_err[i], gain[i], gain_err[i]);// ped, ped_err, gain, gain_err;
  }
  fprintf(stderr,"MINI_CALIBRATION_TABLE_END\n"); 
  
  return ;
}




/*
par[0]=area of pedestal;
par[1]=position of pedestal;
par[2]=sigma of pedestal;
par[3]=factor for 1p.e.
par[4]=poisson mean;
par[5]=channnel for 1 p.e.;
par[6]=sigma for 1p.e.;
par[7]=factor for 2p.e.
par[8]=factor for 3p.e.
par[9]=factor for 4p.e.
par[10]=factor for 5p.e.
*/



//------fit 1 histogram------
void fit_spectrum(TH1I *h1, double ped_ini, double gain_ini, double* result_out){
  TF1 *fitFcn;
  double fit_start, fit_end, area, sigma0, mu, gain, sigma1;
  double binwidth,centerx1,factor1,factor2,factor3,factor4,factor5;
  int bin_fit_start, bin_fit_end; 

  //---- setting for 1st fit(pedestal)-------
  fit_start = (ped_ini - 0.5*gain_ini) ;
  fit_end   = (ped_ini + 0.5*gain_ini) ;
  fitFcn    = new TF1("fitFcn", fitFunction, fit_start, fit_end, 11);
  binwidth  = h1->GetBinWidth(1);
  centerx1  = h1->GetBinCenter(1);
  bin_fit_start = 1+((int)(((fit_start)-centerx1)/binwidth));
  bin_fit_end   = 1+((int)(((fit_end)-centerx1)/binwidth));
  area    = (Double_t)(h1->Integral(bin_fit_start, bin_fit_end));
  sigma0  = 5.0 ;
  mu      = 1.0 ;
  gain    = gain_ini;
  sigma1  = gain_ini/2.0;
  fitFcn->SetParameters(area, ped_ini, sigma0, 1.0, mu, gain, sigma1, 1.0, 1.0, 1.0, 1.0);
  fitFcn->FixParameter(3,1.0);
  fitFcn->FixParameter(4,mu);
  fitFcn->FixParameter(5,gain);
  fitFcn->FixParameter(6,sigma1);
  fitFcn->FixParameter(7,1.0);
  fitFcn->FixParameter(8,1.0);
  fitFcn->FixParameter(9,1.0);
  fitFcn->FixParameter(10,1.0);
  fitFcn->SetParLimits(0,area*0.05,area*2.0);
  fitFcn->SetParLimits(1,ped_ini-5.0,ped_ini+5.0);
  fitFcn->SetParLimits(2,0.1,10.0);
  fitFcn->SetNpx(2000);
  h1->Fit("fitFcn","INO","",fit_start,fit_end);

  
  //----setting for 2nd fit (>=1pe part)-------
  // 2nd rough fit for 1p.e., 2p.e.
  fit_start = (ped_ini - 0.5*gain_ini) ;
  fit_end   = (ped_ini + 3.5*gain_ini) ;
  ped_ini = fitFcn->GetParameter(1);
  area    = fitFcn->GetParameter(0);
  sigma0  = fitFcn->GetParameter(2); 
  fitFcn->SetParameters(area, ped_ini,sigma0,1.0,mu,gain,sigma1,1.0,1.0,1.0,1.0);
  fitFcn->FixParameter(0,area);
  fitFcn->FixParameter(1,ped_ini);
  fitFcn->FixParameter(2,sigma0);
  fitFcn->FixParameter(3,1.0);
  fitFcn->SetParLimits(4,0.1,100.0);
  fitFcn->SetParLimits(5,0.1,100.0);
  fitFcn->SetParLimits(6,1.0,30.0);
  fitFcn->SetParLimits(7,0.1,4.0);
  fitFcn->SetParLimits(8,0.1,10.0);
  fitFcn->FixParameter(9,1.0);
  fitFcn->FixParameter(10,1.0);
  h1->Fit("fitFcn","","",fit_start,fit_end);

  //----setting for 3rd fit (all)-------
  fit_start = (ped_ini - 0.7*gain_ini) ;
  fit_end   = (ped_ini + 4.5*gain_ini) ;
  ped_ini = fitFcn->GetParameter(1);
  area    = fitFcn->GetParameter(0);
  sigma0  = fitFcn->GetParameter(2);
  factor1 = fitFcn->GetParameter(3);
  mu      = fitFcn->GetParameter(4);
  gain    = fitFcn->GetParameter(5);
  sigma1  = fitFcn->GetParameter(6);
  factor2 = fitFcn->GetParameter(7);
  factor3 = fitFcn->GetParameter(8);
  factor4 = fitFcn->GetParameter(9);
  factor5 = fitFcn->GetParameter(10);
  fitFcn->SetParameters(area, ped_ini,sigma0,factor1,mu,gain,sigma1,factor2,factor3,factor4,factor5);
  fitFcn->SetParLimits(0, 0.5*area, 3.5*area);
  fitFcn->SetParLimits(1, ped_ini*0.5, 1.5*ped_ini);
  fitFcn->SetParLimits(2, sigma0*0.5,  sigma0*1.5);
  fitFcn->SetParLimits(3, factor1*0.5, factor1*1.5);
  fitFcn->SetParLimits(4, mu*0.7,  mu*1.3);
  fitFcn->SetParLimits(5, gain*0.5, gain*1.5);
  fitFcn->SetParLimits(6, sigma1*0.5, sigma1*2.0);
  fitFcn->SetParLimits(7, 0.1*factor2,10.0*factor2);
  fitFcn->SetParLimits(8, 0.1*factor3,10.0*factor3);
  fitFcn->SetParLimits(9, 0.0,10.0);
  fitFcn->SetParLimits(10,0.0,10.0);
  fitFcn->FixParameter(9,factor4);
  fitFcn->FixParameter(10,factor5);
  h1->Fit("fitFcn","","",fit_start,fit_end);
  //
  h1->SetFillColor(0);
  h1->SetLineColor(4);
  result_out[0]=fitFcn->GetParameter(1);
  result_out[1]=fitFcn->GetParError(1);	
  result_out[2]=fitFcn->GetParameter(5);
  result_out[3]=fitFcn->GetParError(5);
  //
  return ;
}


//-----fit function ------
// Gaussian Peak function

/*
par[0]=area of pedestal;
par[1]=position of pedestal;
par[2]=sigma of pedestal;
par[3]=factor for 1p.e.
par[4]=poisson mean;
par[5]=channnel for 1 p.e.;
par[6]=sigma for 1p.e.;
par[7]=factor for 2p.e.
par[8]=factor for 3p.e.
par[9]=factor for 4p.e.
par[10]=factor for 5p.e.
*/


Double_t gaussian(Double_t x, Double_t a, Double_t mean, Double_t sigma){
  return (a/sqrt(2.0*TMath::Pi()*sigma*sigma))*exp(-1.0*((x-mean)*(x-mean))/(2.0*sigma*sigma));
}

Double_t pedestal(Double_t *x, Double_t *par) {
	return gaussian(x[0],par[0],par[1],par[2]);
}

Double_t onepe(Double_t *x, Double_t *par){
	Double_t area1=par[0]*pow(par[4],1.0)/1.0;
	return gaussian(x[0],area1,(par[1]+1.0*par[5]),(par[6]*sqrt(1.0)));
}

Double_t twope(Double_t *x, Double_t *par){
	Double_t area2=par[0]*pow(par[4],2.0)/2.0;
	return gaussian(x[0],area2,(par[1]+2.0*par[5]),(par[6]*sqrt(2.0)));
}

Double_t threepe(Double_t *x, Double_t *par){
	Double_t area3=par[0]*pow(par[4],3.0)/6.0;
	return gaussian(x[0],area3,(par[1]+3.0*par[5]),(par[6]*sqrt(3.0)));
}

Double_t fourpe(Double_t *x, Double_t *par){
	Double_t area4=par[0]*pow(par[4],4.0)/24.0;
	return gaussian(x[0],area4,(par[1]+4.0*par[5]),(par[6]*sqrt(4.0)));
}

Double_t fivepe(Double_t *x, Double_t *par){
	Double_t area5=par[0]*pow(par[4],5.0)/120.0;
	return gaussian(x[0],area5,(par[1]+5.0*par[5]),(par[6]*sqrt(5.0)));
}

Double_t fitFunction(Double_t *x, Double_t *par){ 
//   return onepe(x,par);
return pedestal(x,par)+ par[3]*onepe(x,par)+ par[7]*twope(x,par)+ par[8]*threepe(x,par)+ par[9]*fourpe(x,par)+ par[10]*fivepe(x,par);
}
Double_t draw_ped(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return pedestal(x,par);
}
Double_t draw_one(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return par[3]*onepe(x,par);
}
Double_t draw_two(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return  par[7]*twope(x,par);
}
Double_t draw_three(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return par[8]*threepe(x,par);
}

Double_t draw_four(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return par[9]*fourpe(x,par);
}

Double_t draw_five(Double_t *x, Double_t *par){ 
	//   return onepe(x,par);
	return  par[10]*fivepe(x,par);
}



