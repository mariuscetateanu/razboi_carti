#include "Card.h";
#ifndef PACHET_H
#define PACHET_H


class Pachet {

public:
	// constructor pentru crearea  pachetului de carti
	Pachet();

	// imparte carte jucatorului
	Card deal();

	// se amesteca cartile in pachetului
	void amesteca();

	//se numara cartile ramase
	int cardsLeft();

	//se arata pachetul;
	void displayPachet();
	
private:
	Card storage[52];
	int size;

};


#endif