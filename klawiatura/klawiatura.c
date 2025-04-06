//klawiatura
#include <REGX52.H>
volatile unsigned char i,j, stan=0, index=0,button_handled[12]={0}, poprawny=0;
unsigned char poprawna[] = {9, 8, 7, 6};
void Init()
{
	P3_4=1;
	SCON=0x50;
	T2CON=0x30;
	TH2 = 0xFE;         
  TL2 = 0x07;         
  RCAP2H = 0xFC;      
  RCAP2L = 0x00;     
	TR2=1;
	ES=1;
	EA=1;
	
}

void wait()
{
	for(i=0;i<100;i++)
	{
		for(j=0;j<150;j++){;}
	}
}


void send(unsigned char value)
{
	TI=0;
	SBUF=value;
	while(TI==0 ){;}
	TI=0;

		
}

void spr(unsigned char key)
{
  if (key == poprawna[index])
  {
    index++; 
    if (index == 4)
    {
			poprawny=1;
      // Jesli wprowadzono cala sekwencje
      stan = 1;
			P0_0=0;
			send(1);
      index = 0; 
			
    }
  }
  else if(key!=poprawna[index] && poprawny==0)
  {
    // Jesli sekwencja zostala przerwana
    index = 0;
		P0_0=0;
		wait();
		P0_0=1;
		wait();
		P0_0=0;
		wait();
		P0_0=1;
  }
}

void main(void)
{
	Init();
	P2_4=1;
	P2_5=1;
	P2_6=1;
	P2_7=1;
	
	while(1)
	{
		
		P2_1=0;
		P2_2=1;
		P2_3=1;
		
		//PRZYCISK 3
		if(P2_4==0 && button_handled[3] == 0)       
		{
			button_handled[3]=1;
			if(stan==0)
			{
				spr(3);
				
			}
		}
		if (P2_4 == 1 )
		{
			button_handled[3] = 0;
		}
		
		//PRZYCISK 6
		if(P2_5==0 && button_handled[6] == 0)							
		{
			button_handled[6] =1;
			if(stan==0)
			{
				spr(6);
			
			}
		}
		if (P2_5 == 1)
		{
				button_handled[6] = 0;
		}
		
		//PRZYCISK 9
		if(P2_6==0 && button_handled[9] == 0)				
		{
			button_handled[9] =1;
			if(stan==0)
			{
				spr(9);
	
			}
		}
		if (P2_6 == 1)
		{
				button_handled[9] = 0;
		}	
		
		//PRZYCISK #
		if(P2_7==0 && button_handled[11] == 0)
		{
			button_handled[11] =1;
			if(stan==0)
			{
				spr(11);
			}
			
		}
		if (P2_7 == 1)
		{
				button_handled[11] = 0;
		}
		P2_1=1;
		P2_2=0;
		P2_3=1;
		
		//PRZYCISK 2
		if(P2_4==0 && button_handled[2] == 0)
		{
			button_handled[2] =1;
			if(stan==0)
			{
				spr(2);
	
			}
		}
		if (P2_4 == 1)
		{
				button_handled[2] = 0;
		}
		
		//PRZYCISK 5
		if(P2_5==0 && button_handled[5] == 0)							
		{
			button_handled[5] =1;
			if(stan==0)
			{
				spr(5);
			}
			
		}
		if (P2_5 == 1)
		{
				button_handled[5] = 0;
		}
		
		//PRZYCISK 8
		if(P2_6==0 && button_handled[8] == 0)                 
		{
			button_handled[8] =1;
			if(stan==0)
			{
				spr(8);
	
			}
		}
		if (P2_6 == 1)
		{
				button_handled[8] = 0;
		}
		
		//PRZYCISK 0
		if(P2_7==0 && button_handled[0] == 0)
		{
			button_handled[0] =1;
			if(stan==0)
			{
				spr(0);
	
			}
		}
		if (P2_7 == 1)
		{
				button_handled[0] = 0;
		}
		P2_1=1;
		P2_2=1;
		P2_3=0;
	
	
		//PRZYCISK 1
		if(P2_4==0 && button_handled[1] == 0)       
		{
			button_handled[1] =1;
			if(stan==0)
			{
				spr(1);
			}
		}
		if (P2_4 == 1)
		{
				button_handled[1] = 0;
		}
		
		//PRZYCISK 7
		if(P2_6==0 && button_handled[7] == 0)               
		{
			button_handled[7] =1;
			if(stan==0)
			{
				spr(7);
			}
		}
		if (P2_6 == 1)
		{
				button_handled[7] = 0;
		}
		
		//PRZYCISK 4
		if(P2_5==0 && button_handled[4] == 0)          
		{
			button_handled[4] =1;
			if(stan==0)
			{
				spr(4);
			}
		}
		if (P2_5 == 1)
		{
				button_handled[4] = 0;
		}
		
		//PRZYCISK  *
		if(P2_7==0 && button_handled[10] == 0)          
		{
			button_handled[10] =1;
			if(stan==0)
			{
				spr(11);
			}else if(stan==1)
			{
				send(50);
			}
		}
		if (P2_7 == 1)
		{
				button_handled[10] = 0;
		}
		
	}
		
	}