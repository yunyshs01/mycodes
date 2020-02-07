#include <iostream>
using namespace std;

#define ull unsigned long long
#define MOD 1000000000



int main() {
	int n;
	cin >> n;
	ull **dp = new ull*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new ull[10];
		for (int j = 0; j < 10; j++) {
			dp[i][j] = 0;
		}
	}
	
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = dp[i - 1][j - 1]%MOD + dp[i - 1][j + 1]%MOD;
		}
		dp[i][0] = dp[i - 1][1]%MOD;
		dp[i][9] = dp[i - 1][8]%MOD;
	}

	ull sum = 0;
	for (int i = 0; i < 10; i++) {
		sum +=dp[n][i]%MOD;
	}
	cout << sum%MOD << endl;



	for (int i = 0; i < n + 1; i++) {
		delete dp[i];
	}
	delete dp;
}


