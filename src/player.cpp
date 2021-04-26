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

/*bool GenericPlayer::isHitting()
{
}*/

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

bool Player::isHitting()
{
	bool result = false;
	return result;
}

House::House()
{

}

bool House::isHitting()
{
	bool result = false;
	return result;
}

