// Name: Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 10
// Description: Minesweeper Game
// Input: X and Y for where user wants to dig
// Output: The board, including new dig up spot and if user has lost
// Algorithm:
// 1. Skeleton code, including iostream, cstdlib, and ctime as libraries
// 2. Global constant variables width and height
// 3. Create debug mode, setting srand to 0, else set srand to time(null)
// 4. Declare two 12x9 arrays, one is bool and one is char; initialize 
//    their values to false and '?' respectively
// 5. Use rand() function to determine 10 different mines, setting the
//    their bool array to false
// 6. Dsiplay the board using a function
// 7. Ask the user for x and y positions to dig at, notify user if
//    the x and y positions cannot be dug
// 8. If position is a mine, end game with loss and terminate program
// 9. Otherwise, reveal square with amount of mines next to it
// 10. If no mines next to it, reveal squares around it until end of
//     board or all amount of mines > 0
// 11. Loop 6-10 until game is won

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// constants
const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 9;
// prototypes
void displayBoard(char board[][BOARD_WIDTH]);
void displayMines(bool mines[][BOARD_WIDTH]);
bool hasPlayerWon(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH]);
void revealSquare(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH],
     		  int, int, bool&);

int main(int argc, char *argv[]){
	// debug mode so bombs are not random
	if (argc > 1)
		srand(0);
	else
		srand(time(NULL));
	// char array
	char board[BOARD_HEIGHT][BOARD_WIDTH];
	for (int i=0; i<BOARD_WIDTH; i++){
		for (int j=0; j<BOARD_HEIGHT; j++){
			board[j][i] = '?';
		}
	}
	// bool array
	bool mines[BOARD_HEIGHT][BOARD_WIDTH];
	for (int i=0; i<BOARD_WIDTH; i++){
		for (int j=0; j<BOARD_HEIGHT; j++){
			mines[j][i] = false;
		}
	}
	// mines creator
	for (int i=0; i<10; i++){
		int width = rand() % BOARD_WIDTH;
		int height = rand() % BOARD_HEIGHT;
		if (mines[height][width] == true)
			i--;
		else
			mines[height][width] = true;
	}
	int x=0; // variable for user input x and y
	int y=0;
	bool check=true; // variable for if game can continue
	while (hasPlayerWon(board, mines) == false){
		displayBoard(board); // function for board display
		cout << "Dig at X: ";
		cin >> x;
		cout << "Dig at Y: ";
		cin >> y;
		// function for revealing square
		revealSquare(board, mines, x, y, check);
		if (check == false){ // if game is lost
			displayMines(mines);
			cout << endl;
			cout << "You hit a mine!  Game over." << endl;
			exit(0);
		}
	} // end result for if game is won
	displayBoard(board);
	cout << endl;
	cout << "You won!" << endl;

}

// function_identifer: displays the current board
// parameters: char array
// return value: none
void displayBoard(char board[][BOARD_WIDTH]){
	cout << "     ";
	for (int i=1; i<BOARD_WIDTH+1; i++)
		if (i>=9)
			cout << i << "  ";
		else
			cout << i << "   ";
	cout << endl;
	for (int i=1; i<BOARD_HEIGHT+1; i++){
		cout << "   +";
		for (int j=0; j<BOARD_WIDTH; j++)
			cout << "---+";
		cout << endl;
		cout << " " << i << " |";
		for (int j=0; j<BOARD_WIDTH; j++)
			cout << " " << board[i-1][j] << " |";
		cout << endl;
	}
	cout << "   +";
	for (int j=0; j<BOARD_WIDTH; j++){
		cout << "---+";
	}
	cout << endl;
}

