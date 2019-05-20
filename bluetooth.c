/*



 * bluetooth.c
 *
 * Created: 16-May-19 11:25:34 AM
 * Author : admini
 */ 
#define F_CPU 16000000UL


#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED PORTB
char buffer[10];

void USARInit(uint16_t ubrr_value)
{
	//set baud rate
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>8);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//enable the receiver and transmitter
	UCSRB = (1<<RXEN)|(1<<TXEN);
}
char USARReadChar()
{
	while(!(UCSRA&(1<<RXC)))
	{
		//do nothing
	}
	return UDR;
}
void USARWriteChar(char data)
{
	while(!(UCSRA&(1<<UDRE)))
	{
		//do nothing
	}
UDR = data;
}
int main(void)
{
	USARInit(77);
	DDRB = 0Xff;//PORTB as output
	char data;
	LED = 0;
      while (1) 
    {
		data = USARReadChar();
		if(data == '1')
		{
			LED |= 0xff; /*turn on led*/
			//USART_SendString("LED_ON");/*send status ofLED i.e.LED ON*/
    }
	else if(data == '2')
	{
		LED = 0x00;  /*turn off led*/
		//usart_send_string("led_off");/*send status of led i.e.led off*/
	}
	//else
	//usart_send_string("select proper option");/*send message proper_*/
}
return 0;
}

