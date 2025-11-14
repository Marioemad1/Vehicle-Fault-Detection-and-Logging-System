/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/12/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   ADC		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "ADC_interface.h"

void ADC_init(void)
{
	//using the input VCC on ADC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//using the Right adjust
	CLR_BIT(ADMUX,5);
 
	//reduce the clk of the mc for ADC we WILL div by 128 125kHZ
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
 
 
	//Enable the ADC
	SET_BIT(ADCSRA,7);
}

void ADC_getdigitalvalue(u8 channelnumber,u16* digitalvalue)
{
	//CLEAR MUX channel
	ADMUX&=0b11100000;
	
	//OR with channel number
	ADMUX|=channelnumber;
	
	//start converting
	SET_BIT(ADCSRA,6);
	
	//stuck until i have a value 
	while(0 == READ_BIT(ADCSRA,4));
	
	//Clearing the flag so the ADC can work again
	SET_BIT(ADCSRA,4);
	
	//taking the digital value
	*digitalvalue=ADC_u16;
	
	
}