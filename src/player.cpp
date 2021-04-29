#include <iostream>
#include <vector>
#include "cards.h"
#include "hand.h"
#include "player.h"

GenericPlayer::GenericPlayer()
{
}

GenericPlayer::~GenericPlayer()
{

}

bool GenericPlayer::isBusted()
{
	return (getValue() > 21);
}

void GenericPlayer::Bust()
{
	std::cout << "Player " << m_name << " has BUST!!!\n";
}

std::ostream &operator<<(std::ostream &s, GenericPlayer &p)
{
	//std::cout << "Player " << getName() << ": \n";
	for (auto card_ptr: p.getCards()){
		s << *card_ptr;
	}
	s << "\t" << '(' << p.getValue() << ')' << std::endl;
	return s;
}

Player::Player()
{
}

bool Player::IsHitting() 
{
	std::cout << getName() << " request next card?\n";
	bool result = false;
	std::cin >> result; 
	return result;
}

void Player::Win() const 
{
	std::cout << "Player " << getName() << " is winer!!!\n";
}

void Player::Lose() const 
{
	std::cout << "Player " << getName() << " is loser.\n";
}

void Player::Push() const 
{
	std::cout << "Player " << getName() << " Push.\n";
}

House::House()
{

}

bool House::IsHitting() 
{
	bool result = false;
	if (getValue() > 16)
		result = true;
	return result;
}

void House::FlipFirstCard()
{
	std::vector<Card *> tmp_cards = getCards();
	tmp_cards[tmp_cards.size() -1]->flip();
}
