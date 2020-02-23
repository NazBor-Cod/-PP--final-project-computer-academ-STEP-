#pragma once
#include "Card.h"

const int DESK_SIZE = 52;

class CardDesk
{
	int _cards[DESK_SIZE];
	int _counter;
public:
	CardDesk();
	void Shuffle();
	Card GetCard()
	{
		_counter++;
		if (_counter == DESK_SIZE);
			//Shuffle();
		return Card(_cards[_counter]);
	}
};

