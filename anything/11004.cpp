#include <iostream>
#include <algorithm>
#include<list>


using namespace std;




int main() {
	cin.sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	long* arr = new long[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, &arr[n]);

	

	cout << arr[k - 1] << endl;
	
	delete []arr;

}