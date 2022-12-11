#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

class TNode {
public:
	TNode(int key) : Key(key), Left(nullptr), Right(nullptr) { }
	int Key;
	TNode* Left;
	TNode* Right;
};

class Tree {
public:
	Tree() : Root(0) { }
	~Tree() { DestroyNode(Root); }
	void Insert(int data);
	void Print(TNode* root);

	TNode* Root;
private:
	static void DestroyNode(TNode* node) {
		if (node) {
			DestroyNode(node->Left);
			DestroyNode(node->Right);
			delete node;
		}
	}
};

void Tree::Insert(int data) {
	TNode** cur = &Root;
	while (*cur) {
		TNode& node = **cur;
		if (data < node.Key) {
			cur = &node.Left;
		} else if (data > node.Key) {
			cur = &node.Right;
		} else {
			return;
		}
	}
	*cur = new TNode(data);
}

void Tree::Print(TNode* root) {
	if(root == nullptr) {
		return;
	}
	fout << root->Key << endl;
	Print(root->Left);
	Print(root->Right);
}

int main() {
	
	Tree tr;
	int tmp = 0;
	while (!fin.eof()) {
		fin >> tmp;
		tr.Insert(tmp);
	}
	tr.Print(tr.Root);
	return 0;
}
