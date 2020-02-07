#include <iostream>
#include <string>

using namespace std;

const int sSize = 10000;


class stack
{
public:

	stack() {
		data = new int[sSize];

		for (int i = 0; i < sSize; i++) {
			data[i] = -1;
		}
	}

	int length() {
		for (int i = 0; i < sSize; i++) {
			if (data[i] == -1)return i;
		}
		return sSize;
	}
	
	int push(int number) {
		if (this->length() == sSize) return -1;

		data[this->length()] = number;
		return number;
	}

	int pop() {
		if (this->length() == 0)return -1;

		int temp = data[this->length() - 1];
		data[this->length() - 1] = -1;
		return temp;
	}

	bool empty() {
		if (this->length() == 0)return 1;
		return 0;
	}

	int top() {
		if (this->length() == 0)return -1;
		return data[this->length() - 1];
	}

private:

	int *data;


};



int main() {

	int n;
	cin >> n;
	stack S;
	for (int i = 0; i < n; i++) {

		string order = "";
		cin >> order;

		if (order == "push") {
			int num;
			cin >> num;
			S.push(num);
		}
		else if (order == "pop") {
			cout << S.pop() << endl;
		}
		else if (order == "size") {
			cout << S.length() << endl;
		}
		else if (order == "empty") {
			cout << (int)(S.empty()) << endl;
		}
		else if (order == "top") {
			cout << S.top() << endl;
		}
		else {
			i--;
			continue;
		}
	}
	
}