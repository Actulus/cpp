#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

struct Contact {
	std::string name;
	std::string phoneNumber;
//	int year;
};

struct Item {
	std::string name;
	int quantity;
	double price;
};

int feladat1();
void feladat2();
void feladat3();
void feladat4();
void feladat4_2();
void printAllContacts(std::map<std::string, std::vector<Contact>> contacts);
void feladat4_3();
void feladat5();

int main() {
//	feladat1();
//	feladat2();
//	feladat3();
//	feladat4();
//	feladat4_2();
//	feladat4_3();
	feladat5();
	return 0;
}

int feladat1() {
	// szoszamlalo fajlbol
	std::map<std::string, int> wordCount; // map szavak számlálására, egy stringet (szo) es egy szamot (szamlalo) tarol el, ahol a kulcs a szo, az ertek pedig a szamlalo

	// Fajbol olvasas
	std::ifstream inputFile("input.txt");
	if (!inputFile) // ha nem lehet megnyitni a fajlt
	{
		std::cerr << "Hiba a bemeneti fajl megnyitasakor." << std::endl;
		return 1;
	}

	// beolvassuk a szavakat a bemeneti fajlbol
	std::string word;
	while (inputFile >> word) {
		// Frissitjuk a map-et az adott szo (kulcs) szamlalojat (ertek) noveljuk
		wordCount[word]++;
	}

	inputFile.close(); // bezarjuk a fajlt

	// Kiiratjuk a fajlba a szavakat es a hozzajuk tartozo szamlalokat
	std::ofstream outputFile("output.txt");
	if (!outputFile) // ha valamiert nem lehet megnyitni a fajlt
	{
		std::cerr << "Hiba a kimeneti fajl megnyitasakor." << std::endl;
		return 1;
	}

	// for-ral vegigmegyunk a map-en, paronkent veve az elemeket
	for (const auto &pair: wordCount) {
		// kiiratjuk a kimeneti fajlba a par elso es masodik elemet (kulcsot es erteket)
		outputFile << pair.first << ": " << pair.second << std::endl;
	}

	outputFile.close(); // fajl bezarasa

	std::cout << "A szoszamlalo sikeresen kiirva az output.txt fajlba." << std::endl;

	return 0;
}

void feladat2() {
	// diakok es pontszamaik
	// map letrehozasa a student ertekek tarolasara (nev, score)
	std::map<std::string, double> studentScores;

	// adatok beszurasa
	studentScores["Alice"] = 95.5; // az Alice kulcshoz a 95.5-os erteket adjuk meg
	studentScores["Bob"] = 87.2;
	studentScores["Charlie"] = 91.7;
	studentScores["David"] = 78.21;

	// map meretenek kiiratasa
	std::cout << "Size of the map: " << studentScores.size() << std::endl;
	// uj diak hozzaadasa
	studentScores.insert({"Anne", 65.7});
	studentScores.insert(std::make_pair("Anne", 65.7));
	// kulcs ertekenek felulirasa
	studentScores.at("Anne") = 89.7;
	studentScores["Anne"] = 89.7;


	// ket diak ertekeinek kiiratasa
	std::cout << "Score of Alice: " << studentScores["Alice"] << std::endl;
	std::cout << "Score of Alice: " << studentScores.at("Alice") << std::endl;
	std::cout << "Score of Charlie: " << studentScores["Charlie"] << std::endl;

	// letezik-e a diak a map-ben
	std::string searchName = "John";
	if (studentScores.count(searchName) > 0) {
		std::cout << searchName << " is present in the map" << std::endl;
	} else {
		std::cout << searchName << " is not present in the map" << std::endl;
	}

	// vegigiteralunk a map-en es kiiratjuk az elemparokat
	std::cout << "All student scores:" << std::endl;
	for (const auto &entry: studentScores) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}

	// elempar torlese a map-bol
	std::string removeName = "John";
	if (studentScores.count(removeName) > 0) {
		studentScores.erase(removeName);
		std::cout << "Removed " << removeName << " from the map" << std::endl;
	} else {
		std::cout << "No contact like " << removeName << "\n";
	}

	// vegigiteralunk a map-en es kiiratjuk az elemparokat
	std::cout << "All student scores:" << std::endl;
	for (const auto &entry: studentScores) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}

	// map meretenek ellenorzese elemtorles utan
	std::cout << "Size of the map after removal: " << studentScores.size() << std::endl;
}

void feladat3() {
	// szoszamlalo stringgel
	// map szavak es megjelenesi ertek szamlalasara
	std::map<std::string, int> wordFrequency;

	//vizsgalando string
	std::string text = "Lorem ipsum dolor sit amet consectetur adipiscing elit ipsum.";

	// kisbetusitjuk a stringet a konnyebb ellenorzes vegett -> forral vegig kellene menni az egeszen,
	// a transform beepitett algoritmussal ezt konnyebb elvegezni -> ::tolower kisbetusiti
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);

	// irasjelek torlese ".,;:!?" stb. -> ::ispunct megnezi, hogy irasjel-e
	text.erase(std::remove_if(text.begin(), text.end(), ::ispunct), text.end());

	// string szavakra bontasa
	std::istringstream iss(text);
	std::string word;
	while (iss >> word) {
		// a map-ben az adott szo ertekenek novelese
		wordFrequency[word]++;
	}

	// kiiratas
	for (const auto &entry: wordFrequency) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}
}

