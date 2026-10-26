#include "C8051F040.h"
void Timer0_ISR ();
int count=0;
int N=50;
unsigned status=0;
int mode=0;
int temp=0;
sbit p=P1^7;
void
Timer_Configuration (){
 	TMOD = 0x01;
 	TCON = 0x10;
 	CKCON = 0x10;

 	IE = 0x82;
 	TL0 = 0;
 	TH0 = 0;
}//end of function Timer_Configuration

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
 
 	do {
  		key_hold = p;
 	} while (!key_hold);
 
 	if(p==1){
 		mode++;
 		if(mode==5) mode=1;
 	}

 	//Stage 2: wait for key released
 	key_release = 0;
 	count = N;
 	while (!key_release) {
  		key_hold = p;
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
led1 (){
 	status = status>>1;
 	if (status==0) status=0x80;

 	return status;
}

int
led2 (){
  	status = status<<1;
   	if (status>0x80) status=0x01;

 	return status;
}

int
led3 (){
  	status = status>>1;
  	status = status>>1;
  	if (status<0||status==0) status=0x80;
 	return status;
}

int
led4 (){
  	status = status<<1;
  	status = status<<1;
 	if (status>0x80) status=0x01;
 	return status;
}

void Timer0_ISR () interrupt 1{
 	count++;

 	if (count==4) {
  	count = 0;
 	/* status = status>>1;
  if (status==0) status=0x80;*/
  if(mode==0)
   status=status;
  if(mode==1)  
   status=led1();
  if(mode==2)
   status=led2();
  if(mode==3)
   status=led3();
  if(mode==4)
   status=led4();

  
 }
 P2 = status;
 TH0 = 0;
 TL0 = 0;
}

//end of function Timer0_ISR

int
main ()
{
 
 mode=0;
 Default_Config ();

 status = 0x80;
 P2 = status;
 
 while (1) {
  button_detect ();
  
 }//end while (1)
}//end of function main