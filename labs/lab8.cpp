#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	int palidrome_count = 0;
	while (cin >> word){
		string reverse;
		for (int i = word.length()-1; i >= 0; i--){
			reverse+= word[i];
		}
		if (word == reverse) {
			palidrome_count++;
		}
		cout << "Reverse of " << word
		     << " is " << reverse << endl;
	}
	cout << "There are " << palidrome_count
	     << " palindromes in the input file." << endl;
}


