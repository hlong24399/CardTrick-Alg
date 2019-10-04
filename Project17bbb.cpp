#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <algorithm>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main() {
	srand(time(NULL));
	Deck deck;
	int choice{};
	deck.deckOf21();
	deck.deck21Show();
	cout << endl;
	cout << " Choose your card and save it in your mind. " << endl;
	cout << " Hit enter so that I will be able to start the trick " << endl;
	system("pause");
	for (int i = 1; i < 4; i++) {
		deck.col();
		deck.print_Deck21();
		cout << " Which column that has your card ? ";
		cin >> choice;
		deck.possArr(choice,i);
		deck.rearranged21(choice);
	}
	cout << " Give me one sec....... " << endl;
	Sleep(1000);
	cout << " . " << endl;
	Sleep(1000);
	cout << " . " << endl;
	Sleep(1000);
	cout << " . " << endl;
	cout << " Tadaaaaaaaaaa  ";
	deck.selectedCard();
	return 0;
}


