#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int main() {

	int n, m;
	vector<int> vec;
	cin >> n >> m;

	bool** map = new bool*[n];
	int** visited = new int*[n];
	for (int i = 0; i < n; i++) {
		map[i] = new bool[m];
		visited[i] = new int[m];
	}


	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			map[i][j] = s.at(j) - '0';
			visited[i][j] = 0;
		}

	}

	stack<int> s;
	visited[0][0];

	while (!s.empty()) {
		int top = s.top();
		
		int curx = top%m;
		int cury = top / m;

		visited[cury][curx] = 1;

		if (curx == m - 1 && cury == n - 1) {
			vec.push_back(s.size());
		}


		bool allchecked = true;
		for (int i = 0; i < 4; i++) {
			if (cury == 0 && i == 0)continue;
			if (curx == m - 1 && i == 1)continue;
			if (cury == n - 1 && i == 2)continue;
			if (curx == 0 && i == 3)continue;

			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (map[ny][nx] && !visited[ny][nx]) {
				s.push(ny * m + nx);
				allchecked = false;
				break;
			}
			

		}
		if (allchecked) {
			s.pop();
		}



	}



	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << ' ';
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		delete[] map[i];
		delete[] visited[i];
	}
	delete[] map;
	delete[] visited;
}