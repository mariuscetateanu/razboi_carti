#include <algorithm>
 #include <vector>
 #include <cassert>
using namespace std;
 #include "cards.h"
#include "random.h"
void main()
{
	Deck theDeck;
	theDeck.shuffle();
	Player player1 (theDeck); 
	Player player2(theDeck);
	bool done = false;
	while (!done)
	{
		Card card1 = player1.draw();
		cout << " Player 1 plays " <<card1 << endl;
		Card card2 = player2.draw();
		cout << " Player 2 plays " <<card2 << endl;

		if (card1.GetRank() == card2.GetRank())
		{
			//tie
			player1.addPoints(1);
			player2.addPoints(1);
			cout << " Playerstie " << endl;
		}
		else if (card1.GetRank() > card2.GetRank())
		{
			player1.addPoints(2);
			cout << " Player1 wins round " << endl;
		}
		else
		{
			player2.addPoints(2);
			cout << " Player2 wins round " << endl;
		}
		done = theDeck.isEmpty();
		if (!done) player1.replaceCard(theDeck);
		done = theDeck.isEmpty();
		if (!done)  player2.replaceCard(theDeck);
		
	}
	cout << " Player 1 score " << player1.score() << endl;
	cout << " Player 2 score " << player2.score() << endl;
}