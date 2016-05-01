/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Dealer class handles everything involving two poker hands
//	i.e. playing against the dealer and dealer behavior
************************************************************************/
#pragma once

#ifndef DEALER_H
#define DEALER_H

#include <vector>

#include "DeckOfCards.h"
#include "HandOf5.h"
#include "Card.h"

using namespace std;

//Forward declaration needed
class HandOf5;

class Dealer{
	private:
		//The three things you need in a game of heads-up poker
		HandOf5& dealer;
		HandOf5& player;
		DeckOfCards& deck;
		
	public:
		Dealer(HandOf5& dealer_, HandOf5& player_, DeckOfCards& deck_);
		void resetDeck();
		void whoWins();
		int dealerSwap();
};

#endif 