#ifndef CARD_H
#define CARD_H

#define NUMBER_VALUE 13
#define NUMBER_SUIT 4

class Card
{
	public:
		enum suits_t {SPADES, HEARTS, CLUBS, DIAMONDS};
		enum cardsvalue_t {	TWO,
							THREE,
							FOUR,
							FIVE,
							SIX,
							SEVEN,
							EIGHT,
							NINE,
							TEN,
							JACK,
							QUEEN,
							KING,
							ACE
							};
		enum states_t {	SHIRT = 0,
						PICTURE = 1
					}; 
		Card(suits_t suit, cardsvalue_t value);
		suits_t getSuit() {return m_suit;}
		unsigned int getValue();
		states_t getState();
		bool flip();
		void open() {m_state = PICTURE;}
		void display();
		bool operator==(Card &op);
	private:
		suits_t m_suit;
		cardsvalue_t m_value;
		states_t m_state;
};

bool lessCard(Card *op1, Card *op2);
#endif // CARD_H
