#include "Play.h"

void GameStart(GameTable table, Position &pointer)
{
	pointer.X = 10;
	pointer.Y = 3;
	GotoXY(pointer.X, pointer.Y);
}

int ExitGame()
{
	TextColor(7);
	int d = 0;
	char press;
	do
	{
		system("cls");
		printf("\tDo you really want to end this game?\n\t\t");

		if (!d) printf("%c ", (char)175); else printf("  ");
		printf("End game\n\t\t");
		if (d) printf("%c ", (char)175); else printf("  ");
		printf("Keep playing\n");

		press = Input();
		switch (press)
		{
		case 'D': case 'R': d += 2; break;
		case 'U': case 'L': d -= 2; break;
		case 'X': d = 0;
		}
		if (d < 0) d = 2; else if (d > 2) d = 0;
	} while (press != 'S' && press != 'X');

	return d;
}

int GameMove(GameTable table, Position &pointer, int size, int &turn, char XO[])
{
	char press = Input();
	bool select = false;
	int code = 1;

	switch (press)
	{
	case 'L': pointer.X -= 4; break;
	case 'R': pointer.X += 4; break;
	case 'U': pointer.Y -= 2; break;
	case 'D': pointer.Y += 2; break;
	case 'S': select = true; break;
	default: code = ExitGame();
	} 
	if (code - 1) return code;

	if (pointer.X > size * 4 + 8) pointer.X = 10;
	else if (pointer.X < 10) pointer.X = size * 4 + 6;
	if (pointer.Y > size * 2 + 2) pointer.Y = 3;
	else if (pointer.Y < 3) pointer.Y = size * 2 + 1;

	GotoXY(pointer.X, pointer.Y);

	if (select && table[pointer.Y - 2][pointer.X - 8] == (char)0)
	{
		turn++;
		if (turn % 2) TextColor(11); else TextColor(12);
		printf("%c", XO[turn % 2]);
		table[pointer.Y - 2][pointer.X - 8] = XO[turn % 2];
		GotoXY(pointer.X, pointer.Y);
	}
	return code;
}

int GameOver(GameTable table, Position pointer, int size)
{
	int i, j, ii, jj, count, cell;
	char ch = table[pointer.Y - 2][pointer.X - 8];

	if (ch == 0) return 0;

	//Xet hang doc ----- Code: 1
	i = pointer.Y - 2; j = pointer.X - 8;
	ii = pointer.Y - 2; jj = pointer.X - 8;
	count = 0; cell = 0;
	while (count < 6 && cell < 5)
	{
		if (i >= 0)	if (table[i][j] == ch)
		{
			count++;
			i -= 2;
		}
		if (ii <= 2 * size)	if (table[ii][jj] == ch)
		{
			count++;
			ii += 2;
		}
		if ((i >= 0) && (ii <= 2 * size))
			if (table[i][j] != ch && table[ii][jj] != ch)
			{
				if (count == 6 && table[i][j] != 0 && table[ii][jj] != 0) count++;
				break;
			}
			else; else if ((i < 0) && (ii > 2 * size)) break;
		cell++;
	}
	if (count == 6 ) return 1;

	//Xet hang ngang ----- Code: 2
	i = pointer.Y - 2; ii = pointer.Y - 2;
	count = 0; cell = 0;
	while (count < 6 && cell < 5)
	{
		if (j >= 0) if (table[i][j] == ch)
		{
			count++;
			j -= 4;
		}
		if (jj <= 4 * size) if (table[ii][jj] == ch)
		{
			count++;
			jj += 4;
		}
		if ((j >= 0) && (jj <= 4 * size))
			if (table[i][j] != ch && table[ii][jj] != ch)
			{
				if (count == 6 && table[i][j] != 0 && table[ii][jj] != 0) count++;
				break;
			}
			else; else if ((j < 0) && (jj > 4 * size)) break;
		cell++;
	}
	if (count == 6) return 2;
	
	//Xet hang cheo 1 ----- Code: 3
	j = pointer.X - 8; jj = pointer.X - 8;
	count = 0; cell = 0;
	while (count < 6 && cell < 5)
	{
		if (i >= 0 && j >= 0) if (table[i][j] == ch)
			{
				count++;
				i -= 2; j -= 4;
			}
		if (ii <= 2 * size && jj <= 4 * size) if (table[ii][jj] == ch)
			{
				count++;
				ii += 2; jj += 4;
			}
		if ((i >= 0 && j >= 0)	&& (ii <= 2 * size && jj <= 4 * size))
			if (table[i][j] != ch && table[ii][jj] != ch)
			{
				if (count == 6 && table[i][j] != 0 && table[ii][jj] != 0) count++;
				break;
			}
			else; else if ((i < 0 && j < 0) && (ii > 2 * size && jj > 4 * size)) break;
		cell++;
	}
	if (count == 6) return 3;

	//Xet hang cheo 2 ----- Code: 4
	i = pointer.Y - 2; j = pointer.X - 8;
	ii = pointer.Y - 2; jj = pointer.X - 8;
	count = 0; cell = 0;
	while (count < 6 && cell < 5)
	{
		if (i >= 0 && j <= 4 * size) if (table[i][j] == ch)
			{
				count++;
				i -= 2; j += 4;
			}
		if (ii <= 2 * size && jj >= 0) if (table[ii][jj] == ch)
			{
				count++;
				ii += 2; jj -= 4;
			}
		if ((i >= 0 && j <= 4 * size) && (ii <= 2 * size && jj >= 0))
			if (table[i][j] != ch && table[ii][jj] != ch)
			{
				if (count == 6 && table[i][j] != 0 && table[ii][jj] != 0) count++;
				break;
			}
			else; else if ((i < 0 && j > 4 * size) && (ii > 2 * size && jj < 0)) break;
		cell++;
	}
	if (count == 6) return 4;

	return 0;
}

