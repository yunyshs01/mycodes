#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	int *arr = new int[n + 1];
	int *price = new int[n + 1];
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}

	int *dp = new int[n + 1];
	dp[0] = 0;
	price[0] = 0;
	dp[1] = 1;
	price[1] = arr[1];

	for (int i = 2; i < n + 1; i++) {
		int left = (i / dp[i - 1])* arr[dp[i - 1]] + price[(i%dp[i - 1])];
		int right = arr[i];
		if (left >= right) {

			dp[i] = dp[i - 1];
			price[i] = left;
		}
		/*else if (left == right && i < n) {
			price[i] = right;
			if (((i + 1) / dp[i])* arr[dp[i]] + price[(i + 1) % dp[i]] > max(arr[i + 1], arr[i] + arr[1])){

			}
		}*/
		else {
			dp[i] = right;
			price[i] = right;
		}

	}

	for (int i = 1; i < n + 1; i++) {
		cout << dp[i] << ' ' << price[i] << endl;
	}
	delete arr;
	delete price;
	delete dp;

}