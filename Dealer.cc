/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Definitions of Dealer functions
************************************************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

#include "Dealer.h"

using namespace std;

//Initialized with the two hands needed to play
Dealer::Dealer(HandOf5& dealer_, HandOf5& player_, DeckOfCards& deck_) : dealer(dealer_), player(player_), deck(deck_) {}

void Dealer::resetDeck(){
	DeckOfCards tempDeck;
	tempDeck.shuffle();
	deck = tempDeck;
}

// Series of nested conditional statements to decide winner of the round
void Dealer::whoWins(){
	int same = 0;
	Rank dealerRank = dealer.bestRank();
	Rank playerRank = player.bestRank();
	string dealerString = dealer.printHand(dealerRank);
	string playerString = player.printHand(playerRank);
	
	//Trivial case where players don't even have the same hand rank
	if(dealerRank != playerRank){
		if(dealerRank > playerRank){
			cout << "Dealer wins with " + dealerString << endl;
		}
		else{
			cout << "Player wins with " + playerString << endl;
		}
	}
	//Players have the same hand rank
	else{
		//NOTE: the highest kicker in no pair is stored in highAux
		if(dealer.getHigh() == player.getHigh() && dealer.getHighAux() != player.getHighAux()){
			//case where highAux should break a two pair tie
			if(dealerRank == two_pair){
				if(dealer.getHighAux() > player.getHighAux()){
					cout << "Dealer wins with " + dealerString << endl;
				}
				else{
					cout << "Player wins with " + playerString << endl;
				}
			}
			//Only other rank where highAux != 0 is no pair and full house
			//However, full house has a 3 of a kind, so it will never get here
			else{
				if(dealer.getHighAux() > player.getHighAux()){
					cout << "Dealer wins with " + dealerString + " (" + Card::faces[dealer.getHighAux()] + " KICKER)"<< endl;
				}
				else{
					cout << "Player wins with " + playerString + " (" + Card::faces[player.getHighAux()] + " KICKER)"<< endl;
				}
			}
			
		}
		//Players have the same hand rank, but one is stronger
		else{
			if(dealer.getHigh() != player.getHigh()){
				if(dealer.getHigh() > player.getHigh()){
					cout << "Dealer wins with " + dealerString << endl;
				}
				else{
					cout << "Player wins with " + playerString << endl;
				}
			}
			//Final case: round must be decided using one or more kickers
			else{
				//find largest index in kickers that is 
				vector<pair<int, int> > v1 = dealer.getKickers();
				vector<pair<int, int> > v2 = player.getKickers();
				same = v1.size() - 1;
				
				for(int i = v1.size() - 1; i >= 0; i--){
					if(v1[i].second != v2[i].second)
						break;
					
					same--;
				}
				
				//A winner can be decided
				if(same != -1){
					if(v1[same].second > v2[same].second){
						cout << "Dealer wins with " + dealerString + " (" + Card::faces[v1[same].second] + " KICKER)" << endl;
					}
					else{
						cout << "Player wins with " + playerString + " (" + Card::faces[v2[same].second] + " KICKER)" << endl;
					}
				}
				//A tie must be declared
				else{
					cout << "Tie! Pot is split!" << endl;
				}
			}
		}
	}
}

/****************************************************************************************
// dealerSwap:
// 
// Dealer swaps cards using a simplified Jacks or Better strategy found
//     here -> http://www.gamblersbookcase.com/Video-Poker-Jacks-or-Better-Strategy.htm
// 
// There are a few modifications that will make it perform better in the short term
//     i.e. 20 games. Also, the goal is to beat the dealer, not get the best payout
//
// Thusly, the dealer will not attempt to get a straight flush or royal flush with three
//     cards. Likewise, 4-flushes/straight will not draw if it throws away a high pair
*****************************************************************************************/
int Dealer::dealerSwap(){
	Rank rank = dealer.bestRank();
	int swapped = 0;
	
	switch(rank){
		//hold everything better than 3 of a kind
		//Always discard kickers
		case three_kind:{
			vector<pair<int, int> > v = dealer.getKickers();
			for(auto it = v.begin(); it != v.end(); it++){
				dealer.swapCard(it->first, deck);
				swapped++;
			}
			break;
		}	
		//Always discard kicker for full house
		case two_pair:{
			vector<pair<int, int> > v = dealer.getKickers();
			dealer.swapCard(v[0].first, deck);
			swapped++;
			break;
		}
		case one_pair:{
			//Always keep high pair and discard kickers
			if(dealer.getHigh() >= 11){
				vector<pair<int, int> > v = dealer.getKickers();
				for(auto it = v.begin(); it != v.end(); it++){
					dealer.swapCard(it->first, deck);
					swapped++;
				}
			}
			//Low pair will draw a four-flush, but not a straight
			//NOTE: This is the same as also drawing for straight/royal flush
			else{
				if(dealer.is4Flush()){
					dealer.swapCard(dealer.getDraw(), deck);
					swapped++;
				}
				else{
					vector<pair<int, int> > v = dealer.getKickers();
					for(auto it = v.begin(); it != v.end(); it++){
						dealer.swapCard(it->first, deck);
						swapped++;
					}
				}
			}
			break;
		}
		case no_pair:{
			//Always draw 4straights and 4flushes
			if(dealer.is4Straight() || dealer.is4Flush()){
				dealer.swapCard(dealer.getDraw(), deck);
				swapped++;
			} //test flush second
				
			else{
				//Draw 3 if there are 2 high cards
				if(dealer.getHigh() >= 11 && dealer.getHighAux() >= 11){
					vector<pair<int, int> > v1 = dealer.getKickers();
					for(auto it = v1.begin(); it != v1.end(); it++){
						dealer.swapCard(it->first, deck);
						swapped++;
					}
				}
				//Draw 4 if there is one high card
				else if(dealer.getHigh() >= 11 && dealer.getHighAux() < 11){
					vector<pair<int, int> > v = dealer.getKickers();
					for(auto it = v.begin(); it != v.end(); it++){
						dealer.swapCard(it->first, deck);
						swapped++;
					}
				}
				//Draw 5 if there are no high cards
				else{
					vector<pair<int, int> > v = dealer.getKickers();
					for(auto it = v.begin(); it != v.end(); it++){
						dealer.swapCard(it->first, deck);
						swapped++;
					}
				}
			}
		}
	}
	
	dealer.sortHand();
	return swapped;
}