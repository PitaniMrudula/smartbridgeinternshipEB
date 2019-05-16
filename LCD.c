#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#define RS 7
#define E 5

void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)
{
    DDRC = 0XFF;
	DDRD = 0XFF;
	_delay_ms(50);
    
	send_command(0x01);
	send_command(0x38);
	send_command(0x0E);
	
	send_character(0x41);
	send_character(0x42);
	send_character(0x43);
	send_character(0x44);

	void send_command(unsigned char command)
	{
		PORTC=command;
		PORTD&=~(1<<RS);
		PORTD|= (1<<E);
		_delay_ms(50);
		PORTD&=~(1<<E);
		PORTC=0;
	}
    
	void send_character(unsigned char character)
	{
		PORTC=character;
		PORTD|=~(1<<RS);
		PORTD|= (1<<E);
		_delay_ms(50);
		PORTD&=~(1<<E);
		PORTC=0;
	}
	
	}
	
	