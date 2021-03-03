#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_CLASS_SIZE = 30;

int min(int[], int);
int max(int[], int);
double average(int[], int);

int main(int argc, char* argv[]){
	if (argc != 2){
		cout << "Error: invalid command line arguments." << endl;
		return 1;
	}

	ifstream fin;
	string inputFileName = argv[1];
	fin.open(inputFileName.c_str());

	if(!fin.is_open()){
		cout << "Error: unable to open input file." << endl;
		return 1;
	}

	int grades[MAX_CLASS_SIZE];
	int count = 0;

	while(fin >> grades[count]){
		count++;
	}

	cout << "Min: " << min(grades, count) << endl;
	cout << "Max: " << max(grades, count) << endl;
	cout << "Avg: " << average(grades, count) << endl;
	cout << "Rng: " << max(grades,count) - min(grades, count) << endl;
	cout << endl;
}
int min(int list[], int length){
	int x=100000;
	for (int i=0; i<length; i++){
		if (i !=0){
			if(list[i]<x){
				x = list[i];
			}

		}
	}
	return x;
}
int max (int list[], int length){
	int x;
	for (int i=0; i<length; i++){
		if (i !=0){
			if (list[i]>x){
				x = list[i];
			}
		}
	}
	return x;
}
double average (int list[], int length){
	int sum = 0;
	double average;
	for (int i=0; i<length; i++){
		sum +=list[i];
	}
	average = (sum*1.0)/length;
	return average;
}
