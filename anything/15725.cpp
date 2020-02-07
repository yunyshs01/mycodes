#include <iostream> 
#include <string>
using namespace std;

int main() {

	string A;
	string S;
	cin >> A;

	for (int i = 0; i < A.length(); i++) {
		if (A.at(i) != ' ')S.push_back(A.at(i));
	}
	
	

	bool thereIsX = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S.at(i) == 'x') {
			thereIsX = 1;

			if (i == 0) {
				cout << 1 << endl;
				return 0;
			}
			string subS = S.substr(0, i);
			if (subS == "-") cout << -1 << endl;
			else cout << subS << endl;
			
		}
	}
	if (!thereIsX) {
		cout << 0 << endl; 
		return 0;
	}



}