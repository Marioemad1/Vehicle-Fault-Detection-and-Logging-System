/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   10/3/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  KERNEL_TEST	        *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "TMR_RTOS_interface.h"
#include "GI_interface.h"

/*RTOS*/
#include "KERNEL_interface.h"
#include "KERNEL_config.h"

Task_t ARR_TASK[RTOS_TASK_NUMBER]={{0}};

void RTOS_Start(void)
{
	TMR_RTOS_timer0_set_compareMatchValue(249);
	
	TMR_RTOS_TIMER0_CTC_pcallback(&RTOS_Schadule);
	
	GI_enable();
	
	TMR_RTOS_timer0_init();
	
}

void RTOS_CreateTask (u16 period ,u8 periortiy ,void(*PtoFunc)(void))
{
	if( (PtoFunc != NULL) && (periortiy<RTOS_TASK_NUMBER) )
	{
		ARR_TASK[periortiy].periodicy= period;
		
		ARR_TASK[periortiy].PTaskFunc= PtoFunc;
		
		ARR_TASK[periortiy].Task_state = RTOS_TASK_RESUMED;
		
	}
	
}

void RTOS_SuspendTask(u8 periortiy )
{
	ARR_TASK[periortiy].Task_state = RTOS_TASK_SUSPEND;
}

void RTOS_ResumedTask(u8 periortiy )
{
	ARR_TASK[periortiy].Task_state = RTOS_TASK_RESUMED;
}

void RTOS_KillTask   (u8 periortiy )
{
	ARR_TASK[periortiy].PTaskFunc = NULL;
}

void RTOS_Schadule(void)
{
	volatile static u16 counter=0;
	counter++;
	
	u8 loop_counter;
	
	for(loop_counter=0 ; loop_counter < RTOS_TASK_NUMBER ; loop_counter++ )
	{
		if(ARR_TASK[loop_counter].Task_state != RTOS_TASK_SUSPEND)
		{	
			if((counter % ARR_TASK[loop_counter].periodicy) == 0 )
			{
				if(ARR_TASK[loop_counter].PTaskFunc != NULL)
				{
					ARR_TASK[loop_counter].PTaskFunc();
				}
			}
				
		}
	}
	
}
