/* Name: Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 8
 * Description: calculate parametric sets of equations to produce a png
 * Input: formulas for each equation
 * Output: a correct png file for each equation
*/

//variables are self-explanatory

// Code provided for assignment 8
// no main function algorithm required.

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

// prototype for student written 
// functions
void fish( );
double mysteryY( double );
double mysteryX( double );
void mystery();
void archimedean( );

// provided
void genPlotScript( string );

// Global named constant
const double pi=3.14159;

int main()
{
    char selection=' ';
   
    while( true ){
        cout << "Parametric Equation Plotter"<<endl;
        cout << "---------------------------"<< endl;
        cout << "F/f - Fish Curve " << endl;
        cout << "A/a - Archimedean " << endl;
        cout << "M/m - Mystery" << endl;
        cout << "Q/q - quit" << endl;
        cout << "Selection: ";

        cin >> selection;

        switch ( selection )
        {
            case 'F':
            case 'f':
               
                fish( );
                genPlotScript( "fish" );
                system("gnuplot fish_plot.me");
                break;
        
            case 'A':
            case 'a':
                archimedean( );
                genPlotScript( "archimedean" );
                system("gnuplot archimedean_plot.me");
                break;

            case 'm':
            case 'M': 
                cout<< "Mystery Equation plotter" << endl;
                mystery();
                genPlotScript( "mystery" );
                system("gnuplot mystery_plot.me");
                break;

            case 'q':
            case 'Q':
                cout << "Exiting ... " << endl;
                exit(0);

            default:
                cout << "Error -  try again" << endl;
        }
    }
}

//function_identifier: produces fish-like shape on png file
//parameters: none, as it is called using no variable
//return value: none, as it is void
//Algorithm:
//1. Output greeting text
//2. Prompt for size, rotation, count, and plot offset
//3. Verify valid
//4. Open output file
//5. Verify open
//6. for (double i=0; i<count; i++):
//   a. for (double t=0; t<=10*pi; t+=0.1)
//      1. calculate x
//      2. calculate y
//      3. output x and y file
//   b. size *= plot offset
//7. Close file
//8. return

void fish( ){
	double size;
	double rotation; 
	double count;
	double plot_offset;
	ofstream outFile;
	cout << "Fish curve plotter" << endl; //greeting
	cout << "Enter size: "; // prompts and tests for failure
	cin >> size;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter size: ";
		cin >> size;
	}
	cout << "Enter rotation: ";
	cin >> rotation;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter rotation: ";
		cin >> rotation;
	}
	cout << "Enter count: ";
	cin >> count;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter count: ";
		cin >> count;
	}
	cout << "Enter plot offset: ";
	cin >> plot_offset;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter plot offset: ";
		cin >> plot_offset;
	}
	outFile.open("fish.txt"); //opening output file
	outFile.is_open();
	if (outFile.is_open()==false)
		exit(0);
	for (double i =0; i<count; i++){
		for (double t=0; t<=10*pi; t+=0.1){
			double x=size*(cos(t)+2*rotation*cos(t/2));
			//calculating x
			double y=size*sin(t);
			//calculating y
			outFile << x << " " << y << endl;
			//output x and y
		}
		size *=plot_offset; // size modification per iteration
	}
	outFile.close();
}

//function_identifier: produces spiral on png file
//pramaters: none, as it is called using no variables
//return value: none,as it is void
//Algorithm:
//1. Output greeting text
//2. Prompt for spiral count and size
//3. Read values from user and verify valid
//4. Open output file, verify that it opened
//5. for (double t=0; t<count*2*pi; t+=0.1)
//   a. calculate x
//   b. calculate y
//   c. output x and y to file
//6. close file
//7. return

