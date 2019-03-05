#include <iostream>
#include <array>
#include <algorithm>

const int N = 1000;

using namespace std;

struct Wynik
{
	int minimum;
	int maximum;
	Wynik (): minimum(0), maximum(0) {}
};


Wynik znajdz_min_max(std::array<int, N> const& tab)
{
	Wynik wynik;

	for (auto &t : tab) {
		if (t > wynik.maximum)
			wynik.maximum = t;
		if (t < wynik.minimum)
			wynik.minimum = t;
	}

	return wynik;
}

int main()
{
	
	array<int, N> mArray; // create an array, with N elements

	for (auto i = 0; i < mArray.size(); i++)
	{
		mArray[i] = i; // wypelniamy ja liczbami od 0 do 99
	}
	random_shuffle(mArray.begin(), mArray.end()); // mieszamy w sposob losowy 
														 //aby znalezc min i max

	Wynik wynik = znajdz_min_max(mArray);
	cout << wynik.minimum << '\n';
	cout << wynik.maximum;

	return 0;
}
















