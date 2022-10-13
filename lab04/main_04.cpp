#include "PointSet.h"
#define MAX 1000

int main() {
	//--------1--------
	/*//Definíció - üres dinamikus tömb
	vector<int> v;
	//Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
	for( int i=0; i<10; ++i ){
		v.push_back( i * 10 );
	}
	//Kiíratás
	for(int i=0; i<v.size(); ++i ){
		cout<<v[ i ]<<" ";
	}
	cout<<endl;*/

	//--------2--------
	/*int x[100];
	int n = 10;
	cout<<"x = [";
	for( int i=0; i<n; ++i ){
		x[i] = rand() % MAX;
		cout<<x[i]<<" ";
	}
	cout << "]" <<endl;
	cout << "Legkisebb : " << *min_element(x, x+n) << endl;
	vector<int> v;
	v.reserve(100);
	cout<<"v = [";
	for( int i=0; i<n; ++i ){
		v.emplace_back( rand() % MAX );
		cout<<v[ i]<<" ";
	}
	cout << "]" <<endl;
	cout << "Legnagyobb: " << *max_element(v.begin(),v.end()) << endl;
	*/

	int n = 2;
	cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
	cout << fixed;

	for (int i = 0; i < 12; ++i) {
		PointSet pSet(n);
		cout << setw(6) << n << " ";
		cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
		cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
		cout<<setw(10) << pSet.numDistances()<<" ";
		cout<<setw(16) << pSet.numDistinctDistances()<<endl;
		n = n << 1;
	}

	return 0;
}