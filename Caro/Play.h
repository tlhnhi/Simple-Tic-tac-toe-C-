#pragma once

#include "Setup.h"

void GameStart(GameTable table, Position &pointer);
int ExitGame();
int GameMove(GameTable table, Position &pointer, int size, int &turn, char XO[]);
int GameOver(GameTable table, Position pointer, int size);
void Mark(int GOcode, GameTable table, Position pointer, int size);
void Winner(char player[], int size);