#pragma once

#include <conio.h>
#include <iostream>

typedef char GameTable[201][201];
struct Position
{
	int X, Y;
};

char Input();
void GotoXY(int x, int y);
void TextColor(int i);