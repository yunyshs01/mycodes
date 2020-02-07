#include <iostream>
#include <cmath>
using namespace std;



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		int sumc = 0;

		double sumg = 0.0;
		for (int j = 0; j < c; j++) {
			int a;
			double b;
			cin >> a>> b;

			sumc += a;
			sumg += b*a;

		}

		cout.precision(2);
		cout.fixed;
		
		cout<< sumc<< ' ' << 0.1 * round(10*sumg/sumc) << endl;

	

	}

}