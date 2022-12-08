#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	fout.open("output.txt");
	fin.open("bible.txt");
	if (fin.fail()) {
		throw runtime_error("Cannot open file");
	}

	map<string, vector<int>> indexes;
	string line;
	vector<int> temp;
	int counter = 1;

	while (getline(fin, line) && !line.empty()) {
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		indexes.insert(make_pair(line, temp));
	}

	while (fin.peek() != EOF) { //
		getline(fin, line);
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		istringstream iss(line);
		//cout << line << endl;
		for (auto &i: indexes) {
			string temp = "\\b" + i.first + "\\b";
			regex r(temp);
			smatch match;

			//if (line.find(i.first) != string::npos) {
			if (regex_search(line, match, r)) {
				//cout << i.first << " " << counter << endl;
				i.second.push_back(counter);
			}
		}
		counter++;
	}


	for (const auto &index: indexes) {
		//cout << index.first << " ";
		fout << index.first << " ";
		if (index.second.empty()) {
			//cout << "file does not contain";
			fout << "file does not contain";
		} else if (index.second.size() == 1) {
			//cout << index.second[0] << " ";
			fout << index.second[0] << " ";
		} else {
			for (auto i = 0; i < index.second.size(); ++i) {
				if (index.second[i] == index.second[i + 1] - 1) {
					//cout << index.second[i] << "-";
					fout << index.second[i] << "-";
				} else if (i == index.second.size() - 1) {
					//cout << index.second[i] << " ";
					fout << index.second[i] << " ";
				} else {
					//cout << index.second[i] << ", ";
					fout << index.second[i] << ", ";
				}
			}
		}
		//cout << endl;
		fout << endl;
	}

	fin.close();
	fout.close();
	return 0;
}