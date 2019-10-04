#include <iostream>
#include <iomanip>
#include <string>
#include "Card.h"
using namespace std;
const string SUIT[SUIT_MAX] = { "S", "H", "D", "C" };
const string RANK[RANK_MAX] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

Card::Card() {
	suit = generate_suit();
	rank = generate_rank();
}

Card::Card(const int& suit, const int& rank) : suit(suit), rank(rank) {}

int Card::generate_suit() {
	return rand() % (SUIT_MAX - 1);
}

int Card::generate_rank() {
	return rand() % (RANK_MAX - 1);
}

string Card::Card2Str() const {
	return SUIT[get_suit()] + RANK[get_rank()];
}

int Card::get_suit() const {
	return suit;
}

int Card::get_rank() const {
	return rank;
}


