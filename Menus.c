#include "main.h"
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
#define   Menu3_Total_Options     4
#define   Menu3_Opt_Length        7
#define   Menu3_XPos              78
#define   Menu3_YPos              30
#define   ESC                      27
#define   R                        114
#define   B                        98
#define   ENTER                    13	
#define   Menu2_Total_OptionsG     2
#define   Menu2_Opt_LengthG        70
#define   Menu2_XPosG              12
#define   Menu2_YPosG              22
#define TEXT_Highlight 14
#define  BELL             7
#define  BLOCK          (177)
#define   au16WIDTH             195
#define   au16HEIGHT             50
void printSudokuArray1(void);
void printSudokuArray2(void);
void highlightCursor(int x, int y);
 void printSudokuArray(void);
 void vid_Initialize_Game_Frame(void);
 void Entry_Frame(u8);
 void vid_S_Frame(u8); 
 void vid_U_Frame(u8); 
 void vid_Letter_Space(void);
void submitSudokuArray(const int sudokuArray[9][9]);
int isSudokuSolution(const int sudokuArray[9][9]);
void drawRectangularBorder(int width, int height, int startX, int startY);
void printMessageInBox(const char* message, int boxWidth, int boxHeight, int boxX, int boxY);


 CONSOLE_SCREEN_BUFFER_INFO csbi;
 COORD cursorPos; 

 u16 YPos=0;
 u16 XPos=0;
 u16 YMAXLIMIT=0;
 u16 XMAXLIMIT=0;
 u16 YMINLIMIT=0;
 u16 XMINLIMIT=0;
 
 void Grid(void);	
 void hideCursor(void) ;
 void highlightString(const char *, u8 );
  u8 u8_MENU_1(void);
  u8 u8_MENU_2(void);
   u8 u8_MENU_3(void);
	

 
 
 void main(void)
 {
	 
	 
	    
	    vid_Initialize_Game_Frame();
        Entry_Frame(5);
		cmdSetScreenDim(au16WIDTH, au16HEIGHT); 
		while (u8_MENU_1());
		
			
			
	 
	 
 }
  void highlightString(const char *str,u8 au8Color)
 {
	  cmdSetConsoleColour(au8Color);	
      printf("%s", str);                  // This will highlight the string in red
	  hideCursor();
	  cmdGoToXY(XMINLIMIT, YPos);
}

