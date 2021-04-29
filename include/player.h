#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class GenericPlayer:public Hand
{
	public:
		GenericPlayer();
		virtual ~GenericPlayer() override ;
		virtual bool IsHitting() const = 0;
		bool isBusted();
		void Bust();
		std::string getName() const  {return m_name;}
	private:
		std::string m_name;
};

class Player:public GenericPlayer
{
	public:
		Player();
		~Player() override {};
		bool IsHitting() const override ;
		void Win() const; 
		void Lose() const;
};

class House:public GenericPlayer
{
	public:
		House();
		~House() {};
		bool IsHitting() const override;
		void FlipFirstCard();
};

#endif // PLAYER_H
