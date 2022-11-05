#pragma once
#include "card.h"

class Board
{
public:
	Card m_cardArray[16];
	Board();
	~Board();
	void game();
	void populate();
	void shuffle();
	void draw(int sel);
	int pickCard();
	bool checkWin();
};