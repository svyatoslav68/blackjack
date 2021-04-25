#include <iostream> 
#include <vector>
#include <algorithm>
#include "cards.h"
#include "hand.h"

Hand::Hand()
{

}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card *card)
{
	cards.push_back(card);
}

void Hand::Clear()
{
	auto it = cards.begin();
	while (!cards.empty()){
		delete cards.back();
		cards.pop_back();
	}

}

unsigned int Hand::getValue()
/* Для подсчета очков сначала сортируем карты реверсивно. Тогда
 * тузы будут в конце. Мы их сможем правильно посчитать, в 
 * зависимости от очков, набранных предыдущими картами. */
{
	unsigned int result = 0;
	Sort(true);
	auto it = cards.cbegin();
	while (it < cards.cend()){
		if (((*it)->getValue() == 1) and ((result + 11) < 21))
			result += 11;
		else
			result += (*it)->getValue();
		it++;
	}
	return result;
}

void Hand::display()
{
	if (cards.empty())
		std::cout << "Hand is empty";
	for (auto c : cards){
		c->display();
	}
	std::cout << std::endl;
}

void Hand::OpenAll()
{
	for (auto c : cards){
		c->open();
	}
}

void Hand::Sort(bool reverse)
{
	/*std::cout << "begin = ";
	(*cards.begin())->display();
	std::cout << "end = ";
	(*cards.rbegin())->display();*/
	std::sort(cards.begin(), cards.end(), lessCard);
	if (reverse)
		std::reverse(cards.begin(), cards.end());
}

