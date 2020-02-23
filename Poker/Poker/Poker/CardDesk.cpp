#include "CardDesk.h"



CardDesk::CardDesk()
{
	_counter = 0;
	for (int i = 0; i <DESK_SIZE; i++)
	{
		_cards[i] = rand() % DESK_SIZE;
	}
}

void CardDesk::Shuffle()
{
	_counter = 0;
	for (int i = 0; i < DESK_SIZE; i++)
	{
		int rnd = rand() % DESK_SIZE;
		std::swap(_cards[i], _cards[rnd]);
	}
}

