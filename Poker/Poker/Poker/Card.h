#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>

enum Suit { Diamonds, Hearts, Spades, Clubs };
enum Rank { R2, R3, R4, R5, R6, R7, R8, R9, R10, Jack, Queen, King, Ace };

class Card
{
	int _weight;
	Card(int weight) : _weight(weight)
	{
	}
public:
	Card() {
		_weight = 0;
	}
	friend class CardDesk;

	Rank GetRang()
	{
		return Rank(_weight % 13);
	}
	Suit GetSuit()
	{
		return Suit(_weight / 13);
	}

	friend std::ostream & operator<<(std::ostream & os, Card other)
	{
		switch (other._weight / 13)
		{
		case Diamonds:
			os << "Diamonds: ";
			break;
		case Hearts:
			os << "Hearts: ";
			break;
		case Spades:
			os << "Spades: ";
			break;
		case Clubs:
			os << "Clubs: ";
			break;
		}
		switch (other._weight % 13)
		{
		case R2:
		case R3:
		case R4:
		case R5:
		case R6:
		case R7:
		case R8:
		case R9:
		case R10:
			os << other._weight % 13 + 2;
			break;
		case Jack:
			os << "Jack";
			break;
		case Queen:
			os << "Queen";
			break;
		case King:
			os << "King";
			break;
		case Ace:
			os << "Ace";
			break;
		}
		return os;
	}
	bool operator ==(const Card & other)
	{
		return ((this->_weight % 13 == other._weight % 13) && (this->_weight / 13 == other._weight / 13));
		//return ((this->_weight / 13 == other._weight / 13) && (this->_weight % 13 == other._weight % 13));
	}
	std::vector<Card> _vector_table() {
		std::vector<Card> _v(5);
		
		return _v;
	}
};

