#ifndef CARD_H
#define CARD_H

class Card {
public:
	// este creata o carte "goala"
	Card();

	// constructor ce ajuta la crearea carti, se creeaza culoarea si rangul
	Card(int culoare, int rang);

	// se seteaza cartea la o anumita valoare
	void setCard(int culoare, int rang);

	// retuneaza valoarea carti de joc
	int getValue();

	// afiseaza cartea de joc
	void display();

private:
	int rang;
	int culoare;

};

#endif 