void archimedean(  ){
	double count;
	double size;
	ofstream outFile;
	cout << "Archimedean plotter" << endl; //greeting
	cout << "Enter count: "; //prompts and tests for failure
	cin >> count;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter count: ";
		cin >> count;
	}
	cout << "Enter size: ";
	cin >> size;
	while (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Illegal value - try again" << endl;
		cout << "Enter size: ";
		cin >> size;
	}
	outFile.open("archimedean.txt"); //opens output file
	outFile.is_open();
	if (outFile.is_open()==false)
		exit(0);
	for (double t=0; t<count*2*pi; t+=0.1){
		double x=size*t*cos(t+size);
		//calculating x
		double y=size*t*sin(t+size);
		//calculating y
		outFile << x << " " << y << endl;
		//output x and y
	}
	outFile.close();
}

//function_identifier: produces the mystery image on png file
//parameters: none, as it is called without a variable
//return value: none, as it is void
//Algorithm:
//1. Open output file, verify
//2. for (double i=-8.0; i<=8; i+=0.001)
//   a. call mysteryX(i)
//   b. call mysteryy(i)
//   c. output x and y to file
//3. close file

void mystery(){
	ofstream outFile;
	outFile.open("mystery.txt"); //opening output file
	outFile.is_open();
	if (outFile.is_open()==false)
		exit(0);
	for (double i=-8.0; i<=8.0; i+=0.001)
		outFile << mysteryX(i) << " " << mysteryY(i) << endl;
	          //calling x and y functions and outputting them
	outFile.close();
}

//function_identifier: produces the x value for the mystery function
//parameters: the value of i
//return value: the value of x
//Algorithm:
//1. declare retrun value, x
//2. input formula for x
//3. return x

double mysteryX( double t ){
	double x;
	double abs=fabs(t); //absolute value of t
	x = (abs/t)*(0.3*abs+0.2*fabs(abs-1.0)+2.2*fabs(abs
	    -2.0)-2.7*fabs(abs-3.0)-3.0*fabs(abs-5.0)+3.0*fabs(abs-7.0)
	    +5.0*sin((pi/4.0)*(fabs(abs-3.0)-fabs(abs-4.0)+1.0))+(5.0/4.0)
	    *pow((fabs(abs-4.0)-fabs(abs-5.0)-1.0),3.0)-5.3
	    *cos(((pi/2.0)+asin(47.0/53.0))*((fabs(abs-7.0)
	    -fabs(abs-8.0)-1.0)*0.5))+2.8);
	return x;
} 

//function_identifier: produces the y value for the mystery function
//parameters: the value of i
//return value: the value of y
//Algorithm:
//1. declare return value, y
//2. input formula for y
//3. return y

double mysteryY( double t){
	double y;
	double abs=fabs(t); //absolute value of t
	y = (3.0/2.0)*fabs(abs-1.0)-(3.0/2.0)*fabs(abs-2.0)-(29.0/4.0)
	    *fabs(abs-4.0)+(29.0/4.0)*fabs(abs-5.0)+(7.0/16.0)
	    *pow((fabs(abs-2.0)-fabs(abs-3.0)-1.0),4.0)
	    +4.5*sin((pi/4.0)*(fabs(abs-3.0)-fabs(abs-4.0)
	    -1.0))-((3.0*sqrt(2.0))/5.0)*pow(fabs(fabs(abs-5.0)
	    -fabs(abs-7.0)),(5.0/2.0))+6.4*sin(((pi/2.0)+asin(
	    47.0/53.0))*((fabs(abs-7.0)-fabs(abs-8.0)+1.0)*0.5)
            +asin(56.0/64.0))+4.95;
	return y;
}
 
/* genPlotScript 
   Creates a gnuplot script to plot the specified file.  
   argument 
	str - contains the filename of the text file to be plotted. 

   return 
	none
*/
void genPlotScript( string str )
{
    string first = "set terminal png size 640, 480 font \"Helvetica,8\" \nset output ";
    string second = " using 1:2 with lines notitle\n";

    ofstream oFile;

    oFile.open( str+"_plot.me" );
    if (oFile.is_open( ) ){
        oFile << first ;
        oFile << '\"' << str+".png" <<'\"' << endl;
        oFile << "plot " << '\"' << str+ ".txt" << '\"' ;
        oFile << second;
        oFile.close();
    }
}
      


