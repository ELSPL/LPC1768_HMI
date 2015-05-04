/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to create virtual keyboard on GLCD
*           and display input taken from it.
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
	schar key;
	uint16_t i=0,j=0;
	Bool CAPSLOCK=0;

	System_Init();                        // Initialize System
	GLCD_Clear(White);
	while(1)
	{
		key = GLCD_Getche();    // Get character from touch keypad
		printf(LPC_UART0,"%c",key);

		if(i+5 >= 320)          // Performs character wrapping
		{
		   i = 0;                  // Set x at far left position
		   j += 8;                 // Set y at next position down
		}

		if(key == CAPS)        // If CAPS key is pressed toggle CAPS mode
		{
			CAPSLOCK = !CAPSLOCK;
		}
		if(CAPSLOCK && (key!=CAPS))  // if caps lock is enabled
		{
			gprintf(i,j,1,Black,"%c",to_upper(key));
			i=i+6;
		}
		else if(!CAPSLOCK && (key!=CAPS))  // if caps lock is disabled
		{
			gprintf(i,j,1,Black,"%c",key);
			i=i+6;
		}

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
