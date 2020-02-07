#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int ret = 0;
	while (n>0)
	{
		if (n % 2)ret++;


		n /= 2;
	}

	cout << ret << endl;
}