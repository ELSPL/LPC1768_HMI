/******************************************************************//**
* @file		lpc_glcd_cal.h
* @brief	This file contains macro definitions and function declarations
* 			for GLCD Touch Calibration
* @version	1.0
* @date		Mar 21, 2015
* @author	Dwijay.edutech learning solutions
**********************************************************************/

#ifndef EG25I_HEADER_FILES_LPC_GLCD_CAL_H_
#define EG25I_HEADER_FILES_LPC_GLCD_CAL_H_

/* Includes ------------------------------------------------------------------- */
#include <math.h>
#include "lpc_system_init.h"

/* Peripheral group ----------------------------------------------------------- */
/** @defgroup GLCD_CAL
 * @ingroup LPC1700CMSIS_FwLib_Drivers
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif



/* Public Macros -------------------------------------------------------------- */
/** @defgroup GLCD_CAL_Public_Macros
 * @{
 */

#ifndef	OK
	#define		OK			 0
	#define		NOT_OK		-1
#endif

/**
 * @} GLCD_CAL_Public_Macros End
 */

/* Public Types --------------------------------------------------------------- */
/** @defgroup GLCD_CAL_Public_Types
 * @{
 */

typedef struct
{
	/* This arrangement of values facilitates
	 * calculations within getDisplayPoint()
	 */
	int32_t An;  			/* A = An/Divider */
	int32_t Bn;     		/* B = Bn/Divider */
	int32_t Cn;     		/* C = Cn/Divider */
	int32_t Dn;     		/* D = Dn/Divider */
	int32_t En;     		/* E = En/Divider */
	int32_t Fn;     		/* F = Fn/Divider */
	int32_t Divider ;
} MATRIX_Type;

typedef struct
{
	__IO uint16_t x;
	__IO uint16_t y;
	__IO uint16_t z1;
	__IO uint16_t z2;
}ts_eventCal;

/**
 * @} GLCD_CAL_Public_Types End
 */


/* Global Variables -------------------------------------------------------------- */
extern MATRIX_Type cmatrix;
extern ts_eventCal gTouch;
extern __IO Bool TReady;
extern __IO Bool CalTouch;


/* Public Functions ----------------------------------------------------------- */
/** @defgroup GLCD_CAL_Public_Functions
 * @{
 */
void TSC2004_Cal_Init(MATRIX_Type *matrixPtr);
int SetCalibrationMatrix(ts_eventCal *displayPtr, ts_eventCal *screenPtr, MATRIX_Type *matrixPtr);
int TSC2004_Cal_Values(ts_eventCal *displayPtr, MATRIX_Type *matrixPtr);

/**
 * @} GLCD_CAL_Public_Functions End
 */








#ifdef __cplusplus
}
#endif

#endif /* EG25I_HEADER_FILES_LPC_GLCD_CAL_H_ */

/**
 * @} GLCD_CAL End
 */

/* --------------------------------- End Of File ------------------------------ */
