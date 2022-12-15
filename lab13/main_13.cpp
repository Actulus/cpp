#include "myifstream.h"

int main() {
	myifstream f("be.txt");
	//cout << f.filesize();
	for (int i = 0; i < f.filesize(); ++i) {
		cout << f[i];
	}
	cout << endl;
	return 0;
}