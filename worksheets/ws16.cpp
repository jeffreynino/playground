#include <iostream>
#include <string>
using namespace std;
int larger(int,int);
string larger(string,string);
int main(){
	char selection;
	cout << "Please select i/I/S/s: ";
	cin >> selection;
	int one;
	int two;
	string first;
	string second;
	switch (selection){
		case 'i':
		case 'I':
			cout << "Please enter two integers: ";
			cin >> one >> two;
			cout << "Largest integer " << larger(one,two)
			     << endl;
			break;
		case 's':
		case 'S':
			cout << "Please enter two strings: ";
			cin >> first >> second;
			cout << "Largest string " << larger(first,second)
			     << endl;
			break;
		default:
			return 0;
	}
}

int larger(int x, int y){
	if (x>y)
		return x;
	else if (y>x)
		return y;
}

string larger (string x, string y){
	if (x>y)
		return x;
	else if (y>x)
		return y;
}
