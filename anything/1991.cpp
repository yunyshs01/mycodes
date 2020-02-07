#include<iostream>
using namespace std;



struct Node
{
	Node* parent;
	Node* left;
	Node* right;
	char data;

};

void print(Node* obj) {
	cout << obj->data << endl;
}

class Tree {
private:
	Node* root;

public:

	Tree() 
	{
		root = new Node;
		root->parent = NULL;
	}

	Tree(Node* obj) {
		root = obj;
		
	}

	Node* getRoot() {
		return root;
	}

	void preorder(Node* obj) {
		if (obj == NULL)return;

		cout << obj->data << endl;
		preorder(obj->left);
		preorder(obj->right);

	}

	void inorder(Node* obj) {
		if (obj == NULL)return;

		inorder(obj->left);
		cout << obj->data << endl;
		inorder(obj->right);

	}

	void postorder(Node* obj) {
		if (obj == NULL)return;

		postorder(obj->left);
		postorder(obj->right);
		cout << obj->data << endl;

	}

	Node* preorder(Node* obj, Node* (*func)(Node* fobj)) {
		if (obj == NULL)return NULL;

		Node* ret = func(obj);
		preorder(obj->left);
		preorder(obj->right);

		return ret;
	}

	void insert(char a, char b, char c) {

	}
};

int main() {
	Node* newNode = new Node;
	newNode->data = 'A';
	Tree tr(newNode);
	tr.preorder(newNode,)


}