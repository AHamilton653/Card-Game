/************************************************************************
// Author: Alex Hamilton
// Date: 4/30/16
//
// Each card has a face, a suit, and can be represented as a string
************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card{
	private:
		int face;
		int suit;
		
	public:
		static string faces[15];
		static string suits[4];
		Card(int face_ = 0, int suit_ = 0);
		int getFace();
		int getSuit();
		string AtoString();
		bool operator<(Card const & A) const;
		bool operator>(Card const & A) const;
};

#endif