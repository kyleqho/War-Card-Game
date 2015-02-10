#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(){
};

Card::Card(char s, int v){
	//Initiliazes the values of value and suit to the parameter values
	suit = s;
	value = v;
};

int Card::getValue(){
	//Returns the value of the card as long as it is less than 10
	if (value <= 10){
		return value;
	}
	
	//If the value is greater than 10, we return 10 since Jacks, Queens and Kings have the same value
	else{
		return 10;
	}
}

void Card::displayCard(){
	//Uses two string variables to return the specified strings
	string vstring, sstring;

	//Case switch to determine the string of the specified number.
	switch (value){
	case 1:
		vstring = "Ace";
		break;
	case 2:
		vstring = "Two";
		break;
	case 3:
		vstring = "Three";
		break;
	case 4:
		vstring = "Four";
		break;
	case 5:
		vstring = "Five";
		break;
	case 6:
		vstring = "Six";
		break;
	case 7:
		vstring = "Seven";
		break;
	case 8:
		vstring = "Eight";
		break;
	case 9:
		vstring = "Nine";
		break;
	case 10:
		vstring = "Ten";
		break;
	case 11:
		vstring = "Jack";
		break;
	case 12:
		vstring = "Queen";
		break;
	case 13:
		vstring = "King";
		break;
	}
	//Using the suit value in CardDeck to determine the string for the variable specified
	switch (suit){
	case 'S':
		sstring = "Spades";
		break;
	case 'C':
		sstring = "Clubs";
		break;
	case 'D':
		sstring = "Diamonds";
		break;
	case 'H':
		sstring = "Hearts";
		break;
	}
	//Outputs the card generated from the two inputs
	cout << vstring << " of " << sstring << endl;
}


