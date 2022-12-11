#include <fstream>
using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

struct Node {
	Node(int _info = 0, Node* _left = 0, Node* _right = 0) : info(_info), left(_left), right(_right) { }
	int info;
	Node* left;
	Node* right;
};

class BinaryTree {
public:
	BinaryTree() : pTree(nullptr) { }
	~BinaryTree() { Erase(pTree); }

	void Erase(Node*& t) {
		if (t) {
			Erase(t->left);
			Erase(t->right);
			delete t;
		}
	}

	void Insert(int data) {
		Node** cur = &pTree;
		while (*cur) {
			Node& node = **cur;
			if (data < node.info) {
				cur = &node.left;
			}
			else if (data > node.info) {
				cur = &node.right;
			}
			else {
				return;
			}
		}
		*cur = new Node(data);
	}

	Node* t_delete_node(Node* root, int key) {
		if (root == nullptr)
			return root;
		if (root->info > key) {
			root->left = t_delete_node(root->left, key);
			return root;
		}
		else if (root->info < key) {
			root->right = t_delete_node(root->right, key);
			return root;
		}

		if (root->left == nullptr)
			return root->right;
		else if (root->right == nullptr)
			return root->left;
		else {
			int min_info = min_value(root->right)->info;
			root->info = min_info;
			root->right = t_delete_node(root->right, min_info);
			return root;
		}
	}

	void delete_node(int key) {
		Node** pp = &pTree;
		pTree = t_delete_node(*pp, key);
	}

	Node* min_value(Node* node) {
		if (node->left)
			return min_value(node->left);
		else
			return node;
	}

	bool is_leaf(Node* t) {
		if (t->left == nullptr && t->right == nullptr)
			return true;
		else
			return false;
	}

	bool two_sons(Node* t) {
		if (t->left != nullptr && t->right != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	bool one_son(Node* t) {
		if (t->left != nullptr && t->right == nullptr) {
			return true;
		}
		if (t->left == nullptr && t->right != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void PreOrderPrint(Node* t) {
		if (t == nullptr) {
			return;
		}
		fout << t->info << endl;
		PreOrderPrint(t->left);
		PreOrderPrint(t->right);
	}
	Node* pTree;
};

int main() {
	BinaryTree tree;
	int del_key;
	fin >> del_key;
	while (!fin.eof()) {
		int tmp;
		fin >> tmp;
		tree.Insert(tmp);
	}
	tree.delete_node(del_key);
	//fout << tree.min_value(tree.pTree)->info << endl << endl;
	tree.PreOrderPrint(tree.pTree);
	return 0;
}
