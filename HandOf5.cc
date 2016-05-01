/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Class Definitions for HandOf5
************************************************************************/

#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>

#include "HandOf5.h"

using namespace std;

// It is impossible to test improbable scenarios using the constructor for actual gameplay
HandOf5::HandOf5(Card hand_[5]){
	memcpy(hand, hand_, sizeof(hand));
	sortHand();
	high = 0;
	highAux = 0;
	draw = 0;
}

// Hand is initialized with a presumably shuffled deck for actual play
HandOf5::HandOf5(DeckOfCards& deck){
	high = 0;
	highAux = 0;
	draw = 0;
	if(deck.getRemaining() >= 5){
		for(int i = 0; i < 5; i++){
			hand[i] = deck.dealCard();
		}
		sortHand();
	}
	else
		cout << "Not enough cards in deck to make a hand, try with different deck" << endl;
	//possibly try/catch for this?
}

// Card has > overloaded to allow for std::sort
void HandOf5::sortHand(){
	sort(hand, hand + HAND_SIZE);
}

// sort cards
void HandOf5::sortSuit(){
	sort(hand, hand + HAND_SIZE, greater<Card>());
}

// Wrapper for subscript operator on arrays
// This is an alternative for overloading []
Card HandOf5::cardAt(int index){
	return hand[index];
}

// Data member getters
int HandOf5::getHigh(){
	return high;
}

int HandOf5::getHighAux(){
	return highAux;
}

int HandOf5::getDraw(){
	return draw;
}

vector<pair<int, int> > HandOf5::getKickers(){
	return kickers;
}


/***********************************************************************************
// Hand Analysis Functions
// NOTE: Players may have more than 1 hand, but only best will be counted
//	using a switch statement during gameplay - I can avoid
//	differentiating between a pair and a 3 of a kind this way
//
// Kicker - No pari, pair, and two pair need to store tie breakers
// 	ex: AAK62 beats AAQ94 with King kicker
//
// High - Determines the strength of a players hand rank 
//	ex: AAK62 beats KKJ83
//	NOTE: Full house has exceptions
//
// Hands almost never tie, but it is possible
***********************************************************************************/
//Pair is 2 cards with the same face value, such as AA972
bool HandOf5::isPair(){
	int pair = 0;
	kickers.clear();
	
	for(int i = 0; i < HAND_SIZE; i++){
		while(i < HAND_SIZE - 1){
			if(hand[i].getFace() == hand[i + 1].getFace()){
				high = hand[i].getFace();
				pair++;
				i += 2; //skip second card in pair - other pair types do this
			}
			else{
				kick.first = i;
				kick.second = hand[i].getFace();
				kickers.push_back(kick);
				i++; //check next
			}
		}
		if(i < HAND_SIZE){
			kick.first = i;
			kick.second = hand[i].getFace();
			kickers.push_back(kick);
		}
		
	}
	
	if(pair >= 1)
		return true;
	else
		return false;
}

//Two pair is 4 cards with two different sets of cards with matching face values, such as AAKKQ
bool HandOf5::is2Pair(){
	int pairs = 0;
	kickers.clear();
	
	for(int i = 0; i < HAND_SIZE; i++){
		while(i < HAND_SIZE - 1){
			if(hand[i].getFace() == hand[i + 1].getFace()){
				pairs++;
				if(pairs == 1)
					highAux = hand[i].getFace();
				if(pairs == 2)
					high = hand[i].getFace();
				
				i += 2;
			}
			else{
				kick.first = i;
				kick.second = hand[i].getFace();
				kickers.push_back(kick);
				i++; //check next
			}
		}
		if(i < HAND_SIZE){
			kick.first = i;
			kick.second = hand[i].getFace();
			kickers.push_back(kick);
		}
	}
	
	if(pairs == 2)
		return true;
	else
		return false;
}

// Three of a kind is 3 cards with matching face value, such as AAA72
bool HandOf5::is3OfAKind(){
	int pair = 0;
	kickers.clear();
	
	for(int i = 0; i < HAND_SIZE ; i++){
		while(i < HAND_SIZE - 2){
			if(hand[i].getFace() == hand[i + 2].getFace()){
				high = hand[i].getFace(); 
				pair++;
				i += 3;
			}
			else{
				kick.first = i;
				kick.second = hand[i].getFace();
				kickers.push_back(kick);
				i++; //check next
			}
		}
		if(i < HAND_SIZE){
			kick.first = i;
			kick.second = hand[i].getFace();
			kickers.push_back(kick);
		}
	}
	
	if(pair == 1)
		return true;
	else
		return false;
}

