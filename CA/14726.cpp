#include <iostream>


using namespace std;

int main_() {
	int n;
	cin >> n;
	char numbers[17] = "";
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum = 0;
		cin >> numbers;
		for (int i = 0; i < 8; i++) {
			numbers[2 * i] = (((numbers[2 * i] - '0') * 2) > 9 ? ((numbers[2 * i] - '0') * 2) - 9 : (numbers[2 * i] - '0') * 2) + '0';
		}
		for (int i = 0; i < 16; i++) {
			sum += numbers[i] - '0';
		}
		
		if (sum % 10)cout << 'F' << endl;
		else cout << 'T' << endl;
	}

	return 0;
}