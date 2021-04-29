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

Player::Player()
{

}

bool Player::IsHitting() const
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

House::House()
{

}

bool House::IsHitting() const
{
	bool result = false;
	return result;
}

void House::FlipFirstCard()
{
}
