#include "C8051F040.h"
#include "LCD.h"

char LCD_status;

void
LCD_PortConfig ()
{
	//initialize SFR setup page
	SFRPAGE = CONFIG_PAGE;                 // Switch to configuration page

	//setup the cross-bar and configure the I/O ports
	XBR2 = 0xc0;
	P3MDOUT = 0x3f;

	//set to normal mode
	SFRPAGE = LEGACY_PAGE;
}//end of function LCD_PortConfig ()

/****************
The delay_lcd seem to be not long enough. 
Try to change the default value as 10000...
****************/
unsigned int delay_lcd=10000;

void
LCD_Delay ()
{
	int i;
	for (i=0;i<delay_lcd;i++); // wait for a long enough time...
}

void
LCD_SendCommand (char cmd);

void
LCD_Init ()
{
	LCD_SendCommand(0x02);        // Initialize as 4-bit mode
	LCD_SendCommand (0x28);		//Display function: 2 rows for 4-bit data, small 
	LCD_SendCommand (0x0e);		//display and curson ON, curson blink off
	LCD_SendCommand (0x01);		//clear display, cursor to home
	//LCD_SendCommand (0x10);		//cursor shift left
	//LCD_SendCommand (0x06);		//cursor increment, shift off
}

void
LCD_Status_SetRS ()
{
	LCD_status = LCD_status | 1;
}

void
LCD_Status_ClearRS ()
{
	LCD_status = LCD_status & 0xfe;
}

void
LCD_Status_SetWord (char word)
{
	word = word & 0x0f;
	LCD_status = LCD_status & 0x03;
	LCD_status = LCD_status | (word<<2);
}

void
LCD_Status_SetEnable ()
{
	LCD_status = LCD_status | 0x02;
}


void
LCD_Status_ClearEnable ()
{
	LCD_status = LCD_status & 0xfd;
}


void
LCD_SendCommand (char cmd)
{
	LCD_Status_ClearRS ();

	///send the higher half
	LCD_Status_SetWord ((cmd>>4) & 0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();

	///send the lower half
	LCD_Status_SetWord (cmd&0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();
}

void
LCD_SendData (char dat)
{
	LCD_Status_SetRS ();

	///send the higher half
	LCD_Status_SetWord ((dat>>4) & 0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();

	///send the lower half
	LCD_Status_SetWord (dat&0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();
}

void
LCD_PrintString (char* str)
{
	int i;

	for (i=0; str[i]!=0; i++) {
		LCD_SendData (str[i]);
	}//for i
}


void
LCD_ClearScreen ()
{
	LCD_SendCommand (0x01);
}


void
Shutup_WatchDog ()
{
	WDTCN = 0xde;
	WDTCN = 0xad;
}//end of function Shutup_WatchDog



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
int countsec=0;
int sec=0;
int sec1;
int sec2;
int music[33]={12,0,11,12,14,15,14,12,0,17,15,14,0,15,14,12,0,12,0,11,12,14,15,14,12,0,17,0,12,0,15,0,19};
int music_count=33;


int scale=0;
int
main ()
{
 	Config ();
 	status = 0x00;
 	count_for_scale = 0;
    count_for_time = 0;
 	//half_period = 12;
 	countsec=0;
	sec=0;


	
	Shutup_WatchDog ();
	LCD_PortConfig ();
	LCD_Init ();
	
	LCD_ClearScreen ();
	LCD_SendCommand (0x02);	
	//LCD_SendData ('A');
	//LCD_PrintString ("Hello World!!!");
	




 while (1) {
  P2 = status;
 }//end while (1)
}//end of function main


void printsec(int sec){

	LCD_ClearScreen ();
	LCD_SendCommand (0x02);
	sec1=sec/10;
	sec2=sec%10;
	
	if(sec1==1){
		LCD_SendData('1');
	}
	else if(sec1==2){
		LCD_SendData('2');
	}
	else if(sec1==3){
		LCD_SendData('3');
	}
	else if(sec1==4){
		LCD_SendData('4');
	}
	else if(sec1==5){
		LCD_SendData('5');
	}
	else if(sec1==6){
		LCD_SendData('6');
	}
	else if(sec1==7){
		LCD_SendData('7');
	}
	else if(sec1==8){
		LCD_SendData('8');
	}
	else if(sec1==9){
		LCD_SendData('9');
	}else{
		LCD_SendData('0');
	}


	if(sec2==1){
		LCD_SendData('1');
	}
	else if(sec2==2){
		LCD_SendData('2');
	}
	else if(sec2==3){
		LCD_SendData('3');
	}
	else if(sec2==4){
		LCD_SendData('4');
	}
	else if(sec2==5){
		LCD_SendData('5');
	}
	else if(sec2==6){
		LCD_SendData('6');
	}
	else if(sec2==7){
		LCD_SendData('7');
	}
	else if(sec2==8){
		LCD_SendData('8');
	}
	else if(sec2==9){
		LCD_SendData('9');
	}else{
		LCD_SendData('0');
	}
}




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
  if (count_for_time==120) {
    count_for_time = 0;
    n=music[scale];
    scale=(scale+1)%music_count;
  }
  countsec++;
  if (countsec==500) {
    countsec = 0;
	sec++;
    printsec(sec);
  }
  
 TL1 = 0;
 TH1 = 0;
 
}