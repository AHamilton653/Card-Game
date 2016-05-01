all : CardGame

CardGame.exe : CardGame_driver.o Card.o DeckOfCards.o HandOf5.o Dealer.o
	g++ CardGame_driver.o Card.o DeckOfCards.o HandOf5.o Dealer.o -o CardGame.exe
	
CardGame_driver.o : CardGame_driver.cc Card.h DeckOfCards.h HandOf5.h Dealer.h
	g++ -c -g -std=c++11 CardGame_driver.cc
	
Card.o : Card.cc Card.h
	g++ -c -g -std=c++11 Card.cc
	
DeckOfCards.o : DeckOfCards.cc  DeckOfCards.h 
	g++ -c -g -std=c++11 DeckOfCards.cc
	
HandOf5.o : HandOf5.cc HandOf5.h
	g++ -c -g -std=c++11 HandOf5.cc
	
Dealer.o : Dealer.cc Dealer.h 
	g++ -c -g -std=c++11 Dealer.cc
	
