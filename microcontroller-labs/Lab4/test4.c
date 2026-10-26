#include "C8051F040.h"
void Timer0_ISR ();
int count=0;
int N=50;
unsigned status=0;
int temp=0;
sbit putton1=P1^7;
sbit putton2=P1^6;
sbit putton3=P1^5;
sbit putton4=P1^4;
int mode=0;

void
Timer_Configuration (){
 	TMOD = 0x01;
 	TCON = 0x10;
 	CKCON = 0x10;

 	IE = 0x82;
 	TL0 = 0;
 	TH0 = 0;
} //end of function Timer_Configuration

void
Port_Configuration (){ //initialize SFR setup page
 	SFRPAGE = CONFIG_PAGE; // Switch to configuration page
 	XBR2 = 0xc0;
 	P1MDIN = 0xff;
 	P2MDOUT = 0xff;
  	//set to normal mode
 	SFRPAGE = LEGACY_PAGE;

} //end of function Port_Configuration

void
Default_Config (){
 	//turn-off watch-dog timer
 	// disable watchdog timer
 	WDTCN = 0xde;
 	WDTCN = 0xad;

	OSCICN = 0x83;
 	CLKSEL = 0x00;

 	Port_Configuration ();

 	Timer_Configuration ();
} //end of function Default_Config


/****************
There are something wrong with the function below!
Please see the following hints:
1. See the error message and fix those errors
2. The initiailization of N
3. The initialization of P1
****************/
void
button_detect (){
 	char key_hold;
 	int key_release;
 	P1=0;
 	do {
  		key_hold = putton1||putton2||putton3||putton4;
 	} while (!key_hold);
 	if(putton1)
  		mode=1;
 	if(putton2)
  		mode=2; 
 	if(putton3)
  		mode=3;
 	if(putton4)
  		mode=4; 
 	//Stage 2: wait for key released
 	key_release = 0;
 	count = N;
 	while (!key_release) {
  		key_hold = P1;
  		if (key_hold) {
   			count = N;
  		}
  		else {
   			count--;
   		if (count==0) key_release = 1;
  		}
 	} //Stage 2: wait for key released
} //end of function button_detect ()

int
led (){
 	int value;
 	if(mode==1){
 		status = status>>1;
 		if (status==0) status=0x80;
 		P2 = status;
 	}
 	if(mode==2){
 		status = status<<1;
 		if (status>0x80) status=0x01;
 		P2 = status;
 	}
 	if(mode==3){
 		status = status>>1;
 		status = status>>1;
		if (status<0||status==0) status=0x80;
 		if (status>0x80) status=0x01;
 		P2 = status;
 	}
 	if(mode==4){
 		status = status<<1;
 		status = status<<1;
 		if (status>0x80) status=0x01;
 		P2 = status;
 	}
 	value=1;
 	return value;
}

int
main (){
 	int status;
 
 	Default_Config ();

 	status = 1;
 	P2 = status;

 	while (1) {
  		button_detect ();
  		temp=led();
  		//P2 = status;
 } //end while (1)
} //end of function main

/*
void Timer0_ISR () interrupt 1
{
 	count++;

 	if (count==4) {
  	count = 0;
  	status = status>>1;
  	if (status==0) status=0x80;
 	}
 	P2 = status;
 	TH0 = 0;
 	TL0 = 0;
}
*/
//end of function Timer0_ISR