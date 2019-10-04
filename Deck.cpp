#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include <algorithm>
using namespace std;
Deck::Deck() {
	for (unsigned int i = 0; i < SUIT_MAX; i++) {
		for (unsigned int j = 0; j < RANK_MAX; j++) {
			Card card(i, j);
			deck.push_back(card);
		}
	}
}

void Deck::print_Deck() const {
	unsigned int count = 1;
	for (auto i : deck) {
		cout << i.Card2Str() << "  ";
		if (count == 13) {
			cout << endl;
			count = 0;
		}
		count++;
	}
	cout << endl;
}

void Deck::getOneCard() {
	Card cd(deck.back().get_suit(), deck.back().get_rank());
	deck.pop_back();
	cout << cd.Card2Str() << endl;
}
///Card trick function--------------------------------------------------
void Deck::deck21Show() {
	for (int i = 0; i < 21; i++) {
		cout << showpoint << fixed;
		cout << deck21[i].Card2Str() << "  ";
	}
}
void Deck::print_Deck21() const {
	int count = 0;
	for (unsigned int i = 0; i < 21; i++) {
		cout << setw(4) << showpoint << fixed << deck21[i].Card2Str();
		count++;
		if (count % 3 == 0) {
			cout << endl << endl;
		}
	}
}

vector<int> Deck::random() {
	srand(time(NULL));
	vector<int>rand;
	for (unsigned int i = 0; i < 52; i++) {
		rand.push_back(i);
	}
	random_shuffle(rand.begin(), rand.end());
	return rand;
}

void Deck::deckOf21() {
	srand(time(nullptr));
	vector<int>index;
	for (unsigned int i = 0; i < 21; i++) {
		index = random();
		deck21.push_back(deck[index[i]]);
	}
}

void Deck::col() {
    c1.clear();
	c2.clear();
	c3.clear();
	for (unsigned int i = 0; i < 21; i++) {
		if (i % 3 == 0)
			c1.push_back(deck21[i]);
		if (i % 3 == 1)
			c2.push_back(deck21[i]);
		if (i % 3 == 2)
			c3.push_back(deck21[i]);
	}
}

void Deck::rearranged21(int choice) {
	deck21.clear();
	switch (choice) {
	case 1:
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c2[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c1[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c3[i]);
		}
	case 2:
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c1[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c2[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c3[i]);
		}
	case 3:
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c1[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c3[i]);
		}
		for (unsigned int i = 0; i < 7; i++) {
			deck21.push_back(c2[i]);
		}
	}
}

void Deck::possArr(int n, int round) {
	switch (round) {
	case 1:
		switch (n) {
		case 1:
			for (int i = 0; i < 7; i++) {
				ans.push_back(c1[i]);
			}
			break;
		case 2:
			for (int i = 0; i < 7; i++) {
				ans.push_back(c2[i]);
			}
			break;
		case 3:
			for (int i = 0; i < 7; i++) {
				ans.push_back(c3[i]);
			}
			break;
		}
		break;
	case 2:
		switch (n) {
		case 1:
			for (int i = 0; i < 7; i++) {
				ans2.push_back(c1[i]);
			}
			break;
		case 2:
			for (int i = 0; i < 7; i++) {
				ans2.push_back(c2[i]);
			}
			break;
		case 3:
			for (int i = 0; i < 7; i++) {
				ans2.push_back(c3[i]);
			}
			break;
		}
		break;
	case 3:
		switch (n) {
		case 1:
			for (int i = 0; i < 7; i++) {
				ans3.push_back(c1[i]);
			}
			break;
		case 2:
			for (int i = 0; i < 7; i++) {
				ans3.push_back(c2[i]);
			}
			break;
		case 3:
			for (int i = 0; i < 7; i++) {
				ans3.push_back(c3[i]);
			}
			break;
		}
	}
}

void Deck::selectedCard() {
	for (unsigned int i = 0; i < 7; i++) {
		for (unsigned int t = 0; t < 7; t++) {
			for (unsigned int j = 0; j < 7; j++) {
				if ( ans[i].Card2Str() == ans2[t].Card2Str() && ans2[t].Card2Str() == ans3[j].Card2Str()) {
					choice = ans[i];
					
				}
			}
		}
	}
	cout << endl;
	cout << " Here is what you thought: " << choice.Card2Str() << endl;
}