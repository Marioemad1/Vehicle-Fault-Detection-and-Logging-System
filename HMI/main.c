/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   10/10/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  VFDLS			        *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
//the libs we need
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "GI_interface.h"
#include "TMR_interface.h"
/*HAL*/
#include "KPD_Interface.h"
#include "LCD_Interface.h"
/*RTOS*/
#include "KERNEL_interface.h"
#include "TMR_RTOS_interface.h"
/*APIS*/
void HMI_KPD_SCAN_INPUT(void);
void Convert_to_string(u8* data,u8* ptr);
void CheckWindow(u8 num);
void FAULTcheck(u8 num);
void HEATcheck(u8 num);

int main(void)
{
	/*LCD DIRECTIONAL PINS */
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
	/*KPD PINS*/
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);

	UART_init();
	
	/*THE RTOS TASKS OF THIS BUTTONS*/
	RTOS_CreateTask(100,0,&HMI_KPD_SCAN_INPUT);
	
	RTOS_Start();
	
	while (1)
	{
	}
}

void HMI_KPD_SCAN_INPUT(void)
{
	static step=0;
	u8 charact ;
	KPD_SCAN(&charact);
	u8 temp[1]="00";
	u8 window_state;
	//,distance,state1,state2;
	if( 'N' == charact && step==0 )
	{
		/*THE MAIN SCREEN IN THE MENU*/
		step=1;
		LCD_init();
		LCD_sendword("Welcome to HMI");
		LCD_gotoposition(2,0);
		LCD_sendword("ECU interface");
		LCD_gotoposition(3,0);
		LCD_sendword("Press (0)");
		LCD_gotoposition(4,0);
		LCD_sendword("To continue");
	}
	else if ('0' == charact &&  1==step )
	{
		
		//THE OPTIONS WE HAVE
		step=2;
		LCD_clearscreen();
		LCD_sendword("1.StartOperation");
		LCD_gotoposition(2,0);
		LCD_sendword("2.DisplayValues");
		LCD_gotoposition(3,0);
		LCD_sendword("3.RetrieveFaults");
		LCD_gotoposition(4,0);
		LCD_sendword("4.StopMonitoring");
		
	}
	else if ('1' == charact && 2==step )
	{
		//FIRE UP THE SYSTEM
		//SEND 1 TO START THE OPERATIONS OF THE SYSTEM
		UART_Txchar(1);//1
		LCD_clearscreen();
		LCD_sendword("1.StartOperation");
		LCD_gotoposition(2,0);
		LCD_sendword("OperationStarted");
		LCD_gotoposition(3,0);
		LCD_sendword("WORKING...");
		
		_delay_ms(100);
		LCD_clearscreen();
		LCD_sendword("1.StartOperation");
		LCD_gotoposition(2,0);
		LCD_sendword("2.DisplayValues");
		LCD_gotoposition(3,0);
		LCD_sendword("3.RetrieveFaults");
		LCD_gotoposition(4,0);
		LCD_sendword("4.StopMonitoring");
		
	}
	else if ('2' == charact && 2==step )
	{
		
		//DISPLAY THE VALUES 
		LCD_clearscreen();
		//SEND TO ASK FOE THE TEMP VALUE
		UART_Txchar(2);//2
		LCD_sendword("1.Temp:");
		UART_Rxword(temp);
		LCD_sendword(temp);
		LCD_gotoposition(2,0);
		//ASK FOE THE DISTANCE VALUE
		UART_Txchar(3);//3
		LCD_sendword("2.Distance:");
		UART_Rxword(temp);
		LCD_sendword(temp);
		LCD_gotoposition(3,0);
		//THE WINDOW VALUE FROM THE PB
		UART_Txchar(4);//4
		LCD_sendword("3.Win1:");
		UART_Rxchar(&window_state);
		CheckWindow(window_state);//check and print to LCD
		LCD_gotoposition(4,0);
		UART_Txchar(5);//5
		LCD_sendword("Win2:");
		UART_Rxchar(&window_state);
		CheckWindow(window_state);//check and print to LCD
	}
	else if ('3' == charact && 2==step )
	{
		LCD_clearscreen();
		LCD_sendword("Logged Faults:");
		LCD_gotoposition(2,0);
		//THE FAULT OF THE SYSTEM
		UART_Txchar(6);//6
		LCD_sendword("P001:");
		UART_Rxchar(&window_state);
		FAULTcheck(window_state);
		LCD_gotoposition(3,0);
		//HEAT FAULTS
		UART_Txchar(7);//7
		LCD_sendword("P002:");
		UART_Rxchar(&window_state);
		HEATcheck(window_state);
	}
	else if ('4'== charact )
	{
		step=0;
		LCD_clearscreen();
		LCD_init();
		LCD_clearscreen();
		UART_Txchar(0);
	}
	
}

void CheckWindow(u8 num)
{
	if( 1 ==num)
	{
		LCD_sendword("closed");
	}
	else
	{
		LCD_sendword("open");
	}
}
void FAULTcheck(u8 num)
{
	if( 1 ==num)
	{
		LCD_sendword("TOOCLOSE");
	}
	else
	{
		LCD_sendword("NONE");
	}
	
}
void HEATcheck(u8 num)
{
	if(1==num)
	{
		LCD_sendword("Over_heated");
	}
	else
	{
		LCD_sendword("NONE");
	}
}