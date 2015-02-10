/*Kyle Ho
February 5, 2015
Inputs: Numbers 1-5 to select an option
Outputs: Card values with their string names.  Also, you will be playing against a 'computer entity'*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Card.h"//Header file for Card
#include "CardDeck.h"//Header file for CardDeck

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Various inputs that are going to be used in the program
	int decide, playerCard1, playerCard2, computerCard1, computerCard2, pTotal, cTotal;
	char input= 'y';
	char end;
	int count = 0;
	CardDeck d;

	//Description of the game
	cout << "Welcome to the War Card Game!" << endl;
	cout << "Aces are worth 1 point and all face cards are worth 10 points." << endl;
	cout << "Beat the computer and you win!" << endl << endl;

	//Using a do-while in order to create a menu
	do{
		cout << "Select an option: " << endl << endl;
		cout << "1. Begin War." << endl;
		cout << "2. Show the cards in the deck" << endl;
		cout << "3. Shuffle the deck" << endl;
		cout << "4. Make a new deck" << endl;
		cout << "5. Exit" << endl;
		cin >> decide;
		cout << endl;

		//Switch case in order to create a menu
		switch (decide){
				
		case 1:
			/*We use a do-while loop here in order to have the user play as many times
			as he/she wants to play*/
			do{
				/*Since the deck only has 52 cards and we use 4 cards per game of war, we must create
				a parameter in which it stops the player from exceeding the deck amount.  Once the deck
				has been depleted, the user will be prompted to create a new deck to continue playing*/
				if (count < 13){
					cout << "You get a card..." << endl;
					playerCard1 = d.deal();
					cout << endl;

					cout << "The computer gets a card..." << endl;
					computerCard1 = d.deal();
					cout << endl;

					cout << "You get another card..." << endl;
					playerCard2 = d.deal();
					cout << endl;

					cout << "The computer gets another card..." << endl;
					computerCard2 = d.deal();
					cout << endl << endl;

					//Calculating the amount of points the player and the computer has.
					pTotal = playerCard1 + playerCard2;
					cTotal = computerCard1 + computerCard2;

					cout << "You have " << pTotal << " points" << endl << endl;
					cout << "The computer has " << cTotal << " points" << endl << endl;

					//Win conditions
					if (pTotal > cTotal){
						cout << "You win!" << endl;
					}
					else if (cTotal > pTotal){
						cout << "The computer has won! You lost." << endl;
					}
					else if (cTotal == pTotal){
						cout << "It is a tie." << endl;
					}

					//We increment a counter that starts at 0 to 13.
					count++;
				}

				//Once the deck is out of cards, the user to prompted to select the option to create a new deck.
				else{
					cout << "There are no cards left in the deck." << endl;
					cout << "You must create a new deck.  Please select option 4 to do so." << endl;
					break;
				}
				
				//Player will be asked to play as many times as he/she wants
				cout << "Do you want to play again?(y/n)" << endl;
				cin >> input;

			} while (input != 'n');
				break;

		//This case calls the cardsLeft function in CardDeck to show the amount of cards left as well as what cards are left.
		case 2:
			cout << "Remaining number of cards: " << d.cardsLeft() << endl;
			break;

		//Calls the shuffle method in CardDeck to shuffle the deck
		case 3:
			cout << "Shuffling the deck..." << endl;
			d.shuffle();
			cout << "The deck has been shuffled" << endl << endl;
			break;

		//Creates a new deck by calling CardDeck again to generate a new deck
		case 4:
			count = 0;
			cout << "Creating a new deck..." << endl;
			CardDeck::CardDeck();
			cout << "A new deck has been created!" << endl << endl;
			break;

		//Exits the menu
		case 5:
			cout << "You are now exiting the War Card Game." << endl;
			cout << "I hope you had fun!" << endl;
			cout << endl;
			break;

		//If the user inputs a number that is greater than 5, this case will make sure that the number between 1 and 5
		default:
			do{
				cout << "Invalid entry.  Please enter a number between 1 and 5." << endl;
				cin >> decide;
			} while (decide > 5);

			//Once the user is out of the do-while loop, they are back at the menu and have to reenter an option
			cout << "Valid entry. Welcome back to the menu." << endl;
			break;
		}

	//As long as the input is not 5, the game will continue to play
	} while (decide != 5);

	//The user can enter any key to exit the program
	cout << "Press any key to exit." << endl;
	cin >> end;
	return 0;
}
