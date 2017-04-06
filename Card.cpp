#include <iostream>
using namespace std;
#include "Card.h";
#include <string>

// este creata o carte "goala"
Card::Card()
{
	rang;
	culoare;
}

// constructor ce ajuta la crearea carti, se creeaza culoarea si rangul
Card::Card(int s, int r)
{
	rang = r;
	culoare = s;
}

// se seteaza cartea la o anumita valoare
void Card::setCard(int s, int r)
{
	rang = r;
	culoare = s;
}

// retuneaza valoarea carti de joc
int Card::getValue()
{
	return rang;
}

// afiseaza cartea
void Card::display()
{
	string displayString;
	displayString.append("   ");

	string displayDesign;

	switch (rang) {
	case 11: displayString.append("Jack");
		break;
	case 12: displayString.append("Queen");
		break;
	case 13: displayString.append("King");
		break;
	case 1: displayString.append("Ace");
		break;
	default: displayString.append(to_string(rang));
		break;
	}

	displayString.append(" of ");

	switch (culoare) {
	case 0: displayString.append("Spades");
		switch (rang) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[    10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + to_string(rang) + "      ]\n[   *   ]\n[  * *  ]\n[ ***** ]\n[*  *  *]\n[   *   ]\n[      " + to_string(rang) + "]\n -------\n");
			break;
		}
		break;

	case 1: displayString.append("Hearts");
		switch (rang) {
		case 10: displayDesign.append("\n -------\n[" + to_string(rang) + "     ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[     " + to_string(rang) + "]\n -------\n");
			break;
		case 11: displayDesign.append("\n -------\n[J      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12: displayDesign.append("\n -------\n[Q      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13: displayDesign.append("\n -------\n[K      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1: displayDesign.append("\n -------\n[A      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      A]\n -------\n");
			break;
		default: displayDesign.append("\n -------\n[" + to_string(rang) + "      ]\n[ ** ** ]\n[*  *  *]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      " + to_string(rang) + "]\n -------\n");
			break;
		}
		break;
	case 2: displayString.append("Diamonds");
		switch (rang) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[     10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + to_string(rang) + "      ]\n[   *   ]\n[  * *  ]\n[ *   * ]\n[  * *  ]\n[   *   ]\n[      " + to_string(rang) + "]\n -------\n");
			break;
		}
		break;
	case 3: displayString.append("Clubs");
		switch (rang) {
		case 10:
			displayDesign.append("\n -------\n[10     ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   * 10]\n -------\n");
			break;
		case 11:
			displayDesign.append("\n -------\n[J      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  J]\n -------\n");
			break;
		case 12:
			displayDesign.append("\n -------\n[Q      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  Q]\n -------\n");
			break;
		case 13:
			displayDesign.append("\n -------\n[K      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  K]\n -------\n");
			break;
		case 1:
			displayDesign.append("\n -------\n[A      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  A]\n -------\n");
			break;
		default:
			displayDesign.append("\n -------\n[" + to_string(rang) + "      ]\n[   *   ]\n[*  *  *]\n[  ***  ]\n[   *   ]\n[   *   ]\n[   *  " + to_string(rang) + "]\n -------\n");
			break;
		}
		break;
	}

	cout << displayString
		<< displayDesign << endl;



}
