#include <iostream>
#include <vector>
using namespace std;


int sumOf(vector<int> v) {
	int sum_i = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		sum_i += *it;
	}

	return sum_i;
}


bool  get100(const vector<int>& heights, vector<int>& stack) {

	if (sumOf(stack) > 100) {
		
		return false;
	}
	if (sumOf(stack) == 100) {
		if (stack.size() != 7)return false;
		return true;
	}

	for (int i = 0; i < heights.size(); i++){
			vector<int> temp = heights;
			stack.push_back(heights[i]);
			temp.erase(temp.begin(),temp.begin() + i + 1 );
			if (get100(temp, stack)) {
				return true;
			}
			else {
				stack.pop_back();
			}
		}
	return false;

}


int main() {
	cin.sync_with_stdio(0);
	vector<int> varr;

	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		varr.push_back(a);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8 - i; j++) {
			if (varr[j] > varr[j + 1]) {
				int temp = varr[j + 1];
				varr[j + 1] = varr[j];
				varr[j] = temp;
			}
		}
	}

	vector<int> stack;
	
	if (get100(varr, stack)) {
		for (int i = 0; i < stack.size(); i++) {
			cout << stack[i] << endl;
		}
	}
	else cout << "fail" << endl;

	
	
	
	
}