#include <iostream>

using namespace std;

void przesuniecie(int t[], int k, const int n) {
		
	for (auto i = 0; i < n; i++) {
		cout << t[i] << endl;
	}

	cout << '\n';

	for (int j = 0; j < k; j++) {//how many steps?
		int temp = t[n - 1]; //starting fromlast one
		int temp1;//buffor var
		for (int i = 0; i < n; i++) {


			temp1 = t[i];//store value of cell inside of buffor var 
			t[i] = temp;//store value inside current cell with next nth element of tab
			temp = temp1;//changing temp var, which was current cell
						// to "next time last" cell 
		}
	}
	for (auto i = 0; i < n; i++) {
		std::cout << t[i] << std::endl;

	}
}


int main(int argc, char *argv[]) {
	
	const int N = 10;
	int k = 2;
	int tab[N] = { 1,2,3,4,5,6,7,8,9,10 };
	
	przesuniecie(tab, k, N);
	
	
	std::cin.get();
	return 0;
}



