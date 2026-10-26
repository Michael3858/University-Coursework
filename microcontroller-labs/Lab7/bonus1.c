#include "C8051F040.h"
void Timer1_ISR ();
void
Port_Configuration ()
{
 //initialize SFR setup page
 SFRPAGE = CONFIG_PAGE;                 // Switch to configuration page

 //setup the cross-bar and configure the I/O ports
 XBR2 = 0xc0;
 P2MDOUT = 0xff;

 //set to normal mode
 SFRPAGE = LEGACY_PAGE;
}//end of function Port_Configuration

void
Timer_Configuration ()
{
 TMOD = 0x11;
 TCON = 0x50;
 CKCON = 0x10;

 IE = 0x8a;
 TL0 = 0xfd;
 TH0 = 0xeb;
 TL1 = 0xf0;
 TH1 = 0xd8;
}//end of function Timer_Configuration

void
Config ()
{
 //turn-off watch-dog timer
 WDTCN = 0xde;
 WDTCN = 0xad;

 SFRPAGE = CONFIG_PAGE;

 OSCICN = 0x83;
 CLKSEL = 0x00;

 Port_Configuration ();
 Timer_Configuration ();
}//end of function Default_Config





unsigned char status;
int count_for_time;
int count_for_scale;
int half_period;
int half_period_list[7]={19/*DO=3.81*/,17/*RE=3.40*/,15/*MI=3.0*/,14/*FI=2.86*/,12/*SO=2.55*/,11/*LA=2.27*/,10/*SI=2.02*/};//半週期

int music[33]={12,0,11,12,14,15,14,12,0,17,15,14,0,15,14,12,0,12,0,11,12,14,15,14,12,0,17,0,12,0,15,0,19};
int music_count=33;


int scale=0;
//int n=0;
int
main ()
{
 Config ();
 status = 0x00;
 count_for_scale = 0;
    count_for_time = 0;
 half_period = 12;
 
 while (1) {
  P2 = status;
 }//end while (1)
}//end of function main


//basic
/*
void
Timer0_ISR () interrupt 1
{
 count_for_scale++;
 if (count_for_scale==half_period_list[scale]) {
  count_for_scale = 0;
  status = ~status;
 }

 TL0 = 0x00;
 TH0 = 0xff;
}//end of function Timer0_ISR


void Timer1_ISR () interrupt 3
{
  count_for_time++;
  if (count_for_time==300) {
    count_for_time = 0;
    scale=(scale+1)%7;
  }
 TL1 = 0;
 TH1 = 0;
 
}
*/


//bonus1
int n;
void
Timer0_ISR () interrupt 1
{
 count_for_scale=(count_for_scale+1)%n;
 if (count_for_scale==0) {
  //count_for_scale = 0;
  status = ~status;
 }

 TL0 = 0x00;
 TH0 = 0xff;
}//end of function Timer0_ISR

void Timer1_ISR () interrupt 3//for sing
{
  count_for_time++;
  if (count_for_time==60) {
    count_for_time = 0;
    n=music[scale];
    scale=(scale+1)%music_count;
  }
 TL1 = 0;
 TH1 = 0;
 
}