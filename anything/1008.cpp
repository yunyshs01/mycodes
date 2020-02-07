#include <iostream>
#include <cstdlib>
using namespace std;

int _main() {
	int arr[10] = { 0, };
	char  str[1000000];
	int a, b, c;
	
	cin >> a >> b >> c;
	a = a*b*c;
	_itoa_s(a, str, 1000000);

	for (int i = 0; str[i] != '\0'; i++) {
		arr[str[i] - '0']++;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	return 0;

}