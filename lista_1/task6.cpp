#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <ctime>
const int N = 1000000;

using namespace std;

struct Wynik
{
	int minimum;
	int maximum;
	Wynik (): minimum(0), maximum(0) {}
};

Wynik findMinMax(array<int, N> const& tab) {	
	Wynik wynik;

	//logic
	vector<int> winners, loosers;//size for array where N % 2 == 0!


	if(tab.size()%2 == 1){
		winners.push_back(tab[tab.size()-1]);
		loosers.push_back(tab[tab.size()-1]);
	}


	// cout<<"tab size: " << tab.size()<<endl;
	//split into 2 groups
	for(int i = 0; i < tab.size() - 1;i+=2){
		// cout << "i: " <<i << endl;
		if(tab[i] > tab[i+1]){
			winners.push_back(tab[i]);
			loosers.push_back(tab[i+1]);
		}
		else{
			loosers.push_back(tab[i]);
			winners.push_back(tab[i+1]);
		}
	}

	// cout << "winners size: " << winners.size()<<'\n';
	// cout << "loosers size: " << winners.size()<<'\n';
	// for(int i = 0; i< winners.size();i++){
		// cout << "winner nr "<<i<<": "<<winners[i]<<'\n';
	// }
	// cout << "loosers size: " << loosers.size()<<'\n';
	
	// for(int i = 0; i< loosers.size();i++){
		// cout << "looser nr "<<i<<": "<<loosers[i]<<'\n';
	// }

	//maximum

	for (int i = 0; i < winners.size();i++) {
		if (wynik.maximum < winners[i]){
			wynik.maximum = winners[i];
			cout << "nowe maximum: " << wynik.maximum << '\n';
		}
	}
	
	//minimum
	for (int i = 0; i < loosers.size();i++) {
		if (wynik.minimum > loosers[i]){
			wynik.minimum = loosers[i];
			cout << "nowe minimum: " << wynik.minimum << '\n';
		}
	}
	// cout << "max: " <<wynik.maximum<<" min: "<<wynik.minimum <<endl; 

	return wynik;
}

int main(){
	clock_t mClock;
	srand( time( NULL ) );


	// cout<<"array contains " << N << " elements. \n";
	array<int, N> mArray; // creatrs size: " << winners.size()<<'\n';
	// cout << "loosee an array, with N elements
	
	// cout << "our values(not shuffled): \n";
	for (auto i = 0; i < mArray.size(); i++)
	{
		mArray[i] = i; // wypelniamy ja liczbami od 0 do 99
		// cout<<mArray[i]<<'\n';
	}
	// cout << "End of our values(not shuffled): \n";

	random_shuffle(mArray.begin(), mArray.end());

	
	mClock = clock();
	Wynik wynik = findMinMax(mArray);
	cout << "Time: " << (clock() - mClock)/(double)(CLOCKS_PER_SEC/1000) << "ms\n";
	cout << "maximum: " << wynik.minimum << '\n';
	cout << "minimum: " << wynik.maximum << '\n';



	return 0;
	

}














