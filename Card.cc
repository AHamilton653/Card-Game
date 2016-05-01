/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Class Definitions for DeckOfCards
************************************************************************/

#include <string>
#include <iostream>

#include "Card.h"

using namespace std;

// Key for face value and suit representations of cards -- index corresponds to face value
// Index is arbitrary for suits
// JOKER is both the default face value and an offset
// ACE is high version by default, is only low when testing for an ACE low straight
string Card::faces[] = {"JOKER", "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", 
	"NINE", "TEN", "JACK", "QUEEN", "KING", "ACE"};
string Card::suits[] = {"SPADES", "CLUBS", "HEARTS", "DIAMONDS"};

Card::Card(int face_, int suit_) : face(face_), suit(suit_) {}

//Getters -- user cannot set value of data members
int Card::getFace(){
	return face;
}

int Card::getSuit(){
	return suit;
}

// Accesses string array to create string representation of the card
string Card::AtoString(){
	return faces[face]  + " of " + suits[suit];
}

// For the purposes of this program, order of cards is determined by face value
bool Card::operator<(Card const & A) const{
	Card temp = *this;
	return temp.face < A.face;
}

// Need another overloaded comparison
bool Card::operator>(Card const & A) const{
	Card temp = *this;
	return temp.suit > A.suit;
}
