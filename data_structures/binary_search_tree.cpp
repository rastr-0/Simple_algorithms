#include<iostream>
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	Node() {
		data = 0;
		left = nullptr;
		right = nullptr;
	}
};

class Binary_tree {
private:
	Node* root;
	void destroy(Node* leaf);
	void insert(int key, Node* leaf);
	void inorder_print(Node* leaf);
	void preorder_print(Node* leaf);
	void postorder_print(Node* leaf);
	Node* search(int key, Node* leaf);
public:
	Binary_tree();
	void insert(int key);
	void destroy();
	void inorder_print();
	void preorder_print();
	void postorder_print();
	Node* search(int key);
};
// public functions
Binary_tree::Binary_tree() {
	root = nullptr;
}
Node* Binary_tree::search(int key) {
	return search(key, root);
}
void Binary_tree::insert(int key) {
	if (root != nullptr)
		insert(key, root);
	else {
		root = new Node();
		root->data = key;
	}
}
void Binary_tree::destroy() {
	destroy(root);
}
void Binary_tree::inorder_print() {
	inorder_print(root);
}
void Binary_tree::preorder_print() {
	preorder_print(root);
}
void Binary_tree::postorder_print() {
	postorder_print(root);
}
// private functions
void Binary_tree::insert(int key, Node* leaf) {
	if (key < leaf->data) {
		// if leaf->right isn't a leaf, than go to the next and check
		if (leaf->left != nullptr)
			insert(key, leaf->left);
		// if it is a leaf, than create a new object and initialize data with key
		else {
			leaf->left = new Node();
			leaf->left->data = key;
		}
	}
	else if (key >= leaf->data) {
		// if leaf->right isn't a leaf, than go to the next and check
		if (leaf->right != nullptr)
			insert(key, leaf->right);
		// if it is a leaf, than create a new object and initialize data with key
		else {
			leaf->right = new Node();
			leaf->right->data = key;
		}
	}
}
void Binary_tree::destroy(Node* leaf){
	if (leaf != nullptr) {
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}
// left - > root - > right
void Binary_tree::inorder_print(Node* leaf) {
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		std::cout << leaf->data << " ";
		inorder_print(leaf->right);
	}
}
// root - > left - > right
void Binary_tree::preorder_print(Node* leaf) {
	if (leaf != nullptr) {
		std::cout << leaf->data << " ";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}
// left - > right - > root
void Binary_tree::postorder_print(Node* leaf) {
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		std::cout << leaf->data;
	}
}
Node* Binary_tree::search(int key, Node* leaf) {
	if (leaf != nullptr) {
		if (leaf->data == key)
			return leaf;
		else if (key > leaf->data)
			return search(key, leaf->right);
		else
			return search(key, leaf->left);
	}
	else
		return nullptr; // there are no elements in Binary_tree
}
int main()
{

}
