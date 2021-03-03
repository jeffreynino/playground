#include <iostream>
#include <string>

using namespace std;

void writeName (int, string);

int main(){
	int x;
	string y;

	cout << "Enter a number and a name: ";
	cin >> x >> y;

	writeName (x,y);
	cout << endl;
}

void writeName (int number, string name){
	while (number > 0){
		number--;
		cout << name << " ";
	}
}
