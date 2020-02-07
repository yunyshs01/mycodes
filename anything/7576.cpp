#include <iostream>
#include<queue>
using namespace std;

struct Node
{
	int tomato;
	Node* toward[4];
	int date = 0;
};

class Tree {
private:
	Node* baseNode;
	Node*** arr;
public:
	Tree(Node* base, int m, int n) {
		baseNode = base;
		arr = new Node**[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Node*[m];
		}
		arr[0][0] = base;
	}
	Node* at(int a, int b) {
		return arr[a][b];
	}
	void set(Node* obj, int a, int b) {
		arr[a][b] = obj;
	}
};



int main() {
	int ctr = 0;
	int wall = 0;
	int m, n;
	cin >> m >> n;
	Node* baseNode = new Node;
	for (int i = 0; i < 4; i++)baseNode->toward[i] = NULL;

	Tree tr(baseNode, m, n);
	queue<Node*> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;

			Node* newNode;
			if (i == 0 && j == 0) {
				newNode = baseNode;

				
			}
			else {
				newNode = new Node;
				for (int k = 0; k < 4; k++) {
					newNode->toward[k] = NULL;
				}
				tr.set(newNode, i, j);
				if (i != 0) {
					newNode->toward[0] = tr.at(i - 1, j);
					newNode->toward[0]->toward[2] = newNode;
				}
				if (j != 0) {
					newNode->toward[3] = tr.at(i, j - 1);
					newNode->toward[3]->toward[1] = newNode;
				}

			}
			newNode->tomato = a;
			if (a == 1) {
				q.push(newNode);
			}
			if (a == -1) wall++;

		}
	}

	int day = 0;
	while (!q.empty()) {
		Node* top = q.front();

		for (int i = 0; i < 4; i++) {
			if (top->toward[i] != NULL) {
				if (top->toward[i]->date == 0 && top->toward[i]->tomato == 0) {
					q.push(top->toward[i]);
					top->toward[i]->date = top->date + 1;
					top->toward[i]->tomato = 1;
				}
			}
		}
		if (top->date == day)day++;
		q.pop();
		ctr++;
	}

	/*cout << day << ' ' << ctr << endl;
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	cout << tr.at(i, j)->date << ' ';
	}
	cout << endl;
	}*/


	if (ctr != m*n - wall || day == 0) {
		cout << -1 << endl;
	}
	else {
		cout << day - 1 << endl;
	}


}