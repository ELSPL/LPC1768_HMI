/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	write a program to use Timer match to generate specific
*           time in Interrupt mode
* @version	1.0
* @date		26. Nov. 2013
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
/** @defgroup TIMER Interrupt
 * @ingroup TIMER_Examples
 * @{
 */


/*-------------------------PRIVATE Variables------------------------------*/
// Message Blocks


/*-------------------------MAIN Page------------------------------*/
/** @mainpage TIMER Test Example
*   @par Description:
*   - Use Standand inpput and output functions using interrupt
*
*   @par Activity - more information:
*   - Connect Serial cable from PC to LPC1768 board
*   - Open Hyperterminal at Baudrate 9600 8N1
*   - Observe terminal for use of std input and output functions
*/
/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief	Main TIMER testing example sub-routine
 **********************************************************************/

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */
int main(void)
{
	System_Init();                        // Initialize System

	printf(LPC_UART0, "Timer Interrupt will occur at 1sec ");

	while(1);
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
