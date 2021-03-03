#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
const int WIDTH = 6;

bool readMatrix(int matrix[][MAX_COLS], int&, int&, char const*);
void addMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int matrixC[][MAX_COLS], int, int);
void printMatrix(int matrix[][MAX_COLS], int, int);

int main(int argc, char const* argv[]){
	if (argc != 3){
		cout << "Error: invalid command line arguments" << endl;
		cout << "Usage: ./a.out <1st matrix file> <2nd matrix file>" << endl;
		return 1;
	}
	int matrixA[MAX_ROWS][MAX_COLS];
	int rowsA = 0, colsA = 0;

	if (!readMatrix(matrixA, rowsA, colsA, argv[1]))
		return 1;

	int matrixB[MAX_ROWS][MAX_COLS];
	int rowsB = 0, colsB = 0;

	if (!readMatrix(matrixB, rowsB, colsB, argv[2]))
		return 1;

	int matrixC[MAX_ROWS][MAX_COLS];

	addMatrices(matrixA, matrixB, matrixC, rowsA, colsA);

	string plus, equals;
	plus.append((WIDTH * colsA) / 2, ' ');
	equals = plus;
	plus.append("+");
	equals.append("=");

	printMatrix(matrixA, rowsA, colsA);
	cout << plus << endl;
	printMatrix(matrixB, rowsB, colsB);
	cout << equals << endl;
	printMatrix(matrixC, rowsA, colsA);
}

bool readMatrix(int matrix[][MAX_COLS], int& rows, int& cols, char const* fileName){
	ifstream fin;
	fin.open(fileName);

	if (!fin.is_open()){
		cout << "Error: unable to open " << fileName << endl;
		return false;
	}
	else{
		fin >> rows >> cols;
		for (int i=0; i<rows; i++){
			for (int j=0; j<cols; j++){
				fin >> matrix[i][j];
			}
		}
		return true;
	}
}

void addMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int matrixC[][MAX_COLS], int rows, int cols){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols){
	char topLeft = "+", topRight = "+";
	char botLeft = "+", botRight = "+";

	string spaces;
	spaces.append(WIDTH * cols, ' ');

	cout << topLeft << spaces << topRight << endl;

	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			cout << setw(6) << right << matrix[i][j];
		}
		cout << endl;
	}
	
	cout << botLeft << spaces << botRight << endl;
}
