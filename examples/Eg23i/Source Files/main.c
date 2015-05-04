/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to Display line Graph of plotted points
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

	COORDINATE_Type point1,point2;
	COLORCFG_Type ccfg;
	uint16_t x,y,x1,y1,x2,y2,x_scale,y_scale;

	Bool pflag1=0,pflag2=1,fflag=0,switch1=0;
	uint16_t good_state = 0;
	uint16_t adc_state = 0;
	uint16_t temp;

	System_Init();                        // Initialize System
	GLCD_Clear(White);

	Show_BarGraph_VI();  // V vs I bar graph layout
	/* Corner Switch */
	point1.x = 310;
	point1.y = 0;
	point2.x = 320;
	point2.y = 10;
	GLCD_Rect(&point1,&point2,NO,Black,Red);

	while(1)
    {
		if(TReady == TRUE)
		{
			good_state = 0;
			adc_state = 0;

			while (good_state<8)          /* while less that 8 good samples */
			{
				x = gTouch.x;
				y = gTouch.y;

				temp = x;
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
			x = adc_state;               //Sampled X value

			if((gTouch.x>310) && (gTouch.x<=320) && (gTouch.y<=10) && (gTouch.y>0))  // Check if pen touched switch
			{
				/* Corner Switch */
				point1.x = 310;
				point1.y = 0;
				point2.x = 320;
				point2.y = 10;

				switch1=!switch1;       // Toggle switch
				if(switch1)
				{
					GLCD_Rect(&point1,&point2,YES,Black,Red);
				}
				else
				{
					GLCD_Rect(&point1,&point2,YES,Black,White);
				}
				delay_ms(700);
				gTouch.x = 0;      // clear old value
				gTouch.y = 0;
			}

			if((gTouch.x>=30) && (gTouch.x<=310) && (gTouch.y<=225) && (gTouch.y>=18))  // Check if pen touched in desired area
			{
				if(!pflag1 && !switch1)    // initial touch gives 1st point
				{
					x1 = gTouch.x;
					y1 = gTouch.y;
					pflag1 = 1;             // Ready for 2nd Point
					/*color*/
					ccfg.bndry = NO;
					ccfg.fill = YES;
					ccfg.fill_color = Black;
					GLCD_Circle(x1,y1,2,&ccfg);   // Draw a Dot at selected position
				}

				if(fflag && x>x2 && !switch1)
				{
					GLCD_Line(x2,y2,x,y,Green);
					x2 = gTouch.x;
					y2 = gTouch.y;

					/*color*/
					ccfg.bndry = NO;
					ccfg.fill = YES;
					ccfg.fill_color = Black;
					GLCD_Circle(x,y,2,&ccfg);   // Draw a Dot at selected position
				}

				if(!pflag2 && !switch1)     // Enter routine for second point
				{
					x2 = x;            // initial points for next line
					y2 = y;
					pflag2 = 1;       // clear flag
					fflag = 1;        // Ready for next points
					GLCD_Line(x1,y1,x2,y2,Green);   // First line

					/*color*/
					ccfg.bndry = NO;
					ccfg.fill = YES;
					ccfg.fill_color = Black;
					GLCD_Circle(x2,y2,2,&ccfg);   // Draw a Dot at selected position
				}

				if(!fflag)
				{
					pflag2 = 0;     // Ready for second point
				}

				if(switch1)  // if switch pressed display coordinates
				{
					x_scale = ((gTouch.x-30)*10)/26; // scale x according to Graph layout
					y_scale = (234-gTouch.y)/2;      // scale y according to Graph layout

					// Display Coordinates
					GLCD_Erase(200,5,1,9,White);
					delay_ms(25);
					gprintf(200,5,1,Black,"(%d03,%d03)",x_scale,y_scale);
				}
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
