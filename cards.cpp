#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <stdint.h>
using namespace std;
#include "cards.h"
#include "random.h"
Card::Card():rank(1), suit(spade)
{
	
}
Card::Card(suits sv, unsigned int rv) :rank(rv),  suit(sv)
{

}

Card::Card(const Card& orig) : rank(orig.rank), suit(orig.suit)
{

} 
Card:: ~Card()
{

}
Card& Card :: operator =(const Card& rhs)
{
	if (this != &rhs)
	{
		rank = rhs.rank;
		suit = rhs.suit;
	}
	return *this;
}
unsigned int Card :: GetRank() 
{
	return rank;
}



void Card::SetRank(unsigned int rv)
{
	assert ((rv > 0) && (rv <= rank_max));
	rank = rv;
}

suits Card::GetSuit() 
{
	return suit;
}
void Card::SetSuit(suits sv)
{
	suit = sv;
}
void Card::Insert(ostream& out) const
{
	switch (rank) {
	case 1: out << "Ace"; break;
	case 11: out << " Jack "; break;
	case 12: out << "Queen"; break;
	case 13: out << "King "; break;
	default: // output number
		out << rank; break;
	}
	switch (suit)
	{
	case diamond: out << " of Diamonds"; break;
	case spade: out << " of Spades "; break;
	case heart: out << " of Hearts "; break;
	case club: out << " of Clubs "; break;
	}
}
ostream& operator<< (ostream& out, const Card& aCard)
{
	aCard.Insert(out);
	return out;
}
Deck::Deck()
{
	for (int i = 1; i <= rank_max; i++)
	{
		Card c1(diamond, i);
		Card c2(spade, i);
		Card c3(heart, i);
		Card c4(club, i);
		 cards.push_back(c1);
		 cards.push_back(c2);
		 cards.push_back(c3);
		 cards.push_back(c4);
	}
}
Deck::Deck(const Deck& orig)
{
	operator=(orig);

}
Deck:: ~Deck()
{

}
 Deck& Deck::operator=(const Deck& rhs)
{
	 if (this != &rhs)
	{
		cards = rhs.cards;
	}
	return  *this;
}

void Deck::shuffle()
{
	 randomInteger randfunc;
	 random_shuffle(cards.begin(), cards.end(), randfunc);

}
bool Deck::isEmpty() 
{
	return (cards.size() == 0);
}
Card Deck::draw()
{
	assert(!isEmpty());
	Card retval(spade, 1);
	if (!isEmpty())
	{
		retval = cards.back();
		cards.pop_back();
	}
	return retval;
}
const int Player::hand_size = 3;
Player::Player(Deck& aDeck) :myScore(0)
{
	for (int i = 0; i < hand_size; i++)
	{
		assert (!aDeck.isEmpty());
		myCards.push_back(aDeck.draw());

	}
}
Player::Player(const Player& orig) : myCards(orig.myCards), myScore(orig.myScore)
{

}
Player:: ~Player()
{

}

Player& Player :: operator= (const Player& rhs)
{
	if (this !=&rhs)
	{
		myCards = rhs.myCards;
		myScore = rhs.myScore;
	}
	return  *this;
}
Card Player::draw()
{
	assert(myCards.size() > 0);
	randomInteger randomizer;
	int removedCard = randomizer(myCards.size());
	Card drawn_card = myCards[removedCard];
	myCards[removedCard] = myCards.back();
	myCards.pop_back();
	return drawn_card;
}
void Player::addPoints(int howMany)
{
	myScore += howMany;
}
int Player::score() 
{
	return myScore;
}
void Player::replaceCard(Deck& aDeck)
{
	assert(!aDeck.isEmpty());
	myCards.push_back(aDeck.draw());
}