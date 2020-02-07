#include <iostream>
using namespace std;

int function(int n, const int cost[][3], int DP[][3]);
int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	int N;
	cin >> N;

	int(*cost)[3] = new int[N+1][3]();
	int(*DP)[3] = new int[N+1][3]();
	for (int it = 0; it < N; it++) {
		cin >> cost[it][0] >> cost[it][1] >> cost[it][2];
	}


	for (int it = 0; it < N - 1; it++) {
		function(it, cost, DP);
	}

	cout << function(N - 1, cost, DP);
}

int function(int n, const int cost[][3], int DP[][3]) {
	if (n == 0) {
		DP[n][0] = cost[n][0];
		DP[n][1] = cost[n][1];
		DP[n][2] = cost[n][2];
		return min(min(DP[n][0], DP[n][1]), DP[n][2]);
	}

	DP[n][0] = min(DP[n - 1][1], DP[n - 1][2]) + cost[n][0];
	DP[n][1] = min(DP[n - 1][0], DP[n - 1][2]) + cost[n][1];
	DP[n][2] = min(DP[n - 1][0], DP[n - 1][1]) + cost[n][2];

	return min(min(DP[n][0], DP[n][1]), DP[n][2]);

}

