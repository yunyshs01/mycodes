#include<iostream>
#include<vector>
using namespace std;
void funtion(int lo, int hi, int selection, vector<int> &vec) {


	if (selection == 0) {

		for (auto &i = vec.begin(); i < vec.end(); i++) {
			cout << *i << ", ";
		}
		cout << endl;
		return;
	}
	if (hi - lo + 1 < selection)return;

	
	for (int i = lo; i <= hi; i++) {
		vec.push_back(i);
		funtion(i+1, hi, selection - 1,vec);
		vec.pop_back();

	}
}

int main() {

vector<int> v;

int lo, hi, selection;
cout << "lo, hi, selection : " << endl;
cin >> lo >> hi >> selection;

	funtion(lo,hi,selection,v);
	

}