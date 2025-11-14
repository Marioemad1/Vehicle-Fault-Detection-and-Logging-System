/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   10/3/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   2.0 		           	*************************************************
**************************************************    SWC      :   SYSIC	           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 
//UTILES
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "TMR_RTOS_interface.h"

/*TIMER 0 FUNCTIONS*/

void(* TMR_0_CTC_global_ptr)(void)= NULL;

void TMR_RTOS_timer0_init (void)
{
	//set timer0 mode to CTC 
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//set the interrupt of the Compare To Match
	SET_BIT(TIMSK,1);
	
	// set the prescaler=64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


/*                 THE COMPARE MATCH VALUE 
NOTE: IN THE CALLING OF THIS MODE YOU MUST CALL THIS FUNCTION FIRST
 */
void TMR_RTOS_timer0_set_compareMatchValue(u8 matchvalue)
{
	OCR0 = matchvalue;
}

/*Compare match passing the function to global*/
void TMR_RTOS_TIMER0_CTC_pcallback(void(* ptr)(void))
{
	TMR_0_CTC_global_ptr = ptr;
}

/*THE ISR CTC FOR THE TIMER 0*/

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
		// call the function of the ISR
		TMR_0_CTC_global_ptr();
}