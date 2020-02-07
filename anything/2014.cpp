#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<map>


using namespace std;



	


int main() {
	int k, n;

	cin.sync_with_stdio(0);
	cin >> k >> n;
	int* arr = new int[k];				//소수들을 받을 정수배열
	//vector<int> v;
	map<int,bool> lists;
	priority_queue<int, vector<int>, greater<>> q;
	


	
	
	
	
	for (int i = 0; i < k; i++) {		//처음 나오는 소수들을 입력받아 배열과 힙에 넣음
		cin >> arr[i];
		q.push(arr[i]);
		lists[arr[i]] = 1;
		
		
	}

		int Max = 0;
	for (int i = 0; i < n; i++) {
	//while(!q.empty()){
		
		int top = q.top();
		q.pop();

		
		for (int j = 0; j < k; j++) {

			int next = top*arr[j];

			if (q.size() + i + 1 > n && next > Max)break;
			
			if (lists[next] == 0) {
				q.push(next);
				lists[next] = 1;
				Max = Max > next ? Max : next;
			}
		}
		//v.push_back(top);
	}




	/*for (auto i : v) {
		cout << i << ", ";
	}*/

	

	cout << q.top();
	cout << endl;
	return 0;
}