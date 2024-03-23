#include "../Inc/ShapeDraw.h"

void ShapeDraw_Percentage(u8 au8SqXPos, u16 au16SqYPos, u8 au8Total, u8 au8PercentX)
{
	u8 Count =0;
	u8 lu8Amount = (au8PercentX*au8Total)/100;
	f32 lf32Incrementer = (1/(f32)au8Total)*100;
	f32 lf32IncTemp =0;
	
	cmdGoToXY(au8SqXPos, au16SqYPos);
	cmdSetConsoleColour(TEXT_Pink);
	for(Count=0; Count<lu8Amount+1; Count++)
	{
		if(lf32IncTemp <= 50)
		{// 0xB0 | 176 | ░
			printf("%c", 0xB0);
		}else if(lf32IncTemp <=100)
		{// 0xB1 | 177 | ▒
			printf("%c", 0xB1);
		}else{	}
		
		lf32IncTemp +=(lf32Incrementer);
		cmdGoToXY(au8SqXPos +Count, au16SqYPos);
	} 
	cmdResetConsoleColour();
}

void ShapeDraw_BarCode(u8 au8SqXPos, u16 au16SqYPos, u8 au8BarCodeSize, u32 au32ID)
{
	u8 Count =0;
	u32 lu32TempMod = 0;
	u32 lu32TempArg = au32ID;
	for(Count=0; Count<au8BarCodeSize; Count++)
	{
		cmdGoToXY(au8SqXPos+Count, au16SqYPos);
		lu32TempMod = lu32TempArg % 10;
		lu32TempArg = lu32TempArg / 10;
		if(lu32TempMod <= 3)
		{// 0xB0 | 176 | ░
			printf("%c", 0xB0);
		}else if(lu32TempMod <= 6)
		{// 0xB1 | 177 | ▒
			printf("%c", 0xB1);
		}else{// 0xB2 | 178 | ▓
			printf("%c", 0xB1);
		}		
		if(au8BarCodeSize>10 && lu32TempArg ==0)
		{
			lu32TempArg = au32ID;
		}else{	}
		// ▒░▒░░▒░▒▒░▒░▒░░▒░▒▒░▒░▒░░▒	5000 101
		// ░░▒▒░▒▒▒▒░░░▒▒░▒▒▒▒░░░▒▒░▒   5000 100
		// ░░▒▒░▒▒▒▒░   10
		// ░░▒▒░▒▒▒▒░   10
		// ░░▒▒░▒       6		
	}
}

void ShapeDraw_Line(u8 au8SqXPos, u16 au16SqYPos, u8 au8Width, u16 au16Height) 
{
	u8 i =0;
	if(0 == au8Width) // V - Line
	{
		for(i=0; i<au16Height; i++)
		{
			cmdGoToXY(au8SqXPos, au16SqYPos +i);
			printf("%c", V_LINE);
		} 
	}else if(0 == au16Height) // H -Line
	{
		for(i=0; i<au8Width; i++)
		{
			cmdGoToXY(au8SqXPos +i, au16SqYPos);
			printf("%c", H_LINE);
		} 
	}else{	}
}

 
void ShapeDraw_Square(u8 au8SqXPos, u16 au16SqYPos, u8 au8Width, u16 au16Height)
{
	u16 i =0;
	for(i=1; i<au8Width+1; i++)
	{
		cmdGoToXY(au8SqXPos +i, au16SqYPos);
		printf("%c", H_LINE);
		cmdGoToXY(au8SqXPos +i, au16SqYPos+au16Height);
		printf("%c", H_LINE);
	} 
	for(i=1; i<au16Height; i++)
	{
		cmdGoToXY(au8SqXPos, au16SqYPos+i);
		printf("%c", V_LINE);
		cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos+i);
		printf("%c", V_LINE);
	}
	cmdGoToXY(au8SqXPos, au16SqYPos);
	printf("%c", CORNER_TOPLEFT); 
	cmdGoToXY(au8SqXPos, au16SqYPos+au16Height);
	printf("%c", CORNER_BOTLEFT);
	cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos);
	printf("%c", CORNER_TOPRIGHT);
	cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos+au16Height);
	printf("%c", CORNER_BOTRIGHT);
}

void ShapeDraw_FoldSquare(u8 au8SqXPos, u16 au16SqYPos, u8 au8Width, u16 au16Height)
{
	u16 i =0;
	for(i=0; i<=au8Width+1; i++)
	{
		cmdGoToXY(au8SqXPos +i, au16SqYPos);
		printf("%c", FOLDED_MIDDOWN);
		cmdGoToXY(au8SqXPos +i, au16SqYPos+au16Height);
		printf("%c", FOLDED_MIDUP);
	} 
	for(i=1; i<au16Height; i++)
	{
		cmdGoToXY(au8SqXPos, au16SqYPos+i);
		printf("%c", FOLDED_LEFT);
		cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos+i);
		printf("%c", FOLDED_RIGHT);
	}
}

void ShapeDraw_CenterSquare(u8 au8SqXPos, u16 au16SqYPos, u8 au8Width, u16 au16Height)
{
	u32 lu32XPos = (CMD_UNITESCREEN_WI/2) - (au8Width/2);
	u32 lu32YPos = (CMD_UNITESCREEN_HE/2) - (au16Height/2);
	if(0 == au8SqXPos && 0 != au16SqYPos)
	{
		ShapeDraw_Square(lu32XPos, au16SqYPos, au8Width, au16Height);
	}else if(0 != au8SqXPos && 0 == au16SqYPos) 
	{
		ShapeDraw_Square(au8SqXPos, lu32YPos, au8Width, au16Height);
	}else if(0 == au8SqXPos && 0 == au16SqYPos) 
	{
		ShapeDraw_Square(lu32XPos, lu32YPos, au8Width, au16Height);
	}else{	}
}