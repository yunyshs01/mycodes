#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void*a, const void*b) {
	return (*(int*)a - *(int*)b);
}




int main() {
	ios::sync_with_stdio(0);
	int inputlength;
	cin >> inputlength;

	

	int *A = new int[inputlength];
	int *B = new int[inputlength];
	int *temp = new int[inputlength];


	for (int i = 0; i < inputlength; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < inputlength; i++) {
		cin >> B[i];
		temp[i] = B[i];
	}

	qsort(temp, inputlength, sizeof(int), compare);
	qsort(A, inputlength, sizeof(int), compare);

	int sum = 0;
	for (int i = 0; i < inputlength; i++) {
		sum += A[inputlength-1-i] * temp[i];
	}
	
	cout << sum << endl;

	delete A;

	delete B;


	delete temp;

	return 0;
}