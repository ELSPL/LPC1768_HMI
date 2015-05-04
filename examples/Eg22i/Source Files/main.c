/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to Display bar graph and vary bar as it touched
*           using touch screen
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

/*-------------------------MAIN Page------------------------------*/
/** @mainpage TGLCD Test Example
*   @par Description:
*   - Store input from virtual keypad and display it to UART0.
*
*   @par Activity - more information:
*   - Connect TGLCD to EPB1768 and as you type on touch keypad it will
*     be displayed on GLCD and as you press return key it will display
*     typed buffer on UART0 Terminal.
*/
/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief	Main TGLCD testing example sub-routine
 **********************************************************************/

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */
int main(void)
{

	Bool flag[11]={0,0,0,0,0,0,0,0,0,0,0};  // y_ref init index flag
	uint16_t PercentBy2;
	int16_t prev[11]={0,0,0,0,0,0,0,0,0,0,0},diff,index,prev_index;
	int16_t y_ref[11];

	uint16_t good_state = 0;
	uint16_t adc_state = 0;
	uint16_t temp;

	System_Init();                        // Initialize System
	GLCD_Clear(White);

	Show_BarGraph();      // Bar Graph layout

	while(1)
    {
		if(TReady == TRUE)
		{
		   	good_state = 0;
		    adc_state = 0;

			while (good_state<5)          /* while less that 3 good samples */
			{
				temp = gTouch.x;
				if (adc_state == temp)
				{
					good_state++;
				}
				else
				{
					good_state = 0;
				}

				adc_state = temp;
			}
			gTouch.x = adc_state;    // sample x value

				if(gTouch.y>30 && gTouch.y<230)  // bar touch area
				{
					// touch area selecting which bar is selected
					if (gTouch.x>41 && gTouch.x<66)
					{index = 1;}
					else if (gTouch.x>67 && gTouch.x<91)
					{index = 2;}
					else if (gTouch.x>93 && gTouch.x<120)
					{index = 3;}
					else if (gTouch.x>127 && gTouch.x<148)
					{index = 4;}
					else if (gTouch.x>156 && gTouch.x<178)
					{index = 5;}
					else if (gTouch.x>182 && gTouch.x<206)
					{index = 6;}
					else if (gTouch.x>208 && gTouch.x<232)
					{index = 7;}
					else if (gTouch.x>235 && gTouch.x<257)
					{index = 8;}
					else if (gTouch.x>260 && gTouch.x<284)
					{index = 9;}
					else if (gTouch.x>289 && gTouch.x<313)
					{index = 10;}

					if((prev_index - index) !=0)
					{
						if(!flag[index])  // first time selected bar y_ref value
						{
							y_ref[index]=219;
						}
					}
					PercentBy2 = 229-gTouch.y;  // bar value
					diff = prev[index] - PercentBy2; // find difference in value to change
					if(diff < 0)  // Negative value indicate inc in value over past
					{
						diff = -diff;   // change sign
						GLCD_LBar(index,20,y_ref[index],diff,0,Green); // according to index plot line
						y_ref[index]=y_ref[index]-diff;  // new y_ref of selected bar
					}
					else if(diff>0) // positive value indicate dec in value over past
					{
						GLCD_LBar(index,20,y_ref[index],diff,1,White); // select dec flag
						y_ref[index]=y_ref[index]+diff;  // new y_ref of selected bar
					}

					prev[index] = PercentBy2;   // store past value
					flag[index] = 1;            // set flag for that bar as it is initialized

					prev_index = index;  // past index value

			}
			TReady=FALSE;
			NVIC_EnableIRQ(EINT3_IRQn);
		}
    }
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
