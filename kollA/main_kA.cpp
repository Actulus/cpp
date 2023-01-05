#include "Catalog.h"

using namespace std;

int main() {
	Catalog catalog;
	catalog.readGrades("grades_100.txt");
	//ofstream ofs("results.txt");
	//ofs << "#students: " << catalog.getNumStudtents() << endl;
	//set<int> ids = catalog.getIds();
	return 0;
}