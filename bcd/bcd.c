//bcd
#include <REGX52.H>

unsigned char xdata Ones _at_ 0xFD00;
unsigned char xdata Tens _at_ 0xFE00;
unsigned char i=0,j=0,stan=0,counter=0;
const char odlicz[] = {0x3F,0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //0,1,2,3,4,5,6,7,8,9

void Init()
{
	P3_4=0;
	SCON=0x50;
	T2CON=0x30;
	TH2 = 0xFC;         
  TL2 = 0x00;         
  RCAP2H = 0xFC;     
  RCAP2L = 0x00; 
	TI=0;
	RI=0;
	TR2=1;
	EX0=1;
	IT0=1;
	ES=1;
	
	EA = 1; 
}


void ISR_Serial(void) interrupt 4
{
	if(TI == 1) {TI = 0;}
	if(RI==1)
	{
	
			if(SBUF==1)
			{
				stan=1;
				TMOD |= 0x01;   
				TH0 = 0xFC;     
				TL0 = 0x18;
				ET0 = 1;       
				TR0 = 1;
			}
			else if(SBUF==50)
			{
				stan=2;
				
			}
			
	}
	RI=0;
}

void ISR_Timer0(void) interrupt 1
{
	TH0 = 0xFC; 
	TL0 = 0x18;

	
	counter++;

	if(counter >= 90) 
	{
		counter = 0;
		j++; 
		if(j > 9) 
		{
			j = 0;
			i++; 
		}
		if(i == 4 && j == 0) 
		{
			i = 0;
			j = 0;
		}
	}
}


void ISR_INT0() interrupt 0
{
	if(stan==1)
	{
		i=0;
		j=0;
	}

}

void main()
{
	Init();
	
	while(1){
		if(stan==1){
				Tens = odlicz[i]; 
				Ones = odlicz[j];
		}
	}
	
}