void hideCursor() 
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.dwSize=100;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

 
 
 u8 u8_MENU_1(void)
 {
	  #define   ESC                     27
	  #define   ENTER                   13	
	  #define   ARROW_Up                72
	  #define   ARROW_Down              80
	  #define   ARROW_Right             77
	  #define   ARROW_Left              75
      #define   Menu1_Total_Options     2
      #define   Menu1_Opt_Length        5
	  #define   Menu1_XPos              78
      #define   Menu1_YPos              30
		 
     u8 Option=0;	 
	 u8 MENU_1_[Menu1_Total_Options][Menu1_Opt_Length]={"PLAY","EXIT"};  

	  u8 KeyBoard_Input=0;	  
	  
	  XPos=Menu1_XPos;
      YPos=Menu1_YPos;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
	  
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_1_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);   
	 	 printf("%s", MENU_1_[MenuOpt_Count]);
	 }
	 
    	hideCursor();
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
		
	 while(1)
	    {	
	
	        KeyBoard_Input=0;
		   	KeyBoard_Input= _getch();

              highlightString(MENU_1_[YPos-YMINLIMIT], TEXT_DWhite); 
		      switch (KeyBoard_Input)
		       {
			         case ARROW_Up:
			         YPos--;
			         break;
			         case ARROW_Down :
			         YPos++;
			         break;
			         case ARROW_Left :
			         XPos--;
			         break;
			         case ARROW_Right :
			         XPos++;
			         break;
					 default  :
					  /*DO NOTHING*/
			         break;
		       }
			 
		     YPos =  ( YPos % Menu1_Total_Options ) + YMINLIMIT; 
		     cmdGoToXY(XMINLIMIT, YPos);
		     highlightString(MENU_1_[YPos-YMINLIMIT], TEXT_Red);	
			   
			   if(KeyBoard_Input == ENTER)
			   { 
                   cmdResetConsoleColour();		   
				   if( strcmp(MENU_1_[YPos-YMINLIMIT] , "PLAY") == 0 )
				   {
							system("cls") ;
							vid_Initialize_Game_Frame();
                            Entry_Frame(5);
							Option = 1;
							u8_MENU_2();
				   }
				   else if( strcmp(MENU_1_[YPos-YMINLIMIT] , "EXIT") == 0 )
				   {
							 Option = 0;
							 system("cls") ;
							 exit(0);
							 break;
				   }
				   else
				   {
					   /*DO NOTHING*/
				   }
			   }
			   else if(KeyBoard_Input == ESC) 
			   {
					 Option = 0;
					 exit(0);
					 break;
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
		}
		 cmdResetConsoleColour();
		return Option;
		
 }
 u8 u8_MENU_2(void)
 {
	  #define   ESC                     27
	  #define   ENTER                   13	
	  #define   ARROW_Up                72
	  #define   ARROW_Down              80
	  #define   ARROW_Right             77
	  #define   ARROW_Left              75
      #define   Menu2_Total_Options     2
      #define   Menu2_Opt_Length        6
	  #define   Menu2_XPos              78
      #define   Menu2_YPos              30
		 vid_Initialize_Game_Frame();
        Entry_Frame(5);
     u8 Option=0;	 
	 u8 MENU_2_[Menu2_Total_Options][Menu2_Opt_Length]={"LEVEL", "BACK"};  

	  u8 KeyBoard_Input=0;	  
	  
	  XPos=Menu2_XPos;
      YPos=Menu2_YPos;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
	  
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_2_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu2_Total_Options; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);   
	 	 printf("%s", MENU_2_[MenuOpt_Count]);
	 }
    	hideCursor();
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
		
	 while(1)
	    {	
	
	        KeyBoard_Input=0;
		   	KeyBoard_Input= _getch();

              highlightString(MENU_2_[YPos-YMINLIMIT], TEXT_DWhite); 
		      switch (KeyBoard_Input)
		       {
			         case ARROW_Up:
			         YPos--;
			         break;
			         case ARROW_Down :
			         YPos++;
			         break;
			         case ARROW_Left :
			         XPos--;
			         break;
			         case ARROW_Right :
			         XPos++;
			         break;
					 default  :
					  /*DO NOTHING*/
			         break;
		       }
			 
		     YPos =  ( YPos % Menu2_Total_Options ) + YMINLIMIT; 
		     cmdGoToXY(XMINLIMIT, YPos);
		     highlightString(MENU_2_[YPos-YMINLIMIT], TEXT_Red);	
			   
			   if(KeyBoard_Input == ENTER)
			   { 
                   cmdResetConsoleColour();		   
				   if( strcmp(MENU_2_[YPos-YMINLIMIT] , "LEVEL") == 0 )
				   {
							system("cls") ;
							Option = 1;
							vid_Initialize_Game_Frame();
                            Entry_Frame(5);
							u8_MENU_3();
				   }
				   else if( strcmp(MENU_2_[YPos-YMINLIMIT] , "BACK") == 0 )
				   {
							 Option = 0;
							 system("cls") ;
							 vid_Initialize_Game_Frame();
                             Entry_Frame(5);
							u8_MENU_1();
				   }
				   else
				   {
					   /*DO NOTHING*/
				   }
			   }
			   else if(KeyBoard_Input == ESC) 
			   {
					 Option = 0;
					 break;
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
		}
		 cmdResetConsoleColour();
		return Option;
		
 }
 u8 u8_MENU_3(void)
 {
	  
		 
     u8 Option=0;	 
	 u8 MENU_3_[Menu3_Total_Options][Menu3_Opt_Length]={"EASY", "MEDIUM","HARD","BACK"};  

	  u8 KeyBoard_Input=0;	  
	  
	  XPos=Menu3_XPos;
      YPos=Menu3_YPos;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
	  
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_3_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu3_Total_Options; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);   
	 	 printf("%s", MENU_3_[MenuOpt_Count]);
	 }
    	hideCursor();
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
		
	 while(1)
	    {	
	
	        KeyBoard_Input=0;
		   	KeyBoard_Input= _getch();

              highlightString(MENU_3_[YPos-YMINLIMIT], TEXT_DWhite); 
		      switch (KeyBoard_Input)
		       {
			         case ARROW_Up:
			         YPos--;
			         break;
			         case ARROW_Down :
			         YPos++;
			         break;
			         case ARROW_Left :
			         XPos--;
			         break;
			         case ARROW_Right :
			         XPos++;
			         break;
					 default  :
					  /*DO NOTHING*/
			         break;
		       }
			 
		     YPos =  ( YPos % Menu3_Total_Options ) + YMINLIMIT; 
		     cmdGoToXY(XMINLIMIT, YPos);
		     highlightString(MENU_3_[YPos-YMINLIMIT], TEXT_Red);	
			   
			   if(KeyBoard_Input == ENTER)
			   { 
                   cmdResetConsoleColour();		   
				   if( strcmp(MENU_3_[YPos-YMINLIMIT] , "EASY") == 0 )
				   {
							system("cls") ;
							Option = 1;
							printSudokuArray();
				   }
				   else if( strcmp(MENU_3_[YPos-YMINLIMIT] , "BACK") == 0 )
				   {
							system("cls") ;
							Option = 1;
							printSudokuArray1();
				   }
				    else if( strcmp(MENU_3_[YPos-YMINLIMIT] , "HARD") == 0 )
				   {
							system("cls") ;
							Option = 1;
							printSudokuArray2();
				   }
				   
				   else if( strcmp(MENU_3_[YPos-YMINLIMIT] , "MEDIUM") == 0 )
				   {
							 Option = 0;
							 system("cls") ;
							 u8_MENU_2();
				   }
				   else
				   {
					   /*DO NOTHING*/
				   }
			   }
			   else if(KeyBoard_Input == ESC) 
			   {
					 Option = 0;
					 system("cls") ;
					 exit(0);
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
		}
		 cmdResetConsoleColour();
		return Option;
		
 }
 
 void Grid(void)
{
#define TopLeftCorner (0xDA)
#define BotLeftCorner (0xC0)
#define TopRightCorner (0xBF)
#define BotRightCorner (0xD9)
#define TripleCorner (0xB4)
#define FourCorner (0xC5)
#define H_line (0xC4)
#define V_line (0xB3)
#define TTopLeftCorner (0xc9)
#define BBotLeftCorner (0xc8)
#define TTopRightCorner (0xbb)
#define BBotRightCorner (0xbc)
#define HH_line (0xcd)
#define VV_line (0xba)
   int i, j;
	u8 au8Xposition=1, au8Yposition=1;
    // Top border
	cmdSetConsoleColour(TEXT_Sky);
    cmdGoToXY(au8Xposition, au8Yposition);
    printf("%c", TTopLeftCorner);
	au8Xposition+=1;
    for (i = 0; i < 18; i++)
    {
		cmdGoToXY(au8Xposition, au8Yposition);
        printf("%c%c", HH_line, HH_line);
		au8Xposition+=2;
	}
	cmdGoToXY(au8Xposition, au8Yposition);
    printf("%c\n", TTopRightCorner);
	au8Xposition=1;
	au8Yposition+=1;
cmdResetConsoleColour();
    // Middle rows
    for (i = 1; i < 19; i++)
    {
        // Left border
		if(i==18)
		{
			cmdSetConsoleColour(TEXT_Sky);
		cmdGoToXY(au8Xposition, au8Yposition);
        printf("%c", BBotLeftCorner);
		au8Xposition+=1;
		cmdResetConsoleColour();
			 
		}
		else{
		cmdSetConsoleColour(TEXT_Sky);
		cmdGoToXY(au8Xposition, au8Yposition);
        printf("%c", VV_line);
		au8Xposition+=1;
        cmdResetConsoleColour();
		}
		
		
        // Middle squares
        for (j = 0; j < 18; j++)
        {
			
            if (i % 2 == 0 && j % 2 == 0){
				if(i%3)
				{
					if(j==0)
					{
						cmdGoToXY(au8Xposition, au8Yposition);
					printf("%c%c", H_line, H_line);
					au8Xposition+=2;
					}
					else
					{
					cmdGoToXY(au8Xposition, au8Yposition);
					printf("%c%c", BotLeftCorner, H_line);
					au8Xposition+=2;
					}
				}
				else
				{
                    if(j%3)
					{
						cmdSetConsoleColour(TEXT_Sky);
						cmdGoToXY(au8Xposition, au8Yposition);
                   printf("%c%c", HH_line, HH_line);
				   cmdResetConsoleColour();
				   au8Xposition+=2;
					}
				   else
				   {
					   if(i==18)
					{
                        cmdSetConsoleColour(TEXT_Sky);
                        cmdGoToXY(au8Xposition, au8Yposition);
                        printf("%c%c", HH_line, HH_line);
				        cmdResetConsoleColour();
				        au8Xposition+=2;
					}
					else
					{
						
						
					   cmdSetConsoleColour(TEXT_Sky);
                   cmdGoToXY(au8Xposition, au8Yposition);
                   printf("%c%c", HH_line, HH_line);
				   cmdResetConsoleColour();
				   au8Xposition+=2;
						
					}
				  
				   }
				   
				}
                
			}
            else if (i % 2 == 0 && j % 2 == 1)
			{    if(i%3)
				{
					cmdGoToXY(au8Xposition, au8Yposition);
					printf("%c%c", H_line, H_line);
					au8Xposition+=2;
				}
				else
				{
				cmdSetConsoleColour(TEXT_Sky);
				cmdGoToXY(au8Xposition, au8Yposition);
                printf("%c%c", HH_line, HH_line);
				cmdResetConsoleColour();
				au8Xposition+=2;
				}
			}
            else if (i % 2 == 1 && j % 2 == 0){
				if(j%3)
				{
					cmdGoToXY(au8Xposition, au8Yposition);
				 printf("%c%c", V_line, '\0');
				 au8Xposition+=2;
				}
				else{
					if(j==0)
					{
						
						printf("%c", '\0');
						au8Xposition+=2;
						//DO NOTHING
					}
					else{
					cmdSetConsoleColour(TEXT_Sky);
					cmdGoToXY(au8Xposition, au8Yposition);
                printf("%c%c", VV_line, '\0');
				cmdResetConsoleColour();
				au8Xposition+=2;
					}
				}
                
			}
			
            else
            {
				cmdGoToXY(au8Xposition, au8Yposition);
                printf("  ");
				au8Xposition+=2;
			}
        }
         
				   
					  
        // Right border
		
		if(i==18)
		{
			cmdSetConsoleColour(TEXT_Sky);
		cmdGoToXY(au8Xposition, au8Yposition);
        printf("%c", BBotRightCorner);
		au8Xposition=1;
		au8Yposition+=1;
		cmdResetConsoleColour();
			 
		}
		else{
		cmdSetConsoleColour(TEXT_Sky);
		cmdGoToXY(au8Xposition, au8Yposition);
        printf("%c\n", VV_line);
		au8Xposition=1;
		au8Yposition+=1;
		cmdResetConsoleColour();
		}
    }

    
	cmdResetConsoleColour();
	
	
	


}




 
 void vid_Initialize_Game_Frame()
 {
	 cmdClearScreen() ;
	 cmdSetConsoleColour(TEXT_LYellow);	
	 ShapeDraw_Square(Frame_XPos,Frame_YPos, Frame_Width, Frame_Height);
	 printf("\n");
	  cmdResetConsoleColour();	
	 YPos=Frame_YPos+9;
     XPos=Frame_XPos+20; 
 } 
 
 void vid_Letter_Space()
  {
		XPos+=4;
	   cmdGoToXY(XPos, YPos);
  }
 

