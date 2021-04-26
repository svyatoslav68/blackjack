#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class GenericPlayer:public Hand
{
	public:
		GenericPlayer();
		virtual ~GenericPlayer();
		virtual bool isHitting() = 0;
		bool isBusted();
		void Bust();
	private:
		std::string m_name;
};

class Player:public GenericPlayer
{
	public:
		Player();
		bool isHitting() override;
};

class House:public GenericPlayer
{
	public:
		House();
		bool isHitting() override;
};

#endif // PLAYER_H
