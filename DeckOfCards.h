/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// This class determines the behaviors of a deck containing each valid 
//	card
************************************************************************/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include <ctime>

#include "Card.h"

using namespace std;

class DeckOfCards{
	private:
		vector<Card> deck;
		int currentCard; //Next card to deal
		
	public:
		DeckOfCards();
		int getRemaining();
		void shuffle();
		Card dealCard();
		bool moreCards();
};

#endif