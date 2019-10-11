#include "Begin.h"


bool Xchosen = false, Ochosen = false;
int d = 1;
char p[2][20], press;

void SelectCharacter()
{
	printf("   Select character:\n");
	if (d) printf("\t%c X\n\t  O\n", (char)175);
	else printf("\t  X\n\t%c O\n", (char)175);
	press = Input();
	if (!Ochosen && !Xchosen)
	{
		switch (press)
		{
		case 'U': case 'L':	case 'D': case 'R':
			d = (d + 1) % 2;
		}
	}
}

void EnterName(int i)
{
	printf("\tPLAYER %d\nName: ", i+1);
	gets_s(p[i]);
}

void Beginning(char p1[], char p2[], int &x)
{
	printf("Use ARROW keys to move.\nPress ENTER to continue.\n\n");
	EnterName(0);
	do
	{
		system("cls");
		printf("Use ARROW keys to move.\nPress ENTER to continue.\n\n");
		printf("\tPLAYER 1\nName: %s\n", p[0]);
		SelectCharacter();
	} while (press != 'S');

	if (d) Ochosen = true; else Xchosen = true;
	d = (d + 1) % 2;

	EnterName(1);
	do
	{
		system("cls");
		printf("Use ARROW keys to move.\nPress ENTER to continue.\n\n");

		printf("\tPLAYER 1\nName: %s\n", p[0]);
		printf("   Select character:\n");
		if (!d) printf("\t%c X\n\t  O\n", (char)175);
		else printf("\t  X\n\t%c O\n", (char)175);

		printf("\tPLAYER 2\nName: %s\n", p[1]);
		SelectCharacter();
	} while (press != 'S');

	for (int i = 0; i < 50; i++)
	{
		p1[i] = p[0][i];
		p2[i] = p[1][i];
	}
	x = (int)Xchosen;
}
