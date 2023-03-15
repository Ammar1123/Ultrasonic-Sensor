#include "lcd.h"
#include "icu.h"
#include "UltraSonic.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>
#include "std_types.h"



int main(void)
{
	uint16 distance = 0 ;

	LCD_init();


	while(1)
	{

		Ultrasoinc_init();
		distance = Ultrasonic_readDistance();
		if(g_edgeCount == 2)
		{


		Icu_DeInit(); /* Disable ICU Driver */
		g_edgeCount = 0;


		LCD_displayStringRowColumn(0, 0, "distance=");
		/* display the dutyCycle on LCD screen */
		LCD_moveCursor(0, 10);
		if(distance <100)
		{
			LCD_intergerToString(distance);
			LCD_displayCharacter(' ');
		}
		else if(distance<10)
		{

			LCD_intergerToString(distance);
			LCD_displaystring("  ");
		}
		else
		{
			LCD_intergerToString(distance);
		}
		LCD_displayStringRowColumn(0,14, "cm");

		}
	}



}

