#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;
	map<string, int> zukan;
	vector<string> arr;
	arr[0] = "";
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		zukan[str] = i + 1;
		arr.push_back(str);
		str.clear();
	}

	for (int i = 0; i < m; i++) {
		
		
		cin >> str;
		if (str[0] > '1' && str[0] < '9') {
			cout << arr[stoi(str)] << endl;
		}
		else {
			cout << zukan[str] << endl;
		}
		str.clear();
	}


}
