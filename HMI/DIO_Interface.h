/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   8/23/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   DIO_INTERFACE         *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

			/******** MACROS FOR PORTID*********/

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

			/********* MACROS FOR PINID********/
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

			/*********MACROS FOR PIN DIRECTION***/
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

			/*********MACROS FOR PORT DIRECTION***/
#define DIO_PORT_OUTPUT 0xff // 0b11111111
#define DIO_PORT_INPUT 0x00  //0b00000000

			/*********MACROS FOR PIN DIRECTION***/
#define DIO_PIN_LOW   0
#define DIO_PIN_HIGH  1

			/*********MACROS FOR PORT VALUES***/
#define DIO_PORT_LOW   0x00
#define DIO_PORT_HIGH  0xff


/* FUNCTION DECLERATIONS */
/*PIN APIS*/
void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDirection);
void DIO_GetPin(u8 PortId,u8 PinId,u8* PinValue);
void DIO_SetPin(u8 PortId,u8 PinId,u8 PinValue);
void DIO_TogglePin(u8 PortId,u8 PinId);
void DIO_pullupres(u8 PortId,u8 PinId);
/*PORT APIS*/
void DIO_SetPORTDirection(u8 PortId,u8 PortDirection);
void DIO_GetPORT(u8 PortId,u8* PortValue);
void DIO_SetPORT(u8 PortId,u8 PortValue);
void DIO_TogglePORT(u8 PortId);


#endif /* DIO_INTERFACE_H_ */