void vid_S_Frame(u8 au8Scale)
{
	 u16 lu16InitXPos=XPos;
	 u16 lu16InitYPos=YPos;
	 u16 lu16U_Width= au8Scale+1;
	         for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
			  }
			   cmdGoToXY(XPos, ++YPos);
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
				  cmdGoToXY(XPos, YPos++);
			  }
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
		      XPos=cursorPos.X-2;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				   printf("%c%c",219,219);			  
			  }
			  cmdGoToXY(lu16InitXPos, YPos-1);
		      for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  { 
				  printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
			   XPos=cursorPos.X;
			   YPos=lu16InitYPos;
}

 
  void vid_U_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 u16 lu16U_Width= au8Scale+1;
		 au8Scale= (au8Scale*2)+1;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  printf("%c%c",219,219);
				  cmdGoToXY(XPos, YPos++);
			  }
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  { 
				 printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
			   XPos=cursorPos.X;
			 for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, --YPos);
				  printf("%c%c",219,219);  
			  }
			  cmdGoToXY(++XPos, YPos);
			  
  }


      void vid_D_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 au8Scale= (au8Scale*2)+1;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos+lu8CursorMov);
				  printf("%c%c",219,219);	
			  } 
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2;lu8CursorMov++)
			  {
				  XPos+=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			    XPos+=2;
				cmdGoToXY(XPos, ++YPos);
				printf("%c%c",219,219);	
				XPos+=2;
				lu16InitXPos =XPos;
				cmdGoToXY(XPos, ++YPos);
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale-4;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				  printf("%c%c",219,219);	
			  } 
			    XPos-=2;
			   cmdGoToXY(XPos, YPos++);
				printf("%c%c",219,219);	
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2;lu8CursorMov++)
			  {
				  XPos-=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 

			  XPos=  lu16InitXPos ;
			  YPos=  lu16InitYPos;
			  cmdGoToXY(XPos, lu16InitYPos); 
  }
 
  void vid_O_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 au8Scale= (au8Scale*2)+1;
		 	  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2+1;lu8CursorMov++)
			  {
				  XPos+=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			   XPos+=2;
			   lu16InitXPos=XPos;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				  printf("%c%c",219,219);	
			  } 
			  YPos--;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2+1;lu8CursorMov++)
			  {
				  XPos-=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			   XPos-=2;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos--);
				  printf("%c%c",219,219);	
			  } 
			  YPos++;

			  XPos=  lu16InitXPos ;
			  YPos=  lu16InitYPos;             
			  cmdGoToXY(XPos, lu16InitYPos); 
  }
 
  void vid_K_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 au8Scale= (au8Scale*2)+1;
		 u8 x=au8Scale-4;
		 u8 co=1;
            for(u8 i=au8Scale; i> 0;i--)
			  {
				  if(x>1 && co>0)
				  {
		 	       for(u8 lu8CursorMov=0; lu8CursorMov<x;lu8CursorMov++)
			       {
			          cmdGoToXY(XPos, YPos);
			 	      if(lu8CursorMov==0 || (lu8CursorMov==x-1)) printf("%c%c",219,219);	
			 	      XPos+=2;  
			       }
                   	x--;	   
			       XPos=lu16InitXPos;
			       YPos++;
				  }
				  else
				  {
					  co=0;
					if(x<=0)
					{
						YPos--;
						(x++);	
					}
                    else {	x++; }
					for(u8 lu8CursorMov=0; lu8CursorMov<x;lu8CursorMov++)
			       {   	 
			          cmdGoToXY(XPos, YPos);
			 	      if(lu8CursorMov==0 || (lu8CursorMov==x-1)) printf("%c%c",219,219);	
			 	      XPos+=2;  
			       }
			       XPos=lu16InitXPos;
			       YPos++;
				  }
			  }
			 

			  XPos=  lu16InitXPos+au8Scale+1;
			  YPos=  lu16InitYPos;             
			  cmdGoToXY(XPos, lu16InitYPos); 
  }

 
 
 
