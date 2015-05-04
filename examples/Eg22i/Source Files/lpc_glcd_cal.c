/******************************************************************//**
* @file		lpc_glcd_cal.c
* @brief	This file contains functional definition for GLCD Calibration.
* @version	1.0
* @date		Mar 21, 2015
* @author	Dwijay.edutech learning solutions
**********************************************************************/


/* Includes ------------------------------------------------------------------- */
#include "lpc_glcd_cal.h"

/* Peripheral group ----------------------------------------------------------- */
/** @addtogroup GLCD_CAL
 * @{
 */

/* Global Variables -------------------------------------------------------------- */
MATRIX_Type cmatrix;
ts_eventCal gTouch;
__IO Bool TReady=FALSE;
__IO Bool CalTouch=TRUE;


/* Public Functions ----------------------------------------------------------- */

/** @addtogroup GLCD_CAL_Public_Functions
 * @{
 */
void TSC2004_Cal_Init(MATRIX_Type *matrixPtr)
{
	int n;
	COLORCFG_Type ClrCfg;
	MATRIX_Type	matrix[4],avgmatrix;
	ts_event RTouch;
	ts_eventCal screenSample[5];
	ts_eventCal displaySample[5] =	{
									{  20,  20 },
									{ 300,  20 },
									{ 300, 220 },
									{  20, 220 },
									{ 160, 120 },
								};

 ts_eventCal displaytriangle1[3] = {displaySample[0],displaySample[4],displaySample[1]};
 ts_eventCal displaytriangle2[3] = {displaySample[1],displaySample[4],displaySample[2]};
 ts_eventCal displaytriangle3[3] = {displaySample[2],displaySample[4],displaySample[3]};
 ts_eventCal displaytriangle4[3] = {displaySample[3],displaySample[4],displaySample[0]};



 GLCD_Clear(White);


 for(n=0; n<5; n++)
 	{
 		switch (n) {
 			case 0:
 				ClrCfg.bcolor = Red;
 				ClrCfg.bndry = FALSE;
 				ClrCfg.fill = TRUE;
 				ClrCfg.fill_color = Red;
 				GLCD_Circle(20,20,3,&ClrCfg);
 				break;

 			case 1:
 				ClrCfg.bcolor = Red;
 				ClrCfg.bndry = FALSE;
 				ClrCfg.fill = TRUE;
 				ClrCfg.fill_color = Red;
 				GLCD_Circle(300,20,3,&ClrCfg);
 				break;

 			case 2:
 				ClrCfg.bcolor = Red;
 				ClrCfg.bndry = FALSE;
 				ClrCfg.fill = TRUE;
 				ClrCfg.fill_color = Red;
 				GLCD_Circle(300,220,3,&ClrCfg);
 				break;

 			case 3:
 				ClrCfg.bcolor = Red;
 				ClrCfg.bndry = FALSE;
 				ClrCfg.fill = TRUE;
 				ClrCfg.fill_color = Red;
 				GLCD_Circle(20,220,3,&ClrCfg);
 				break;

 			case 4:
 				ClrCfg.bcolor = Red;
 				ClrCfg.bndry = FALSE;
 				ClrCfg.fill = TRUE;
 				ClrCfg.fill_color = Red;
 				GLCD_Circle(160,120,3,&ClrCfg);
 				break;

 			default:
 				break;
 		}
 		//printf(LPC_UART0, "Touch point\n\r");
 		while(TReady == FALSE);
// 		printf(LPC_UART0,"\x1b[8;1After While\n\r");
 		delay_ms(2000);

 		screenSample[n].x = gTouch.x;
 		screenSample[n].y = gTouch.y;
 //		printf(LPC_UART0,"\x1b[3;1H gTouchx = %d08",gTouch.x);
 //		printf(LPC_UART0,"\x1b[4;1H gTouchy = %d08",gTouch.y);
 		TReady = FALSE;
 	}

 	CalTouch=FALSE;
// 	printf(LPC_UART0,"line reached");
 	 ts_eventCal screentriangle1[3] = {screenSample[0],screenSample[4],screenSample[1]};
     ts_eventCal screentriangle2[3] = {screenSample[1],screenSample[4],screenSample[2]};
     ts_eventCal screentriangle3[3] = {screenSample[2],screenSample[4],screenSample[3]};
     ts_eventCal screentriangle4[3] = {screenSample[3],screenSample[4],screenSample[0]};


     SetCalibrationMatrix(displaytriangle1, screentriangle1, &matrix[0]);
     SetCalibrationMatrix(displaytriangle2, screentriangle2, &matrix[1]);
     SetCalibrationMatrix(displaytriangle3, screentriangle3, &matrix[2]);
     SetCalibrationMatrix(displaytriangle4, screentriangle4, &matrix[3]);


    	matrixPtr->An = ( matrix[0].An + matrix[1].An + matrix[2].An + matrix[3].An ) / 4;
    	matrixPtr->Bn = ( matrix[0].Bn + matrix[1].Bn + matrix[2].Bn + matrix[3].Bn ) / 4;
    	matrixPtr->Cn = ( matrix[0].Cn + matrix[1].Cn + matrix[2].Cn + matrix[3].Cn ) / 4;
    	matrixPtr->Dn = ( matrix[0].Dn + matrix[1].Dn + matrix[2].Dn + matrix[3].Dn ) / 4;
    	matrixPtr->En = ( matrix[0].En + matrix[1].En + matrix[2].En + matrix[3].En ) / 4;
    	matrixPtr->Fn = ( matrix[0].Fn + matrix[1].Fn + matrix[2].Fn + matrix[3].Fn ) / 4;
    	matrixPtr->Divider = ( matrix[0].Divider + matrix[1].Divider + matrix[2].Divider + matrix[3].Divider ) / 4;


    	GLCD_Clear(White);

}

