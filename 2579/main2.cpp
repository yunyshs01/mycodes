#include <iostream>
using namespace std;

int function(int N,const int* score, int DP[][2]);
int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	int N;
	cin >> N;

	int score[301] = { 0, };
	int DP[301][2];

	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	for (int i = 1; i < N; i++) {
		function(i, score, DP);
	}

	cout << function(N, score, DP);
}

int function(int N, const int* score, int DP[][2]) {
	if (N == 1) {
		DP[N][0] = score[N];
		DP[N][1] = 0;
		return max(DP[N][0], DP[N][1]);
	}
	if (N == 2) {
		DP[N][0] = DP[1][0] + score[2];
		DP[N][1] = score[2];
		return max(DP[N][0], DP[N][1]);

	}

	DP[N][0] = DP[N - 1][1] + score[N];
	DP[N][1] = max(DP[N - 2][0], DP[N - 2][1]) + score[N];
	return max(DP[N][0], DP[N][1]);

}