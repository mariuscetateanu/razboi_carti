#ifndef CARDS_H
#define CARDS_H

#include<iostream>
#include <vector>
#include <stdint.h>
#include <cstdint>
using namespace std;

enum suits { diamond, club, heart, spade };
const unsigned int rank_max = 13;
class Card
{
public:
	Card();
	Card(const Card& orig);
	Card(suits sv, unsigned int rv);
	~Card();
	Card& operator=(const Card& rhs);
	unsigned int GetRank() ;
	suits GetSuit() ;
	void SetRank(unsigned int rv);
	void SetSuit(suits sv);
	void Insert(ostream& out) const;
private:
	unsigned int rank;
	suits suit;
};
ostream& operator<< (ostream& out, const Card& aCard);

class Deck
{
public:
	Deck();
	Deck(const Deck& orig);
	~Deck();
	Deck& operator=(const Deck& rhs);
	void shuffle();
	bool isEmpty() ;
	Card draw();
private:
	vector<Card> cards; 
};
class Player
{
public:
	Player(Deck& aDeck);
	Player(const Player& orig);
	~Player();
	Player& operator=(const Player& rhs);
	Card draw();
	void addPoints(int howMany);
	int score() ;
	void replaceCard(Deck& aDeck);
private:
	Player();
private:
	vector<Card> myCards;
	int myScore;
	static const int  hand_size;
};
#endif // CARDS_H

