#include <iostream>
using namespace std;


int main() {

	unsigned long long arr[91] = { 0, };
	for (int i = 2; i < 91; i++) {
		arr[i] = -1;
	}

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i < 91; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	
	int n;
	cin >> n;
	cout << arr[n] << endl;

	



}