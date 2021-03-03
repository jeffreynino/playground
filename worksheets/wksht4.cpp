/* Jeffrey Crillin Nino, 5005572268, CS135 Section 1004, Worksheet 4 HW
 * Write a complete program that sums two integers
 * cin >> x >> y;
 * z = x + y;
 */

#include <iostream>

using namespace std;

int main()

{

	int x;
	int y;

	cout << "Enter two integers to sum: ";
	cin >> x >> y;

	int z=x+y;

	cout << "The sum of " << x << " + " << y << " = " << z << endl;

}
