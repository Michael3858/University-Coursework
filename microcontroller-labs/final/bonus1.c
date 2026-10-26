#include "C8051F040.h"
#include "glcd.h"
#include <stdlib.h>

char P2_CWORD_TEMPLATE = 0x22;

int length = 3;
int snakeX[6] = {4, 3, 2, -1, -1, -1};
int snakeY[6] = {0, 0, 0, 0, 0, 0};
int score = 7;
int foodX;
int foodY;
int state = 0;

void set_GLCD_WriteMode()
{
	P4MDOUT = 0xff;
} // end of function set_GLCD_WriteMode

void set_GLCD_ReadMode()
{
	P4MDOUT = 0x00;
	P4 = 0xff;
} // end of function set_GLCD_ReadMode

void system_init_config()
{
	// turn-off the watch-dog timer
	WDTCN = 0xde;
	WDTCN = 0xad;

	// initialize SFR setup page
	SFRPAGE = CONFIG_PAGE; // Switch to configuration page

	// setup the cross-bar and configure the I/O ports
	XBR2 = 0xc0;
	P1MDIN = 0xff;
	P2MDOUT = 0xff;
	P3MDOUT = 0xff;
} // end of function system_init_config

void GLCD_delay()
{
	int i;
	for (i = 0; i < 10; i++)
		;
} // end of function GLCD_delay

void GLCD_Write(char P2_cword, char P4_cword)
{
	char P2_cword_rep;

	P2_cword_rep = P2_cword;
	set_GLCD_WriteMode();
	GLCD_delay();

	P2_cword_rep = P2_cword_rep & (~P2_E); // clear E bit
	P2 = P2_cword_rep;
	P4 = P4_cword;
	GLCD_delay();

	P2_cword_rep = P2_cword_rep | P2_E; // set E bit
	P2 = P2_cword_rep;
	GLCD_delay();

	P2_cword_rep = P2_cword_rep & (~P2_E); // clear E bit
	P2 = P2_cword_rep;
	GLCD_delay();
	P0 = P2_cword_rep; // nien debug

} // end of function GLCD_Write

char GLCD_Read(char P2_cword)
{
	char status;
	char P2_cword_rep;

	P2_cword_rep = P2_cword;
	set_GLCD_ReadMode();
	GLCD_delay();

	P2_cword_rep = P2_cword_rep & (~P2_E); // clear E bit
	P2 = P2_cword_rep;
	GLCD_delay();

	P2_cword_rep = P2_cword_rep | P2_E; // set E bit
	P2 = P2_cword_rep;
	GLCD_delay();

	status = P4;

	P2_cword_rep = P2_cword_rep & (~P2_E); // clear E bit
	P2 = P2_cword_rep;
	GLCD_delay();

	return status;
} // end of function GLCD_Read

char GLCD_ReadStatus()
{
	char P2_cword;
	char status;

	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword & (~P2_RS);
	P2_cword = P2_cword | (P2_RW);
	status = GLCD_Read(P2_cword);

	return status;
} // end of function GLCD_ReadStatus

char GLCD_ReadData()
{
	char P2_cword;
	char dat;

	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword | (P2_RS);
	P2_cword = P2_cword | (P2_RW);
	dat = GLCD_Read(P2_cword);

	return dat;
} // end of function GLCD_ReadData

int GLCD_IsBusy()
{
	char status;

	status = GLCD_ReadStatus();
	if (status & P4_Busy)
		return 1;
	else
		return 0;
} // end of function GLCD_IsBusy

int GLCD_IsReset()
{
	char status;

	status = GLCD_ReadStatus();
	if (status & P4_Reset)
		return 1;
	else
		return 0;
} // end of function GLCD_IsReset

int GLCD_IsON()
{
	return !GLCD_IsOFF();
} // end of function GLCD_IsON

int GLCD_IsOFF()
{
	char status;

	status = GLCD_ReadStatus();
	if (status & P4_Status_On)
		return 1;
	else
		return 0;
} // end of function GLCD_IsOFF

