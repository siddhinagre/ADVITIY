/*
 * UARTproj.cpp
 *
 * Created: 3/18/2018 4:37:26 PM
 * Author : Siddhi Nagre
 */ 
#define F_CPU 14745600
 #define BAUD 9600
 #define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>

void uart_transmit(int data){
	while(!( UCSRA & (1<<UDRE))){
		
	}
UDR=data;
}

int uart_receieve (void)
{
	while(!UCSRA & (1<<RXC)){
		
	}
	

return UDR;
}


void USART_Init()
{
	UCSRA=0;
	UCSRB=0;
	UCSRC=0;
	UCSRA |= (1<<U2X);
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = 191;
	UBRRH = 0;
	
	
	
}

int main( void )
{
	 USART_Init();
	  DDRC=0b00000001;
	PORTC=0b00000000;
	 while(1)
	 {	int buffer;
	 buffer=uart_receieve();
	  _delay_ms(100);
	  //PORTC ^= (1<<PINC0);
	   uart_transmit(buffer) ;
     }
  
}
 
