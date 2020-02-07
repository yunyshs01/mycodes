#include<iostream>

using namespace std;

int divsum(int num) {
	int dvs = 0;
	int nownum = num;
	while (true)
	{
		if (nownum == 0)break;

		dvs += nownum % 10;
		nownum /= 10;

	}
	dvs += num;
	return dvs;
}

int main() {
	int n;
	cin >> n;


	int log = 0;
	int nown = n;
	while (true)
	{
		if (nown / 10 == 0)break;

		log++;
		nown /= 10;

	}

	int rangeMax = 1;
	for (int i = 0; i < log; i++) {
		rangeMax *= 10;
	}

	int rangeMin = rangeMax - 9 * log;
	rangeMax = rangeMax * 10 - 1 > 1000000 ? 1000000 : rangeMax * 10 - 1;

	int result = 0;
	for (int i = rangeMin; i <= rangeMax; i++) {
		if (divsum(i) == n) {
			result = i;
			break;
		}
	}

	cout << result << endl;

}