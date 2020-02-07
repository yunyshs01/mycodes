#include <iostream>

using namespace std;



int max2(int a, int b) {
	return a > b ? a : b;
}

int main() {

	int n;
	cin >> n;

	int ** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	int ** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}

	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			else {
				dp[i][j] = max2(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}

	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > max)max = dp[n - 1][i];
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;

	}*/

	cout << max << endl;



	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete[] dp;

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}