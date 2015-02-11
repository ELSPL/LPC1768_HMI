#include "lpc_system_init.h"

int main(void)
{
	System_Init();

    GLCD_Clear (White);
    GLCD_Display_String(2,3,"Sample Text");
    GLCD_PutPixel(180,120,Black);
    GLCD_PutPixel(181,120,Black);
    GLCD_PutPixel(180,121,Black);
    GLCD_PutPixel(181,121,Black);

    GLCD_PutPixel(90,180,Red);
    GLCD_PutPixel(91,180,Red);
    GLCD_PutPixel(90,181,Red);
    GLCD_PutPixel(91,181,Red);

	while (1);
	return 0;
}

