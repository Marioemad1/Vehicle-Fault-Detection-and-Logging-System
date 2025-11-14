/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/21/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0    	        	*************************************************
**************************************************    SWC      :   UART     	     	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/

//the libs we need 
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "UART_interface.h"

void UART_init(void)
{
	UCSRC =0x86;//0b10000110
/*  1 -> to use ucsrc register
	0 -> Asynchronous Operation
	00->  Parity Mode Disabled
	0 -> (Stop Bit) 1-bit
	11->  Character Size  8-bit
	0 ->  polarity in synchronous 
	*/
	
	CLR_BIT(UCSRB,2); //the continue selection the data bit number
	
	UBRRL=103;//BUD rate 9600
	
	SET_BIT(UCSRB,3);//TX ENABLE
	SET_BIT(UCSRB,4);//RX ENABLE
}

void UART_Txchar(u8 data_to_send)
{
	while(READ_BIT(UCSRA,5)== 0);
	UDR = data_to_send;
}

void UART_Rxchar(u8* data_in)
{
	while(READ_BIT(UCSRA,7)== 0);
	
	*data_in = UDR;
}

void UART_Txword(u8* data_to_send)
{
	u8 iterations=0;
	while (iterations<3)
	{
		UART_Txchar(data_to_send[iterations]);
		iterations++;
	}
}
void UART_Rxword(u8* data_in)
{
		u8 iterations=0;
		while (iterations<3)
		{
			UART_Rxchar(&data_in[iterations]);
			iterations++;
		}
}