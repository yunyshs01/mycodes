#include <iostream>
#include <string>
using namespace std;


bool yes(int num) {
	string number = to_string(num);
	string reverse = number;
	for (unsigned int i = 0; i < number.length(); i++) {
		reverse.at(i) = number.at(number.length() - i - 1);
	}

	int inumber = stoi(number);
	int ireverse = stoi(reverse);
	int sum = inumber + ireverse;
	string ssum = to_string(sum);

	bool fail = 0;

	for (unsigned int i = 0; i < ssum.length() / 2; i++) {
		if (ssum.at(i) != ssum.at(ssum.length() - 1 - i))fail = 1;
	}

	return !fail;

	
	
}

int main() {

	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		
		
		if (yes(input))cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}