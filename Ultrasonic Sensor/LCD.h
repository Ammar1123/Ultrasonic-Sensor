/*
 * LCD.h
 *
 *  Created on: Oct 3, 2022
 *      Author: amaar
 */
#include "common_macros.h"
#include "std_types.h"
#include "gpio.h"

#ifndef LCD_H_
#define LCD_H_
#define LCD_RS_PORT_ID                 PORTD_ID
#define LCD_RS_PIN_ID                  PIN4_ID

#define LCD_E_PORT_ID                  PORTD_ID
#define LCD_E_PIN_ID                   PIN5_ID

#define LCD_DATA_PORT_ID               PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

void LCD_Send_Command(uint8 Command);

void LCD_displayCharacter(uint8 Data);

void LCD_init(void);

void LCD_displayString(char *str);

void LCD_moveCursor(uint8 row,uint8 col);

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

void LCD_init(void);

void LCD_ClearScreen(void);

#endif /* LCD_H_ */
