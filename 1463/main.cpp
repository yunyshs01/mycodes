#include <iostream>

using namespace std;

int function(int, int*);
int min3(int, int, int);


#define INT_MAX       2147483647
int min2(int, int);
int main() {
	int n;
	cin >> n;

	int* arr = new int[n + 1];
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		
		function(i, arr);
	}

	cout << function(n, arr) << endl;
}

int function(int n, int* arr) {
	if (n == 1) {
		arr[1] = 0;
		return arr[1];
	}
	
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;

	if (!(n % 3)) {
		a = arr[n / 3] + 1;
	}
	if (!(n % 2)) {
		b = arr[n / 2] + 1;
	}
	c = arr[n - 1] + 1;
	
	
	arr[n] = min3(a, b, c);

	return arr[n];
}

int min2(int a, int b) {
	if (a > b) return b;
	return a;
}

int min3(int a, int b, int c) {
	return min2(min2(a, b), c);
}