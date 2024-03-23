/** 
 * File: Terminal.h
 * Author: Eng- Mohamed Mokhtar
 * Group: Online16
 * Date: 2024,Feb
 * Description: This header file defines enumerated constants for colors.
 * Version: 1.0
 */

#ifndef TERMINAL_H
#define TERMINAL_H

/***************_APP_INCLUDES_*****************************/
#include "../Inc/Helpers/Utility.h"

/***************_Consol_Management_INCLUDES_***************/
#include "../Inc/cmd_Handler.h"

/***************_Standard_INCLUDES_************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>   // Windows API header


/***************_Types_Define_*****************************/
/**********_Keyboard_Keys_Define_***********/
#define TERMKEY_UPArrow		(0x48) // 72 
#define TERMKEY_DownArrow	(0x50) // 80 
#define TERMKEY_RightArrow	(0x4D) // 77 
#define TERMKEY_LeftArrow	(0x4B) // 75 
#define TERMKEY_ESC			(0x1B) // 27 
#define TERMKEY_Space		(0x20) // 32 
#define TERMKEY_Tab			(0x09) // 9 
#define TERMKEY_BackSpace	(0x08) // 8 
#define TERMKEY_Enter		(0x0D) // 13 

#define TERMSHAPE_UPArrow	(0x1E) // 72 
#define TERMSHAPE_DownArrow	(0x1F) // 80 

/***************_Terminal.c_FUNCTION_PROTOTYPE_*******************/
u8 Terminal_GetUserPush(void);
u8 Terminal_Switch_UpDown(u8 *apu8Switch, u8 au8MaxLimit);

void Terminal_GetString(u8 *apu8Str, u8 au8StrSize);
u8 TermValid_NameString(u8 *apu8Str, u8 au8StrSize, u8 au8MinLen);
u8 TermValid_CheckStrRepeat(u8 au8AllowRepeat, u8 *apu8String, u8 au8StrSize);

void Terminal_Getu8Num_Dec(u8 *apu8Num);
void Terminal_Getu16Num_Dec(u16 *apu16Num);
void Terminal_Getu32Num_Dec(u32 *apu32Num);

void Terminal_Getf32Num_Float(f32 *apf32Num);

#endif /* TERMINAL_H */