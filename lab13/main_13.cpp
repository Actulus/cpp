#include "myifstream.h"
#include "Huffman.h"

void ex1();
void ex2();

int main() {
	//ex1();
	ex2();
	return 0;
}

void ex1() {
	myifstream f("be.txt");
	//cout << f.filesize();
	for (int i = 0; i < f.filesize(); ++i) {
		cout << f[i];
	}
	cout << endl;
}

void ex2() {
	Huffman h("bemenet.txt");
	h.HuffmanCodes();
}