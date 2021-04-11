#pragma once
#include "Headers.h"
#ifndef __BUFFER_H__
#define __BUFFER_H__

#define SCR_LENGTH 100
static char front_buffer[SCR_LENGTH][SCR_LENGTH];
static char back_buffer[SCR_LENGTH][SCR_LENGTH];

inline void moveCursorTo(const int x, const int y)
{
	const COORD pos = { (SHORT)x, (SHORT)(y) };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
	for (int j = 0; j < SCR_LENGTH; j++)
	{
		for (int i = 0; i < SCR_LENGTH; i++)
		{
			front_buffer[j][i] = '\0';
			back_buffer[j][i] = '\0';
		}
	}
}

inline void render()
{
	for (int j = 0; j < SCR_LENGTH; j++)
	{
		for (int i = 0; i < SCR_LENGTH; i++)
		{
			if (back_buffer[j][i] != front_buffer[j][i])
			{
				moveCursorTo(i, j);

				if (back_buffer[j][i] == '\0')
					printf_s("%c", ' ');
				else
					printf_s("%c", back_buffer[j][i]);
			}
		}
	}
	moveCursorTo(10, 0);
	for (int j = 0; j < SCR_LENGTH; j++)
	{
		for (int i = 0; i < SCR_LENGTH; i++)
		{
			front_buffer[j][i] = back_buffer[j][i];
			back_buffer[j][i] = '\0';
		}
	}
}

#endif // !__BUFFER_H__