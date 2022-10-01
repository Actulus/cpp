//
// Created by Pati on 9/22/2022.
//

#include "functions.h"

void fuggvenyek() {
	//fel1();
//    int nr = 5;
//    int order = 2;
//    cout<<countBits(nr);
//    bitsFrom1To127();
//    fel2(nr, order);
//    fel3();
//    fel4();
	fel5();
}

void fel1() {
	cout << "Hello, World!" << std::endl;
	cout << "\nAdj meg egy szamot:" << endl;
	int x;
	cin >> x;
}

void bitsFrom1To127() {
	cout << endl;
	for (int i = 0; i <= 127; ++i) {
		cout << i << " egyes bitjeinek a szama: " << countBits(i) << endl;
	}
}

int countBits(int number) {
	int ones = 0;
	while (number != 0) {
		/*number = number & (number - 1);
		ones++;*/
		if ((number & 1) == 1) {
			ones++;
		}
		number >>= 1;
	}
	return ones;
}

void fel2(int nr, int order) {
	cout << endl;
	for (int i = 0; i < 31; ++i) {
		int n = 0;
		if (setBit(n, i)) {
			cout << i << " --> " << n << endl;
		} else {
			cout << "Impossible operation!" << endl;
		}
	}
}

bool setBit(int &number, int order) { //& - pointer
	if (number >= 0 && number < 31) {
		number = number | 1 << order;
		return true;
	}
	return false;
}

double fel3() {
	int n;
	cout << "\nHany eleme legyen a tombnek?";
	cin >> n;
	if (n <= 0) {
		return (NAN);
	}
	double a[n];
	cout << "\nAdd meg a tomb elemeit:\n";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << "\nAtlag: " << mean(a, n);
}

double mean(double array[], int numElements) {
	double avg = 0, sum = 0;
	for (int i = 0; i < numElements; ++i) {
		sum += array[i];
	}
	avg = sum / numElements;

	return avg;
}

double fel4() {
	int n;
	cout << "\nHany eleme legyen a tombnek?";
	cin >> n;
	if (n <= 0) {
		return (NAN);
	}
	double a[n];
	cout << "\nAdd meg a tomb elemeit:\n";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout.precision(5);
	cout << "\nSzoras: " << stddev(a, n);
	return 0;
}

double stddev(double array[], int numElements) {
	double e = 0;
	double sum = 0;

	for (int i = 0; i < numElements; ++i) {
		sum += array[i];
	}

	for (int i = 0; i < numElements; ++i) {
		e += pow(array[i] - mean(array, numElements), 2);
	}
	e = e / numElements;
	e = sqrt(e);
	return e;
}

void fel5() {
	int n;
	cout << "Hany elemu a tomb?";
	cin >> n;
	double a[n];
	makeArray(a, n);
	printArray(a, n);
	cout << "\nA tomb ket legnagyobb eleme: " << max2(a, n).first << ", " << max2(a, n).second;
}

void makeArray(double *a, int n) {
	if (n >= 1) {
		cout << "Add meg a tomb elemeit:\n";
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
	}
}

void printArray(double *a, int n) {
	if (n >= 1) {
		cout << "A tomb eleme(i):\n";
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
	}
}

pair<double, double> max2(double array[], int numElements) {
	pair<double, double> max;
	if (numElements <= 0) {
		max = make_pair(NAN, NAN);
	} else if (numElements == 1) {
		max = make_pair(array[0], array[0]);
	} else {
		qsort(array, numElements, sizeof(double), cmp);
		max.first = array[numElements - 1];
		max.second = array[numElements - 2];
	}

	return max;
}

int cmp(const void *a, const void *b) {
	if (*(double *) a > *(double *) b)
		return 1;
	else if (*(double *) a < *(double *) b)
		return -1;
	else
		return 0;
}

void karakterlancok() {
	string s = "alma", szavak;
	cout << "Adj meg egy hosszabb stringet:\n";
	getline(cin, szavak);
	//stringSum(s);
	//cout << "\nszavak szama: " << countWords(s);
	/*cout << "A kodolt szoveg: " << code(s);
	cout << "\nA dekodolt szoveg: " << decode(s);*/
	cout << "\nNagybetusitve: " << capitalizeWords(s);
	cout << "\nNagybetusitve(megadott string): " << capitalizeWords(szavak);

}

void stringSum(const string &s) {
	stringstream stream(s);
	double sum = 0;
	string temp;
	double val;
	while (!stream.eof()) {
		stream >> temp;
		if (stringstream(temp) >> val) {
			cout << val << " ";
			sum += val;
		}

	}
	cout << " osszege = " << sum;
}

int countWords(const string &text) {
	stringstream stream(text);
	string temp;
	int count = 0;
	while (stream >> temp) {
		count++;
	}
	return count;
}

string code(const string &text) {
	string changed;
	int c;

	for (int i = 0; i < text.size(); ++i) {
		c = int(text[i]);

		if (c == 122) {
			changed.append(1, char(97));
		} else if (c == 90) {
			changed.append(1, char(60));
		} else if (c >= 97 && c < 122 || c >= 60 && c < 90) {
			changed.append(1, char(c + 1));
		}
	}

	return changed;
}

string decode(const string &text) {
	string changed;
	int c;

	for (char i: text) {
		c = int(i);

		if (c == 97) {
			changed.append(1, char(122));
		} else if (c == 60) {
			changed.append(1, char(90));
		} else if (c > 97 && c <= 122 || c > 60 && c <= 90) {
			changed.append(1, char(c - 1));
		}
	}

	return changed;
}

string capitalizeWords(string text) {
	for (int i = 0; i < text.length(); ++i) {
		if (i == 0) {
			text[i] = toupper(text[i]);
		} else if (text[i - 1] == ' ') {
			text[i] = toupper(text[i]);
		}
	}

	return text;
}

void extra(char *argv[]) {
	//cout << argv[1] << " " << argv[2];
	FILE *fin;
	fin = fopen("bible.txt", "r");
	if (fin == NULL) {
		cout << "file does not exist";
		return;
	}
	int n;
	cout << "Hany leggyakoribb szot keresunk?";
	cin >> n;

	char buffer[32];

	fclose(fin);
}