#include <iostream>
using namespace std;




int main() {


	int a;
	char op;
	int b;
	cin >> a >> op >> b;

	switch (op)
	{

	case '+':
		cout << a + b << endl;
		break;
	case '-':
		cout << a - b << endl;
		break;
	case '*':
		cout << a*b << endl;
		break;
	case '/':
		cout << a / b << endl;
		break;
	case '%':
		cout << a%b << endl;
		break;
	case '~':
		cout << (float)a / (float)b << endl;
		break;
	default:
		break;
	}
	
}