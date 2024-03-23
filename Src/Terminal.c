#include "../Inc/Terminal.h"

u8 Terminal_GetUserPush(void)
{
	u8 lu8KeyRead =0;
	if(224 == (lu8KeyRead =getch())) // or -32 but s8 Var
	{
		lu8KeyRead = getch();
	}else{	} 	
	//printf("Return = %c | %d | 0x%0.2X------\n",lu8KeyRead,lu8KeyRead,lu8KeyRead);
	return lu8KeyRead;
}

u8 Terminal_Switch_UpDown(u8 *apu8Switch, u8 au8MaxLimit)
{	// Every Switch must start from 1
	u8 lu8KeyRead = Terminal_GetUserPush();
	if(lu8KeyRead == TERMKEY_DownArrow)
	{
		*apu8Switch+=1;
		if(*apu8Switch > au8MaxLimit)
		{
			*apu8Switch =1;
		}else{	}
	}else{	}
	if(lu8KeyRead == TERMKEY_UPArrow)
	{
		*apu8Switch-=1;
		if(*apu8Switch == 0)
		{
			*apu8Switch = au8MaxLimit;
		}else{	}
	}else{	}
	return lu8KeyRead;
	//printf("Switch = %d\n", *apu8Switch);
}

void Terminal_GetString(u8 *apu8Str, u8 au8StrSize)
{
	cmdSetConsoleColour(TEXT_Green);
	fflush(stdin);fgets(apu8Str, au8StrSize, stdin);
	cmdResetConsoleColour();
	u8 Count =0;
	for(Count=0; Count<au8StrSize; Count++)
	{
		if(apu8Str[Count] == '\n')
		{
			apu8Str[Count] = '\0'; break;
		}else{	}
	}
}

u8 TermValid_NameString(u8 *apu8Str, u8 au8StrSize, u8 au8MinLen)
{
	u8 RetVal =0; u8 Count =0;
	for(Count=0; Count<au8StrSize; Count++)
	{
		if(apu8Str[Count] == '\0')
		{	
			Count++; break;
		}else{	}
	}
	//printf("Count = %d\n", Count);
	if(Count <au8MinLen || Count >(au8StrSize-1))
	{
		RetVal =1; // Not Valid
	}else{
		RetVal =0; // Valid
	}
	return RetVal;
}

u8 TermValid_CheckStrRepeat(u8 au8AllowRepeat, u8 *apu8String, u8 au8StrSize)
{
	u8 i =0;
	u8 RepeatedCharFlag =0;
	for(i=0; i<au8StrSize; i++)
	{
		if(apu8String[i] == '\0')
		{
			break;
		}
		else{
			if(apu8String[i] == apu8String[i+1])
			{
				RepeatedCharFlag++; // 0, 1, ..., (AllowRepeat-1)
				if(RepeatedCharFlag ==(au8AllowRepeat-1))
				{
					RepeatedCharFlag++;
					break;
				}else{	}
			}
			else{	
				RepeatedCharFlag =0;
			}
		}
	}
	//printf("RepeatedCharFlag = %d\n", RepeatedCharFlag);
	return RepeatedCharFlag;
}

void Terminal_Getu8Num_Dec(u8 *apu8Num)
{
	s8 ls8ScanFlag =0;
	cmdSetConsoleColour(TEXT_Sky);
	//printf("Enter : ");
	fflush(stdin);
	ls8ScanFlag = scanf("%d", apu8Num); cmdResetConsoleColour();
	if(ls8ScanFlag == 1) // Valid Number
	{}else{ // Non-Valid
		*apu8Num = -1;
	}
}

void Terminal_Getu16Num_Dec(u16 *apu16Num)
{
	s8 ls8ScanFlag =0;
	cmdSetConsoleColour(TEXT_Sky);
	//printf("Enter : ");
	fflush(stdin);
	ls8ScanFlag = scanf("%d", apu16Num); cmdResetConsoleColour();
	if(ls8ScanFlag == 1) // Valid Number
	{}else{ // Non-Valid
		*apu16Num = -1;
	}
}

void Terminal_Getu32Num_Dec(u32 *apu32Num)
{
	// 000F FFFF FFFF FFFF
	// 4503 5996 2737 0495
	s8 ls8ScanFlag =0;
	cmdSetConsoleColour(TEXT_Sky);
	//printf("Enter : ");
	fflush(stdin);
	ls8ScanFlag = scanf("%d", apu32Num); cmdResetConsoleColour();
	if(ls8ScanFlag == 1) // Valid Number
	{}else{ // Non-Valid
		*apu32Num = -1;
	}//printf("ScanFlag :%d \n", ls8ScanFlag);
}


void Terminal_Getf32Num_Float(f32 *apf32Num)
{
	s8 ls8ScanFlag =0;
	cmdSetConsoleColour(TEXT_Green);
	//printf("Enter : ");
	fflush(stdin);
	ls8ScanFlag = scanf("%f", apf32Num); cmdResetConsoleColour();
	if(ls8ScanFlag == 1) // Valid Number
	{}else{ // Non-Valid
		*apf32Num = -1;
	}//printf("ScanFlag :%d \n", ls8ScanFlag);
}