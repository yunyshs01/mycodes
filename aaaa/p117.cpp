#include <iostream>
#include <vector>
using namespace std;

const int MIN = numeric_limits<int>::min();

int inefficientMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; ++j) {
			int sum = 0;
			for (int k = i; k <= j; ++k)sum += A[k];
			ret = ret > sum ? ret : sum;

		}
		
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);

	vector<int> v;

	int input;
	while (cin>>input)
	{
		v.push_back(input);
	}

	cout << inefficientMaxSum(v) << endl;


}