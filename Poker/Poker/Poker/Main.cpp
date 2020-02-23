//#include "Player.h"
#include "MainHeader.h"

int main()
{
	CardDesk desk;
	std::vector<Card> cards;
	Card card1(desk.GetCard());

	desk.Shuffle();
	desk.Shuffle();
	desk.Shuffle();
	desk.Shuffle();
	desk.Shuffle();
	desk.Shuffle();





	Player bot("Bot", desk.GetCard(), desk.GetCard());
	for (int i = 0; i < 6; i++)
	{
		cards.push_back(desk.GetCard());
	}
	cards.push_back(card1);
	for (int i = 0; i < 5; i++)
	{

		std::cout << cards[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << bot.Get_FirstCard() << std::endl;
	std::cout << bot.Get_SecondCard() << std::endl;
	std::cout << std::endl;

	std::cout << sort_player_card(cards, bot);



	system("pause");
	return 0;
}