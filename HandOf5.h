/************************************************************************
// Author: Alex Hamilton
// Date: 4/30/16
//
// This class handles everything related to a single 5-card poker hand
************************************************************************/


#ifndef HANDOF5_H
#define HANDOF5_H

#include <vector>

#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

const int HAND_SIZE = 5;

typedef enum Hand_Rank{no_pair = 0, one_pair, two_pair, three_kind, straight, five_flush, full_house, four_kind, straight_flush, royal_flush}Rank;

class HandOf5{
	private:
		Card hand[5]; //Hand has fixed size of 5 and needs to be accessed often, therefore array is best
		int high; //Highest card in made hand
		int highAux; //Two pair and full house have two highs
		int draw; //index of Card to be drawn for 4-flush/straight scenarios
		vector<pair<int, int> > kickers; //first = index | second = face
		pair<int, int> kick; //transitional pair for pushing kickers
		
	public:
		HandOf5(Card hand_[5]);
		HandOf5(DeckOfCards& deck);
		Card cardAt(int index);
		int getHigh();
		int getHighAux();
		int getDraw();
		vector<pair<int, int> > getKickers();
		void sortHand();
		void sortSuit();
		
		bool isPair();
		bool is2Pair();
		bool is3OfAKind();
		bool is4OfAKind();
		bool isStraight();
		bool isFlush();
		bool is4Straight();
		bool is4Flush();
		bool isFullHouse();
		bool isStraightFlush();
		bool isRoyalFlush();
		
		void swapCard(int index, DeckOfCards& deck);
		Rank bestRank();
		string printHand(Rank rank);
};

#endif