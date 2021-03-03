#include <iostream>
#include <string>

using namespace std;

struct studentType{
	string first;
	string last;
	int grade;
};

void getStudentData(studentType& IStudent);

int main(){
	studentType data;
	getStudentData(data);

	cout << data.first << " " << data.last << " " << data.grade
	     << endl;
}

void getStudentData(studentType& IStudent){
	cout << "Firstname: ";
	cin >> IStudent.first;
	cout << "Lastname: ";
	cin >> IStudent.last;
	cout << "Grade: ";
	cin >> IStudent.grade;
}


