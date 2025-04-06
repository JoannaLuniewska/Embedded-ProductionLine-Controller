//silnik
#include <REGX52.H>
#define MAX 255
#define MIN 0
#define MOTOR P2_4

volatile unsigned char data Suwak, Nastawa;

void Init(void)
{
	P2=0x00;
	P2_5=1;
	P2_6=0;
	P2_1=1;
	P2_2=1;
	Suwak=0x00;
	Nastawa= 0xCC; 
	TMOD=0x02;
	TCON=0x00;
	TH0=TL0=0xF0; 
	ET0=1;
	P3_4=0;
	TR0=1;
	EA=1;

}

//regulacja mocy poprzez zmienianie nastawy
void motor_isr (void) interrupt 1
{
	Suwak++;
	
	
	if(Nastawa==MIN)
	{
		MOTOR=0;
	}
	else
	{
		if(Nastawa==MAX){
			MOTOR=1;
		}
		else
		{
			if(Suwak<=Nastawa)
			{
				MOTOR=1;
			}
			else
			{
				MOTOR=0;
			}
		}
		
	}
	
	if(Suwak==MAX)
	{
		Suwak=MIN;
	}
	TH0=TL0=0xF0; 
}

void main(void)
{
Init();
	for(;;)
	{}

}