void feladat4() {
	// telefonkonyv
	// map-ben fogjuk eltarolni a keresztnevet es a nevhez tartozo contactokat, amik tartalmaznak egy teljes nevet es egy telefonszamot
	std::map<std::string, Contact> phoneBook;

	// Contact hozzadasa
	phoneBook["Alice"] = {"Alice Smith", "+123456789"}; // az Alice kulcshoz hozzaadunk egy Contactot
//	phoneBook.at("Alice") = {"Alice Smith", "+123456789"};
	phoneBook["Bob"] = {"Bob Johnson", "+987654321"};
	phoneBook["Charlie"] = {"Charlie Brown", "+111222333"};

	// Contact keresese
	std::string searchName = "Leon";
	if (phoneBook.count(searchName) > 0) { // addig megyunk, amig a keresett nev szerepel
		const Contact &contact = phoneBook[searchName]; // kivesszuk a contactot
		std::cout << "Name: " << contact.name << std::endl; // kiiratjuk a nevet
		std::cout << "Phone Number: " << contact.phoneNumber << std::endl; // kiiratjuk a tel.szamot
	} else {
		std::cout << "Contact not found" << std::endl; // abban az esetben, ha ezzel a nevvel nincs contact
	}

	// Minden contact kiiratasa
	std::cout << "All contacts:" << std::endl;
	for (const auto &entry: phoneBook) {
		std::cout << "Key -" << entry.first << "-\n";
		std::cout << "\tName: " << entry.second.name << std::endl;
		std::cout << "\tPhone Number: " << entry.second.phoneNumber << std::endl;
		std::cout << std::endl;
	}
}

void feladat4_2() {
	// map letrehozasa, egy kulcshoz tobb erteket tarsitunk
	// pl. Bill kulcshoz tarsitjuk Bill Bob es Bill Smith contactocat is
	std::map<std::string, std::vector<Contact>> contacts;

	// elemek hozzadasa
	contacts["Bill"].push_back({"Bill Bob", "+123123123"});
	contacts["Bill"].push_back({"Bill Smith", "+111222333"});
	contacts["Eve"].push_back({"Eve Smith", "+122212221"});
	contacts["Joe"].push_back({"Joe J.", "+012352934"});
//	contacts.at("Lola").push_back({"Lola O.", "+123632347"}); // ugy veszi, hogy a "Lola" kulcs mar letezik, de mi hozza akarjuk adni a map-hez -> nem fog mukodni
	contacts["Lola"].push_back({"Lola O.", "+123632347"});

	// osszes elem kiiratasa
	for (auto &elem: contacts) { // vegigmegyunk a kulcsokon
		std::cout << elem.first << "\n"; // kulcs
		for (auto contact: elem.second) { // minden kulcsnal vegigmegyunk a masodik elemen, ami jelen esetben vector
			std::cout << "\t" << contact.name << " - " << contact.phoneNumber // \t - tabulator, bennebb kezdi a sort
			          << "\n"; // a vectoron belul minden elemnek kiiratjuk a nevet es a tel.szamot
		}
		std::cout << "\n"; // ket kulcs kozotti ujsor
	}

	// elem keresese kulcs szerint - nev szerint
	std::string name = "Bill";
	auto index = contacts.find(name); // visszaadja az indexet
	if (index != contacts.end()) { // ha letezik ez a kulcs
		const std::vector<Contact> &nameContacts = index->second;
		std::cout << "Contacts with key -" << name << "- are : " << std::endl;
		for (auto i: nameContacts) { // vegigjarjuk a vectort
			std::cout << "\t" << i.name << " - " << i.phoneNumber << "\n"; // contactok kozti ujsor
		}
		std::cout << std::endl; // kulcsok kozti ujsor
	} else {
		std::cout << "No contacts with this name."; // ha nem letezik ez a kulcs
	}

	// ertek torlese a kulcstol
	std::string nameToDelete = "Bill";
	auto pair2 = contacts.find(name);
	if (pair2 != contacts.end()) {
		std::vector<Contact> &contacts = pair2->second;
		if (contacts.size() > 1) {
			// Erase the second contact
			contacts.erase(contacts.begin() + 1);
			std::cout << "Second contact with key \"" << nameToDelete << "\" deleted." << std::endl;
		} else {
			std::cout << "No second contact found with key \"" << nameToDelete << "\"" << std::endl;
		}
	} else {
		std::cout << "No contacts found with key \"" << nameToDelete << "\"" << std::endl;
	}

	// osszes elem kiiratasa
	for (auto &elem: contacts) { // vegigmegyunk a kulcsokon
		std::cout << elem.first << "\n";
		for (auto contact: elem.second) { // minden kulcsnal vegigmegyunk a masodik elemen, ami jelen esetben vector
			std::cout << "\t" << contact.name << " - " << contact.phoneNumber
			          << "\n"; // a vectoron belul minden elemnek kiiratjuk a nevet es a tel.szamot
		}
		std::cout << "\n";
	}

	// kulcs torlese
	std::string deleteKey = "Joe";
	int deletedCount = contacts.erase(deleteKey); // visszateriti hogy hany elemet torolt
	if (deletedCount > 0) {
		std::cout << "Key \"" << deleteKey << "\" and associated contacts deleted." << std::endl;
	} else {
		std::cout << "No contacts found with key \"" << deleteKey << "\"" << std::endl;
	}

	// osszes elem kiiratasa
	printAllContacts(contacts);
}

