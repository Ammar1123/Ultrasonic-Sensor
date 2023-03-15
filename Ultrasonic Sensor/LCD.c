/*
 * LCD.c
 *
 *  Created on: Oct 3, 2022
 *      Author: amaar
 */

#include "lcd.h"
#include "gpio.h"
#include <avr/delay.h>

void LCD_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(PORTB_ID,PIN2_ID,LOGIC_HIGH);
	GPIO_setupPortDirection(PORTA_ID,LOGIC_HIGH);
	_delay_ms(20);
	LCD_Send_Command(0x38);
	LCD_Send_Command(0x0C);
	LCD_Send_Command(0x01);

}

void LCD_Send_Command(uint8 Command){
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(PORTA_ID,Command);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_LOW);
	_delay_ms(1);

}


void LCD_displayCharacter(uint8 Data){
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(PORTA_ID,Data);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_LOW);
	_delay_ms(1);

}

void LCD_displaystring(char *str){
	uint8 i = 0;
	while(str[i] != '\0'){
		LCD_displayCharacter(str[i]);
		i++;
	}
}
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_Send_Command(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displaystring(Str); /* display the string */
}


void LCD_intergerToString(int number){
	char buffer[16];
	itoa(number,buffer,10);
	LCD_displaystring(buffer);

}
void LCD_ClearScreen(void){
	LCD_Send_Command(0x01);
}

