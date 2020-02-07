//2193.cpp
//12171694 Á¤À±½Â

#include <iostream>

using namespace std;






int main() {

	unsigned long n;
	cin >> n;

	unsigned long arr[91];

	if (n == 1||n==2) {
		cout << 1 << endl;
		return 0;
	}
	arr[0] = 1l;
	arr[1] = 1l;
	for (unsigned long i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n - 1] << endl;
}