void printAllContacts(std::map<std::string, std::vector<Contact>> contacts) {
	for (auto pair: contacts) {
		std::cout << "Elements with the key -" << pair.first << "- are: " << std::endl; // kulcs
		for (auto value: pair.second) { // vegigjarjuk elemeket tarolo vektort
			std::cout << "\t" << value.name << " - " << value.phoneNumber
			          << std::endl; // kiiratjuk az elemeket a vektorbol
		}
		std::cout << std::endl;
	}
}

void feladat4_3() {
	//telefonkonyv feladat
	std::map<std::string, std::string> dataMap;

	// fajlbol beolvasas es map-hez adas
	std::ifstream inputFile("contactsIn.txt");
	if (inputFile.is_open()) { // ha megnyitottuk a fajlt
		std::string key, value;
		while (inputFile >> key >> value) { // beolvassuk a parokat
			dataMap[key] = value; // adott kulcshoz hozzaadjuk az erteket
		}
		inputFile.close(); // fajl bezarasa
	} else {
		std::cout << "Failed to open input file." << std::endl;
		exit(-1);
	}

	// itt lehet modositani a map-et, ahogy szeretnenk - torles, hozzaadas, feluliras stb.
	dataMap["Lola"] = "+12344363";
	dataMap.erase("Bob");
	dataMap["Bill"] = "1234";

	// map tartalmanak kiiratasa fajlba
	std::ofstream outputFile("contactsOut.txt");
	if (outputFile.is_open()) { // kimeneti fajl megnyitasa
		for (const auto &entry: dataMap) { // iteralas a map-en
			outputFile << entry.first << " " << entry.second << std::endl; // elemek kiiratasa
		}
		outputFile.close(); // fajl bezarasa
	} else {
		std::cout << "Failed to open output file." << std::endl;
		exit(-1);
	}

	std::cout << "Map data has been read from 'input.txt' and written to 'output.txt'." << std::endl;

}

void feladat5() {
	// raktar feladat
	// map - ID, a hozza tartozo elem
	std::map<int, Item> inventory;

	// Elemek hozzaadasa a raktarhoz
	inventory[1] = {"Apple", 10, 1.99}; // Mi, hany darab, mennyibe kerul
	inventory[2] = {"Banana", 15, 0.99};
	inventory[3] = {"Orange", 12, 1.49};

	inventory.insert({4, {"Strawberry", 20, 4.5}}); // hozzaadas inserttel

	inventory.at(4).quantity = 25; // felulirjuk, update

	// Osszes elem kiiratasa
	std::cout << "Inventory:" << std::endl;
	for (const auto &entry: inventory) {
		const Item &item = entry.second;
		std::cout << "ID: " << entry.first << std::endl;
		std::cout << "Name: " << item.name << std::endl; // entry.second.name
		std::cout << "Quantity: " << item.quantity << std::endl; //		entry.second.quantity;
		std::cout << "Price: $" << item.price << std::endl;
		std::cout << std::endl;
	}

	// Egy elem mennyisegenek felulirasa Id alapjan, ha az elem letezik
	int itemId = 2;
	int newQuantity = 20;
	if (inventory.count(itemId) > 0) { // leell. hogy valoban benne van-e a mapben
		Item &item = inventory[itemId]; // kivesszuk az elemet
		item.quantity = newQuantity; // hozzarendeljuk az uj mennyiseget
		std::cout << "Quantity updated for item with ID " << itemId << std::endl;
	} else {
		std::cout << "Item not found" << std::endl;
	}

	// Elem torlese Id alapjan, ha letezik
	itemId = 3;
	if (inventory.count(itemId) > 0) { // valoban benne van-e a mapben
		inventory.erase(itemId); // toroljuk az itemId-val rendelkezo elemet
		std::cout << "Item with ID " << itemId << " removed from the inventory" << std::endl;
	} else {
		std::cout << "Item not found" << std::endl;
	}

	// Modositott inventory kiiratasa
	std::cout << "Updated Inventory:" << std::endl;
	for (const auto &entry: inventory) {
		const Item &item = entry.second;
		std::cout << "ID: " << entry.first << std::endl;
		std::cout << "Name: " << item.name << std::endl;
		std::cout << "Quantity: " << item.quantity << std::endl;
		std::cout << "Price: $" << item.price << std::endl;
		std::cout << std::endl;
	}

}