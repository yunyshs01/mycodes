#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int function(vector<int>& vec, int money, int now) {
	if (vec.empty()) {
		return now;
	}
	if (money == 0)return now;

	int divider = vec.back();

	vec.pop_back();
	int pass = function(vec, money, now);
	now = now + money/ divider;
	int done = function(vec, money%divider, now);
	

	return min(pass, done);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> clist;


	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		clist.push_back(a);
	}

	cout << function(clist, k, 0) << endl;
}
