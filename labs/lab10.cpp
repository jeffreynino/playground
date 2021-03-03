#include <iostream>
using namespace std;
void print_sequence(int);
int fibonacci(int);
int main (int argc, char* argv[1]){
	if (argc !=3){
		cout << "Error: invalid command line arguments." << endl;
		cout << "Usage: <executable> <position> <max>" << endl;
		cout << "Exiting." << endl;
		return 0;
	}
	int pos = atoi (argv[1]);
	int max = atoi (argv[2]);
	int fib = fibonacci(pos);
	cout << "The " << pos
	     << "th number in the Fibonacci sequence is:" << endl;
	cout << fib << endl;
	cout << "The Fibonacci sequence up to " << max << " is:" << endl;
	print_sequence(max);
}
void print_sequence(int x){
	int current = 0;
	int next = 1;
	while (current < x){
		cout << current << " ";
		int temp = current;
		current = next;
		next+=temp;
	}
	cout << endl;
}
int fibonacci(int x){
	int current =0;
	int next = 1;
	for (int i=1; i < x ; i++){
		int temp = current;
		current = next;
		next+=temp;
	}
	return current;
}