void Set_Xaddr(char x)
{
	char P2_cword, P4_cword;

	/// prepare control words
	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword & (~P2_RS); // clear RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = P4_Set_Xaddr_TMPL;
	P4_cword = P4_cword | (x & 0x07);

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Set_Xaddr

void Set_Yaddr(char y)
{
	char P2_cword, P4_cword;

	/// prepare control words
	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword & (~P2_RS); // clear RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = P4_Set_Yaddr_TMPL;
	P4_cword = P4_cword | (y & 0x3f);

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Set_Yaddr

void Set_DisplayStartLine(char z)
{
	char P2_cword, P4_cword;

	/// prepare control words
	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword & (~P2_RS); // clear RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = P4_Set_Zaddr_TMPL;
	P4_cword = P4_cword | (z & 0x3f);

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Set_DisplayStartLine

void Send_Data(char pattern)
{
	char P2_cword, P4_cword;

	/// prepare control words
	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword | (P2_RS);	// set RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = pattern;

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Send_Data

void Set_DisplayOn(int half)
{
	char P2_cword, P4_cword;
	P2_cword = P2_CWORD_TEMPLATE;
	if (half == 0) // 10:left
	{
		P2_CWORD_TEMPLATE = 0x22;
		P2_cword = P2_CWORD_TEMPLATE;
		P2_cword = P2_cword & ~(0x01);
		P2_cword = P2_cword | 0x02;
	}
	else // 01:right
	{
		P2_CWORD_TEMPLATE = 0x21;
		P2_cword = P2_CWORD_TEMPLATE;
		P2_cword = P2_cword | 0x01;
		P2_cword = P2_cword & ~(0x02);
	}
	// prepare control words
	P2_cword = P2_cword & (~P2_RS); // set RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = P4_Set_Display_TMPL;
	P4_cword = P4_cword | P4_Display_On; // set display ON bit

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Set_DisplayOn

void Set_DisplayOff()
{
	char P2_cword, P4_cword;

	/// prepare control words
	P2_cword = P2_CWORD_TEMPLATE;
	P2_cword = P2_cword & (~P2_RS); // set RS bit
	P2_cword = P2_cword & (~P2_RW); // clear RW bit
	P4_cword = P4_Set_Display_TMPL;
	P4_cword = P4_cword & (~P4_Display_On); // clear display ON bit

	/// flush out control signals
	while (GLCD_IsBusy())
		;
	GLCD_Write(P2_cword, P4_cword);
} // end of function Set_DisplayOff

void GLCD_Reset()
{
	char P2_cword, P4_cword;

	set_GLCD_WriteMode();

	P2_cword = P2_CWORD_TEMPLATE;
	P4_cword = 0;

	P2_cword = P2_cword | P2_RST; // set reset bit
	GLCD_Write(P2_cword, P4_cword);

	P2_cword = P2_cword & (~P2_RST); // clear reset bit
	GLCD_Write(P2_cword, P4_cword);

	P2_cword = P2_cword | P2_RST; // set reset bit
	GLCD_Write(P2_cword, P4_cword);

	while (GLCD_IsReset())
		;
} // end of function GLCD_Reset

void resetSnake()
{
	int i;
	length = 3;
	score = 0;
	for (i = 0; i < length; i++)
	{
		snakeX[i] = length - i;
		snakeY[i] = 0;
	}
	state = 0;
	P3 = score;
}

void detectFood()
{
	// snake eat food
	if (snakeX[0] == foodX && snakeY[0] == foodY)
	{
		score++;
		// length++;
		foodX = rand() % 8;
		foodY = rand() % 16;
		foodY *= 8;
		P3 = score;
	}
}

void button_detect()
{
	int b_state;
	b_state = P1;
	if (b_state == 1)
		state = 0;
	else if (b_state == 2) // print Bye
		state = 1;
	else if (b_state == 8) // up
		state = 3;
	else if (b_state == 16) // down
		state = 4;
	else if (b_state == 32) // move left
		state = 5;
	else if (b_state == 64) // move right
		state = 6;
	else if (b_state == 128) // wait button && start game
		state = 7;

	if (state >= 3 && state < 7)
	{
		int x, y;
		int i;

		// snake head
		x = snakeX[0];
		y = snakeY[0];

		// move snake body
		for (i = length - 1; i >= 1; i--)
		{
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}

		// move snake head
		if (state == 3) // up
		{
			snakeX[0] = x - 1;
			snakeY[0] = y;
			detectFood();
		}
		else if (state == 4) // down
		{
			snakeX[0] = x + 1;
			snakeY[0] = y;
			detectFood();
		}
		else if (state == 5) // left
		{
			snakeX[0] = x;
			snakeY[0] = y - 8;
			detectFood();
		}
		else if (state == 6) // right
		{
			snakeX[0] = x;
			snakeY[0] = y + 8;
			detectFood();
		}
		state = 7;
	}

	// touch the wall
	if (snakeX[0] < 0 || snakeX[0] > 7)
	{
		state = 2;
	}
	if (snakeY[0] < 0 || snakeY[0] > 127)
	{
		state = 2;
	}
}

void reset()
{
	int i, j;
	Set_DisplayOn(0);
	Set_Yaddr(0);
	for (i = 0; i < 8; i++)
	{
		Set_Xaddr(i);
		for (j = 0; j < 64; j++)
			Send_Data(0x00);
	}

	Set_DisplayOn(1);
	Set_Yaddr(0);
	for (i = 0; i < 8; i++)
	{
		Set_Xaddr(i);
		for (j = 0; j < 64; j++)
			Send_Data(0x00);
	}
}

void print(int *posx, int *posy)
{
	int i, j;

	// clean screen
	reset();

	// start print snake
	for (i = 0; i < length; i++)
	{
		// check snake part is on the left side
		if (posy[i] >= 0 && posy[i] < 64)
		{
			Set_DisplayOn(0);
			// left side doesn't need to compute y-address
			Set_Yaddr(posy[i]);
			Set_Xaddr(posx[i]);
			// print part of snake
			for (j = 0; j < 8; j++)
				Send_Data(0xff);
		}
		// check snake part is on the right side
		else if (posy[i] >= 64 && posy[i] < 128)
		{
			Set_DisplayOn(1);
			// right side need to compute the y-address.
			// see the note in my ipad
			Set_Yaddr(((posy[i] / 8) - 8) * 8);
			Set_Xaddr(posx[i]);
			// print part of snake
			for (j = 0; j < 8; j++)
				Send_Data(0xff);
		}
	}

	// start print food
	if (foodY >= 0 && foodY < 64)
	{
		Set_DisplayOn(0);
		// left side doesn't need to compute y-address
		Set_Yaddr(foodY);
		Set_Xaddr(foodX);
		// print part of snake
		Send_Data(0x08);
		Send_Data(0x14);
		Send_Data(0x32);
		Send_Data(0x51);
		Send_Data(0x51);
		Send_Data(0x32);
		Send_Data(0x14);
		Send_Data(0x08);
	}
	else if (foodY >= 64 && foodY < 128)
	{
		Set_DisplayOn(1);
		// right side need to compute the y-address.
		// see the note in my ipad
		Set_Yaddr(((foodY / 8) - 8) * 8);
		Set_Xaddr(foodX);
		// print part of snake
		Send_Data(0x08);
		Send_Data(0x14);
		Send_Data(0x32);
		Send_Data(0x51);
		Send_Data(0x51);
		Send_Data(0x32);
		Send_Data(0x14);
		Send_Data(0x08);
	}
}

void printGameOver()
{
	reset();
	// left
	Set_DisplayOn(0);
	Set_Yaddr(48);
	Set_Xaddr(3);
	// G
	Send_Data(0x00);
	Send_Data(0x3c);
	Send_Data(0x42);
	Send_Data(0x81);
	Send_Data(0x91);
	Send_Data(0x91);
	Send_Data(0x72);
	Send_Data(0x00);
	// A
	Send_Data(0x00);
	Send_Data(0xfc);
	Send_Data(0x12);
	Send_Data(0x11);
	Send_Data(0x11);
	Send_Data(0x12);
	Send_Data(0xfc);
	Send_Data(0x00);

	Set_Yaddr(48);
	Set_Xaddr(4);
	// O
	Send_Data(0x3c);
	Send_Data(0x42);
	Send_Data(0x81);
	Send_Data(0x81);
	Send_Data(0x81);
	Send_Data(0x81);
	Send_Data(0x42);
	Send_Data(0x3c);
	// V
	Send_Data(0x0f);
	Send_Data(0x38);
	Send_Data(0x60);
	Send_Data(0xc0);
	Send_Data(0xc0);
	Send_Data(0x60);
	Send_Data(0x38);
	Send_Data(0x0f);

	// right
	Set_DisplayOn(1);
	Set_Yaddr(0);
	Set_Xaddr(3);
	// M
	Send_Data(0xfe);
	Send_Data(0x01);
	Send_Data(0x02);
	Send_Data(0x04);
	Send_Data(0x04);
	Send_Data(0x02);
	Send_Data(0x01);
	Send_Data(0xfe);
	// E
	Send_Data(0x00);
	Send_Data(0xff);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xc3);
	Send_Data(0x00);

	Set_Yaddr(0);
	Set_Xaddr(4);
	// E
	Send_Data(0x00);
	Send_Data(0xff);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xdb);
	Send_Data(0xc3);
	Send_Data(0x00);
	// R
	Send_Data(0xff);
	Send_Data(0x19);
	Send_Data(0x19);
	Send_Data(0x19);
	Send_Data(0x19);
	Send_Data(0x29);
	Send_Data(0x49);
	Send_Data(0x86);
}

main()
{
	system_init_config();

	GLCD_Reset();

	reset();

	foodX = rand() % 8;
	foodY = rand() % 16;
	foodY *= 8;

	P3 = score;

	while (1)
	{
		button_detect();
		if (state == 2)
			printGameOver();
		else
			print(snakeX, snakeY);
	}
} // end of function main