int SetCalibrationMatrix(ts_eventCal *displayPtr, ts_eventCal *screenPtr, MATRIX_Type *matrixPtr)
{
	int  retValue = OK;

    matrixPtr->Divider = ((screenPtr[0].x - screenPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) -
                         ((screenPtr[1].x - screenPtr[2].x) * (screenPtr[0].y - screenPtr[2].y));

    if(matrixPtr->Divider == 0)
    {
        retValue = NOT_OK;
    }
    else
    {
        matrixPtr->An = ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) -
                        ((displayPtr[1].x - displayPtr[2].x) * (screenPtr[0].y - screenPtr[2].y));

        matrixPtr->Bn = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].x - displayPtr[2].x)) -
                        ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].x - screenPtr[2].x));

        matrixPtr->Cn = (screenPtr[2].x * displayPtr[1].x - screenPtr[1].x * displayPtr[2].x) * screenPtr[0].y +
                        (screenPtr[0].x * displayPtr[2].x - screenPtr[2].x * displayPtr[0].x) * screenPtr[1].y +
                        (screenPtr[1].x * displayPtr[0].x - screenPtr[0].x * displayPtr[1].x) * screenPtr[2].y;

        matrixPtr->Dn = ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].y - screenPtr[2].y)) -
                        ((displayPtr[1].y - displayPtr[2].y) * (screenPtr[0].y - screenPtr[2].y));

        matrixPtr->En = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].y - displayPtr[2].y)) -
                        ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].x - screenPtr[2].x));

        matrixPtr->Fn = (screenPtr[2].x * displayPtr[1].y - screenPtr[1].x * displayPtr[2].y) * screenPtr[0].y +
                        (screenPtr[0].x * displayPtr[2].y - screenPtr[2].x * displayPtr[0].y) * screenPtr[1].y +
                        (screenPtr[1].x * displayPtr[0].y - screenPtr[0].x * displayPtr[1].y) * screenPtr[2].y;
    }

    return(retValue);
} /* end of setCalibrationMatrix() */



int TSC2004_Cal_Values(ts_eventCal *displayPtr, MATRIX_Type *matrixPtr)
{
    int  retValue = OK;
	ts_event RTouchn;

    TSC2004_Read_Values(&RTouchn);

    if(matrixPtr->Divider != 0)
    {
            /* Operation order is important since we are doing integer */
            /*  math. Make sure you add all terms together before      */
            /*  dividing, so that the remainder is not rounded off     */
            /*  prematurely.                                           */

        displayPtr->x = ( (matrixPtr->An * RTouchn.x) +
                          (matrixPtr->Bn * RTouchn.y) +
                           matrixPtr->Cn
                        ) / matrixPtr->Divider;

        displayPtr->y = ( (matrixPtr->Dn * RTouchn.x) +
                          (matrixPtr->En * RTouchn.y) +
                           matrixPtr->Fn
                        ) / matrixPtr->Divider;
    }
    else
    {
        retValue = NOT_OK;
    }

    return(retValue);
} /* end of getDisplayPoint() */


/**
 * @} GLCD_CAL_Public_Functions End
 */


/**
 * @} GLCD_CAL End
 */

 /* --------------------------------- End Of File ------------------------------ */
