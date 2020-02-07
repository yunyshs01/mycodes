#include <iostream>
#include <vector>
#define INT_MAX       2147483647
using namespace std;

int main() {
	int n;
	cin >> n;
	int min = INT_MAX;
	int a = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (min < a)min = a;

	}
	cout << min*n << endl;
}