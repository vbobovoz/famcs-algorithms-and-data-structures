#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	long long info = 0ll;
	long long level = 0ll;
	long long height = 0ll;
	long long depth = 0ll;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(long long _info = 0ll, Node* _left = nullptr, Node* _right = nullptr, long long _depth = 0ll, long long _height = 0ll, long long _level = 0ll) : info(_info), left(_left), right(_right), depth(0), height(0), level(0) { }
};

class BinaryTree {
private:
	Node* root = nullptr;
public:
	BinaryTree() : root(nullptr) { }
	~BinaryTree() { Erase(root); }

	void Erase(Node*& t) {
		if (t) {
			Erase(t->left);
			Erase(t->right);
			delete t;
		}
	}
	// ------------------ INSERT ------------------
	void Insert(long long data) {
		Node** cur = &root;
		long long some_key = 0;
		while (*cur) {
			Node& node = **cur;
			if (data < node.info) {
				cur = &node.left;
				some_key++;
			}
			else if (data > node.info) {
				cur = &node.right;
				some_key++;
			}
			else {
				return;
			}
		}
		*cur = new Node(data);
		(*cur)->depth = some_key;
	}

	// ------------------ DeleteNode ------------------
	Node* DeleteNode(Node* root, long long key) {
		if (root == nullptr)
			return root;
		if (root->info > key) {
			root->left = DeleteNode(root->left, key);
			return root;
		}
		else if (root->info < key) {
			root->right = DeleteNode(root->right, key);
			return root;
		}
		if (root->left == nullptr)
			return root->right;
		else if (root->right == nullptr)
			return root->left;
		else {
			long long min_info = MinValue(root->right)->info;
			root->info = min_info;
			root->right = DeleteNode(root->right, min_info);
			return root;
		}
	}

	void DeleteNode(long long key) {
		Node** pp = &root;
		root = DeleteNode(*pp, key);
	}
	Node* MinValue(Node* node) {
		if (node->left)
			return MinValue(node->left);
		else
			return node;
	}

	// ------------------ Print ------------------
	void PreOrderPrint(ofstream& out, Node* node) {
		if (node == nullptr) {
			return;
		}
		out << node->info << endl;
		PreOrderPrint(out, node->left);
		PreOrderPrint(out, node->right);
	}

	// ------------------ HeightAndLevel ------------------
	void SetHeight(Node* node) {
		if (node == nullptr) {
			return;
		}
		SetHeight(node->left);
		SetHeight(node->right);
		if (node->left == nullptr && node->right == nullptr) {
			node->height = 0;
		}
		else if (node->left == nullptr && node->right != nullptr) {
			node->height = node->right->height + 1;
		}
		else if (node->left != nullptr && node->right == nullptr) {
			node->height = node->left->height + 1;
		}
		else if (node->left != nullptr && node->right != nullptr) {
			node->height = max(node->left->height, node->right->height) + 1;
		}
	}
	void SetLevel(Node* node) {
		if (node == nullptr) {
			return;
		}
		SetLevel(node->left);
		SetLevel(node->right);
		node->level = root->height - node->depth;
	}

	// ------------------ Flags ------------------
	void SetFlags(Node* node, vector<long long>& vec) {
		if (node == nullptr) {
			return;
		}
		if (node->level == root->height / 2) {
			if (node->left != nullptr && node->right != nullptr) {
				if (node->left->height == node->right->height) {
                    vec.push_back(node->info);
				}
			}
			else if (node->left == nullptr && node->right == nullptr) {
                vec.push_back(node->info);
			}
		}
		SetFlags(node->left, vec);
		SetFlags(node->right, vec);
	}

	Node* GetRoot() {
		return root;
	}
};

int main() {
    ofstream fout("out.txt");
	ifstream fin("in.txt");
	BinaryTree tree;
    vector<long long> v;
	while (!fin.eof()) {
		long long data;
		fin >> data;
		tree.Insert(data);
	}
	tree.SetHeight(tree.GetRoot());
	tree.SetLevel(tree.GetRoot());
	tree.SetFlags(tree.GetRoot(), v);

    if(v.size() % 2 == 0) {
        tree.PreOrderPrint(fout, tree.GetRoot());
    }
    else {
        tree.DeleteNode(v[v.size() / 2]);
        tree.PreOrderPrint(fout, tree.GetRoot());
    }
	return 0;
}