// Four of a kind is 4 cards with matching face value, such as AAAA4
bool HandOf5::is4OfAKind(){
	int pair = 0;
	kickers.clear();
	
	for(int i = 0; i < HAND_SIZE; i++){
		while(i < HAND_SIZE - 3){
			if(hand[i].getFace() == hand[i + 3].getFace()){
				high = hand[i].getFace();
				i += 4;
				pair++;
			}
			else{
				kick.first = i;
				kick.second = hand[i].getFace();
				kickers.push_back(kick);
				i++; //check next
			}
		}
		if(i < HAND_SIZE){
			kick.first = i;
			kick.second = hand[i].getFace();
			kickers.push_back(kick);
		}
	}
	
	if(pair == 1)
		return true;
	else
		return false;
}

// A straight contains 5 cards with consecutive face values, such as 45678
bool HandOf5::isStraight(){
	int i = 0;
	int conCount = 0;
	
	//Test the case where Ace is treated as low card
	if(hand[4].getFace() == 14 && hand[3].getFace() == 5){
		while(hand[i].getFace() == (hand[i + 1].getFace() - 1)){
			conCount++;
			if(i == HAND_SIZE - 3)
				break;
			
			i++;
		}
		
		if(conCount == 3){
			high = 14;
			return true;
		}	
		else
			return false;
	}
	else{
		i = 0;
		while(hand[i].getFace() == (hand[i + 1].getFace() - 1)){
			conCount++;
			if(i == HAND_SIZE - 2)
				break;
		
			i++;
		}
		
		if(conCount == 4){
			high = hand[4].getFace();
			return true;
		}	
		else
			return false;
	}
}

// A flush has 5 cards of the same suit, such as AT962s
bool HandOf5::isFlush(){
	sortSuit();
	
	if(hand[0].getSuit() == hand[4].getSuit()){
		sortHand(); //revert sorting
		high = hand[4].getFace();
		return true;
	}
	else{
		sortHand();
		return false;
	}
		
}

//Dealer may need to swap if the following conditions are true
//We don't care about high card because they are not real hands

//4-Staright: four cards to a straight
bool HandOf5::is4Straight(){
	int conCount = 0;
	
	//A 4 straight with no pairs will always be contained within four cards
	//There are two cases for each set of four cards
	for(int i = 0; i < HAND_SIZE - 2; i++){
		if(hand[i].getFace() == hand[i + 1].getFace() - 1)
			conCount++;
	}
	
	//case 1: straight is open-ended
	if(conCount == 3){
		draw = 4;
		return true;
	}
	//case 2: There is a gut-shot
	if(conCount == 2){
		if(hand[0].getFace() == hand[3].getFace() + 4){
			draw = 4;
			return true;
		}
	}
	
	conCount = 0;
	
	for(int i = 1; i < HAND_SIZE - 1; i++){
		if(hand[i].getFace() == hand[i + 1].getFace() - 1)
			conCount++;
	}
	
	//case 1: straight is open-ended
	if(conCount == 3){
		draw = 0;
		return true;
	}
	//case 2: There is a gut-shot
	if(conCount == 2){
		if(hand[1].getFace() == hand[4].getFace() + 4){
			draw = 0;
			return true;
		}
		else
			return false;
	}
	
	return false;
}

//4-flush: hand has 4 cards to a flush
bool HandOf5::is4Flush(){
	sortSuit();
	
	//two cases: 0-3 are the same suit or 1-4 are
	if(hand[0].getSuit() == hand[3].getSuit()){
		draw = 4;
		sortHand();
		return true;
	}
	
	if(hand[1].getSuit() == hand[4].getSuit()){
		draw = 0;
		sortHand();
		return true;
	}
	
	sortHand();
	return false;
}

//Full House: Two matching cards of one face, and three mathcing cards of another
bool HandOf5::isFullHouse(){
	bool house = (is2Pair() && is3OfAKind());
	//find highAux
	if(hand[0].getFace() != getHigh())
		highAux = hand[0].getFace();
	else
		highAux = hand[4].getFace();
	
	return house;
}

//Straight flush: hand is both a straight and a flush
bool HandOf5::isStraightFlush(){
	return (isStraight() && isFlush());
}

//Royal flsuh: an Ace-high straight flush
bool HandOf5::isRoyalFlush(){
	return (isStraightFlush() && getHigh() == 14);
}

