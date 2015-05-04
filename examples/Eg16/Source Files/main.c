/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a program to Draw Solid Triangle with boundary and
*           also display its coordinates on TFT
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
*   - Draw a solid triangle with boundary and display it coordinates
*
*   @par Activity - more information:
*   - Connect GLCD to EPB1768 and observe triangle with coordinates
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
	COORDINATE_Type point1,point2,point3;
	COLORCFG_Type tricfg;
	System_Init();                        // Initialize System

	GLCD_Clear(White);
	// Triangle coordinates
	point1.x = 20;
	point1.y = 20;
	point2.x = 80;
	point2.y = 80;
	point3.x = 30;
	point3.y = 120;
	tricfg.fill = YES;
	tricfg.bndry= YES;
	tricfg.bcolor = Blue;
	tricfg.fill_color=Green;
	// Display Triangle
	GLCD_Triangle(&point1,&point2,&point3,&tricfg);

	// Display Coordinates
    gprintf(point1.x+2,point1.y,1,Black,"(%d03,%d03)",point1.x,point1.y);
    gprintf(point2.x+2,point2.y,1,Black,"(%d03,%d03)",point2.x,point2.y);
    gprintf(point3.x+2,point3.y,1,Black,"(%d03,%d03)",point3.x,point3.y);

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
