#include <iostream>

using namespace std;

int max2(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	int *arr = new int[n];
	
	int *dp = new int[n];
	
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << arr[0] << endl;
		return 0;
	}
	else if (n == 2) {
		cout << arr[0] + arr[1] << endl;
		return 0;
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	
	dp[2] = max2(max2(dp[1],dp[0] + arr[2]),arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max2(max2(dp[i - 1], dp[i - 2] + arr[i]), dp[i - 3] + arr[i - 1] + arr[i]);
		
	}
	
		cout << dp[n - 1]<<endl;

}