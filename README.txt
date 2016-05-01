Project: CardGame.exe
Author: Alex Hamilton
Date: 30 April, 2016

Implementation---------------------------------------------------

-Getters of data members are implemented and used where needed

Card class
	-Ability to represent each card in a standard 52 card deck
	-Ace can be represented as either high or low
	-Default card is JOKER, which helps for error checking
	-Overloaded <, > operators to sort Cards by face value or suit
	
DeckOfCards class
	-Ability to store all 52 possible card representations in a vector
	-Ability to deal a single Card
	-Ability to shuffle deck using standard random shuffle
	-Ability return cards remaining in deck
	-Ability to check if there are cards left in the deck
	
HandOf5 class
	-Represents a hand as an integer array of 5 Cards
	-Constructed using a DeckOfCards to deal 5 Cards to the hand
	-Represents kickers in a vector of pairs since each hand has a different kicker size
	-Pairs in kickers are int index and int face
	-Able to store high card of hand, secondary high card of hand, and index of Cards to be drawn in draw hands
	-Able to if a hand represents each type of hand rank, up to royal flush (extra credit?)
	-Wrapper for access of hand data member
	-Can swap a Card given an index and a DeckOfCards to deal a new Card
	-Using a switch and enum type, can return the best rank of the hand
	-Can create a string that forms the predicate of the printed result
	
Dealer Class
	-Constructed using two hands and a deck
	-Can print a string deciding the winner and winning hand guven two hands
	-Intelligence dictating which cards the dealer should swap
	-Can change out for a fresh deck
	
Experiments--------------------------------------------------------------

Experiment 1:
	-Player: Mother (I'm at home this weekend)
	
	Data:
		Dealer wins with THREE JACKS
		Dealer wins with PAIR of EIGHTS
		Player wins with PAIR of ACES
		Dealer wins with PAIR of QUEENS
		Dealer wins with PAIR of JACKS
		Player wins with PAIR of NINES
		Dealer wins with TWO PAIR: ACES and FIVES
		Player wins with TWO PAIR: ACES and JACKS
		Player wins with STAIGHT: NINE to KING
		Dealer wins with PAIR of SIXES
		Player wins with ACE HIGH (NINE KICKER)
		Dealer wins with FULL HOUSE: QUEENS over THREES
		Dealer wins with TWO PAIR: FOURS and TWOS
		Dealer wins with PAIR of QUEENS
		Player wins with PAIR of THREES
		Dealer wins with PAIR of QUEENS
		Dealer wins with FLUSH: ACE HIGH
		Dealer wins with PAIR of NINES
		Dealer wins with PAIR of FOURS
		Player wins with STAIGHT: TEN to ACE
		
	Result:
		Player = 7
		Dealer = 13
		
	Analysis:
		I believe my AI had an advantage because it tried to win with smaller hands more often
		The player would often go for big hands that the dealer is programmed not to except in some special cases
		
Experiment 2:
	-Player: Myself
	
	Data:
		Player wins with STAIGHT: SEVEN to JACK
		Dealer wins with PAIR of KINGS
		Dealer wins with PAIR of KINGS
		Player wins with KING HIGH
		Player wins with FULL HOUSE: NINES over SEVENS
		Dealer wins with TWO PAIR: KINGS and SIXES
		Dealer wins with PAIR of ACES
		Dealer wins with STAIGHT: TEN to ACE
		Dealer wins with THREE TENS
		Player wins with TWO PAIR: TENS and TWOS
		Player wins with THREE QUEENS
		Dealer wins with KING HIGH
		Dealer wins with TWO PAIR: EIGHTS and FOURS
		Player wins with PAIR of NINES
		Dealer wins with PAIR of TWOS
		Player wins with PAIR of JACKS
		Player wins with FULL HOUSE: ACES over FOURS
		Player wins with PAIR of ACES
		Dealer wins with TWO PAIR: FIVES and FOURS
		Player wins with PAIR of KINGS

	Result:
		Player = 10
		Dealer = 10
		
	Analysis:
		I played the same way I programmed the dealer to play, so that's that
		
Other-----------------------------------------------------------------------------

Bugs:
	-Fixed as many as I could during the experiment phase as they came up
	-Probably others, but there's no way to know except by using it a lot
	
To Do:
	-Add color to string representation of suits
	-Add more complex strategies to AI
	-Better system to take user input










		




