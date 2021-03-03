#include <iostream>
using namespace std;
void readChars(int&);
void printReverse(int);
int main(){
	int characters;
	readChars(characters);
	printReverse(characters);
}
void readChars(int& charCount){
	cout << "How many chars: ";
	cin >> charCount;
	if (charCount > 25){
		cout << "Error- max chars 25" << endl;
		exit(0);
	}
}
void printReverse(int charCount){
	char letterCount=0;
	int numberCount=0;
	char reverse[25];
	int reverseNum[25];
	for (int i=0;i<charCount;i++){
		if (i%2 == 0){
			char letter = 'a' + letterCount;
			cout << letter << " ";
			reverse[i]=letter;
			letterCount++;
		}
		else if (i%2 == 1){
			int number = 1 + numberCount;
			cout << number << " ";
			reverseNum[i]=number;
			numberCount++;
		}
	}
	cout << endl;
	for(int o=charCount-1;o>-1;o--){
		if (o%2 == 0)
			cout << reverse[o] << " ";
		else if (o%2 == 1)
			cout << reverseNum[o] << " ";
	}
	cout << endl;
}
