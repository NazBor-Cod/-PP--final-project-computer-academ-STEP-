#pragma once
#include "CardDesk.h"


class Player
{
	std::string _name; 
	Card _card_first;
	Card _card_second;
	int _score;	
public:
	Player(std::string name, Card first_card, Card second_card);
	
	std::string GetName();
	Card Get_FirstCard();
	Card Get_SecondCard();
	int GetScore();
	void SetScore(int value);

	friend std::ostream& operator<<(std::ostream& os, Player tmp);
};

