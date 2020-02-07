#include <iostream>
using namespace std;

int main() {
	int arr[2][41];

	
	
	arr[0][1] = 0;
	arr[1][1] = 1;
	arr[0][0] = 1;
	arr[1][0] = 0;

	for (int i = 2; i < 41; i++) {
		arr[0][i] = arr[0][i - 2] + arr[0][i - 1];
		arr[1][i] = arr[1][i - 2] + arr[1][i - 1];

	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cout << arr[0][a] << ' ' << arr[1][a] << endl;
	}

}