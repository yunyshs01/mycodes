#include <iostream>
using namespace std;
#define INT_MIN     (-2147483647 - 1) // minimum (signed) int value
#define INT_MAX       2147483647    // maximum (signed) int value

int main() {

	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	int max = INT_MIN, min =INT_MAX;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a > max)max = a;
		if (a < min)min = a;

	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << int(a <= max&&a >= min) << endl;
	}

}