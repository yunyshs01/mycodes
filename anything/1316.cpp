#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		string s;
		cin >> s;
		int arr[26];
		for (int k = 0; k<26; k++) {
			arr[k] = -1;

		}
		
		
		for (int j = 0; j < s.length(); j++){
			if (arr[s[j] - 'a'] == -1) {
				arr[s[j] - 'a'] = j;
			}
			else if(j - arr[s[j] - 'a']==1){
				arr[s[j] - 'a'] = j;
			}
			else {
				flag = false;
			}

		}

		if (flag) {
			count++;
			//cout << "true" << endl;
		}
	}

	cout << count << endl;

}