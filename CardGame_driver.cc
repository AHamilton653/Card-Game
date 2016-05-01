/************************************************************************
// Author: Alex Hamilton
// Date:  4/30/16
//
// Driver program for card game
************************************************************************/
#include <iostream>
#include <vector>

#include "Card.h"
#include "DeckOfCards.h"
#include "HandOf5.h"
#include "Dealer.h"

using namespace std;

int main(int argc, char* argv[]){
	DeckOfCards deck1;
	
	/////////////////////////////////////////////////////////////--Testing phase 1
	cout << "----------------------------------------Phase 1: Shuffle and deal a deck" << endl;
	cout << "Print unshuffled deck:" << endl << endl;
	//print unshuffled deck
	while(deck1.moreCards()){
		Card c1 = deck1.dealCard();
		cout << c1.AtoString() << endl;
	}
	
	cout << endl << "------------------------------------------------------------" << endl << endl;
	
	DeckOfCards deck2;
	deck2.shuffle();
	
	cout << "Print shuffled deck:" << endl << endl;
	//print shuffled deck
	while(deck2.moreCards()){
		Card c2 = deck2.dealCard();
		cout << c2.AtoString() << endl;
	}
	//////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////--Testing phase 2
	cout << "--------------------------------Phase 2: Determine strength of hand" << endl;
	DeckOfCards deck3;
	deck3.shuffle();
	HandOf5 h(deck3);
	
	cout << "Analyze a random hand:" << endl << endl;
	//print hand from shuffled deck
	for(int i = 0; i < 5; i++){
		Card c3 = h.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	
	//Analyze a random hand using all functions -- this can confirm that ranks are false when they should be
	cout << "This hand has a pair: " << boolalpha << h.isPair() << endl;
	cout << "This hand has two pair: " << boolalpha << h.is2Pair() << endl;
	cout << "This hand has three of a kind: " << boolalpha << h.is3OfAKind() << endl;
	cout << "This hand has four of a kind: " << boolalpha << h.is4OfAKind() << endl;
	cout << "This hand has a straight: " << boolalpha << h.isStraight() << endl;
	cout << "This hand has a flush: " << boolalpha << h.isFlush() << endl;
	cout << "This hand has 4 to a straight: " << boolalpha << h.is4Straight() << endl;
	cout << "This hand has 4 to a flush: " << boolalpha << h.is4Flush() << endl;
	cout << "This hand has a full house: " << boolalpha << h.isFullHouse() << endl;
	cout << "This hand has a straight flush: " << boolalpha << h.isStraightFlush() << endl;
	cout << "This hand has a royal flush: " << boolalpha << h.isRoyalFlush() << endl;
	
	cout << endl << "------------------------------------------------------------" << endl << endl;
	
	cout << "Test an example of each hand rank:" << endl << endl;
	//Test two pair
	Card twoP[5] = {Card(14, 0), Card(10, 1), Card(2, 3), Card(2, 1), Card(14, 2)};
	HandOf5 twoPair(twoP);
	
	for(int i = 0; i < 5; i++){
		Card c3 = twoPair.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has two pair: " << boolalpha << twoPair.is2Pair() << endl << endl;
	
	//Test three of a kind
	Card threeK[5] = {Card(14, 0), Card(10, 1), Card(14, 2), Card(2, 1), Card(14, 2)};
	HandOf5 threeKind(threeK);
	
	for(int i = 0; i < 5; i++){
		Card c3 = threeKind.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout  << endl << "This hand has three of a kind: " << boolalpha << threeKind.is3OfAKind() << endl << endl;
	
	//Test four of a kind
	Card fourK[5] = {Card(14, 0), Card(14, 1), Card(14, 2), Card(10, 3), Card(14, 2)};
	HandOf5 fourKind(fourK);
	
	for(int i = 0; i < 5; i++){
		Card c3 = fourKind.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has four of a kind: " << boolalpha << fourKind.is4OfAKind() << endl << endl;
	
	//Test Straight - A low
	Card str81[5] = {Card(5, 0), Card(4, 1), Card(3, 2), Card(2, 3), Card(14, 2)};
	HandOf5 straight1(str81);
	
	for(int i = 0; i < 5; i++){
		Card c3 = straight1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a straight: " << boolalpha << straight1.isStraight() << endl << endl;
	
	//Test Straight - A high
	Card str82[5] = {Card(14, 0), Card(12, 1), Card(13, 2), Card(11, 3), Card(10, 2)};
	HandOf5 straight2(str82);
	
	for(int i = 0; i < 5; i++){
		Card c3 = straight2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a straight: " << boolalpha << straight2.isStraight() << endl << endl;
	
	//Test Flush
	Card fl[5] = {Card(5, 2), Card(9, 2), Card(3, 2), Card(11, 2), Card(10, 2)};
	HandOf5 flush(fl);
	
	for(int i = 0; i < 5; i++){
		Card c3 = flush.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a flush: " << boolalpha << flush.isFlush() << endl << endl;
	
	//Test 4-Straight
	Card s4[5] = {Card(5, 0), Card(9, 1), Card(12, 2), Card(11, 2), Card(10, 3)};
	HandOf5 straight4(s4);
	
	for(int i = 0; i < 5; i++){
		Card c3 = straight4.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has 4 to a straight: " << boolalpha << straight4.is4Straight() << endl << endl;
	
	//Test 4-flush
	Card f4[5] = {Card(5, 2), Card(2, 1), Card(12, 2), Card(11, 2), Card(10, 2)};
	HandOf5 flush4(f4);
	
	for(int i = 0; i < 5; i++){
		Card c3 = flush4.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has 4 to a flush: " << boolalpha << flush4.is4Flush() << endl << endl;
	
	//Test full house
	Card fh[5] = {Card(5, 2), Card(5, 1), Card(5, 0), Card(7, 1), Card(7, 0)};
	HandOf5 fullHouse(fh);
	
	for(int i = 0; i < 5; i++){
		Card c3 = fullHouse.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a full house: " << boolalpha << fullHouse.isFullHouse() << endl << endl;
	
	//Test straight flush
	Card sf[5] = {Card(5, 2), Card(6, 2), Card(7, 2), Card(8, 2), Card(9, 2)};
	HandOf5 straightFlush(sf);
	
	for(int i = 0; i < 5; i++){
		Card c3 = straightFlush.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a straight flush: " << boolalpha << straightFlush.isStraightFlush() << endl << endl;
	
	//Test royal flush
	Card rf[5] = {Card(14, 2), Card(10, 2), Card(13, 2), Card(11, 2), Card(12, 2)};
	HandOf5 royalFlush(rf);
	
	for(int i = 0; i < 5; i++){
		Card c3 = royalFlush.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl << "This hand has a royal flush: " << boolalpha << royalFlush.isRoyalFlush() << endl << endl;
	///////////////////////////////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////////////--Testing phase 3
	cout << "--------------------------------Phase 3: Determine winner of two hands" << endl;
	cout << "Winner of two random hands:" << endl << endl;
	//Deal two random hands and test winner
	DeckOfCards deck4;
	deck4.shuffle();
	HandOf5 dealerTest(deck4);
	HandOf5 playerTest(deck4);
	Dealer dTest(dealerTest, playerTest, deck4);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = dealerTest.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = playerTest.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dTest.whoWins();
	cout << endl;
	
	//Test one instance of each branching win condition
	//Testing higher ranked hands is more likely to discover new bugs because low ranking hands
	//Usually win the random tests; also alternate between dealer and player winning
	cout << endl << "------------------------------------------------------------" << endl << endl;
	cout << "Test key win conditions (Refer to comments)" << endl << endl;
	//Test victory by unequal card ranked - straight v full house
	DeckOfCards dummyDeck;
	Card uneq1[5] = {Card(2, 0), Card(5, 1), Card(3, 2), Card(4, 3), Card(6, 2)};
	Card uneq2[5] = {Card(5, 2), Card(5, 1), Card(5, 0), Card(7, 1), Card(7, 0)};
	HandOf5 unequal1(uneq1);
	HandOf5 unequal2(uneq2);
	Dealer dUnequal(unequal1, unequal2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = unequal1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = unequal2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dUnequal.whoWins();
	cout << endl;
	
	//Test same rank, but same high card - two straights
	Card eq1[5] = {Card(9, 2), Card(12, 1), Card(13, 0), Card(11, 0), Card(10, 3)};
	Card eq2[5] = {Card(8, 0), Card(10, 1), Card(11, 2), Card(9, 3), Card(7, 2)};
	
	HandOf5 equal1(eq1);
	HandOf5 equal2(eq2);
	Dealer dEqual(equal1, equal2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = equal1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = equal2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dEqual.whoWins();
	cout << endl;
	
	//Test a game decided with the first kicker - two pairs have one kicker
	Card kick1[5] = {Card(9, 2), Card(3, 1), Card(9, 0), Card(3, 0), Card(10, 3)};
	Card kick2[5] = {Card(3, 3), Card(9, 1), Card(11, 2), Card(9, 3), Card(3, 2)};
	
	HandOf5 kicker1(kick1);
	HandOf5 kicker2(kick2);
	Dealer dKicker(kicker1, kicker2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = kicker1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = kicker2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dKicker.whoWins();
	cout << endl;
	
	
	//Test a game decided by multiple kickers - no pair has 3
	Card twoKick1[5] = {Card(14, 2), Card(9, 1), Card(13, 0), Card(6, 0), Card(10, 3)};
	Card twoKick2[5] = {Card(13, 3), Card(14, 0), Card(6, 2), Card(9, 3), Card(3, 2)};
	
	HandOf5 twoKicker1(twoKick1);
	HandOf5 twoKicker2(twoKick2);
	Dealer dKicker2(twoKicker1, twoKicker2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = twoKicker1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = twoKicker2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dKicker2.whoWins();
	cout << endl;
	
	//Test a tie with the most kickers used -- so no pair
	Card t1[5] = {Card(14, 2), Card(9, 1), Card(13, 0), Card(6, 0), Card(3, 3)};
	Card t2[5] = {Card(13, 3), Card(14, 0), Card(6, 2), Card(9, 3), Card(3, 2)};
	
	HandOf5 tie1(t1);
	HandOf5 tie2(t2);
	Dealer dTie(tie1, tie2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = tie1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = tie2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dTie.whoWins();
	cout << endl;
	
	//Test two full houses
	Card fh1[5] = {Card(14, 2), Card(14, 1), Card(14, 0), Card(2, 0), Card(2, 3)};
	Card fh2[5] = {Card(13, 3), Card(13, 0), Card(13, 2), Card(9, 3), Card(9, 2)};
	
	HandOf5 fullHouse1(fh1);
	HandOf5 fullHouse2(fh2);
	Dealer dFull(fullHouse1, fullHouse2, dummyDeck);
	
	cout << "Dealer: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = fullHouse1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	cout << "Player: " << endl;
	
	for(int i = 0; i < 5; i++){
		Card c3 = fullHouse2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	cout << endl;
	dFull.whoWins();
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////--Testing phase 2
	//NOTE: since the hands are hard-coded in, a fresh deck might produce the same
	//     card -- we don't care about this. If it happens, just run it again
	cout << endl << "------------------------------Phase 4: Program dealer AI" << endl << endl;
	cout << "Test behaviours of dealer in various situations (refer to comments)" << endl << endl;
	
	//Test scenario: three of a kind (draw non hand members)
	DeckOfCards deck5;
	deck5.shuffle();
	Card draw1[5] = {Card(14, 0), Card(14, 1), Card(14, 2), Card(10, 3), Card(7, 2)};
	Card dummy[5] = {Card(4, 0), Card(5, 1), Card(9, 2), Card(10, 3), Card(7, 2)};
	
	HandOf5 drawTest1(draw1);
	HandOf5 dummyPlayer(dummy);
	Dealer dDraw1(drawTest1, dummyPlayer, deck5);
	
	cout << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw1.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest1.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: two pair (draw for full house)
	Card draw2[5] = {Card(14, 0), Card(14, 1), Card(10, 2), Card(10, 3), Card(7, 2)};
	
	HandOf5 drawTest2(draw2);
	Dealer dDraw2(drawTest2, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw2.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest2.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: High pair draw 3
	Card draw3[5] = {Card(14, 0), Card(14, 1), Card(4, 2), Card(10, 3), Card(7, 2)};
	
	HandOf5 drawTest3(draw3);
	Dealer dDraw3(drawTest3, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest3.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw3.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest3.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: Low pair w/ 4-flush
	Card draw4[5] = {Card(5, 0), Card(14, 0), Card(5, 2), Card(10, 0), Card(7, 0)};
	
	HandOf5 drawTest4(draw4);
	Dealer dDraw4(drawTest4, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest4.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw4.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest4.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: No pair w/ 4 straight
	Card draw5[5] = {Card(5, 0), Card(14, 0), Card(6, 2), Card(8, 1), Card(7, 0)};
	
	HandOf5 drawTest5(draw5);
	Dealer dDraw5(drawTest5, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest5.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw5.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest5.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: No pair 2 high cards
	Card draw6[5] = {Card(5, 0), Card(11, 0), Card(6, 2), Card(13, 1), Card(7, 0)};
	
	HandOf5 drawTest6(draw6);
	Dealer dDraw6(drawTest6, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest6.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw6.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest6.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: No pair 1 high card
	Card draw7[5] = {Card(5, 0), Card(11, 0), Card(6, 2), Card(10, 1), Card(7, 0)};
	
	HandOf5 drawTest7(draw7);
	Dealer dDraw7(drawTest7, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest7.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw7.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest7.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	//Test scenario: No high cards - draw 5
	Card draw8[5] = {Card(5, 0), Card(2, 0), Card(6, 2), Card(10, 1), Card(7, 0)};
	
	HandOf5 drawTest8(draw8);
	Dealer dDraw8(drawTest8, dummyPlayer, deck5);
	
	cout << endl << "Dealer before draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest8.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
	dDraw8.dealerSwap();
	
	cout << endl << "Dealer after draw: " << endl;
	for(int i = 0; i < 5; i++){
		Card c3 = drawTest8.cardAt(i);
		cout << c3.AtoString() << endl;
	}
	
		//////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////--Testing phase 5
	//Game is player HERE
	cout << endl << "-------------------------Testing COMPLETE. Game START" << endl << endl;
	int discard = -1;
	vector<int> discards;
	char choice;
	
	do{
		
		DeckOfCards deckFinal;
		deckFinal.shuffle();
		
		HandOf5 dealerFinal(deckFinal);
		HandOf5 playerFinal(deckFinal);
		
		Dealer dFinal(dealerFinal, playerFinal, deckFinal);
		
		//Make sure dealer was making the right decisions
		/*cout << endl << "DEALER'S HAND: " << endl;
		for(int i = 0; i < 5; i++){
			Card c3 = dealerFinal.cardAt(i);
			cout << i << ") " << c3.AtoString() << endl;
		}*/
		
		cout << endl << "YOUR HAND: " << endl;
		for(int i = 0; i < 5; i++){
			Card c3 = playerFinal.cardAt(i);
			cout << i + 1 << ") " << c3.AtoString() << endl;
		}
		
		cout << endl << "Dealer discards " << dFinal.dealerSwap() << " card(s)" << endl;
		
		cout << endl << "Choose cards to discard 1 - 5(ex: 1 2 5) and then press 'enter', then enter the ctrl+d command" << endl;
		while(cin >> discard){
			discards.push_back(discard - 1);
		}
		
		for (auto it = discards.begin(); it != discards.end(); it++){
			playerFinal.swapCard(*it, deckFinal);
		}
		
		cout << endl << "DEALER'S HAND: " << endl;
		for(int i = 0; i < 5; i++){
			Card c3 = dealerFinal.cardAt(i);
			cout << i + 1 << ") " << c3.AtoString() << endl;
		}
		
		playerFinal.sortHand();
		
		cout << endl << "YOUR HAND: " << endl;
		for(int i = 0; i < 5; i++){
			Card c3 = playerFinal.cardAt(i);
			cout << i + 1 << ") " <<c3.AtoString() << endl;
		}
		
		cout << endl;
		dFinal.whoWins();
		
		cin.clear();
		fflush(stdin);
		
		cout << endl << "Enter 'y' for another game; any other key to exit" << endl;
		cin >> choice;
		
		dFinal.resetDeck();
		discards.clear();
	}
	while(choice == 'y');
	
	cout << endl << "Thanks for playing!" << endl;
	
	return 0;
}