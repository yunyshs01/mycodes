#include <iostream>
using namespace std;

int abs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int xarr[7];
	int yarr[7];

	for (int i = 0; i < 7; i++) {
		int a, b;
		cin >> a >> b;
		xarr[i] = a;
		yarr[i] = b;

	}

	int min = INT_MAX;
	int minx = 0, miny = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int cal = 0;
			for (int k = 0; k < 7; k++) {
				cal += abs(i - xarr[k]) + abs(j - yarr[k]);
			}
			if (min > cal) {
				min = cal;
				minx = i;
				miny = j;
			}
		}
		
		
	}

	cout << minx << ' ' << miny << endl;
}