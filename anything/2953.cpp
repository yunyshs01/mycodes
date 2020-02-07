#include <iostream>
using namespace std;



int main() {
	int sum[5];
	int* max = sum;
	for (int i = 0; i < 5; i++) {
		int s = 0;
		sum[i] = s;

		for (int j = 0; j < 4; j++) {
			cin >> s;
			sum[i] += s;
		}

		if (sum[i] > *max)max = &sum[i];
	}


	cout << max - sum + 1 << ' ' << *max << endl;
}