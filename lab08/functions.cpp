//
// Created by Pati on 11/10/2022.
//

#include "functions.h"

#include <random>

void exercises() {
	/*fruits();
	isAllEven();
	doubleIt();
	months();
	sortDesc();
	monthsAndTemperature();
	sortAbs();
	monthsLower();*/
	alphabetShuffler();
}

void fruits() {
	//1
	cout << "\nSubstring in fruits name";
	vector<string> fruits{
			"melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
	};

	string fruit;
	cout << "\nEnter a fruit's name\n";
	cin >> fruit;
	auto it = find_if(fruits.begin(), fruits.end(), [fruit](const string &iFruit) {
		return iFruit.find(fruit) != string::npos;
	});

	if (it != fruits.end()) {
		cout << "Contains " << fruit << " at " << *it << endl;
	} else {
		cout << "Doesn't contain " << fruit << endl;
	}
	cout << endl;
}
void isAllEven() {
//2
	cout << "\nAre are numbers in vector even?\n";
	auto print = [](const int &nr) { cout << nr << " "; };
	vector<int> numbers{2, 4};
	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
	bool even = std::all_of(numbers.begin(), numbers.end(), [](int &nr) {
		return nr % 2;
	});

	if (even == 0) {
		cout << "All numbers are even" << endl;
	} else {
		cout << "Not all numbers are even" << endl;
	}
	cout << endl;
}

void doubleIt() {
	//3
	cout << "\nDouble all elements in vector\n";
	auto print = [](const int &nr) { cout << nr << " "; };
	vector<int> numbers{1, 2, 3};
	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
	std::for_each(numbers.begin(), numbers.end(), [](int &nr) { nr = nr * 2; });
	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
}

void months() {
	//4
	cout << "\nHow many months with the length of 5?";
	vector<string> months{
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
	};

	int length5 = 0;

	std::for_each(months.begin(), months.end(), [&length5](string &month) {
		if (month.length() == 5) {
			length5++;
		}
	});

	auto nr = std::count_if(months.begin(), months.end(), [](string &m) {
		return m.length() == 5;
	});
	cout << "\nNumber of months with 5 letter(count_if): " << nr;
	cout << "\nNumber of months with 5 letter: " << length5 << endl;
}

void sortDesc() {
	//5
	cout << "\nSort vector of numbers in descending order\n";
	auto print = [](const auto &nr) { cout << nr << " "; };

	vector<double> numbers{2.4, 5.1, 6.0, 3.33, 2.3, 7.67, 8.43};
	vector<double> numbers2{2.4, 5.1, 6.0, 3.33, 2.3, 7.67, 8.43};

	cout << "Before and after sort:\n";
	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
	sort(numbers.begin(), numbers.end(), [](double &nr1, double &nr2) -> bool {
		return nr1 > nr2;
	});

	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;

	cout << "\nBefore and after sort:\n";
	std::for_each(numbers2.begin(), numbers2.end(), print);
	std::sort(numbers2.begin(), numbers2.end(), greater<>());
	cout << endl;
	std::for_each(numbers2.begin(), numbers2.end(), print);
	cout << endl;
}

void monthsAndTemperature() {
	//6
	cout << "\nSort months by their average temperature\n";
	cout << "The average temperature in Bucharest by months\n";
	auto print = [](const pair<string, double> &p) {
		cout << "\t" << p.first << " : " << p.second << "C" << endl;
	};
	vector<pair<string, double>> monthsWithMeanTemp{{"January",   -1},
	                                                {"February",  1},
	                                                {"March",     6},
	                                                {"April",     12},
	                                                {"May",       17},
	                                                {"June",      21},
	                                                {"July",      23},
	                                                {"August",    23},
	                                                {"September", 18},
	                                                {"October",   12},
	                                                {"November",  6},
	                                                {"December",  0}};
	std::sort(monthsWithMeanTemp.begin(), monthsWithMeanTemp.end(),
	          [](pair<string, double> &p1, pair<string, double> &p2) -> bool {
		          return p1.second < p2.second;
	          });

	std::for_each(monthsWithMeanTemp.begin(), monthsWithMeanTemp.end(), print);
	cout << endl;
}

void sortAbs() {
	//7
	cout << "\nSort vector by absolute value\n";
	auto print = [](auto &item) { cout << item << " "; };
	vector<double> numbers{4.5, -2.53, 2.46, -8.34, 9.12, -4.34, 3.33};

	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
	std::sort(numbers.begin(), numbers.end(), [](double &nr1, double &nr2) -> bool {
		return abs(nr1) < abs(nr2);
	});
	std::for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
}

void monthsLower() {
	//8
	cout << "\nTransform months to lowercase\n";
	auto print = [](auto &item) { cout << item << endl; };
	vector<string> months{
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
	};

	std::for_each(months.begin(), months.end(), [](string &month) {
		std::transform(month.begin(), month.end(), month.begin(), ::tolower);
	});
	for_each(months.begin(), months.end(), print);
	cout << endl;
}

void alphabetShuffler() {
	//9
	cout << "\nShuffle the alphabet and sort months by this new alphabet\n";
	auto print = [](auto &item) { cout << item << " "; };
	auto print2 = [](auto &item) { cout << item << endl; };
	vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f',
	                      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	vector<string> months{
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
	};

	vector<int> position(26, -1);

	std::for_each(alphabet.begin(), alphabet.end(), print);
	cout << endl;
	std::random_shuffle(alphabet.begin(), alphabet.end());
	cout << endl;

	std::for_each(months.begin(), months.end(), [](string &month) {
		std::transform(month.begin(), month.end(), month.begin(), ::tolower);
	});
	for_each(months.begin(), months.end(), print2);
	cout << endl;

	auto i = 0;
	std::for_each(alphabet.begin(), alphabet.end(), [&position, &i](char &c) {
		if (position[c - 'a'] == -1) {
			position[c - 'a'] = i;
			++i;
		}
	});

	//std::for_each(position.begin(), position.end(), print);
	cout << endl;

	int it1 = 0;
	std::sort(months.begin(), months.end(), [&position, &it1](string &m1, string &m2) -> bool {
		if (position[m1.front() - 'a'] != position[m2.front() - 'a']) {
			return position[m1.front() - 'a'] < position[m2.front() - 'a'];
		} else {
			it1 = 0;
			while (position[m1.at(it1) - 'a'] == position[m2.at(it1) - 'a']) {
				if (it1 == m1.size() || it1 == m2.size()) {
					return m1.size() < m2.size();
				}
				++it1;
			}
			return position[m1.at(it1) - 'a'] < position[m2.at(it1) - 'a'];
		}
	});
	std::for_each(alphabet.begin(), alphabet.end(), print);
	cout << endl;
	std::for_each(months.begin(), months.end(), print2);
	cout << endl;
}