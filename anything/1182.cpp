#include <iostream>
#include <vector>
using namespace std;
static int call = 0;



int canMakeSum(const vector<int>& set, int goal) {
	call++;
	if (set.empty()) {
		if (goal == 0) {
			cout << call << ' ' << 1 << endl;
			return 1;
		}
		cout << call << ' ' << 0 << endl;
		return 0;
	}
	vector<int> temp = set;
	int store = *(temp.end() - 1);
	temp.pop_back();
	
	int result = canMakeSum(temp, goal) + canMakeSum(temp, goal - store);
	cout << call << ' ' << result << endl;
	return result;
	
	
	
}

int main() {
	cin.sync_with_stdio(0);

	int n, s;

	cin >> n >> s;
	vector<int> Set;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (Set[j] == a) {
				flag = false;
				break;
			}
		}
		if (flag)Set.push_back(a);
	}
	if(s==0)
	cout << canMakeSum(Set, s) - 1 << endl;
	else cout << canMakeSum(Set, s) << endl;

	
	cout << call << endl;
}