void Mark(int GOcode, GameTable table, Position pointer, int size)
{
	int i, j, ii, jj, count = 0;
	char ch = table[pointer.Y - 2][pointer.X - 8];
	TextColor(14);

	i = pointer.Y- 2; j = pointer.X - 8;
	ii = pointer.Y - 2; jj = pointer.X - 8;

	switch (GOcode)
	{	
	case 1: //Xet hang doc ----- Code: 1
		while (count < 6)
		{
			if (i >= 0)
				if (table[i][j] == ch)
				{
					GotoXY(j + 8, i + 2);
					printf("%c", ch);
					count++;
				}
			i -= 2;

			if (ii <= 2 * size)
				if (table[ii][jj] == ch)
				{
					GotoXY(jj + 8, ii + 2);
					printf("%c", ch);
					count++;
				}
			ii += 2;
		}
		break;

	case 2: //Xet hang ngang ----- Code: 2
		while (count < 6)
		{
			if (j >= 0)
				if (table[i][j] == ch)
				{
					GotoXY(j + 8, i + 2);
					printf("%c", ch);
					count++;
				}
			j -= 4;

			if (jj <= 4 * size)
				if (table[ii][jj] == ch)
				{
					GotoXY(jj + 8, ii + 2);
					printf("%c", ch);
					count++;
				}
			jj += 4;
		}
		break;

	case 3: //Xet hang cheo 1 ----- Code: 3
		while (count < 6)
		{
			if (i >= 0 && j >= 0)
				if (table[i][j] == ch)
				{
					GotoXY(j + 8, i + 2);
					printf("%c", ch);
					count++;
				}
			i -= 2; j -= 4;

			if (ii <= 2 * size && jj <= 4 * size)
				if (table[ii][jj] == ch)
				{
					GotoXY(jj + 8, ii + 2);
					printf("%c", ch);
					count++;
				}
			ii += 2; jj += 4;
		}
		break;

	case 4: //Xet hang cheo 2 ----- Code: 4
		while (count < 6)
		{
			if (i >= 0 && j <= 4 * size)
				if (table[i][j] == ch)
				{
					GotoXY(j + 8, i + 2);
					printf("%c", ch);
					count++;
				}
			i -= 2; j += 4;

			if (ii <= 2 * size && jj >= 0)
				if (table[ii][jj] == ch)
				{
					GotoXY(jj + 8, ii + 2);
					printf("%c", ch);
					count++;
				}
			ii += 2; jj -= 4;
		}
	}	
}

void Winner(char player[], int size)
{
	GotoXY(size * 4 + 10, 10);
	printf("%s has won the game!!!\n", player);
	GotoXY(size * 4 + 10, 12);
	TextColor(7);
	system("pause");
}