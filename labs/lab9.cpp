#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[]){
	if (argc!=3){
		cout << "Error: invalid command line agruments." << endl;
		cout << "Usage: <executable> <1st input file> <2nd input file>" << endl;
		cout << "Exiting." << endl;
		return 0;
	}
	string file1_name = argv[1];
	ifstream inf1;
	inf1.open(file1_name.c_str());
	if (!inf1.is_open()){
		cout << "Error: unable to open " << file1_name << endl;
		cout << "Exiting." << endl;
		return 0;
	}
	int letter_count1[26]={0};
	char current;
	while (inf1 >> current){
		letter_count1[current - 'a']++;
	}
	inf1.close();
	string file2_name = argv[2];
	ifstream inf2;
	inf2.open(file2_name.c_str());
	if (!inf2.is_open()){
		cout << "Error: unable to open " << file2_name << endl;
		cout << "Exiting." << endl;
		return 0;
	}
	int letter_count2[26]={0};
	char current2;
	while (inf2 >> current2){
		letter_count2[current2 - 'a']++;
	}
	inf2.close();
	bool got_anagrams = true;
	for (int i=0; i<26; i++){
		if (letter_count2[i] != letter_count1[i]){
			got_anagrams = false;
		}
	}
	if (got_anagrams){
		cout << file1_name << " and " << file2_name << " are anagrams!" << endl;
	}
	else {
		cout << file1_name << " and " << file2_name << " are not anagrams." << endl;
	}
}
