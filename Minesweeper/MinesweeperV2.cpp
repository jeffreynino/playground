// Name: Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 11
// Description: Flags for Minesweeper Game
// Input: Selection for Dig, Flag, or Quit
// Output: The board, including moves, new dig up spot/flag 
//         and if user has lost
// Algorithm:
// 1. Copy Assignment 10 to create skeleton for Assignment 11
// 2. Create two structs for individual tile and the whole game
// 3. Replace old arrays with minesweeper tile array
// 4. Create menu for user input that chooses between dig, flag, and quit
// 5. Implement move counter
// 6. Create flag function, where user selects x and y to change to P
// 7. Flag counter for amount of P's on board
// 8. Once won, state win and amount of moves taken

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// constants
const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 9;
const int mineCount = 10;
// new structs
struct tile{
	char letter = '0';
	bool hasMine = true;
};
struct minesweeper{
	tile board[BOARD_HEIGHT][BOARD_WIDTH];
	int flagCount = 0;
	int correct = 0; // count for flags that are correct
	int unrevealedCount = 0;
	int moves = 1;
};
// prototypes
void displayBoard(minesweeper&);
void displayMines(minesweeper&);
bool hasPlayerWon(minesweeper&);
void revealSquare(minesweeper&, bool&);
void flag(minesweeper&);

int main(int argc, char *argv[]){
	minesweeper game;
	// debug mode so bombs are not random
	if (argc > 1)
		srand(0);
	else
		srand(time(NULL));
	// char array to ?
	for (int i=0; i<BOARD_WIDTH; i++){
		for (int j=0; j<BOARD_HEIGHT; j++){
			game.board[j][i].letter = '?';
		}
	}
	// bool array to false
	for (int i=0; i<BOARD_WIDTH; i++){
		for (int j=0; j<BOARD_HEIGHT; j++){
			game.board[j][i].hasMine = false;
		}
	}
	// mines creator
	for (int i=0; i<mineCount; i++){
		int width = rand() % BOARD_WIDTH;
		int height = rand() % BOARD_HEIGHT;
		if (game.board[height][width].hasMine == true)
			i--;
		else
			game.board[height][width].hasMine = true;
	}

	bool check=true; // variable for if game can continue
	while (hasPlayerWon(game) == false){
		char selection;
		displayBoard(game); // function for board display
		cout << endl;
		cout << "Move #" << game.moves << endl;
		cout << "[D]ig up Tile" << endl;
		cout << "[F]lag/Unflag Tile. " << game.flagCount
		     << " flag(s) placed." << endl;
		cout << "[Q]uit" << endl;
		cout << "Choose an action: ";
		cin >> selection;
		// switch statement for menu selection
		switch (selection){
			// Dig
			case 'd':
			case 'D':
				// function for revealing square
				revealSquare(game, check);
				if (check == false){ // if game is lost
					displayMines(game);
					cout << endl;
					cout << "You hit a mine! "
					     << " Game over." << endl;
					cout << endl;
					exit(0);
				}
				break;
			// Quit
			case 'q':
			case 'Q':
				cout << "Quitting..." << endl;
				cout << endl;
				exit(0);
				break;
			// Flag/Unflag
			case 'f':
			case 'F':
				flag(game);
				break;
			// Invalid selection
			default:
				cout << "Invalid action" << endl;
				cout << endl;
		}

	} // end result for if game is won
	displayBoard(game);
	cout << endl;
	cout << "You won in " << game.moves << " moves!" << endl;
	cout << endl;

}

// function_identifier: creates flags and unflags previous flags
// parameters: minesweeper struct
// return value: none
void flag(minesweeper& game){
	int x=0;
	int y=0;
	cout << "Place flag at:" << endl;
	cout << "Row: ";
	cin >> y;
	cout << "Column: ";
	cin >> x;
	cout << endl;
	// Flag
	if (game.board[y-1][x-1].letter == '?'){
		game.board[y-1][x-1].letter = 'P'; // converts ? to P
		game.flagCount++;
		// checks for if flag is correct
		if (game.board[y-1][x-1].hasMine == true)
			game.correct++;
	}
	// Unflag
	else if (game.board[y-1][x-1].letter == 'P'){
		game.board[y-1][x-1].letter = '?'; // converts P to ?
		game.flagCount--;
		// checks for if flag was correct
		if (game.board[y-1][x-1].hasMine == true)
			game.correct--;
	}
	// Non-flag placing spot
	else {
		cout << "You cannot place a flag there" << endl;
		cout << endl;
	}
}

// function_identifer: displays the current board
// parameters: minesweeper struct
// return value: none
void displayBoard(minesweeper& game){
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
			cout << " " << game.board[i-1][j].letter << " |";
		cout << endl;
	}
	cout << "   +";
	for (int j=0; j<BOARD_WIDTH; j++){
		cout << "---+";
	}
	cout << endl;
}

