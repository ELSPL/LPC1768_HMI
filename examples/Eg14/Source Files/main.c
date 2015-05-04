/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to Display Bar Graph
*           which vary according to ADC value
* @version	1.0
* @date		09. Dec. 2013
* @author	Dwijay.Edutech Learning Solutions
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.
**********************************************************************/
#include "lpc_system_init.h"

/* Example group ----------------------------------------------------------- */
/** @defgroup TGLCD
 * @ingroup TGLCD_Examples
 * @{
 */


/*-------------------------PRIVATE Variables------------------------------*/


/*-------------------------MAIN Page------------------------------*/
/** @mainpage GLCD Test Example
*   @par Description:
*   - Display Bar Graph which vary according to ADC value
*
*   @par Activity - more information:
*   - Connect GLCD with EPB1768 and as you move potentiometer
*     you will see the bar graph responding with it
*/
/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief	Main GLCD testing example sub-routine
 **********************************************************************/

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */
int main(void)
{
	uint32_t adc_value;
	uint16_t PercentBy2;
	int16_t prev=0,diff,y_ref;
	System_Init();                        // Initialize System

	GLCD_Clear(White);

	y_ref=219;
	Show_BarGraph();                      // Show Bar Graph layout
    while(1)
    {
		// Start conversion
		ADC_StartCmd(LPC_ADC, ADC_START_NOW);  // start ADC conversion

		//Wait conversion complete
		while (!(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_4, ADC_DATA_DONE)));
		adc_value = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_4); // store converted value
		PercentBy2 = (uint16_t)(adc_value/20.475);              // scale value with respect to Bar height
		//Display the result of conversion on the UART0
	//	printf(LPC_UART0,"\x1b[1;1H ADC value on channel 4: %d04", adc_value);

		diff = prev - PercentBy2;       // find difference
		if(diff < 0)   // negative diff shows bar value incresed over past value
		{
			diff = -diff;   // change sign
			GLCD_LBar(1,24,y_ref,diff,0,Green); // Plot lines
			y_ref=y_ref-diff;                   // new y_ref
		}
		else if(diff>0) // positive diff shows bar value decresed over past value
		{
			GLCD_LBar(1,24,y_ref,diff,1,White); // set decrement bar flag and plot lines
			y_ref=y_ref+diff;                   // new y_ref
		}

		prev = PercentBy2;   // store value as previous value
    }
    return 1;
}



#ifdef  DEBUG
/*******************************************************************************
* @brief		Reports the name of the source file and the source line number
* 				where the CHECK_PARAM error has occurred.
* @param[in]	file Pointer to the source file name
* @param[in]    line assert_param error line source number
* @return		None
*******************************************************************************/
void check_failed(uint8_t *file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while(1);
}
#endif

/*
 * @}
 */
