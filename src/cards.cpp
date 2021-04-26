#include <iostream>
#include <string>
#include "cards.h"

Card::Card(suits_t suit, cardsvalue_t value):m_suit(suit), m_value(value), m_state(SHIRT)
{
}

unsigned int Card::getValue()
{
	switch (m_value){
		case ACE:
			return 1;
		case TWO:
			return 2;
		case THREE:
			return 3;
		case FOUR:
			return 4;
		case FIVE:
			return 5;
		case SIX:
			return 6;
		case SEVEN:
			return 7;
		case EIGHT:
			return 8;
		case NINE:
			return 9;
		case TEN:
		case JACK:
		case QUEEN:
		case KING:
			return 10;
		default:
			return 0;
	}
}

Card::states_t Card::getState()
{
	return m_state;
}

bool Card::flip()
{
	m_state = static_cast<states_t>(!static_cast<bool>(m_state));
	return m_state;
}

void Card::display()
/* На консоль выводится значение карты. Для отображения масти используются символы
 * в коде UTF-8. Все хорошо работает на Linux-консоли в локали ru_RU.UTF-8*/
{
	if (m_state == SHIRT)
		std::cout << "**|";
	else {
		std::string picture_suit;
		std::string picture_value;
		switch (m_value){
			case TWO:
			case THREE:
			case FOUR:
			case FIVE:
			case SIX:
			case SEVEN:
			case EIGHT:
			case NINE:
			case TEN:
				std::cout << getValue();
				break;
			case JACK:	
				std::cout << "J";
				break;
			case QUEEN:	
				std::cout << "Q";
				break;
			case KING:	
				std::cout << "K";
				break;
			case ACE:	
				break;
			default:
				std::cout << "**";
		}
		switch (m_suit) {
			case SPADES:
				picture_suit = "\u2660";
				break;
			case HEARTS:
				picture_suit = "\u2665";
				break;
			case CLUBS:
				picture_suit = "\u2663";
				break;
			case DIAMONDS:
				picture_suit = "\u2666";
				break;
		}
		std::cout << picture_suit << "|";
	}
}

bool Card::operator==(Card &op)
{
	return ((this->m_suit == op.m_suit) && (this->m_value == op.m_value));
}

bool lessCard(Card *op1, Card *op2)
/* Функция необходима для алгоритма сортировки. Работает очевидно. */
{
	if (op1->getValue() == op2->getValue())
		return static_cast<int>(op1->getSuit()) < static_cast<int>(op2->getSuit());
	return (op1->getValue() < op2->getValue());
}

std::ostream &operator<<(std::ostream &s, Card &c)
{
	if (c.getState() == Card::SHIRT){
		s << "**|";
		return s;
	}
	else {
		switch (c.getValue()) {
			case Card::TWO:
			case Card::THREE:
			case Card::FOUR:
			case Card::FIVE:
			case Card::SIX:
			case Card::SEVEN:
			case Card::EIGHT:
			case Card::NINE:
			case Card::TEN:
				s << c.getValue();
				break;
			case Card::JACK:	
				s << "J";
				break;
			case Card::QUEEN:	
				s << "Q";
				break;
			case Card::KING:	
				s << "K";
				break;
			case Card::ACE:	
				break;
			default:
				s << "**";
		}
		switch (c.getSuit()) {
			/* Выводим изображение мастей, используя
			utf-8 коды этих изображений */
			case Card::SPADES:
				s << "\u2660";
				break;
			case Card::HEARTS:
				s << "\u2665";
				break;
			case Card::CLUBS:
				s << "\u2663";
				break;
			case Card::DIAMONDS:
				s << "\u2666";
				break;
		}
		s << "|";
		return s;
	}
}