void Entry_Frame(u8 au8Scale)
	 {
			 vid_Letter_Space();
			 cmdSetConsoleColour(TEXT_Red);	
			 vid_S_Frame( au8Scale );
			 vid_Letter_Space();
			 vid_U_Frame(au8Scale);
			 vid_Letter_Space();
			 vid_D_Frame( au8Scale);
			 vid_Letter_Space();
			 vid_O_Frame( au8Scale) ;
			 vid_Letter_Space();
			 vid_K_Frame( au8Scale);
			 vid_Letter_Space();
			 vid_U_Frame(au8Scale);
			 cmdResetConsoleColour();	
			
	 }
 

 void printSudokuArray(void) {
	 
	  
	  
		
int sudokuArray[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int originalArray[9][9]; // Keep track of original numbers
	int userModified[9][9] = {0};
    int cursorX = 0;
    int cursorY = 0;
    int editZeros = 1;

    // Copy the original array
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            originalArray[i][j] = sudokuArray[i][j];
            if (sudokuArray[i][j] == 0) {
                userModified[i][j] = 1; // Mark cells with zero as user-modified
            }
        }
    }
    
	

    while (1) {
        system("cls");
		Grid();
		
	 
	 u8 MENU_2_[Menu2_Total_OptionsG][Menu2_Opt_LengthG]={"RETRY  (PRESS (R))              NOTE: PRESS ENTER TO INPUT", 
	                                                      "BACK   (PRESS (B))              NOTE: PRESS S TO SUBMIT"};  

	  	  
	  
	  XPos=Menu2_XPosG;
      YPos=Menu2_YPosG;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_2_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu2_Total_OptionsG; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);  
         cmdSetConsoleColour(TEXT_Red);		 
	 	 printf("%s", MENU_2_[MenuOpt_Count]);
	 }
    	
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
        for (u8 i = 0; i < 9; ++i) {
    for (u8 j = 0; j < 9; ++j) {
        cmdGoToXY(j * 4 + 3, i * 2 + 2); // Adjust positions based on your preference

        if (i == cursorY && j == cursorX) {
            cmdSetConsoleColour(TEXT_DYellow); // Highlight the cursor position
            printf("%c%c%c",BLOCK,BLOCK,BLOCK); // Print "-" for cursor position
        } else {
            cmdResetConsoleColour();
            if (sudokuArray[i][j] == 0) {
                if (editZeros) {
                    cmdSetConsoleColour(TEXT_Red); // Set the color for editing zeros
                    printf("  "); // Print empty spaces for editing
                } else {
                    printf("  "); // Print empty spaces without editing
                }
            } else {
                if (sudokuArray[i][j] != originalArray[i][j]) {
                    cmdSetConsoleColour(TEXT_Green); // Color for newly edited numbers
                } else {
                    cmdSetConsoleColour(TEXT_Gray);
                }
                printf("%2d", sudokuArray[i][j]);
            }
        }
    }
}
cmdResetConsoleColour(); // Reset color after loop completion

        int key = _getche();
        if (key == KEY_ESC) {
			cmdResetConsoleColour();
			system("cls") ;
            exit(0); // Exit editing mode on escape key press
        }
		
         if(key == R)
			   { 
                   cmdResetConsoleColour();		   
							system("cls") ;
							
							printSudokuArray();
				            break;
				  
			   }
	      if(key == B) 
			   {
					 
							 system("cls") ;
							 vid_Initialize_Game_Frame();
                             Entry_Frame(5);
							u8_MENU_3();
							break;
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
        switch (key) {
            case KEY_UP:
                if (cursorY > 0) {
					
                    cursorY--;
                }
                break;
            case KEY_DOWN:
                if (cursorY < 8) {
                    cursorY++;
                }
                break;
            case KEY_LEFT:
                if (cursorX > 0) {
                    cursorX--;
                }
                break;
            case KEY_RIGHT:
                if (cursorX < 8) {
                    cursorX++;
                }
                break;
            case KEY_ENTER:
               if (userModified[cursorY][cursorX] == 1) {
                    printf("\n\n\nEnter a number: ");
                    int num;
                    scanf("%d", &num);

                    while (num < 1 || num > 9) {
                        printf("\n\n\nEnter a valid number (1-9): ");
                        scanf("%d", &num);
                    }

                    sudokuArray[cursorY][cursorX] = num;
                } else {
                   printf("%c",BELL);
                }
                break;
			case KEY_S:
                
                submitSudokuArray(sudokuArray);
				break;

            default:
                break;
        }
    }
	
}
void printSudokuArray1(void) {
	 
	  
	  
		
int sudokuArray[9][9] = {
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
    {0, 8, 0, 0, 7, 0, 0, 9, 0},
    {6, 0, 2, 0, 0, 0, 5, 0, 0},
    {0, 7, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 5, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 0, 1, 0, 0, 0, 6, 0, 3},
    {0, 5, 0, 0, 2, 0, 0, 8, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0}
    };

    int originalArray[9][9]; // Keep track of original numbers
	int userModified[9][9] = {0};
    int cursorX = 0;
    int cursorY = 0;
    int editZeros = 1;

    // Copy the original array
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            originalArray[i][j] = sudokuArray[i][j];
            if (sudokuArray[i][j] == 0) {
                userModified[i][j] = 1; // Mark cells with zero as user-modified
            }
        }
    }
    
	

    while (1) {
        system("cls");
		Grid();
		
	 
	 u8 MENU_2_[Menu2_Total_OptionsG][Menu2_Opt_LengthG]={"RETRY  (PRESS (R))              NOTE: PRESS ENTER TO INPUT", 
	                                                      "BACK   (PRESS (B))              NOTE: PRESS S TO SUBMIT"};  

	  	  
	  
	  XPos=Menu2_XPosG;
      YPos=Menu2_YPosG;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_2_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu2_Total_OptionsG; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);  
         cmdSetConsoleColour(TEXT_Red);		 
	 	 printf("%s", MENU_2_[MenuOpt_Count]);
	 }
    	
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
        for (u8 i = 0; i < 9; ++i) {
    for (u8 j = 0; j < 9; ++j) {
        cmdGoToXY(j * 4 + 3, i * 2 + 2); // Adjust positions based on your preference

        if (i == cursorY && j == cursorX) {
            cmdSetConsoleColour(TEXT_DYellow); // Highlight the cursor position
            printf("%c%c%c",BLOCK,BLOCK,BLOCK);  // Print "-" for cursor position
        } else {
            cmdResetConsoleColour();
            if (sudokuArray[i][j] == 0) {
                if (editZeros) {
                    cmdSetConsoleColour(TEXT_Red); // Set the color for editing zeros
                    printf("  "); // Print empty spaces for editing
                } else {
                    printf("  "); // Print empty spaces without editing
                }
            } else {
                if (sudokuArray[i][j] != originalArray[i][j]) {
                    cmdSetConsoleColour(TEXT_Green); // Color for newly edited numbers
                } else {
                    cmdSetConsoleColour(TEXT_Gray);
                }
                printf("%2d", sudokuArray[i][j]);
            }
        }
    }
}
cmdResetConsoleColour(); // Reset color after loop completion

        int key = _getche();
        if (key == KEY_ESC) {
			cmdResetConsoleColour();
			system("cls");
            exit(0); // Exit editing mode on escape key press
        }
		
         if(key == R)
			   { 
                   cmdResetConsoleColour();		   
							system("cls") ;
							
							printSudokuArray1();
				            break;
				  
			   }
	      if(key == B) 
			   {
					 
							 system("cls") ;
							 vid_Initialize_Game_Frame();
                             Entry_Frame(5);
							u8_MENU_3();
							break;
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
        switch (key) {
            case KEY_UP:
                if (cursorY > 0) {
					
                    cursorY--;
                }
                break;
            case KEY_DOWN:
                if (cursorY < 8) {
                    cursorY++;
                }
                break;
            case KEY_LEFT:
                if (cursorX > 0) {
                    cursorX--;
                }
                break;
            case KEY_RIGHT:
                if (cursorX < 8) {
                    cursorX++;
                }
                break;
            case KEY_ENTER:
               if (userModified[cursorY][cursorX] == 1) {
                    printf("\n\n\nEnter a number: ");
                    int num;
                    scanf("%d", &num);

                    while (num < 1 || num > 9) {
                        printf("\n\n\nEnter a valid number (1-9): ");
                        scanf("%d", &num);
                    }

                    sudokuArray[cursorY][cursorX] = num;
                } else {
                   printf("%c",BELL);
                }
                break;
			case KEY_S:
                
                submitSudokuArray(sudokuArray);
				break;

            default:
                break;
        }
    }
	
}
void printSudokuArray2(void) {
	 
	  
	  
		
int sudokuArray[9][9] = {
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 8, 5},
    {0, 0, 1, 0, 2, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 7, 0, 0, 0},
    {0, 0, 4, 0, 0, 0, 1, 0, 0},
    {0, 9, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0, 0, 0, 0, 0, 7, 3},
    {0, 0, 2, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 9}
    };

    int originalArray[9][9]; // Keep track of original numbers
	int userModified[9][9] = {0};
    int cursorX = 0;
    int cursorY = 0;
    int editZeros = 1;

    // Copy the original array
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            originalArray[i][j] = sudokuArray[i][j];
            if (sudokuArray[i][j] == 0) {
                userModified[i][j] = 1; // Mark cells with zero as user-modified
            }
        }
    }
    
	

    while (1) {
        system("cls");
		Grid();
		
	 
	 u8 MENU_2_[Menu2_Total_OptionsG][Menu2_Opt_LengthG]={"RETRY  (PRESS (R))              NOTE: PRESS ENTER TO INPUT", 
	                                                      "BACK   (PRESS (B))              NOTE: PRESS S TO SUBMIT"};  

	  	  
	  
	  XPos=Menu2_XPosG;
      YPos=Menu2_YPosG;
      XMINLIMIT= XPos; 	  
	  YMINLIMIT= YPos; 
	  cmdGoToXY(XPos, YPos); 
      cmdSetConsoleColour(TEXT_Red);	
  	  printf("%s", MENU_2_[0]);
  	  cmdResetConsoleColour();
	
	 for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu2_Total_OptionsG; MenuOpt_Count++ )
	 {
	 	 cmdGoToXY(XPos, ++YPos);  
         cmdSetConsoleColour(TEXT_Red);		 
	 	 printf("%s", MENU_2_[MenuOpt_Count]);
	 }
    	
	    YMAXLIMIT=YPos; 
	    YPos= YMINLIMIT;
	    cmdGoToXY(XPos, YPos);
        for (u8 i = 0; i < 9; ++i) {
    for (u8 j = 0; j < 9; ++j) {
        cmdGoToXY(j * 4 + 3, i * 2 + 2); // Adjust positions based on your preference

        if (i == cursorY && j == cursorX) {
            cmdSetConsoleColour(TEXT_DYellow); // Highlight the cursor position
            printf("%c%c%c",BLOCK,BLOCK,BLOCK);  // Print "-" for cursor position
        } else {
            cmdResetConsoleColour();
            if (sudokuArray[i][j] == 0) {
                if (editZeros) {
                    cmdSetConsoleColour(TEXT_Red); // Set the color for editing zeros
                    printf("  "); // Print empty spaces for editing
                } else {
                    printf("  "); // Print empty spaces without editing
                }
            } else {
                if (sudokuArray[i][j] != originalArray[i][j]) {
                    cmdSetConsoleColour(TEXT_Green); // Color for newly edited numbers
                } else {
                    cmdSetConsoleColour(TEXT_Gray);
                }
                printf("%2d", sudokuArray[i][j]);
            }
        }
    }
}
cmdResetConsoleColour(); // Reset color after loop completion

        int key = _getche();
        if (key == KEY_ESC) {
			cmdResetConsoleColour();
			system("cls");
            exit(0); // Exit editing mode on escape key press
        }
		
         if(key == R)
			   { 
                   cmdResetConsoleColour();		   
							system("cls") ;
							
							printSudokuArray2();
				            break;
				  
			   }
	      if(key == B) 
			   {
					 
							 system("cls") ;
							 vid_Initialize_Game_Frame();
                             Entry_Frame(5);
							u8_MENU_3();
							break;
		       }   
			   else
			   {
		 	        /*DO NOTHING*/
			   }	   
        switch (key) {
            case KEY_UP:
                if (cursorY > 0) {
					
                    cursorY--;
                }
                break;
            case KEY_DOWN:
                if (cursorY < 8) {
                    cursorY++;
                }
                break;
            case KEY_LEFT:
                if (cursorX > 0) {
                    cursorX--;
                }
                break;
            case KEY_RIGHT:
                if (cursorX < 8) {
                    cursorX++;
                }
                break;
            case KEY_ENTER:
               if (userModified[cursorY][cursorX] == 1) {
                    printf("\n\n\nEnter a number: ");
                    int num;
                    scanf("%d", &num);

                    while (num < 1 || num > 9) {
                        printf("\n\n\nEnter a valid number (1-9): ");
                        scanf("%d", &num);
                    }

                    sudokuArray[cursorY][cursorX] = num;
                } else {
                   printf("%c",BELL);
                }
                break;
			case KEY_S:
                
                submitSudokuArray(sudokuArray);
				break;

            default:
                break;
        }
    }
	
}
void submitSudokuArray(const int sudokuArray[9][9]) {
    
    if (isSudokuSolution(sudokuArray)) {
		system("cls");
		cmdGoToXY(0,0);
        printMessageInBox("Congratulations! You solved the Sudoku puzzle! PRESS B", 60, 10, 20, 10);
    } else {
		system("cls");
		cmdGoToXY(15,25);
		printMessageInBox("Sorry, the solution is incorrect. Keep trying! PRESS B", 60, 10, 20, 10);
       
		
    }
	int key = _getch();
        if (key == KEY_ESC) {
			cmdResetConsoleColour();
           exit(0); // Exit editing mode on escape key press
        }
}



