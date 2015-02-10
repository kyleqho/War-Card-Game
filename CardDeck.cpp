#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>//We are using Vectors to do this card game
#include <algorithm>
#include "Card.h"
#include "CardDeck.h"

using namespace std;

/*While trying to do this program, I found it extremely difficult to use arrays to achieve 
a clean and efficient code.  If I used arrays, I would have to create a minimum of three arrays.
This, I think, is very inefficient.  Therefore, I turned to vectors.

The beauty of vectors is that they have an ulimited index. I do not have to worry about an out of bounds error, 
therefore letting me create a deck of any size.  In this case, I create a deck of 52 cards*/
vector<Card> deck;

CardDeck::CardDeck(){
	//Begin by clearing the already empty vector in case
	deck.clear();

	//Creating an object of Card
	Card card;

	//Creating an array to hold character values for the suits of each card
	char suits[] = { 'S', 'C', 'D', 'H' };

	//Nested for loop to generate 52 cards
	for (int i = 1; i < 14; i++){
		for (int j = 0; j < 4; j++){

			//Adds cards to the last index of the array
			deck.push_back(Card(suits[j], i));
		}
	}
	//Calling the shuffle function in CardDeck
	shuffle();
}

void CardDeck::displayCardAt(int l){
	//Displaying the card at the current index of the vector
	deck[l].displayCard();
}

int CardDeck::deal(){
	//Initializing a variable to hold the value of the current card
	int num = deck[0].getValue();

	//Gets the card at the "top" of the deck
	deck[0].displayCard();

	/*Erases the card at the beginning of the deck, or the "top"
	Makes sure there are no repeats of cards that have been used already*/
	deck.erase(deck.begin());
	return num;
}

int CardDeck::cardsLeft(){
	//Displays all the cards using a for-loop
	for (int i = 0; i < deck.size(); i++){
		displayCardAt(i);
	}
	//Returns the size of the vector
	return deck.size();
}

void CardDeck::shuffle(){
	/*Using the algorithm function, we are able to use a known functionality.
	This uses multiple sorts in order to randomize the contents of the vector
	by using a specified start and ending index*/
	random_shuffle(deck.begin(), deck.end());
}
