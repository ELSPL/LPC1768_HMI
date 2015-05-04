/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to Display Bar Graph, which vary according
*           to ADC value also after crossing some limit its color should change
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
*   - Draw Bar Graph which vary according POT ADC value and after crossing
*     some limit its color should change
*
*   @par Activity - more information:
*   - Connect GLCD to EPB1768 and observe the Bar Graph with varying POT
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

	//bar var
	int16_t x1,x2,h,y_diff;
	int16_t index,y,per;
	uint8_t width;
	uint16_t color;

	System_Init();                        // Initialize System

	GLCD_Clear(White);

	y_ref=219;
	Show_BarGraph();                      // Bar Graph layout
    while(1)
    {
		// Start conversion
		ADC_StartCmd(LPC_ADC, ADC_START_NOW); // start ADC conversion

		//Wait conversion complete
		while (!(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_4, ADC_DATA_DONE)));
		adc_value = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_4); // store converter value
		PercentBy2 = (uint16_t)(adc_value/20.475);  // scale according to max bar height
		//Display the result of conversion on the UART0
	//	printf(LPC_UART0,"\x1b[1;1H ADC value on channel 4: %d04", adc_value);

		diff = prev - PercentBy2;   // find difference in value over past
		if(diff < 0)  // Negative diff suggest value increased over past value
		{
			diff = -diff;  // change size
            index = 1;     // Bar Graph index number specifying which bar it is
            width= 24;     // Bar width
            y=y_ref;       // new y_ref
            per = diff;    // bar diff value

			y_diff=y-(per);  // y_ref diff

			// if y_diff is not crossing layout and it supports 10 Bars
			if((y_diff>=20) && (index<=10))
			{
				for(h=0;h<=per;h++)   // plot bar graph
				{
					// value half of width and away from center of bar placement
					x1 = 30+(index*26)-(width-(width/2));
					x2 = x1+width;
					if((y-h)<=80) // value greater than 70 percent (Remember y value inc from top to bottom)
					{
						color=Red;
						GLCD_Line(x1,y-h,x2,y-h,color); // plot RED color bar
					}
					else
					{
						color=Blue;
						GLCD_Line(x1,y-h,x2,y-h,color); // Below limit plot Blue bar
					}
				}
			}
			y_ref=y_ref-diff;  // new y_ref
		}
		else if(diff>0)  // decrement bar means clear the difference
		{
			GLCD_LBar(1,24,y_ref,diff,1,White);
			y_ref=y_ref+diff;  // new y_ref
		}

		prev = PercentBy2;   // store past value
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
