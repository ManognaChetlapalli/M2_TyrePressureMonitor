#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define enable            5
#define registerselection 6

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);

unsigned volatile FLAG=0;

void initADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(1<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0XF8;
    ch=ch&0b00000111;
    ADCSRA|=(1<<ADSC);

    while (!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

int main(void)
{
    DDRB = 0xFF;
    DDRC|=(1<<PC1);
    DDRD|=(1<<PD5);
    DDRD|=(1<<PD6);

    int16_t COUNTA;
    char SHOWA[4];
    

    EICRA|=(1<<ISC00);
    EIMSK|=(1<<INT0);
    sei();
    
    initADC();

    send_a_command(0x01); //Clear Screen 0x01 = 00000001
    _delay_ms(50);
    send_a_command(0x38);
    _delay_ms(50);
    send_a_command(0b00001111);
    _delay_ms(50);
    

    while (1)
    {
        COUNTA = ReadADC(0);
        
        send_a_string ("Tyre pressure");
        send_a_command(0x80 + 0x40 + 0);
        send_a_string ("ADCvalue");
        send_a_command(0x80 + 0x40 + 8);
        itoa(COUNTA,SHOWA,10);
        send_a_string(SHOWA);
        
        send_a_command(0x80 + 0);
        
        if (FLAG==1)
        {
            PORTC|=(1<<PC1);
             _delay_ms(5000);
             FLAG=0;     
             
        }
        else
        {
        PORTC&=~(1<<PC1);
        _delay_ms(200);
        }
         
    }
    return 0;
}

ISR(INT0_vect)
{
    FLAG=1;
}

void send_a_command(unsigned char command)
{
    PORTB = command;
    PORTD &= ~ (1<<registerselection);
    PORTD |= 1<<enable;
    _delay_ms(20);
    PORTD &= ~1<<enable;
    PORTB = 0;
}

void send_a_character(unsigned char character)
{
    PORTB = character;
    PORTD |= 1<<registerselection;
    PORTD |= 1<<enable;
    _delay_ms(20);
    PORTD &= ~1<<enable;
    PORTB = 0;
}
void send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {
        send_a_character(*string_of_characters++);
    }
}