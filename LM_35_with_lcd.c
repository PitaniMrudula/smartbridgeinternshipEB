
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define enable 5
#define registerselection  7

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char* string_of_character);


int main(void)
{
	DDRC = 0XFF;
	DDRA = 0X00;
	DDRD = 0XFF;
	_delay_ms(50);
	
	ADMUX|= (1<<REFS0)|(1<<REFS1); //VOLTAGE SELECTION
	ADCSRA|= (1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);

	int16_t COUNTA = 0;
	char SHOWA[3];
	
	send_a_command(0x01);
	_delay_ms(50);
	
	send_a_command(0x38);
	_delay_ms(50);
	
	send_a_command(0b00001111);
	_delay_ms(50);
	
	
	ADCSRA|= (1<<ADSC); //ADC CONV START

    while (1) 
    {
	COUNTA = ADC/4;
	
	send_a_string("smartbridge");
	send_a_command(0x80+0x40+0);//shifting cursor to the first shell of 2nd line
    send_a_string("Temp(c) = ")	;
	send_a_command(0x80+0x40+8);// shifting cursor to the 9th shell if 2nd line
	
	// command for putting variable in LCD
	// VARIABLE no in character to replace which are in variable (ten here as we r counting in base(10)
	itoa(COUNTA,SHOWA,10);
	
	send_a_string(SHOWA);
	send_a_string("");
	send_a_command(0X80+0); //RETURN TO THE FIRST LINE OF THE SHELL
	
	}
}


void send_a_command(unsigned char command)
{
	PORTC = command;
	PORTD&= ~(1<<registerselection);
	PORTD|= (1<<enable);
	_delay_ms(20);
	
	PORTD&= ~(1<<enable);
	PORTC = 0;
}

void send_a_character(unsigned char character)
{
	PORTC = character;
	PORTD|= 1<<registerselection;
	PORTD|= 1<<enable;
	_delay_ms(20);
	
	PORTD&= ~(1<<enable);
	PORTC = 0;
}
 	void send_a_string(char* string_of_characters)
	 {
		 while(*string_of_characters>0)
		 {
			 send_a_character(*string_of_characters++);
	 } 
		 }
	

 
 
 	
	 
	


