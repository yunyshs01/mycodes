#include <iostream>
#include <vector>
using	namespace std;

int function(int goal, vector<int> parr) {
	static int count = 0;
	if (parr.size() <= 1) {
		if (goal%parr.back() == 0)count++;
		return count;
	}
	int tgoal = goal;
	int max = parr.back();
	parr.pop_back();
	while (1) {
		
		function(tgoal, parr);
		tgoal -= max;
		if (tgoal < 0)break;
	}

	return count;

}


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() -  i - 1; j++) {
			if (arr[i + 1] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	cout << function(k, arr) << endl;


}