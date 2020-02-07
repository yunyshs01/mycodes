#include <iostream>

#include<iomanip>
#include <string>
#include <queue>
#include<algorithm>

using namespace std;

vector<int>popu;
int chomes = 0;

struct Node
{
	Node* to[4] = { NULL, NULL, NULL, NULL };
	bool map;
	int chome = -1;

};

int main() {

	int n;
	
	cin >> n;

	Node*** data = new Node**[n];
	for (int i = 0; i < n; i++) {
		data[i] = new Node*[n];
	}


	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		Node* newNode;
		for (int j = 0; j < str.length(); j++) {
			
			newNode = new Node;
			newNode->map = str.at(j)-'0';
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

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << data[i][j]->map;
		}
		cout << endl;
	}*/

	queue<Node*> q;
	
	
	

	for (int i = 0; i < n*n; i++) {
		if (data[i / n][i%n]->chome != -1 || data[i / n][i%n]->map == 0)continue;
		data[i / n][i%n]->chome = ++chomes;
		q.push(data[i / n][i%n]);
		int counter = 0;
		while (!q.empty()) {
			Node* top = q.front();
			for (int i = 0; i < 4; i++) {
				if (top->to[i] == NULL || top->to[i]->map == 0)continue;

				if (top->to[i]->chome == -1) {
					top->to[i]->chome = top->chome;
					q.push(top->to[i]);
				}

			}

			
			q.pop();
			counter++;
		}
			popu.push_back(counter);

	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<setw(3) << data[i][j]->chome;
		}
		cout << endl;
	}*/
	sort(popu.begin(), popu.end());
	cout << chomes << endl;
	for (int i =  0; i < chomes; i++) {
		cout << popu[i] << endl;
	}

}