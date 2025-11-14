/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/16/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   DC_MOTOR          	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 
//the libs we need
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/*HAL*/
#include "DCM_interface.h"
#include "DCM_config.h"
/*MCAL*/
#include "DIO_Interface.h"

 void DCM_init (u8 enable)
{
	switch(enable)
	{
		/*IN CASE OF MOTOR A*/
		case DCM_ENA:
			/*SET THE MOTORA ENA PIN TO BE A OUTPUT*/
			DIO_SetPinDirection(DCM_PORT_MOTORA, DCM_MOTORA_ENA_PIN ,DIO_PIN_OUTPUT);
			//SET ENA TO HIGH
			DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_ENA_PIN ,DIO_PIN_HIGH);
			//SET THE IN1 OF MOTORA TO BE OUTPUT
			DIO_SetPinDirection(DCM_PORT_MOTORA, DCM_MOTORA_IN1_PIN ,DIO_PIN_OUTPUT);
			//SET THE IN2 OF MOTORA TO BE OUTPUT
			DIO_SetPinDirection(DCM_PORT_MOTORA, DCM_MOTORA_IN2_PIN ,DIO_PIN_OUTPUT);
		break;
		
		/*IN CASE OF MOTOR B*/
		case DCM_ENB:
			/*SET THE MOTORA ENA PIN TO BE A OUTPUT*/
			DIO_SetPinDirection(DCM_PORT_MOTORB, DCM_MOTORB_ENB_PIN ,DIO_PIN_OUTPUT);
			//SET ENB TO HIGH
			DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_ENB_PIN ,DIO_PIN_HIGH);
			//SET THE IN1 OF MOTORA TO BE OUTPUT
			DIO_SetPinDirection(DCM_PORT_MOTORB, DCM_MOTORB_IN1_PIN ,DIO_PIN_OUTPUT);
			//SET THE IN2 OF MOTORA TO BE OUTPUT
			DIO_SetPinDirection(DCM_PORT_MOTORB, DCM_MOTORB_IN2_PIN ,DIO_PIN_OUTPUT);
		break;
		
	}
}				
						
 void DCM_direction(u8 direction,u8 enable)
{
	switch(enable)
	{
		//CASE OF THE FIRST MOTOR
		case DCM_ENA:
		
			switch(direction)
			{
				//in case of clk wise direction
				case DCM_CLOCK_WISE:
				
				DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_IN1_PIN ,DIO_PIN_HIGH);
				DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_IN2_PIN ,DIO_PIN_LOW);
				
				break;
				
				//in case of anti clk wise
				case DCM_ANTI_CLOCK_WISE:
				
				DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_IN1_PIN ,DIO_PIN_LOW);
				DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_IN2_PIN ,DIO_PIN_HIGH);
				
				break;
				
			}
		
		break;
		
		
		//CASE OF SECOND MOTOR
		case DCM_ENB:
		
			switch(direction)
			{
				//in case of clk wise direction
				case DCM_CLOCK_WISE:
				
				DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_IN1_PIN ,DIO_PIN_HIGH);
				DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_IN2_PIN ,DIO_PIN_LOW);
				
				break;
				
				//in case of anti clk wise
				case DCM_ANTI_CLOCK_WISE:
				
				DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_IN1_PIN ,DIO_PIN_LOW);
				DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_IN2_PIN ,DIO_PIN_HIGH);
				
				break;
				
			}
		
		break;
		
	}
}
						
 void DCM_stop_motor(u8 enable)
{
	switch(enable)
	{
		case DCM_ENA:
		
		//SET ENA TO LOW
			DIO_SetPin(DCM_PORT_MOTORA, DCM_MOTORA_ENA_PIN ,DIO_PIN_LOW);
		
		break;
		
		case DCM_ENB:
		
		DIO_SetPin(DCM_PORT_MOTORB, DCM_MOTORB_ENB_PIN ,DIO_PIN_LOW);
		
		break;
	}
}