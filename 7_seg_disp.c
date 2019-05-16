#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRA=0xFF;
	
	
     while (1) 
    {
		int i,j;
		int num[10]={0XFC,0X60,0XDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF7};
			PORTA = 0X00;
			for(i=0;i<10;i++)
			{
				PORTA=num[i];
				_delay_ms(100);
			}
       int alpha[10] = {0xEE,0X3E,0X9C,0X7A,0X8E,0X8E,0XF6,0X2E,0X60,0X78};
		   PORTA = 0X00;
		   
		   for(j=0;j<10;j++)
		   {
			   PORTA=alpha[j];
			   _delay_ms(1000);
			   
		   
	
	}
	
	
}

	}