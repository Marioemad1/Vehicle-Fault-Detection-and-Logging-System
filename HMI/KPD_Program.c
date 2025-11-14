/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/7/2025 9:31:51 	*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   KPD		          	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
//the libs we need 
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
/*HAL*/
#include "KPD_Interface.h"
#include "KPD_Config.h"

/*APIS*/
void KPD_SCAN(u8* pinvalue)
{
	*pinvalue= KPD_NOT_PREESD;
	u8 colonsarr[4]={KPD_COL0,KPD_COL1,KPD_COL2,KPD_COL3};
	u8 rowssarr[4] ={KPD_ROW0,KPD_ROW1,KPD_ROW2,KPD_ROW3};
	u8 key[KPD_KES_ROWS][KPD_KES_COLNS]= KPD_KES_ARC;
	u8 value;
	u8 colonscounter;
	u8 rowscounter;
	u8 indecator=0;
	for(colonscounter=0;colonscounter<4;++colonscounter)
	{
		DIO_SetPin(KPD_COLNSPORT,colonsarr[colonscounter],DIO_PIN_LOW);
		for(rowscounter=0;rowscounter<4;++rowscounter)
		{
			DIO_GetPin(KPD_ROWSSPORT,rowssarr[rowscounter],&value);
			if(0 == value)
			{
				*pinvalue=key[rowscounter][colonscounter];
				while(0==value)
				{
					DIO_GetPin(KPD_ROWSSPORT,rowssarr[rowscounter],&value);
				}
				indecator=1;
				break;
			}
		}
		
		DIO_SetPin(KPD_COLNSPORT,colonsarr[colonscounter],DIO_PIN_HIGH);
		if(1==indecator)
		{
			break;
		}
	}
}