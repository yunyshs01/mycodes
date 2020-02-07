#include <iostream>

#include<iomanip>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

struct Node
{
	Node* to[4] = { NULL, NULL, NULL, NULL };
	bool map;
	int chome = -1;

};

int main() {

	int n, m;
	vector<int> vec;
	cin >> n >> m;

	Node*** data = new Node**[n];
	for (int i = 0; i < n; i++) {
		data[i] = new Node*[m];
	}


	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Node* newNode;
		for (int j = 0; j < s.length(); j++) {
			newNode = new Node;
			newNode->map = s.at(j) - '0';
			data[i][j] = newNode;
			if (i != 0) {
				newNode->to[0] = data[i - 1][j];
				data[i - 1][j]->to[2] = newNode;
			}
			if (j != 0) {
				newNode->to[3] = data[i][j - 1];
				data[i][j - 1]->to[1] = newNode;
			}

		}

	}

	queue<Node*> q;
	q.push(data[0][0]);
	int day = 0;
	data[0][0]->chome = 0;
	while (!q.empty()) {
		Node* top = q.front();
		for (int i = 0; i < 4; i++) {
			if (top->to[i] == NULL || top->to[i]->map == 0)continue;

			if (top->to[i]->chome == -1) {
				top->to[i]->chome = top->chome + 1;
				q.push(top->to[i]);
			}
			
		}

		if (top->chome == day)day++;
		q.pop();
	}
	
	cout << 1 +data[n - 1][m - 1]->chome << endl;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<setw(3) << data[i][j]->chome;
		}
		cout << endl;
	}
	*/

	

	
}