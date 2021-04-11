#pragma once
#include "Headers.h"

#ifndef __BUFFER_H__
#define __BUFFER_H__

#define SCR_LENGTH 1024	
static char front_buffer[SCR_LENGTH][SCR_LENGTH];
static char back_buffer[SCR_LENGTH][SCR_LENGTH];
extern bool g_bColorCheck;

static HANDLE hOut;
static CONSOLE_CURSOR_INFO cInfo;

inline void moveCursorTo(const int x, const int y, const int Color = 7)
{
	/* Èò»ö   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  */
	/* ÃÊ·Ï»ö SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);  */
	/* »¡°£»ö SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);  */
	const COORD pos = { (SHORT)x, (SHORT)(y) };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	/*cInfo.dwSize = 1;
	cInfo.bVisible = FALSE;*/
}

inline void drawToBackBuffer(const int i, const int j)
{
	back_buffer[j][i] = 'o';
}
inline void drawfrontBuffer(const int i, const int j)
{
	front_buffer[j][i] = '\0';
}

inline void Clearbuff()
{
	moveCursorTo(0, 0);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cInfo.dwSize = 1;
	cInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cInfo);
	for (int j = 0; j < SCR_LENGTH; j++)
	{
		for (int i = 0; i < SCR_LENGTH; i++)
		{
			front_buffer[j][i] = '\0';
			back_buffer[j][i] = '\0';
		}
	}
}

inline void render(bool* iCheck, int Green, int iSize)
{
	for (int j = 0; j < iSize; j++)
	{
		for (int i = 0; i < iSize; i++)
		{
			if (g_bColorCheck)
			{
				if (back_buffer[j] != front_buffer[j])
				{
					if (j == Green)
						moveCursorTo(i, j, 2);
					else if (iCheck[j] == true)
						moveCursorTo(i, j, 4);
					else
						moveCursorTo(i, j, 7);
					// moveCursorTo(i, j, 7);
					if (back_buffer[j][i] == '\0')
						printf_s("%c", ' ');
					else
						printf_s("%c", back_buffer[j][i]);
				}
			}
			else
			{
				if (back_buffer[j][i] != front_buffer[j][i])
				{
					moveCursorTo(i, j, 7);
					if (back_buffer[j][i] == '\0')
						printf_s("%c", ' ');
					else
						printf_s("%c", back_buffer[j][i]);
				}
			}
			
		}
	}
	moveCursorTo(10, 0);
	for (int j = 0; j < iSize; j++)
	{
		for (int i = 0; i < iSize; i++)
		{
			front_buffer[j][i] = back_buffer[j][i];
			back_buffer[j][i] = '\0';
		}
	}
}

#endif // !__BUFFER_H__