// Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 5
// The card game 333
// Input an argc value to determine gametype
// Output will be ending result of game
// Algorithm:
// 1. Create shell including argc, argc, and GAME_TYPE
// 2. If statement to determine game type
// 3. Initialize the many variables that will be used
// 4. Deal out cards and determine total values
// 5. Start game by putting down the table card
// 6. Remove player cards that match table card
// 7. Update total values
// 8. Loop to stop 5 until five rounds are played, reme-
// 8. mbering to remove any duplicate table cards
// 9. Game ends when a player has no cards in hand or -
// 9. when card totals are close to 3 or 33, without going over

#include <iostream>
#include <iomanip>
#include "cardDeckType.h"

using namespace std;

int main(int argc, char* argv[], enum GAME_TYPE)
{
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Welcome to the Lunch Time Dessert 333 Game" << endl;
	cout << "------------------------------------------" << endl;
	cout << endl;

	cardDeckType deck;
	int testbench;

	if (argc > 1){
	
	cout << "Test Bench Menu" << endl;
	cout << "1 - Normal" << endl;
	cout << "2 - Duplicate table cards" << endl;
	cout << "3 - Tie score 0" << endl;
	cout << "4 - Tie score 3" << endl;
	cout << "5 - Tie score 33" << endl;
	cout << "6 - Tie score other" << endl;
	cout << "7 - Player 1 win" << endl;
	cout << "8 - Player 2 win" << endl;
	cout << endl;
	cout << "Enter your selection: ";
	cin >> testbench;

	switch (testbench){

		case 1:
		deck.setDeck(NORMAL);
		deck.shuffle();
		break;

		case 2:
		deck.setDeck(DUPLICATE);
		break;

		case 3:
		deck.setDeck(TIE0);
		break;

		case 4:
		deck.setDeck(TIE3);
		break;

		case 5:
		deck.setDeck(TIE33);
		break;

		case 6:
		deck.setDeck(TIE_OTHER);
		break;

		case 7:
		deck.setDeck(PLAYER1_WIN);
		break;

		case 8:
		deck.setDeck(PLAYER2_WIN);
		break;

		default:
		cout << "Invalid Entry" << endl;
		return 0;
}
}

	else{
	deck.setDeck(NORMAL);
	deck.shuffle();
	}
	int card1=0; // Odd cards belong to Plauer 1
	int card2=0;
	int card3=0;
	int card4=0; // Even cards belong to Player 2
	int card5=0;
	int card6=0;
	int tablecard; // The given table card alotted to any round
	int buffer;
	int buffer1;	// buffers used to weed out duplicates
	int buffer2;
	int buffer3;
	int buffer4;
	int round=0; // round number

	card1 = deck.drawCard();
	card2 = deck.drawCard();
	card3 = deck.drawCard();
	card4 = deck.drawCard();
	card5 = deck.drawCard();
	card6 = deck.drawCard(); // drawing the cards in order
	
	int total1;
	total1 = card1 + card3 + card5; // total for Player 1

	int total2;
	total2 = card2 + card4 + card6; // total for Player 2

	cout << "Player 1:  " << card1 << "  " << card3 << "  " << card5
	     << " Total:  " << total1 << endl;
	cout << "Player 2:  " << card2 << "  " << card4 << "  " << card6
	     << " Total:  " << total2 << endl;
	cout << endl;

	tablecard = deck.drawCard();
	buffer = tablecard;

	while (round < 5){ // used to repeat game for multiple rounds

	round+=1;
	cout << "Round " << round << endl;
	cout << "------------------" << endl;
	if (round == 2){
		buffer1 = deck.drawCard();
	while (buffer1 == tablecard){
		cout << "Table card is " << buffer1
		     << " ** Duplicate **" << endl;
		buffer1 = deck.drawCard();
	}
	tablecard = buffer1;
	}
	else if (round == 3){
		buffer2 = deck.drawCard();
	while ((buffer2 == buffer1) or (buffer2 == buffer)){
		cout << "Table card is " << buffer2
		     << " ** Duplicate **" << endl;
		buffer2 = deck.drawCard();
	}
	tablecard = buffer2;
	}
	else if (round == 4){
		buffer3 = deck.drawCard();
	while ((buffer3 == buffer2) or (buffer3 == buffer1) or
        	(buffer3 == buffer)){
		cout << "Table card is " << buffer3
		     << " ** Duplicate **" << endl;
		buffer3 = deck.drawCard();
	}
	tablecard = buffer3;
	}
	else if (round == 5){
		buffer4 = deck.drawCard();
	while ((buffer4 == buffer3) or (buffer4 == buffer2) or
		(buffer4 == buffer1) or (buffer4 == buffer)){
		cout << "Table card is " << buffer4
		     << " ** Duplicate **" << endl;
		buffer4 = deck.drawCard();
	}
	tablecard = buffer4;
	}

	cout << "Table card is " << tablecard << endl;
	cout << endl; 
					// here I discard cards
					// by setting variables to zero
	if (tablecard == card1){
		card1 = 0;
	}
	if (tablecard == card2){
		card2 = 0;
	}
	if (tablecard == card3){
		card3 = 0;
	}
	if (tablecard == card4){
		card4 = 0;
	}
	if (tablecard == card5){
		card5 = 0;
	}
	if (tablecard == card6){
		card6 = 0;
	}

	total1 = card1 + card3 + card5; // recalculating the value for
	total2 = card2 + card4 +card6;  // the totals

	cout << "Player 1:  " << card1 << "  " << card3 << "  " << card5
	     << " Total:  " << total1 << endl;
	cout << "Player 2:  " << card2 << "  " << card4 << "  " << card6
	     << " Total:  " << total2 << endl;
	cout << endl;

	if ((total1 == 0) or (total2 == 0)){
		cout << "Player 1 total: " << total1 << endl;
		cout << "Player 2 total: " << total2 << endl;
		cout << "Game result - ";
	if (total1 == total2){
		cout << "Tie  => You have to split the goodies" << endl;
	return 0;
	}
	else if (total1 == 0){
		cout << "Player 1 gets the goodies" << endl;
	return 0;
	}
	else if (total2 == 0){
		cout << "Player 2 gets the goodies" << endl;
	return 0;
	}
	}
	}
	cout << "Player 1 total: " << total1 << endl;
	cout << "Player 2 total: " << total2 << endl;
	cout << "Game result - ";

	int result1; // variables to help calculate the winner
	int result2;

	if (total1 == total2){
		cout << "Tie => You have to split the goodies" << endl;
	return 0;
	}
	
	if (total1 <= 3){
		result1=3-total1;
	}
	if (total2 <=3){
		result2=3-total2;
	}
	if ((total1 <= 33) and (total1 > 3)){
		result1=33-total1;
	}
	if ((total2 <= 33) and (total2 > 3)){
		result2=33-total2;
	}
	if (total1 > 33){
		result1=333-total1;
	}
	if (total2 > 33){
		result2=333-total2;
	}

	if (result1 < result2){
		cout << "Player 1 gets the goodies" << endl;
	}
	if (result1 > result2){
		cout << "Player 2 gets the goodies" << endl;
	}
}
