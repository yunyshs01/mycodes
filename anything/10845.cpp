#include <iostream>

#include <string>
using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node* next;
public:

	Node():next(NULL)
	{
		
	}
	Node(T nd) :next(NULL), data(nd)
	{

	}
	~Node() {

	}

	T retrieve() {
		return data;
	}

	Node* next() {
		return next;
	}

	void add_back(T nd) {
		if (next == NULL) {
			next = new Node(nd);
		}
	}
};

template <typename T>
class que
{
public:
	que();
	

private:
	Node* head = NULL;


};

que::que()
{
}

que::~que()
{
}

int main() {

	
	que<int> q;


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		try {
			string s;
			cin >> s;
			if (s == "push") {
				int a;
				cin >> a;
				q.push(a);
			}
			else if (s == "pop") {
				int a;
				cin >> a;

				q.pop();
			}
			else if (s == "size") {
				cout << q.size() << endl;

			}
			else if (s == "empty") {
				cout << q.empty() << endl;

			}
			else if (s == "front") {
				cout << q.front() << endl;
			}
			else if (s == "back") {
				cout << q.back() << endl;
			}
		}
		catch (exception e) {
			cout << -1 << endl;
		}
	}
	

}