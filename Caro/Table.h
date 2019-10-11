#pragma once

#include <stdio.h>
#include "Setup.h"

void EnterN(int &n);
void BuildTable(int size, GameTable table);
void DrawTable(char p1[], char p2[], GameTable table, int size, char XO[]);