/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program of Paint application with color palette
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

	uint16_t x,y,i,sel_color;
	uint16_t palette[16]={White,Black,Yellow,Green,DarkGreen,Cyan,DarkCyan,Blue,Navy,Red,Magenta,Maroon,Purple,Olive,LightGrey,DarkGrey};

	System_Init();                        // Initialize System
	GLCD_Clear(White);

	/*Palette*/
	for(i=0;i<16;i++)
	{
		/*Coordinates*/
		point1.x = i*20;
		point1.y = 220;
		point2.x = (i+1)*20;
		point2.y = 240;
		GLCD_Rect(&point1,&point2,1,Black,palette[i]);
	}

	while(1)
    {
		if(TReady == TRUE)
		{
		// Define range for palette selection
			if(gTouch.x>4 && gTouch.x<12 && gTouch.y>230 && gTouch.y<24)
			{
				sel_color = palette[0];
				delay_ms(500);
			}
			else if(gTouch.x>23 && gTouch.x<33 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[1];
				delay_ms(500);
			}
			else if(gTouch.x>42 && gTouch.x<53 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[2];
				delay_ms(500);
			}
			else if(gTouch.x>61 && gTouch.x<71 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[3];
				delay_ms(500);
			}
			else if(gTouch.x>82 && gTouch.x<92 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[4];
				delay_ms(500);
			}
			else if(gTouch.x>102 && gTouch.x<112 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[5];
				delay_ms(500);
			}
			else if(gTouch.x>122 && gTouch.x<134 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[6];
				delay_ms(500);
			}
			else if(gTouch.x>143 && gTouch.x<155 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[7];
				delay_ms(500);
			}
			else if(gTouch.x>166 && gTouch.x<176 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[8];
				delay_ms(500);
			}
			else if(gTouch.x>186 && gTouch.x<197 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[9];
				delay_ms(500);
			}
			else if(gTouch.x>206 && gTouch.x<217 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[10];
				delay_ms(500);
			}
			else if(gTouch.x>226 && gTouch.x<237 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[11];
				delay_ms(500);
			}
			else if(gTouch.x>240 && gTouch.x<258 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[12];
				delay_ms(500);
			}
			else if(gTouch.x>268 && gTouch.x<278 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[13];
				delay_ms(500);
			}
			else if(gTouch.x>288 && gTouch.x<298 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[14];
				delay_ms(500);
			}
			else if(gTouch.x>308 && gTouch.x<320 && gTouch.y>230 && gTouch.y<240)
			{
				sel_color = palette[15];
				delay_ms(500);
			}

			if((gTouch.x>=0) && (gTouch.x<=320) && (gTouch.y>=0) && (gTouch.y<229))  // Check if pen touched in desired area
			{
				/*color*/
				ccfg.bndry = NO;
				ccfg.fill = YES;
				ccfg.fill_color = sel_color;
				GLCD_Circle(gTouch.x,gTouch.y,1,&ccfg);   // Draw a Dot at selected position
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