// function_identifer: displays mine locations for if game is lost
// parameters: minesweeper struct
// return value: none
void displayMines(minesweeper& game){
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
			if (game.board[i-1][j].hasMine == true)
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
// parameters: bool to check for loss, and minesweeper struct
// return value: none
void revealSquare(minesweeper& game, bool& check){
	int x=0;
	int y=0;
	game.moves++;
	cout << "Dig at..." << endl;
	cout << "Row: ";
	cin >> y;
	cout << "Column: ";
	cin >> x;
	cout << endl;
	if (game.board[y-1][x-1].letter != '?'){ // unable to dig
		game.moves--;
		cout << "You cannot dig there" << endl;
		cout << endl;
	}
	else if (game.board[y-1][x-1].hasMine == true)
		check=false; // loss
	else{
		game.board[y-1][x-1].letter = 'c';
		bool checkAgain = true;
		while (checkAgain == true){
			checkAgain = false;
			for (int i=0; i<BOARD_HEIGHT; i++){
				for (int j=0; j<BOARD_WIDTH; j++){
					int minesFound = 0;
					// 8 values test
					if (game.board[i][j].letter
					    == 'c'){
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j-1<BOARD_WIDTH)
							and
							(j-1>-1)
							and
							(game.board[i-1]
							 [j-1].hasMine))
							minesFound++;
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j<BOARD_WIDTH)
							and
							(j>-1)
							and
							(game.board[i-1]
							 [j].hasMine))
							minesFound++;
						if ((i-1<BOARD_HEIGHT)
							and
							(i-1>-1)
							and
							(j+1<BOARD_WIDTH)
							and
							(j+1>-1)
							and
							(game.board[i-1]
							 [j+1].hasMine))
							minesFound++;
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(game.board[i]
							 [j-1].hasMine))
							minesFound++;
						if ((i<BOARD_HEIGHT)
	        				 	and
	        				 	(i>-1)
	       				 	 	and
	        				 	(j+1<BOARD_WIDTH)
	        				 	and
		        			 	(j+1>-1)
		      		 		  	and
			        		 	(game.board[i]
							 [j+1].hasMine))
							minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(game.board[i+1]
							 [j-1].hasMine))
                                        		minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(game.board[i+1]
							 [j].hasMine))
                                        		minesFound++;
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(game.board[i+1]
							 [j+1].hasMine))
                                        		minesFound++;
						game.board[i][j].letter =
							'0' + minesFound;
					}
					// if no mines are found
					if (game.board[i][j].letter
					    == '0'){
						checkAgain = true;
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(game.board[i-1]
                                                	      [j-1].letter
							      =='?'))
							game.board[i-1]
							     [j-1].letter
							     = 'c';
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(game.board[i-1]
                                                	      [j].letter
							      =='?'))
							game.board[i-1]
							     [j].letter
							     = 'c';
						if ((i-1<BOARD_HEIGHT)
                                                 	and
                                                 	(i-1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(game.board[i-1]
                                                	      [j+1].letter
							      =='?'))
							game.board[i-1]
							     [j+1].letter
							     = 'c';
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(game.board[i]
                                                	      [j-1].letter
							      =='?'))
							game.board[i]
							     [j-1].letter
							     = 'c';
						if ((i<BOARD_HEIGHT)
                                                 	and
                                                 	(i>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(game.board[i]
                                                	      [j+1].letter
							      =='?'))
							game.board[i]
							     [j+1].letter
							     = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j-1<BOARD_WIDTH)
                                                 	and
                                                 	(j-1>-1)
                                                 	and
                                                 	(game.board[i+1]
                                                	      [j-1].letter
							      =='?'))
							game.board[i+1]
							     [j-1].letter
							     = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j<BOARD_WIDTH)
                                                 	and
                                                 	(j>-1)
                                                 	and
                                                 	(game.board[i+1]
                                                	      [j].letter
							      =='?'))
							game.board[i+1]
							     [j].letter
							     = 'c';
						if ((i+1<BOARD_HEIGHT)
                                                 	and
                                                 	(i+1>-1)
                                                 	and
                                                 	(j+1<BOARD_WIDTH)
                                                 	and
                                                 	(j+1>-1)
                                                 	and
                                                 	(game.board[i+1]
                                                	      [j+1].letter
							      =='?'))
							game.board[i+1]
							     [j+1].letter
							     = 'c';
						game.board[i][j].letter
						       	= ' ';
					}
				}
			}
		}
	}
}

// function_identifier: checks for amount of '?' in game.board; if 10,
//                      game is won
// parameters: minesweeper struct
// return value: true if count is 10, false for else
bool hasPlayerWon(minesweeper& game){
	game.unrevealedCount = 0;
	for (int i=0;i<BOARD_HEIGHT;i++){
		for (int j=0;j<BOARD_WIDTH;j++){
			if (game.board[i][j].letter == '?')
				game.unrevealedCount++;
		}
	}
	if (game.unrevealedCount + game.correct == mineCount)
		return true;
	else
		return false;
}
