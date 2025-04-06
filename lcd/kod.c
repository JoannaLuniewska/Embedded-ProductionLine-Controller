//lcd kod
#include <REGX52.H>
volatile unsigned char i,j,x;
volatile bit off=0;
extern void LcdInit();
extern void Lcd_DisplayString (char row, char column, char *string);
extern void Lcd_WriteControl (unsigned char LcdCommand);

unsigned char data Var1, Var2, Var3;
volatile unsigned char data stan=0;


void ISR_Serial(void) interrupt 4
{
	if(TI == 1) {TI = 0;}
	if(RI==1)
	{
			if(SBUF==1)
			{
					stan=1;
			}else if(SBUF==50 && stan==2) //gwiazdka-koniec
			{
				stan=3;
			}
	}
	RI=0;
}

void ISR_INT1() interrupt 2
{
	off=!off;
}

void Init(void)
  {
    P3_4 = 0;
		SCON=0x50;
		TH2 = 0xFE;         
		TL2 = 0x07;         
		RCAP2H = 0xFC;     
		RCAP2L = 0x00; 
		T2CON=0x30;
		TI=0;
		RI=0;
		EX1=1;
		IT1=1;
		ES=1;
		TR2=1;
    EA = 1;
	
  }
	

void main(void){
  LcdInit();	  
  Init();
	Lcd_DisplayString (2,2,"Predkosc       ");
	Lcd_DisplayString (3,2,"napedu:   134  ");
	Lcd_DisplayString (4,2,"obr/min        ");

	
  while(1) {
		if(stan==0)
		{
			Lcd_DisplayString (1,2,"PODAJ PIN!");
			
		}
		else if(stan==1)
		{
			Lcd_DisplayString (1,2,"STAN AKTYWNY   ");
			stan=2;

		}
		else if(stan==3)
		{
			Lcd_DisplayString (1,2,"ZAKONCZONO!  ");

		}
		else if(stan==2 && off)
		{
			Lcd_DisplayString (2,2,"               ");
			Lcd_DisplayString (3,2,"               ");
			Lcd_DisplayString (4,2,"               ");
			
		}
		else if(stan==2 && off==0)
		{
			Lcd_DisplayString (2,2,"Predkosc       ");
			Lcd_DisplayString (3,2,"napedu:   134  ");
			Lcd_DisplayString (4,2,"obr/min        ");

		}
		
		
	}
}