#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>

class ExceptionZero : public std::runtime_error
{
public:
	ExceptionZero(const char* error): runtime_error(error){}

};


class Ulamek {
private:
	int licznik, mianownik;
public:
	Ulamek(){
		licznik = 1;
		mianownik = 1;
	}
	Ulamek(int licznik, int mianownik = 1) {
		if (mianownik == 0)
			throw ExceptionZero("Mianownik nie moze byc zerem");
		this->licznik = licznik;
		this->mianownik = mianownik;
		skracanie();
	}
	int get_licznik() { return licznik; }
	int get_mianownik() { return mianownik; }
	void set_licznik(int a) {
		licznik = a;
	}
	void set_minanownik(int a) {
		if (a == 0)
			throw ExceptionZero("Mianownik nie moze byc zerem");
		mianownik = a;
	}
	void skracanie() {
		bool skracalny = true;

		while (skracalny == true) {
			
			if (licznik % 2 == 0 && mianownik % 2 == 0) {
				mianownik /= 2;
				licznik /= 2;
			}
			else if (licznik % 3 == 0 && mianownik % 3 == 0) {
				mianownik /= 2;
				licznik /= 2;
			}
			else if (licznik % 5 == 0 && mianownik % 5 == 0) {
				mianownik /= 5;
				licznik /= 5;
			}
			else if (licznik % 7 == 0 && mianownik % 7 == 0) {
				mianownik /= 7;
				licznik /= 7;
			}
			else {
				skracalny = false;
			}
				
		}
	}
	
	void nwd(Ulamek & drugi) {
		
		int a = mianownik;
		int b = drugi.get_mianownik();
		
		if (a != b) {
			
			mianownik *= b;
			licznik *= b;

			drugi.set_licznik(drugi.get_licznik() * a);
			drugi.set_minanownik(drugi.get_mianownik() * a);
		}
		

	}
	
};


// operator wyjsciowy
std::ostream & operator<< (std::ostream &wyjscie, Ulamek &u) {
	return  wyjscie << u.get_licznik() << "/" << u.get_mianownik() << std::endl;

}
// operator wejscia
std::istream & operator >> (std::istream &wejscie, Ulamek& u) {
	std::string ulom;
	//wpisanie stringa
	wejscie >> ulom;
	//wyliczenie pozycji do usuwania zbednej czesci stringa
	int position = ulom.find('/');
	int end = ulom.length() - 1;
	std::string ulom2 = ulom;
	std::string licz = ulom2.erase(position, end);
	position++;
	std::string mian = ulom.erase(0, position);
	u.set_licznik(atoi(licz.c_str()));
	u.set_minanownik(atoi(mian.c_str()));
	u.skracanie();
	
	return wejscie;
}

// operator mnozenia
Ulamek operator* (Ulamek &jeden, Ulamek &dwa)
{
	Ulamek wynik;
	wynik.set_licznik(jeden.get_licznik() * dwa.get_licznik());
	wynik.set_minanownik(jeden.get_mianownik() * dwa.get_mianownik());
	wynik.skracanie();
	return wynik;
}

//operator dzielenia
Ulamek operator/ (Ulamek &jeden, Ulamek &dwa) {
	Ulamek wynik;
	wynik.set_licznik(jeden.get_licznik() * dwa.get_mianownik());
	wynik.set_minanownik(jeden.get_mianownik() * dwa.get_licznik());
	wynik.skracanie();
	return wynik;
}
//operator dodawania
Ulamek operator+ (Ulamek &jeden, Ulamek &dwa)
{
	Ulamek wynik;
	jeden.nwd(dwa);
	wynik.set_licznik(jeden.get_licznik() + dwa.get_licznik());
	wynik.set_minanownik(jeden.get_mianownik());
	wynik.skracanie();
	return wynik;
}
//operator odejmowanaia
Ulamek operator- (Ulamek &jeden, Ulamek &dwa)
{
	Ulamek wynik;
	jeden.nwd(dwa);
	wynik.set_licznik(jeden.get_licznik() - dwa.get_licznik());
	wynik.set_minanownik(jeden.get_mianownik());
	wynik.skracanie();
	return wynik;
}

int main()
{
	
	Ulamek u1;
	Ulamek u2;
	char koniec = 'z';
	
	do{
		
		std::cout << "Wprowadz po kolei 2 ulamki w formie 1/3, mianownik nie moze byc zerem" << std::endl;
		try {
			//wprowadzenie ulamkow
			std::cin >> u1;
			std::cin >> u2;

			//wypisanie 
			std::cout << u1;
			std::cout << u2;
			
			std::cout << "wybierz operacje na ulamkach, wpisujac '+' '-' '*' '/' lub 'x' aby zakonczyc " << std::endl;
			std::cin >> koniec;

			if (koniec == '*') {
				std::cout << "Iloczyn: " << u1*u2 << std::endl;
			}
			else if (koniec == '+') {
				std::cout << "Suma: " << u1 + u2 << std::endl;
			}
			else if (koniec == '-') {
				std::cout << "Roznica: " << u1 - u2 << std::endl;
			}
			else if (koniec == '/') {
				std::cout << "Iloraz: " << u1/u2 << std::endl;
			}
			else if (koniec == 'x') {
				std::cout << "wybrano koniec" << std::endl;
			}
			else {
				std::cout << "nieprawidlowy znak" << std::endl;
			}

		}
		catch (ExceptionZero & e) {
			std::cerr << std::endl;
			std::cerr << "[ERROR]" << e.what() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << std::endl;
			std::cerr << "[ERROR]" << e.what() << std::endl;
		}
		
	}while (koniec != 'x') ;
	std::cout << "Wcisnij klawisz aby zakonczyc" << std::endl;
	std::cin.get();
	std::cin.get();
	return 0;
}




