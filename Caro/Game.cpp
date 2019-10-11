#include "Begin.h"
#include "Table.h"
#include "Play.h"

GameTable table;
Position pointer;
char player[2][20];
int x, turn = 0, play = 1, size, GOcode;

int main()
{
	Beginning(player[0], player[1], x);
	char XO[2];
	if (x) { XO[0] = 'X'; XO[1] = 'O'; }
	else { XO[0] = 'O'; XO[1] = 'X'; }

	EnterN(size);
	BuildTable(size, table);
	DrawTable(player[0], player[1], table, size, XO);

	GameStart(table, pointer);

	while (play)
	{
		GotoXY(size * 4 + 10, 10);
		TextColor(14);
		printf("It's %s's turn.%10c", player[turn % 2], ' ');
		GotoXY(pointer.X, pointer.Y);
		
		play = GameMove(table, pointer, size, turn, XO);

		if (play == 2)
		{
			DrawTable(player[0], player[1], table, size, XO);
			GotoXY(pointer.X, pointer.Y);
			play = 1;
			continue;
		}

		GOcode = GameOver(table, pointer, size);
		if (GOcode)
		{
			play = 0;
			Mark(GOcode, table, pointer, size);
			Winner(player[(turn + 1) % 2], size);
		}
		if (turn == size*size)
		{
			GotoXY(size * 4 + 10, 10);
			printf("GAME DRAW!!!!\n");
			GotoXY(size * 4 + 10, 12);
			TextColor(7);
			system("pause");
			play = 0;
		}
	}
	return 0;
}