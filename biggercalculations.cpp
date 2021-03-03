// Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 4
// Calculator that reads in rock shape and edge length for its dimensions
// Rock shape using switch inputs and if statements
// edge length after set precision and dimensions sA, V, h, and sa/V

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout << endl;
	cout << "   ***************************" << endl;
	cout << "   *  Slate Rock and Gravel  *" << endl;
	cout << "   *  Rock Volume Calculator *" << endl;
	cout << "   ***************************" << endl;
	cout << endl;

	char shape;
	double edge;
	double h;
	double sA;
	double V;
	double r;

	cout << setprecision(2) << fixed;
	cout << " (p/P) - Pentagonal Pyramid" << endl;
	cout << " (b/B) - Pentagonal Bipyramid" << endl;
	cout << " (d/D) - Gyroelongated Square Dipyramid" << endl;
	cout << " (g/G) - Gyrobifastigium" << endl;
	cout << " (e/E) - Elongated Pentagonal Pyramid" << endl;
	cout << " (q/Q) - Quit" << endl;
	cout << endl;
	cout << " Your selection: ";
	cin >> shape;
	cout << endl;
	
	switch (shape)
	{
		case 'p':
		case 'P':
	
	cout << "Pentagonal Pyramid Calculator" << endl;
	cout << "Valid Range [2.00 < edge length < 500.00]" << endl;
	cout << "Edge Length: ";
	cin >> edge;

	if ((2.00 < edge) and (edge < 500.00))
	{
	cout << "-----------------------------------------" << endl;
	cout << "Calculations for a Pentagonal Pyramid" << endl;
	}
	else
	{
	cout << "Error - edge length out of range" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout <<	"Gravel for your gravel needs" << endl;
	return 0;
	}	
	h=(sqrt((5-sqrt(5))/10))*edge; 
	sA=(sqrt(25+10*sqrt(5))/4+5*sqrt(3)/4)*pow(edge,2);
	V=(5+sqrt(5))/24*pow(edge,3);
	break;
		case 'b':
		case 'B':
	
	cout << "Pentagonal Bipyramid Calculator" << endl;
	cout << "Valid range [1.00 < edge length < 750.00]" << endl;
	cout << "Edge Length: ";
	cin >> edge;

	if ((1.00 < edge) and (edge < 750.00))
	{
	cout << "-----------------------------------------" << endl;
	cout << "Calculations for a Pentagonal Bipyramid" << endl;
	}
	else
	{
	cout << "Error - edge length out of range" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout << "Gravel for your gravel needs" << endl;
	return 0;
	}
	sA=5*sqrt(3)/2*pow(edge,2);
	V=(5+sqrt(5))/12*pow(edge,3);
	h=2*sqrt((5-sqrt(5))/10)*edge;
	break;
		case 'd':
		case 'D':

	cout << "Gyroelongated Square Dipyramid Calculator" << endl;
	cout << "Valid range [7.00 < edge length < 1502.00" << endl;
	cout << "Edge length: ";
	cin >> edge;
	
	if ((7.00 < edge) and (edge < 1502.00))
	{
	cout << "-----------------------------------------" << endl;
	cout << "Calculations for a Gyroelongated Square ";
	cout << "Dipyramid" << endl;
	}
	else
	{
	cout << "Error - edge length out of range" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout << "Gravel for your gravel needs" << endl;
	return 0;
	}
	sA=4*sqrt(3)*pow(edge,2);
	V=(sqrt(2)+sqrt(4+3*sqrt(2)))/3*pow(edge,3);
	h=(sqrt(1-1/(2+sqrt(2)))+2/sqrt(2))*edge;
	break;
		case 'g':
		case 'G':
	
	cout << "Gyrobifastigium Calculator" << endl;
	cout << "Valid range [0.00 < edge length < 1740.00]" << endl;
	cout << "Edge length: ";
	cin >> edge;

	if ((0.00 < edge) and (edge < 1740.00))
	{
	cout << "-----------------------------------------" << endl;
	cout << "Calculations for a Gyrobifastigium" << endl;
	}
	else
	{
	cout << "Error - edge length out of range" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout << "Gravel for your gravel needs" << endl;
	return 0;
	}
	sA=(4+sqrt(3))*pow(edge,2);
	V=sqrt(3)/2*pow(edge,3);
	h=sqrt(3)*edge;
	break;
		case 'e':
		case 'E':

	cout << "Elongated Pentagonal Pyramid Calculator" << endl;
	cout << "Valid range [0.52 < edge length < 2751.00]" << endl;
	cout << "Edge length: ";
	cin >> edge;

	if ((0.52 < edge) and (edge < 2751.00))
	{
	cout << "-----------------------------------------" << endl;
	cout << "Calculations for a Elongated Pentagonal ";
	cout << "Pyramid" << endl;
	}
	else
	{
	cout << "Error - edge length out of range" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout << "Gravel for your gravel needs" << endl;
	return 0;
	}
	sA=(sqrt(25+10*sqrt(5))/4+5*sqrt(3)/4+5)*pow(edge,2);
	V=((5+sqrt(5))/24+sqrt(25+10*sqrt(5))/4)*pow(edge,3);
	h=(sqrt((5-sqrt(5))/10)+1)*edge;
	break;
		case 'q':
		case 'Q':
	cout << "Quitting ..." << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout << "Gravel for your gravel needs" << endl;
	return 0;
	break;

		default:
	
	cout << "Error - invalid entry" << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout <<	"Gravel for your gravel needs" << endl;
	return 0;
	}

	r=sA/V;
	cout << "Edge Length: " << edge << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Surface Area: " << sA << endl;
	cout << "Volume: " << V << endl;
	cout << "Height: " << h << endl;
	cout << "Surface to Volume Ratio: " << r << endl;
	cout << endl;
	cout << "Thank you for choosing Slate Rock and ";
	cout <<	"Gravel for your gravel needs" << endl;
}



