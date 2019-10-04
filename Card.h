#pragma once
#include <string>
using namespace std;
const int SUIT_MAX(4);
const int RANK_MAX(13);
class Card
{
	friend class Deck;
public:
	explicit Card();
	explicit Card(const int& suit, const int& rank);
	string Card2Str() const;
private:
	int generate_suit();
	int generate_rank();
	int get_rank() const;
	int get_suit() const;
	int suit;
	int rank;
};