#include<iostream>
using namespace std;

#define MOD 10007

int main() {

	int	arr[1001];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 1001; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
	}
	int n;
	cin >> n;
	cout << arr[n] << endl;


}