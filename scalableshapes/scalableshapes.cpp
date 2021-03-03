// Name: Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 7
// Description: produce scalable shapes from a shape type, size, and
// symbol.
// Input: read in user input for input file and loop output file creation
// for each shape.
// Output: amount of files for every result of loop; each file containing
// the shape type made up of a symbol, scaled to a size.
// Algorithm:
// 1. Create skeleton code including fstream, iostream, and string as
//    libraries.
// 2. Create prototypes for right arrow, up arrow, and zero.
// 3. Prompt user for input file name until valid input file is read.
// 4. Open file.
// 5. Read variables ShapeType, size, and character from input file.
// 6. Create output file using ShapeType and size, then open it.
// 7. Identify ShapeType, size, and character within output file.
// 8. Depending on ShapeType, run a function to output the shape
//    made up of the given character, for a given size.
// 9. Close the output file, letting user know the shape was created
//    within the file.
// 10. Loop steps 5-9 until end of input file is reached.
// 11. Write to the user that end of file was reached and how many shapes
//     were created.
// 12. Close the input file.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void rightArrow (int, char);
void upArrow (int, char);
void zero (int, char);
ofstream outFile; // necessary global output file for use in functions
ifstream inFile; // necessary global input file for use in functions

int main(){
	string filename; // file name
	string ShapeType; // shape type
	int size; // size of shape
	char character; // symbol to fill shape
	int shapeCount=0; // used at end of code to identify amount-
			  // of shapes created
	cout << "Enter input file name: ";
	cin >> filename;

	inFile.open(filename.c_str());
	inFile.is_open();
	while (inFile.is_open()==false){ // loop for valid input file name
		cout << "Error - invalid input file name"
		     << endl;
		cout << "Enter input file name: ";
		cin >> filename;

		inFile.open(filename.c_str());
		inFile.is_open();
	}
	inFile >> ShapeType >> size >> character; // read variables
	while (!inFile.eof()){ // loop for each instance of shape within-
		shapeCount++;  // input fike
		string outfilename = ShapeType + "_" +
			             to_string(size) + ".txt"; // output-
		outFile.open(outfilename.c_str());             // file
		if (ShapeType == "rightArrow"){
			ShapeType = "Right Arrow";
		}
		else if (ShapeType == "upArrow"){
			ShapeType = "Up Arrow";
		}
		else if (ShapeType == "zero"){
			ShapeType = "ZERO";
		}
		outFile << "Symbol: " << ShapeType; // Identify shape-
		outFile << "    Size: " << size;    // for outFile
		outFile << " Character: '" << character << "'";
		outFile << endl;
		if ((ShapeType == "Right Arrow") or
		    (ShapeType == "Up Arrow")){
			if (size % 2 == 1){ // adds 1 to odd numbers
				outFile << "Note: "
				        << ShapeType
				        << " must have an even size.  ";
				size++;
				outFile << "Shape created with size: "
				        << size << endl;
			}
		}
		int line=0;
		int lineCount=0;
		while (size != line){ // used to identify size
			line++;
			lineCount++;
			if (lineCount == 10)
				lineCount = 0;
			outFile << lineCount;
		}
		outFile << endl;
		outFile << endl; // does function for given ShapeType
		if (ShapeType == "Right Arrow"){
			rightArrow (size, character);
		}
		else if (ShapeType == "Up Arrow"){
			upArrow (size, character);
		}
		else if (ShapeType == "ZERO"){
			zero (size, character);
		}
		outFile.close(); // lets user know shape is created
		cout << "Shape Created: " << outfilename << endl;
		inFile >> ShapeType >> size >> character; 
	}                   // ^^^ reads variables for next iteration
	cout << "Finished processing input file" << endl;
	cout << shapeCount << " Shapes Created" << endl;
	inFile.close(); 
}

// function_identifier: creates a scalable zero with given variables
// parameters: size and character for x and y
// return value: none, as it is void
 
void zero (int x, char y){
	for (int i=x; i>0; i--){
		if ((i==x) or (i==1)){ // top and bottom of zero
			for (int o=1; o<=x; o++)
				outFile << y;
			outFile << endl;
			continue;
		}
		outFile << y; // left border of zero
		for (int o=0; o<i-2; o++) // left spaces til slash
			outFile << " ";
		outFile << y; // slash
		for (int p=0; p<x-(i+1); p++) // right spaces from slash
			outFile << " ";
		outFile << y; // right border of zero
		outFile << endl;
	}
}

// function_identifier: creates a scalable up arrow with given variables
// parameters: size and character for x and y
// return value: none, as it is void

void upArrow (int x, char y){
	int count=0; // used for top half of arrow to loop
	while (x/2 > count){
		count++;
		int leftSpaces=-1; // left Spaces until arrow
		while ((x/2)-1-count-leftSpaces > 0){
			leftSpaces++;
			outFile << " ";
		}
		int charFill=0; //arrow
		while (count*2 > charFill){
			charFill++;
			outFile << y;
		}
		int rightSpaces=-1; // right spaces from arrow
		while ((x/2)-1-count-rightSpaces > 0){
			rightSpaces++;
			outFile << " ";
		}
		outFile << endl;
	}
	int shaftCount=0; // used for bottom half of arrow to loop
	while (x/2 > shaftCount){
		shaftCount++;
		int leftSpaces=1; // left spaces until shaft
		while ((x/2)-leftSpaces > 0){
			leftSpaces++;
			outFile << " ";
		}
		outFile << y; //shaft
		outFile << y; //shaft
		int rightSpaces=1;
		while ((x/2)-rightSpaces > 0){ // right spaces from shaft
			rightSpaces++;
			outFile << " ";
		}
		outFile << endl;
	}
}

// function_identifer: creates a scalable right arrow with given variables
// parameters: size and character for x and y
// return value: none, as it is void

void rightArrow (int x, char y){
	int count=0; // used to loop for size of arrow
	do{
		count++; // creates shaft upon half of size
		if ((count == x/2) or (count == (x/2)+1)){
			int charFill=0;
			do{
				charFill++;
				outFile << y;
			}while (charFill < x);
			outFile << endl;
			continue;
		}
		int leftSpaces=0;
		do{ // fills left side of arrow with spaces
			outFile << " ";
			leftSpaces++;
		}while (x/2 > leftSpaces);
		if (count < x/2){ // top half of arrow head
			int charFill=0;
			do{
				outFile << y;
				charFill++;
			}while (charFill < count);
		}
		else if (count > x/2){ // bottom half of arrow head
			int charFill;
			charFill = x+1;
			do{
				outFile << y;
				charFill--;
			}while (charFill > count);
		}
		outFile << endl;
	}while (x > count);
}
