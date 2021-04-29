#include <iostream>
#include "player.h"
#include "cards.h"

int main(int argc, char **argv)
{
	House house;
	Player player;
	Card *card = new Card(Card::CLUBS, Card::FOUR);
	card->flip();
	player.Add(card);
	card = new Card(Card::DIAMONDS, Card::QUEEN);
	card->flip();
	player.Add(card);
	std::cout << player<< std::endl;
	card = new Card(Card::SPADES, Card::ACE);
//	card->flip();
	house.Add(card);
	card = new Card(Card::HEARTS, Card::TWO);
	house.Add(card);
	card = new Card(Card::DIAMONDS, Card::ACE);
	house.Add(card);
	house.FlipFirstCard();
	std::cout << house << std::endl;
}
