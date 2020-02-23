#include "MainHeader.h"

std::vector<Card> card_sort(std::vector <Card> cards)//сортирует масив карт по рангу от 0 до макс 
{
	Card tmp0;
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (cards[i].GetRang() > cards[i + 1].GetRang())
			{
				tmp0 = cards[i];
				cards[i] = cards[i + 1];
				cards[i + 1] = tmp0;
			}
		}
	}
	return cards;
}

int sort_player_card(std::vector<Card> cards, Player other)
{
	Card tmp1, tmp2;
	int switcher1 = 0, switcher2 = 0;
	cards = card_sort(cards);
	for (int i = 0; i < 5; i++)
	{
		if (other.Get_FirstCard().GetSuit() == cards[i].GetSuit() && cards[i].GetSuit() == cards[i + 1].GetSuit())//проверка на масть 
			switcher1++;
		if (other.Get_SecondCard().GetSuit() == cards[i].GetSuit() && cards[i].GetSuit() == cards[i + 1].GetSuit())//проверка на масть 
			switcher2 ++;
	}
	if (switcher1+switcher2>=6)//если масть 2 карт одинаковая значит в масив встиамив 2 карты
	{
		for (int i = 0; i < 5; i++)
		{
			if (other.Get_FirstCard().GetRang() > cards[i].GetRang() && switcher1)
			{
				cards.push_back(other.Get_FirstCard());
				cards = card_sort(cards);
				switcher1 = 0;
			}
			if (other.Get_SecondCard().GetRang() > cards[i].GetRang() && switcher2)
			{		
				cards.push_back(other.Get_SecondCard());
				cards = card_sort(cards);
				switcher1 = 0;
			}
		}
		return check_score_oneSuit(cards);
	}
	else if (switcher1 == 4)//если 1 карта сходиться с 4 мастями значит она подходит 
	{
		for (int i = 0; i < 5; i++)
		{
			if (other.Get_FirstCard().GetRang() < cards[i].GetRang() && switcher1)
			{
				cards.push_back(other.Get_FirstCard());
				cards = card_sort(cards);
				break;				
			}
		}
		return check_score_oneSuit(cards);
	}
	else if (switcher2 == 4)//если 2 карта сходиться с 4 мастями значит она подходит 
	{
		for (int i = 0; i < 5; i++)
		{
			if (other.Get_FirstCard().GetRang() < cards[i].GetRang() && switcher1)
			{
				cards.push_back(other.Get_SecondCard());
				cards = card_sort(cards);
				break;
			}
		}
		return check_score_oneSuit(cards);
	}
	else if (switcher1 < 4 && switcher2 < 4)
	{
		return check_score_allSuit(cards, other);
	}
	return 0;
}

int check_score_oneSuit(std::vector <Card> cards)//проверка на комбинации карт с одной мастью
{
	int sum = 0, cheker;
	for (int i = 1; i < 5; i++)
	{
		sum += cards[i].GetRang();
	}
	if (sum == 60)
	{
		return 100;
	}
	else
	{
		for (int i = 1; i < 4; i++)
		{
			if (cards[i].GetRang() == (cards[i].GetRang() + 1))
				cheker = 1;
			else
			{
				cheker = 0;
				break;
			}
		}
		if (cheker)
			return 90;
		else
			return 60;
	}
}
int stret_cheak_1(std::vector<Card> cards, Player other)
{
	int sum = 0;
	cards.push_back(other.Get_FirstCard());
	cards = card_sort(cards);
	for (int i = 0; i < 5; i++)
	{
		if ((cards[i].GetRang() + 1) == (cards[i + 1].GetRang()))
		{
			sum += 10;
		}
		else
		{
			sum = 0;
			break;
		}
	}
		return sum;
}
int stret_cheak_2(std::vector<Card> cards, Player other)
{
	int sum = 0;
	cards.push_back(other.Get_SecondCard());
	cards = card_sort(cards);
	for (int i = 0; i < 5; i++)
	{
		if ((cards[i].GetRang() + 1) == (cards[i + 1].GetRang()))
		{
			sum += 10;
		}
		else
		{
			sum = 0;
			break;
		}
	}
	return sum;
}
int stret_cheak_3(std::vector<Card> cards, Player other)
{
	int sum = 0;
	cards.push_back(other.Get_SecondCard());
	cards = card_sort(cards);
	cards.push_back(other.Get_FirstCard());
	cards = card_sort(cards);
	for (int i = 0; i < 5; i++)
	{
		if ((cards[i].GetRang() + 1) == (cards[i + 1].GetRang()))
		{
			sum += 10;
		}
		else
		{
			sum = 0;
			break;
		}
	}
	return sum;
}

int check_score_allSuit(std::vector<Card> cards, Player other)//проверка на комбинации с разной мастью 
{
	int sum = 0, sum1 = 0;
	if (other.Get_FirstCard().GetRang() == other.Get_SecondCard().GetRang())//пара на руках 
	{
		sum += 20;
		for (int i = 1; i < 6; i++)//сколько одноранговых карт в колоде 
		{
			if (cards[i].GetRang() == other.Get_FirstCard().GetRang())
			{
				sum += 10;
			}
		}
		if (sum == 40)//каре 
		{
			return 80;
		}
		else if (sum == 30)
		{
			return 40;
		}
		return 20;
	}
	for (int i = 0; i < 5; i++)//если нет пары на руках 
	{
		if (other.Get_FirstCard().GetRang() == cards[i].GetRang())
			sum += 10;
		else if (other.Get_SecondCard().GetRang() == cards[i].GetRang())
			sum1 += 10;
	}
	if (sum == 20 || sum1 == 20)
		return 40;
	else if ((sum == 30 && sum1 == 20) || (sum == 20 && sum1 == 30))//проверка на фулл-хаус
		return 70;
	else if (sum == 30 || sum1 == 30)//каре при 1 карте на руке 
		return 80;
	else if (sum == 10 && sum1 == 10)//две пары
		return 30;
	else
	{
		if (stret_cheak_1(cards, other))
			return stret_cheak_1(cards, other);
		else if (stret_cheak_2(cards, other))
			return stret_cheak_2(cards, other);
		else if (stret_cheak_3(cards, other))
			return stret_cheak_3(cards, other);
		else 
			for (int i = 0; i < 5; i++)
			{
				if (other.Get_FirstCard() == cards[i])//проверка на старшую карту 
				{
					std::cout << other.Get_FirstCard();
					std::cout << cards[i];
					std::cout << std::endl;
				}
			}
		return 0;
	}
}
