/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/14/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   TMR		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 
//UTILES
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "TMR_interface.h"

void(* TMR_1_CTC_global_ptr)(void)= NULL;

/*TIMER 1 FUNCTIONS*/

void TMR_timer1_init(void)
{
	//Choose the CTC MODE 
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	//ENABLE THE INTERRUPT OF THE CTC 
	SET_BIT(TIMSK,4);
	
	//CHOOSE THE PRESCALER TO 64 TO SIT THE HZ TO 250KHZ
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
}
void TMR_TIMER1_CTC_pcallback(void(* ptr)(void))
{
	TMR_1_CTC_global_ptr = ptr;
}


void TMR_timer1_set_compareMatchValue(u16 OCR1A_VALUE)
{
	OCR1A_u16= OCR1A_VALUE;
}

void __vector_7(void) __attribute__ ((signal));
void __vector_7(void)
{
	TMR_1_CTC_global_ptr();
}