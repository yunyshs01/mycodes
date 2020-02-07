#include <iostream>

using namespace std;
struct time
{
	int f;
	int s;

};

int  func (void* a, void*b) {
	if((*(time*)a).f>(*(time*)b).f) {
		return 1;
	}
	else if ((*(time*)a).f<(*(time*)b).f) {
		return -1;
	}
	else {
		return 0;
	}

}

int main() {
	int n;
	cin >> n;
	time* arr = new time[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].f;
		cin >> arr[i].s;
	}


	qsort(arr, n, sizeof(time), func);


}