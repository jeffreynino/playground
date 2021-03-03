#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int main(){
char move;

srand(time(0));
while ((move != 'e') and (move != 'E')){
int cpumove = rand() % 3 + 1;
string cpuresult;

if (cpumove == 1){
	cpuresult = "rock";
}
else if (cpumove == 2){
	cpuresult = "paper";
}
else if (cpumove == 3){
	cpuresult = "scissors";
}
	
cout << "[R]ock" << endl;
cout << "[P]aper" << endl;
cout << "[S]cissors" << endl;
cout << "[E]xit" << endl;
cout << "What's your move? ";
cin >> move;
cout << "The computer used " << cpuresult << "." << endl;

switch (move){
	case 'r':
	case 'R':
	if (cpumove == 1){
		cout << "It's a tie!" << endl;
}
	else if (cpumove == 2){
		cout << "You lost!" << endl;
}
	else if (cpumove == 3){
		cout << "You won!" << endl;
}
break;
	case 'p':
	case 'P':
	if (cpumove == 1){
		cout << "You won!" << endl;
}
	else if (cpumove == 2){
		cout << "It's a tie!" << endl;
}
	else if (cpumove == 3){
		cout << "You lost!" << endl;
}
break;
	case 's':
	case 'S':
	if (cpumove == 1){
		cout << "You lost!" << endl;
}
	else if (cpumove == 2){
		cout << "You won!" << endl;
}
	else if (cpumove == 3){
		cout << "It's a tie!" << endl;
}
break;
	case 'e':
	case 'E':
	cout << "Exiting game." << endl;
break;
	default:
	cout << "Your move is invalid!" << endl;
}
cout << endl;
}
return 0;
}
