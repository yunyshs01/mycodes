#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {

	int n, m, v;
	cin >> n >> m >> v;

	int ** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n]();
	}

	vector<int> bfs;
	vector<int> dfs;

	bool* DisChecked = new bool[n]();
	bool* BisChecked = new bool[n]();
	
	

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a>> b;
		matrix[a - 1][b - 1] = 1;
		matrix[b - 1][a - 1] = 1;

	}

	queue<int> q;
	stack<int> s;

	q.push(v - 1);
	BisChecked[v - 1] = true;
	bfs.push_back(v - 1);

	s.push(v - 1);
	DisChecked[v - 1] = true;
	dfs.push_back(v - 1);

	while (!q.empty())									
	{
		int front = q.front();							

		for (int i = 0; i < n; i++) {
			if (matrix[front][i] && !BisChecked[i]) {	
				q.push(i);
				BisChecked[i] = true;
				bfs.push_back(i);
			}
		}


		

		q.pop();

	}

	while (!s.empty())
	{
		int top = s.top();
		
			bool allChecked = true;
		for (int i = 0; i < n; i++) {
			if (matrix[top][i] && !DisChecked[i]) {
				s.push(i);
				DisChecked[i] = true;
				dfs.push_back(i);
				allChecked = false;
				break;
			}
		}

		if (allChecked) {
			
			s.pop();
		}


	}

	for (auto it = dfs.begin(); it != dfs.end(); it++) {
		cout << (*it) + 1 << ' ';
	}
	cout << endl;


	for (auto it = bfs.begin(); it != bfs.end();it++) {
		cout << (*it) + 1 << ' ';
	}
	cout << endl;

	

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] DisChecked;
	delete[] BisChecked;



}