//Dealer and user have the ability to swap cards of their choosing
void HandOf5::swapCard(int index, DeckOfCards& deck){
	if(deck.moreCards()){
		hand[index] = deck.dealCard();
	}
	else
		cout << "Deck is empty!" << endl;
}

//Test ranks in descending order
Rank HandOf5::bestRank(){
	Rank rank;
	if(isRoyalFlush())
		return rank = royal_flush;
	else if(isStraightFlush())
		return rank = straight_flush;
	else if(is4OfAKind())
		return rank = four_kind;
	else if(isFullHouse())
		return rank = full_house;
	else if(isFlush())
		return rank = five_flush; 
	else if(isStraight())
		return rank = straight;
	else if(is3OfAKind())
		return rank = three_kind;
	else if(is2Pair())
		return rank = two_pair;
	else if(isPair())
		return rank = one_pair;
	else{
		//Set high and kickers for no pair here
		int i = 0;
		kickers.clear();
		high = hand[4].getFace();
		highAux = hand[3].getFace(); //HighAux is needed here for dealer AI
		for(i = 0; i < HAND_SIZE; i++){
			if(i == 3 && hand[i].getFace() >= 11)
				break;
			
			if(i == 4 && hand[i].getFace() >= 11)
				break;
			
			kick.first = i;
			kick.second = hand[i].getFace();
			kickers.push_back(kick);
		}
		
		return rank = no_pair;
	}
	
}

// Hands are represented in different ways 
//	PAIR of TWOS
//	STAIGHT, EIGHT high
//  TWO PAIR QUEENS and TWOS
string HandOf5::printHand(Rank rank){
	string str;
	
	
	switch(rank){
		case royal_flush:
			str = "ROYAL FLUSH!!! BIG WINNER";
			break;
		case straight_flush:
			str = "STRAIGHT FLUSH: " + Card::faces[getHigh()] + " HIGH";
			break;
		case four_kind:
			if(getHigh() == 6)
				str = "FOUR " + Card::faces[getHigh()] + "ES";
			else
				str = "FOUR " + Card::faces[getHigh()] + "S";
			break;
		case full_house:
			if(getHigh() == 6 && getHighAux() == 6)
				str = "FULL HOUSE: " + Card::faces[getHigh()] + "ES over " + Card::faces[getHighAux()] + "ES";
			else if(getHigh() == 6 && getHighAux() != 6)
				str = "FULL HOUSE: " + Card::faces[getHigh()] + "ES over " + Card::faces[getHighAux()] + "S";
			else if(getHigh() != 6 && getHighAux() == 6)
				str = "FULL HOUSE: " + Card::faces[getHigh()] + "S over " + Card::faces[getHighAux()] + "ES";
			else
				str = "FULL HOUSE: " + Card::faces[getHigh()] + "S over " + Card::faces[getHighAux()] + "S";
			break;	
		case five_flush:
			str = "FLUSH: " + Card::faces[getHigh()] + " HIGH";
			break;
		case straight:
			str = "STAIGHT: " + Card::faces[getHigh() - 4] + " to " + Card::faces[getHigh()];
			break;
		case three_kind:
			if(getHigh() == 6)
				str = "THREE " + Card::faces[getHigh()] + "ES";
			else
				str = "THREE " + Card::faces[getHigh()] + "S";
			break;
		case two_pair:
			if(getHigh() == 6 && getHighAux() == 6)
				str = "TWO PAIR: " + Card::faces[getHigh()] + "ES and " + Card::faces[getHighAux()] + "ES";
			else if(getHigh() == 6 && getHighAux() != 6)
				str = "TWO PAIR: " + Card::faces[getHigh()] + "ES and " + Card::faces[getHighAux()] + "S";
			else if(getHigh() != 6 && getHighAux() == 6)
				str = "TWO PAIR: " + Card::faces[getHigh()] + "S and " + Card::faces[getHighAux()] + "ES";
			else
				str = "TWO PAIR: " + Card::faces[getHigh()] + "S and " + Card::faces[getHighAux()] + "S";
			break;
		case one_pair:
			if(getHigh() == 6)
				str = "PAIR of " + Card::faces[getHigh()] + "ES";
			else
				str = "PAIR of " + Card::faces[getHigh()] + "S";
			break;
		case no_pair:
			str = Card::faces[getHigh()] + " HIGH";
	}
	
	return str;
}
