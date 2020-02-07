#include <iostream>
using namespace std;

int main() {
	bool arr[42];

	for (int i = 0; i < 42; i++) {
		arr[i] = false;
	}


	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;

		arr[a%42] = true;
	}

	int sum = 0;
	for (int i = 0; i < 42; i++) {
		sum += (int)arr[i];
	}

	cout << sum << endl;
}