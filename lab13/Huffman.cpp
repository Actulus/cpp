//
// Created by Pati on 12/15/2022.
//

#include "Huffman.h"

Huffman::Huffman(string file) {
	ifstream fin(file);
	char c;
	int counter = 0;
	while (fin >> c) {
		if (c == '\n') {
			counter = 0;
		}
		text.insert(make_pair(c, 0));
		text.find(c)->second++;
	}

	/*for (auto i: text) {
		cout << i.first << " " << i.second << endl;
	}*/

	fin.close();
}
void Huffman::printToFile(ostream &fout, HuffmanTreeNode *root, int arr[], int top) {
	if (root->left) {
		arr[top] = 0;
		printToFile(fout, root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printToFile(fout, root->right, arr, top + 1);
	}
	if (!root->left && !root->right) {
		fout << root->data << setw(10);
		fout << text.find(root->data)->second << setw(10);
		for (int i = 0; i < top; ++i) {
			fout << arr[i];
		}
		fout << endl;
	}
}
void Huffman::HuffmanCodes() {
	priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq;

	for (auto i: text) {
		auto *newnode = new HuffmanTreeNode(i.first, i.second);
		pq.push(newnode);
	}

	HuffmanTreeNode *root = generateTree(pq);

	int top = 0, arr[100];
	ofstream fout("kimenet.txt");
	fout << "Char" << setw(10) << "Freq." << setw(10) << "Code\n";
	printToFile(fout, root, arr, top);
	fout.close();
}
HuffmanTreeNode *Huffman::generateTree(priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq) {
	while (pq.size() != 1) {
		HuffmanTreeNode *left = pq.top();
		pq.pop();

		HuffmanTreeNode *right = pq.top();
		pq.pop();

		auto *node = new HuffmanTreeNode('$', left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}
	return pq.top();
}
