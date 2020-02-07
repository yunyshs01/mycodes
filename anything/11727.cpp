#include<iostream>

using namespace std;

static int arr[1001];

int func(int num) {
	if (arr[num] != -1)return arr[num];

	if (num <= 0) {
		arr[0] = 0;
		return 0;
	}
	if (num == 1) {
		arr[1] = 1;
		return 1;
	}
	if (num == 2) {
		arr[2] = 3;
		return 3;
	}
	arr[num] = ((func(num-2) * 2) % 10007 + func(num-1) % 10007)%10007;
	return arr[num];
}

int main() {
	int a;
	cin >> a;

	for (int i = 0; i < 1001; i++) {
		arr[i] = -1;
	}

	cout << func(a) << endl;
}