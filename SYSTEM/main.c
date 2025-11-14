/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   11/9/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  system_test	        *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "GI_interface.h"
#include "TMR_interface.h"
#include "ADC_interface.h"
/*HAL*/
#include "UTS_interface.h"
#include "TEMP_interface.h"
	
void CONV_to_string(u16 num,u8* arr);


int main(void)
{
	/*ULTRASONIC PIN INPUT*/
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	/*LM35 PIN INPUT*/
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);
	
	/*WIN1 BUTTON*/
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT);
	/*WIN2 BUTTON*/
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_INPUT);
	
	/*MOTORS DIRECTIONS PINS*/
	/*MOTOR1*/
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	/*MOTOR2*/
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	
	

	ADC_init();
	UART_init();
	

    /* Replace with your application code */
    while (1) 
    {
		u16 period=0;
		u16 period1=0;
		u8 command;
		u8 readings_arr[2]="10";
		u8 Window_readings=0;
		UART_Rxchar(&command);
		switch (command)
		{
			case 1://FIRE SYSTEM
				UTS_init();
				TEMP_init();
				break;
			case 2://ASKING FOR TEMP READINGS 
				TEMP_getvalue(&period,ADC_CHANNEL1);
				CONV_to_string(period,readings_arr);
				UART_Txword(readings_arr);
				break;
			case 3://ASKING FOR DISTANCE READINGS
				UTS_getdistance(&period1,ADC_CHANNEL0);
				CONV_to_string(period1,readings_arr);
				UART_Txword(readings_arr);
				break;
			case 4://SEE THE BUTTON OF THE WINDOW1
				DIO_GetPin(DIO_PORTB,DIO_PIN0,&Window_readings);
				UART_Txchar(Window_readings);
				break;
			case 5://SEE THE BUTTON OF THE WINDOW2
				DIO_GetPin(DIO_PORTB,DIO_PIN1,&Window_readings);
				UART_Txchar(Window_readings);
				break;
			case 6:
				if (50<period1)
				{
					UART_Txchar(1);
				}
				else
				{
					UART_Txchar(0);
				}
				
				break;
			case 7:
			if (10>period)
			{
				UART_Txchar(1);
			}
			else
			{
				UART_Txchar(0);
			}
				break;
		}
		
		
		
	}
}

void CONV_to_string(u16 num,u8* arr)
{
	arr[0]=(num/10)+'0';
	arr[1]=(num%10)+'0';
}