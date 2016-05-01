/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Class Definitions for DeckOfCards
************************************************************************/

#include <vector>
#include <random>
#include <algorithm>

#include "DeckOfCards.h"

using namespace std;

// Initialize standard deck of 52 cards with a nested loop iterating through each face value and suit
DeckOfCards::DeckOfCards(){
	int i, j;
	
	for(i = 2; i < 15; i++){
		for(j = 0; j < 4; j++){
			Card A(i, j);
			deck.push_back(A);
		}
	}
}

// A hand of 5 should not be dealt if the deck is empty -- moreCards does not cover this
int DeckOfCards::getRemaining(){
	return deck.size();
}

// A solid RNG shuffler for a school project
void DeckOfCards::shuffle(){
	srand(time(0));
	random_shuffle(deck.begin(), deck.end());
}

// The card returned to the user is popped from the deck
Card DeckOfCards::dealCard(){
	Card next = deck.back();
	deck.pop_back();
	return next;
}

// Single cards should not be dealt if the deck is empty
bool DeckOfCards::moreCards(){
	if(deck.empty())
		return false;
	else
		return true;
}