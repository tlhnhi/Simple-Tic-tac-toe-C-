#include "Setup.h"
#include <Windows.h>


char Input()
{
	char button;
	if (!_kbhit())
	{
		int press = _getch();
		if (press == 224)
			switch (_getch())
			{
			case 75: button = 'L'; break; //LEFT arrow
			case 77: button = 'R'; break; //RIGHT arrow
			case 72: button = 'U'; break; //UP arrow
			case 80: button = 'D'; break; //DOWN arrow
			}
		else if (press == (int)' ' || press == 13) button = 'S'; //Select
		else button = 'X'; //Exit
	}
	return button;
}

void GotoXY(int x, int y)
{
	COORD position = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void TextColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}