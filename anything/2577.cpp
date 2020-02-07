#include <iostream>
#include <string>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	string S = to_string(a*b*c);

	int arr[10] = { 0, };

	for (int i = 0; i < S.length(); i++) {
		arr[S.at(i) - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

}