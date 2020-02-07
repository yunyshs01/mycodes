#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> v) {
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > max)max = v[i];
	}
	return max;
}

vector<vector<int>> dp;



int main() {
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> Ti;
	vector<int> Pi;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		Ti.push_back(a);
		Pi.push_back(b);
	}

	Ti.push_back(0);
	Pi.push_back(0);
	
	vector<vector<int>> dp(Ti.size() + 1);
	for (int i = 0; i < Ti.size(); i++) {
		if (i != Ti.size() - 1) {
			int psbl = max(dp[i]);
			if (i + Ti[i] < Ti.size() && i + Ti[i] + Ti[i + Ti[i]] < Ti.size())
				psbl += Pi[i + Ti[i]];
			dp[i + 1].push_back(psbl);
		}
		if (i + Ti[i] < Ti.size()) {
			dp[i].push_back(Pi[i]);
			int psbl = max(dp[i]);
			if (i + Ti[i] + Ti[i + Ti[i]] < Ti.size())
				psbl += Pi[i + Ti[i]];
			dp[i + Ti[i]].push_back(psbl);
		}

	}

	int maxnum = 0;
	for (int i = 0; i < Ti.size(); i++) {
		if (maxnum < max(dp[i]))maxnum = max(dp[i]);
	}
	cout << maxnum << endl;
	
}