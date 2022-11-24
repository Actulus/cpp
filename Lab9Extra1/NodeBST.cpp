//
// Created by Pati on 11/22/2022.
//

#include "NodeBST.h"

void NodeBST::inorder(NodeBST::Node *node) const {
	if (node == nullptr) { return; }
	inorder(node->left);
	cout << node->val << " ";
	inorder(node->right);
}

void NodeBST::preorder(NodeBST::Node *node) const {
	if (node == nullptr) { return; }
	cout << node->val << " ";
	preorder(node->left);
	preorder(node->right);
}

void NodeBST::postorder(NodeBST::Node *node) const {
	if (node == nullptr) { return; }
	postorder(node->left);
	postorder(node->right);
	cout << node->val << " ";
}

void NodeBST::deleteSubTree(NodeBST::Node *node) {
	if (node == nullptr) { return; }
	else {
		deleteSubTree(node->left);
		deleteSubTree(node->right);
		delete node;
	}
}
NodeBST::NodeBST() {
	this->root = new Node(0, nullptr, nullptr);
}
NodeBST::~NodeBST() {
	deleteSubTree(this->root);
}
void NodeBST::insert(int val) {
	Node *node = new Node(val);
	if (!root) {
		root = node;
		return;
	}
	Node *tempRoot = this->root;
	Node *prev = nullptr;
	while (tempRoot) {
		if (tempRoot->val > val) {
			prev = tempRoot;
			tempRoot = tempRoot->left;
		} else if (tempRoot->val < val) {
			prev = tempRoot;
			tempRoot = tempRoot->right;
		} else {
			return;
		}
	}
	if (prev->val > val) {
		prev->left = node;
	} else {
		prev->right = node;
	}

}
bool NodeBST::find(int val) const {
	Node *temp = this->root;
	while (temp != nullptr) {
		if (temp->val == val) {
			return true;
		} else if (temp->val > val) {
			temp = temp->left;
		} else {
			temp = temp->right;
		}
	}
	return false;
}
void NodeBST::print_inorder() const {
	Node *tempRoot = this->root;
	inorder(tempRoot);
}
void NodeBST::print_preorder() const {
	Node *tempRoot = this->root;
	preorder(tempRoot);
}
void NodeBST::print_postorder() const {
	Node *tempRoot = this->root;
	postorder(tempRoot);
}
