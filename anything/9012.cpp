#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;

		bool yes = 1;
		int stack = 0;

		for (int j = 0; j < S.length(); j++) {
			if (S.at(j) == '(') stack++;
			else stack--;

			if (stack < 0) {
				yes = 0;
				break;
			}
		}
		if (stack != 0)yes = 0;
	


		if (yes)cout << "YES" << endl;
		else cout << "NO" << endl;


	}
	return 0;
}