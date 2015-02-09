/**********************************************************************
* $Id$		lpc_system_init.c
*//**
* @file		lpc_system_init.c
* @brief	Contains all functions support for SYSTEM INIT library
* 			on LPC17xx
* @version	1.0
* @date		24. July. 2013
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

/* Peripheral group ----------------------------------------------------------- */
/** @addtogroup SYSTEM_INIT
 * @{
 */

/* Includes ------------------------------------------------------------------- */
#include "lpc_system_init.h"

/* If this source file built with example, the LPC17xx FW library configuration
 * file in each example directory ("lpc17xx_libcfg.h") must be included,
 * otherwise the default FW library configuration file must be included instead
 */

/** @addtogroup SYSTEM_INIT_Public_Functions
 * @{
 */

/* Public Functions ----------------------------------------------------------- */
/*********************************************************************//**
 * @brief	Initial System Init using Port and Peripheral
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void System_Init(void)
{
	Port_Init();
	SYSTICK_Config();
	UART_Config(LPC_UART0, 57600);
	UART_Config(LPC_UART2, 115200);
}

/*********************************************************************//**
 * @brief 		General Port Initialization
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void Port_Init(void)
{
  //Use P0.0 to test System Tick interrupt
	GPIO_SetDir(1, _SBF(18,0xFF), 1); //Set P2.18 as output
}

/**
 * @}
 */

/* End of Public Functions ---------------------------------------------------- */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */

