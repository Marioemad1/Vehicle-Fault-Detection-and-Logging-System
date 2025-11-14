/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   8/23/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   DIO_PROGRAM           *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 
//the libs we need 
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"

void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDirection)
{
	switch(PortId)
	{
		/* CASE A */
		case DIO_PORTA:
		if(DIO_PIN_OUTPUT==PinDirection)
		{
			SET_BIT(DDRA,PinId);
		}
		else if(DIO_PIN_INPUT==PinDirection)
		{
			CLR_BIT(DDRA,PinId);
		}
		break;
		
		/* CASE B */
		
		case DIO_PORTB:
		if(DIO_PIN_OUTPUT==PinDirection)
		{
			SET_BIT(DDRB,PinId);
		}
		else if(DIO_PIN_INPUT==PinDirection)
		{
			CLR_BIT(DDRB,PinId);
		}
		break;
		
		/* CASE C */
		
		case DIO_PORTC:
		if(DIO_PIN_OUTPUT==PinDirection)
		{
			SET_BIT(DDRC,PinId);
		}
		else if(DIO_PIN_INPUT==PinDirection)
		{
			CLR_BIT(DDRC,PinId);
		}
		break;
		
		/* CASE D */
		
		case DIO_PORTD:
		if(DIO_PIN_OUTPUT==PinDirection)
		{
			SET_BIT(DDRD,PinId);
		}
		else if(DIO_PIN_INPUT==PinDirection)
		{
			CLR_BIT(DDRD,PinId);
		}
		break;
	}
}

void DIO_GetPin(u8 PortId,u8 PinId,u8* PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(1 == READ_BIT(PINA,PinId))
		{
			*PinValue= DIO_PIN_HIGH;
		}
		else
		{
			*PinValue= DIO_PIN_LOW;
		}
		break;
		
		case DIO_PORTB:
		if(1 == READ_BIT(PINB,PinId))
		{
			*PinValue= DIO_PIN_HIGH;
		}
		else
		{
			*PinValue= DIO_PIN_LOW;
		}
		break;
		
		case DIO_PORTC:
		if(1 == READ_BIT(PINC,PinId))
		{
			*PinValue= DIO_PIN_HIGH;
		}
		else
		{
			*PinValue= DIO_PIN_LOW;
		}
		break;
		
		case DIO_PORTD:
		if(1 == READ_BIT(PIND,PinId))
		{
			*PinValue= DIO_PIN_HIGH;
		}
		else
		{
			*PinValue= DIO_PIN_LOW;
		}
		break;
		
	}
}

void DIO_SetPin(u8 PortId,u8 PinId,u8 PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTA,PinId);
		}
		else if(DIO_PIN_LOW == PinValue)
		{
			CLR_BIT(PORTA,PinId);
		}
		break;
		
		case DIO_PORTB:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTB,PinId);
		}
		else if(DIO_PIN_LOW == PinValue)
		{
			CLR_BIT(PORTB,PinId);
		}
		break;
		
		case DIO_PORTC:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTC,PinId);
		}
		else if(DIO_PIN_LOW == PinValue)
		{
			CLR_BIT(PORTC,PinId);
		}
		break;
		
		case DIO_PORTD:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTD,PinId);
		}
		else if(DIO_PIN_LOW == PinValue)
		{
			CLR_BIT(PORTD,PinId);
		}
		break;
		
	}
}

void DIO_TogglePin(u8 PortId,u8 PinId)
{
	switch(PortId)
	{
		case DIO_PORTA:
		TOOGLE_BIT(PORTA,PinId);
		break;
		
		case DIO_PORTB:
		TOOGLE_BIT(PORTB,PinId);
		break;
		
		case DIO_PORTC:
		TOOGLE_BIT(PORTC,PinId);
		break;
		
		case DIO_PORTD:
		TOOGLE_BIT(PORTD,PinId);
		break;
	}
}
void DIO_SetInternalPinPullUpRes(u8 PortId,u8 PinId)
{
	switch(PortId)
	{
		case 0:
		SET_BIT(PORTA,PinId);
		break;
		
		case 1:
		SET_BIT(PORTB,PinId);
		break;
		
		case 2:
		SET_BIT(PORTC,PinId);
		break;
		
		case 3:
		SET_BIT(PORTD,PinId);
		break;
	}
}

/*PORT*/
void DIO_SetPORTDirection(u8 PortId,u8 PortDirection)
{
	switch(PortId)
	{
		case 0: //portA
		if(DIO_PORT_OUTPUT==PortDirection)
		{
			DDRA=0xff;
		}
		else if(DIO_PORT_INPUT==PortDirection)
		{
			DDRA=0x00;
		}
		break;
		
		case 1: //portB
		if(DIO_PORT_OUTPUT==PortDirection)
		{
			DDRB=0xff;
		}
		else if(DIO_PORT_INPUT == PortDirection)
		{
			DDRB=0x00;
		}
		break;
		
		case 2: //portC
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRC=0xff;
		}
		else if(DIO_PORT_INPUT == PortDirection)
		{
			DDRC=0x00;
		}
		break;
		
		case 3: //portD
		if(DIO_PORT_OUTPUT==PortDirection)
		{
			DDRD=0xff;
		}
		else if(DIO_PORT_INPUT==PortDirection)
		{
			DDRD=0x00;
		}
		break;
	}
}
void DIO_SetPORT(u8 PortId,u8 PortValue)
{
	switch(PortId)
	{
		case 0: //portA
		PORTA=PortValue;
		break;
		
		case 1: //portB
		PORTB=PortValue;
		break;
		
		case 2: //portC
		PORTC=PortValue;
		break;
		
		case 3: //portD
		PORTD=PortValue;
		break;
	}
}
void DIO_GetPORT(u8 PortId,u8* PortValue)
{
	switch(PortId)
	{
		case 0: //PORTA
		*PortValue=PINA;
		break;
		
		case 1: //PORTB
		*PortValue=PINB;
		break;
		
		case 2: //PORTC
		*PortValue=PINC;
		break;
		
		case 3: //PORTD
		*PortValue=PIND;
		break;
	}
}

void DIO_TogglePORT(u8 PortId)
{
	switch(PortId)
	{
		case 0: //PORTA
		PORTA = ~PORTA;
		break;
		
		case 1: //PORTB
		PORTB = ~PORTB;
		break;
		
		case 2: //PORTC
		PORTC = ~PORTC;
		break;
		
		case 3: //PORTD
		PORTD = ~PORTD;
		break;
		
	}
}
void DIO_SetInternalPortPullUpRes(u8 PortId)
{
	switch(PortId)
	{
		case 0:
		PORTA=0xff;
		break;
		
		case 1:
		PORTB=0xff;
		break;
		
		case 2:
		PORTC=0xff;
		break;
		
		case 3:
		PORTD=0xff;
		break;
	}
}
void DIO_pullupres(u8 PortId,u8 PinId)
{
	DIO_SetPin(PortId,PinId,DIO_PIN_HIGH);
}