#include<iostream>
#include <vector>
using namespace std;


#define MAXIMUM 100





int main() {
	cin.sync_with_stdio(0);
	
	int n;
	cin >>n;
	vector<int> arr;

	vector<int> answerA;
	vector<int> answerB;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		
	}
	if (n == 1) {
		cout << "A" << endl;
		return 0;
	}

	for (int b = -MAXIMUM; b < MAXIMUM; b++) {
		bool flag = true;
		vector<int> modi;
		modi.push_back(arr[0]);
		modi.push_back(arr[1] - b);

		if ((arr[0]) == 0) {



			for (int i = 1; i < modi.size(); i++) {
				if (arr[i] != 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answerA.push_back(0);
				
				answerB.push_back(b);
				
			}
			break;

		}
		if ((modi[1]) % (modi[0]) != 0)continue;

		int r = (modi[1]) / (modi[0]);
		modi.pop_back();
		for (int i = 1; i < arr.size(); i++) {
			modi.push_back(arr[i - 1]*r + b);

		}
		
		
		
		
		for (int i = 0; i < arr.size(); i++) {
			if (modi[i] != arr[i]) {
				flag = false;
				break;
			}
		}
		

			
			

			if (flag) {
				
					answerA.push_back(r);
					answerB.push_back(b);
					
				
			
		}
		
		
	}

	 if (answerA.size() == 0) {
		cout << "B" << endl;
	}
	else {
		int sameflag = true;
		int answer = arr.back()*answerA[0] + answerB[0];
		for (int i = 0; i < answerA.size(); i++) {
			if (arr.back()*answerA[i] + answerB[i] != answer)sameflag = false;
		}
		if (sameflag) {
			cout << answer << endl;
		}
		else {
			cout << "A" << endl;
		}
	}

}