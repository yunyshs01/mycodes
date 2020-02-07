#include<iostream>
#include<vector>
using namespace std;



void function(int*, vector<int>&, int, int, int, int&, int);

int main() {
	int n, m;

	cin >> n >> m;

	vector<int> v;

	int*arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int nearestSum = 0;

	function(arr, v, 0, n, 3, nearestSum, m);

	cout << nearestSum << endl;


	
}

void function(int* arr,vector<int>& v, int lo_idx, int hi_idx, int toPick, int& nearestSum, int m) {
	if (toPick == 0) {
		int nowSum = 0;
		for (vector<int>::iterator i = v.begin(); i < v.end(); i++) {
			nowSum = nowSum + *i;
		}

		if (nowSum <= m && nowSum > nearestSum) {
			
			nearestSum = nowSum;
		}
		return;
	}
	if (hi_idx - lo_idx + 1 < toPick)return;

	for (int i = lo_idx; i <= hi_idx; i++) {
		v.push_back(arr[i]);
		function(arr, v, i + 1, hi_idx, toPick - 1, nearestSum, m);
		v.pop_back();
	}
}