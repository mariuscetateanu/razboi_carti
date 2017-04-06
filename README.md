#include <iostream>
using namespace std;
#include "Pachet.h";
#include "Card.h";
#include <ctime>;
#include <stdlib.h>

//constructor pentru crearea pachetului de carti

// constructor which creates a deck of 52 cards
Deck este inlocuit cu Pachet
Pachet::Pachet()
{
	size = 52;
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			storage[counter].setCard(i, j);
			counter++;
		}
	}
}

//se impart cartile
Card Pachet::deal()
{
	size--;
	//storage[size].getValue();
	Card card1 = storage[size];
	return card1;
}


// se amesteca cartile in pachet
void Deck::amesteca()
{
	srand(time(0));
	int a, b;

	for (int i = 0; i < size; i++) {
		a = rand() % size;
		b = rand() % size;

		Card c1 = storage[a];
		storage[a] = storage[b];
		storage[b] = c1;
	}

}

//se numara cartile ramase in pachet
int Deck::cardsLeft()
{
	return size;
}

//arata paachetul de  carti
void Deck::displayPachet()
{
	for (int i = 0; i < size; i++) {
		storage[i].display();
	}
}
