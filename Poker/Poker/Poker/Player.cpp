#include "Player.h"


Player::Player(std::string name, Card first_card, Card second_card):_name(name), _card_first(first_card), _card_second(second_card)
{
}

std::string Player::GetName()
{
	return _name;
}

Card Player::Get_FirstCard()
{
	return _card_first;
}

Card Player::Get_SecondCard()
{
	return _card_second;
}

int Player::GetScore()
{
	return _score;
}

void Player::SetScore(int value)
{
	_score = value;
}

std::ostream & operator<<(std::ostream & os, Player other)
{
	os << "Name " << other._name << " First card: " << other._card_first << " Second card: " << other._card_second << " Score: " << other._score << std::endl;
	return os;
}
