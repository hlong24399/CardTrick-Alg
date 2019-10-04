#pragma once
#include "Card.h"
#include <vector>
using namespace std;
class Deck {
public:
	explicit Deck();
	void print_Deck() const;
	void getOneCard();
	void print_Deck21() const;
	void deckOf21();
	vector<int> random();
	void col();
	void rearranged21(int);
	void deck21Show();
	void possArr(int,int);
	void selectedCard();
private:
	vector<Card>deck;
	vector<Card>deck21;
	vector<Card>c1;
	vector<Card>c2;
	vector<Card>c3;
	vector<Card>ans;
	vector<Card>ans2;
	vector<Card>ans3;
	Card choice{};
};

