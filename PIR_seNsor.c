/*
 * GccApplication4.c
 *
 * Created: 13-05-2019 10:43:59
 * Author : anand_000
 */ 
#ifdef F_CPU
#define F_CPU16000000UL
#endif
#include <avr/io.h>

#define LED_OUTPUT PORTB
#define PIR_input PINC


int main(void)
{
  DDRC = 0X00; /*PIR PORT AS IP*/
  DDRB = 0XFF;/*LED PORT AS OP*/
  
    while (1) 
    {
    LED_OUTPUT = PIR_input;//WHEN SENSOR DETECTS LED WIL BE HIGH
	
	}
	
}

