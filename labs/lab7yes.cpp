#include <iostream>
using namespace std;
int main (int argc, char const *argv[]){
	int count, sum = 0, sum2 = 0;
	cin >> count;
	for (int i = 0; i < count; i++){
		int n, r, t;
		cin >> n;
		r = 0;
		sum +=n;
		cout << "Reverse of " << n;
		while (n > 0){
			t = n % 10;
			r*=10;
			r+=t;
			n/=10;
		}
		sum2 +=r;
	cout << " is " << r << endl;
		}
	cout << "The sum of all reverse and non-reverse numbers is "
	     << sum+sum2 << endl;
	return 0;
}