// function_identifer: displays mine locations for if game is lost
// parameters: bool array
// return value: none
void displayMines(bool mines[][BOARD_WIDTH]){
	char board[BOARD_HEIGHT][BOARD_WIDTH]={'0'};
	cout << "     ";
	for (int i=1; i<BOARD_WIDTH+1; i++)
		if (i>=9)
			cout << i << "  ";
		else
			cout << i << "   ";
	cout << endl;
	for (int i=1; i<BOARD_HEIGHT+1; i++){
		cout << "   +";
		for (int j=0; j<BOARD_WIDTH; j++)
			cout << "---+";
		cout << endl;
		cout << " " << i << " |";
		for (int j=0; j<BOARD_WIDTH; j++){
			if (mines[i-1][j] == true)
				board[i-1][j] = '*'; // * on mine location
			else
				board[i-1][j] = ' ';
			cout << " " << board[i-1][j] << " |";
		}
		cout << endl;
	}
	cout << "   +";
	for (int j=0; j<BOARD_WIDTH; j++){
		cout << "---+";
	}
	cout << endl;
}

// function_identifier: takes user input and sets spot to 'c'; uses triple
//                      nested loop to: check the 8 char values around
//                      'c', changes 'c' to minesFound, and if
//                      minesFound = 0, set the 8 char values around input
//                      to 'c'
// parameters: char and bool arrays, user inputted x and y, and
//             the bool variable for loss
// return value: none
void revealSquare(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH],
		  int x, int y, bool& check){
	if (mines[y-1][x-1] == true)
		check=false; // loss
	else if (board[y-1][x-1] != '?') // user input unable to dig
		cout << "You cannot dig there" << endl;
	else{
		board[y-1][x-1]='c';
		bool checkAgain = true;
		while (checkAgain == true){
			checkAgain = false;
			for (int i=0; i<BOARD_HEIGHT; i++){
				for (int j=0; j<BOARD_WIDTH; j++){
					int minesFound = 0;
					// 8 values test
					if (board[i][j] == 'c'){
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j-1<BOARD_WIDTH)
							and
							(j-1>-1)
							and
							(mines[i-1][j-1]))
							minesFound++;
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j<BOARD_WIDTH)
							and
							(j>-1)
							and
							(mines[i-1][j]))
							minesFound++;
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j+1<BOARD_WIDTH)
							and
							(j+1>-1)
							and
							(mines[i-1][j+1]))
							minesFound++;
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(mines[i][j-1]))
							minesFound++;
						if ((i<BOARD_HEIGHT)
	        				 	and
	        				 	(i>-1)
	       				 	 	and
	        				 	(j+1<BOARD_WIDTH)
	        				 	and
		        			 	(j+1>-1)
		      		 		  	and
			        		 	(mines[i][j+1]))
							minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(mines[i+1][j-1]))
                                        		minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(mines[i+1][j]))
                                        		minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(mines[i+1][j+1]))
                                        		minesFound++;
						board[i][j] =
							'0' + minesFound;
					}
					// if no mines are found
					if (board[i][j] == '0'){
						checkAgain = true;
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(board[i-1]
                                                	      [j-1]=='?'))
							board[i-1]
							     [j-1] = 'c';
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(board[i-1]
                                                	      [j]=='?'))
							board[i-1]
							     [j] = 'c';
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(board[i-1]
                                                	      [j+1]=='?'))
							board[i-1]
							     [j+1] = 'c';
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(board[i]
                                                	      [j-1]=='?'))
							board[i]
							     [j-1] = 'c';
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(board[i]
                                                	      [j+1]=='?'))
							board[i]
							     [j+1] = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(board[i+1]
                                                	      [j-1]=='?'))
							board[i+1]
							     [j-1] = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(board[i+1]
                                                	      [j]=='?'))
							board[i+1]
							     [j] = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(board[i+1]
                                                	      [j+1]=='?'))
							board[i+1]
							     [j+1] = 'c';
						board[i][j] = ' ';
					}
				}
			}
		}
	}
}

// function_identifier: checks for amount of '?' in char array; if 10,
//                      game is won
// parameters: char and bool arrays
// return value: true if count is 10, false for else
bool hasPlayerWon(char board[][BOARD_WIDTH], bool mines[][BOARD_WIDTH]){
	int count=0;
	for (int i=0;i<BOARD_HEIGHT;i++){
		for (int j=0;j<BOARD_WIDTH;j++){
			if (board[i][j] == '?')
				count++;
		}
	}
	if (count == 10)
		return true;
	else
		return false;
}