int isSudokuSolution(const int sudokuArray[9][9]) {
        u16 freq_row[9][10] = {0}; 

    // Check each row
    for (u16 i = 0; i < 9; ++i) {
        for (u16 j = 0; j < 9; ++j) {
            u16 num = sudokuArray[i][j];

           
            if (freq_row[i][num] == 1) {
                return 0; 
            }

            freq_row[i][num] = 1; 
        }
    }

    u16 freq_col[9][10] = {0}; 

    // Check each column
    for (u16 j = 0; j < 9; ++j) {
        for (u16 i = 0; i < 9; ++i) {
            u16 num = sudokuArray[i][j];

            
            if (freq_col[j][num] == 1) {
                return 0;  
            }

            freq_col[j][num] = 1; 
        }
    }

    // Check each 3x3 grid
    for (u16 k = 0; k < 9; k += 3) {
        for (u16 l = 0; l < 9; l += 3) {
            u16 freq_subgrid[10] = {0}; 

            for (u16 i = k; i < k + 3; ++i) {
                for (u16 j = l; j < l + 3; ++j) {
                    u16 num = sudokuArray[i][j];

                   
                    if (freq_subgrid[num] == 1) {
                        return 0; 
                    }

                    freq_subgrid[num] = 1; 
                }
            }
        }
    }

    return 1;
}
void drawRectangularBorder(int width, int height, int startX, int startY) {
    cmdGoToXY(startX, startY);
	cmdSetConsoleColour(TEXT_Blue);
    printf("%c", TTTopLeftCorner);
    
    // Print top border
    for (int i = 0; i < width - 2; ++i) {
        printf("%c", HHH_line);
    }
    
    printf("%c", TTTopRightCorner);
    
    // Print sides
    for (int i = 0; i < height - 2; ++i) {
        cmdGoToXY(startX, startY + i + 1);
        printf("%c", VVV_line);
        cmdGoToXY(startX + width - 1, startY + i + 1);
        printf("%c", VVV_line);
    }
    
    cmdGoToXY(startX, startY + height - 1);
    printf("%c", BBBotLeftCorner);
    
    // Print bottom border
    for (int i = 0; i < width - 2; ++i) {
        printf("%c", HHH_line);
    }
    
    printf("%c", BBBotRightCorner);
	cmdResetConsoleColour();
}

void printMessageInBox(const char* message, int boxWidth, int boxHeight, int boxX, int boxY) {
    drawRectangularBorder(boxWidth, boxHeight, boxX, boxY);
    
    // Calculate the center position for the message
    int messageX = boxX + (boxWidth - strlen(message)) / 2;
    int messageY = boxY + (boxHeight - 2) / 2;
    cmdSetConsoleColour(TEXT_Gray);
    cmdGoToXY(messageX, messageY);
    printf("%s", message);
	cmdResetConsoleColour();
}
void highlightCursor(int x, int y) {
    // ANSI escape code for setting text attributes
    printf("\x1b[7m");  // This sets reverse video (background and foreground color are swapped)

    // Move the cursor to the desired position
    cmdGoToXY(x, y);

    // Print the highlighted content
   

    // Reset text attributes
    printf("\x1b[0m");
}