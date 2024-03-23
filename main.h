#ifndef MAIN_H_
#define MAIN_H_

/***************_APP_INCLUDES_*****************************/
#include "Inc/Helpers/Utility.h"

/***************_Consol_Management_INCLUDES_***************/
#include "Inc/cmd_Handler.h"
#include "Inc/ShapeDraw.h"

/***************_User_Interface_Management_INCLUDES_*******/
#include "Inc/Terminal.h"

/***************_File_Management_INCLUDES_*****************/


/***************_Standard_INCLUDES_************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>   // Windows API header
#include <stdio.h> 
#include <conio.h> 
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include "../Menu_representation/Inc/Helpers/Utility.h"
#include "../Menu_representation/Inc/cmd_Handler.h"
#include "../Menu_representation/Inc/Terminal.h"
#include "../Menu_representation/Inc/ShapeDraw.h"
#include "../Soduko_Game/Inc/Helpers/Utility.h"
#include "../Soduko_Game/Inc/cmd_Handler.h"
#include "../Soduko_Game/Inc/Terminal.h"
#include "../Soduko_Game/Inc/ShapeDraw.h"
#define ALPHA_FIGS         "///"
#define Frame_Height         40
#define Frame_Width      150
#define Frame_XPos         15
#define Frame_YPos          2
#define TTTopLeftCorner (177)
#define BBBotLeftCorner (177)
#define TTTopRightCorner (177)
#define BBBotRightCorner (177)
#define HHH_line (220)
#define VVV_line (219)
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_S 115
#define   ESC                     27
#define   ENTER                   13	
#define   ARROW_Up                72
#define   ARROW_Down              80
#define   ARROW_Right             77
#define   ARROW_Left              75



/***************_main.c_FUNCTION_PROTOTYPE_****************/
void Delay (u32 DelayValue);

#endif /* MAIN_H_ */
