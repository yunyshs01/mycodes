#include <iostream>
#include <vector>

#define MIN -10000

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

static int sum = MIN;



int subSum(const vector<int>& arr,int* dp,int last) {

	if (last == 0)return sum = arr[0];
	if (dp[last] != -1)return dp[last];
	
	dp[last] = max(subSum(arr,dp, last - 1) + arr[last], arr[last]);
	if (sum < dp[last])sum = dp[last];
	return dp[last];
}

int main() {
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	int *dp = new int[n];

	

	vector<int> v;
	for (int i = 0; i < n; i++) {
		dp[i] = -1;
		int a;
		cin >> a;
		
		v.push_back(a);
	}

	
	subSum(v, dp, n - 1);
	cout << sum << endl;

	
}