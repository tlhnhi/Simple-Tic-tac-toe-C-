#include "Table.h"

void EnterN(int &n)
{
	system("cls");
	printf("Table size nxn (5 < n <= 50)\n");
	do
	{
		printf("Enter n: ");
		scanf("%d", &n);
	} while (n <= 5 || n > 50);
}

void BuildTable(int size, GameTable table)
{
	int s4 = 4 * size, s2 = 2 * size;
	int i, j;

	for (i = 0; i <= s2; i++)
		for (j = 0; j <= s4; j++)
			table[i][j] = 0;

	for (i = 0; i <= size; i++)
	{
		for (j = 0; j <= size; j++) table[2 * i - 1][4 * j] = 179;
		for (j = 0; j <= s4; j++)
			table[2 * i][j] = (j % 4) ? 196 : 197;
	}
	for (i = 1; i <= size; i++)
	{
		table[i * 2][0] = 195;
		table[i * 2][s4] = 180;
	}
	for (i = 1; i <= size; i++)
	{
		table[0][4 * i] = 194;
		table[s2][4 * i] = 193;
	}
	table[0][0] = 218; table[0][s4] = 191;
	table[s2][0] = 192; table[s2][s4] = 217;
}

void DrawTable(char p1[], char p2[], GameTable table, int size, char XO[])
{
	system("cls");
	printf("\n\n");
	for (int i = 0; i <= 2 * size; i++)
	{
		printf("\t");
		for (int j = 0; j <= 4 * size; j++)
		{
			if (table[i][j] == XO[1]) TextColor(11);
			else if (table[i][j] == XO[0]) TextColor(12);
			printf("%c", table[i][j]);
			if (table[i][j] == XO[1] || table[i][j] == XO[0])
				TextColor(7);
		}
		printf("\n");
	}
	GotoXY(size * 4 + 10, 3);
	printf("Use ARROW keys to move.\n");
	GotoXY(size * 4 + 10, 4);
	printf("Press SPACEBAR or ENTER to play.\n");
	GotoXY(size * 4 + 10, 5);
	printf("Press any other keys to EXIT.\n");

	GotoXY(size * 4 + 10, 7);
	TextColor(11);
	printf("PLAYER 1: %s (%c)\n", p1, XO[1]);
	GotoXY(size * 4 + 10, 8);
	TextColor(12);
	printf("PLAYER 2: %s (%c)\n", p2, XO[0]);
}