#include <iostream>

using namespace std;

int function(int n, int*DP);

int main() {
	ios::sync_with_stdio(0);

	int TestCase;
	cin >> TestCase;

	int*DP = new int[TestCase+1]();

	for (int i = 0; i < TestCase; i++) {





	}
	

}

int function(int n, int*DP) {
	if (n == 1) {
		DP[n] = 1;
		return DP[n];
	}
	if (n == 2) {
		DP[n] = 2;
		return DP[n];
	}
	if (n == 3) {
		DP[n] = 4;
		return DP[n];
	}

	DP[n] = DP[n - 1] * 2 + DP[n - 2] * 5 + DP[n - 3];


	
}