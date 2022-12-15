//
// Created by Pati on 12/15/2022.
//

#ifndef LAB13_HUFFMAN_H
#define LAB13_HUFFMAN_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

class HuffmanTreeNode {
public:
	char data;
	int freq;
	HuffmanTreeNode *left;
	HuffmanTreeNode *right;
	HuffmanTreeNode(char character, int frequency) {
		this->data = character;
		this->freq = frequency;
		this->left = this->right = nullptr;
	}
};

class Compare {
public:
	bool operator()(HuffmanTreeNode *a, HuffmanTreeNode *b) {
		return a->freq > b->freq;
	}
};

class Huffman {
private:
	map<char, int> text;
public:
	Huffman(string file);
	void printToFile(ostream &fout, HuffmanTreeNode *root, int arr[], int top);
	void HuffmanCodes();
	HuffmanTreeNode *generateTree(priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq);
};


#endif //LAB13_HUFFMAN_H
