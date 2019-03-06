#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <list>
#include <array>
#include <algorithm>

const int SIZE = 100;

const int N = 1000;

using namespace std;

// int x=a[--n];
// while(n--)
//     if(t[n]<x)
//         x=t[n]; 
// return x;

int max_iter(int t[], int n) {
	int x = t[--n];//set max to last cell of arr
	
    while (n--) {//we first take n than, decreasing it's value
		if (t[n] > x)//if t[n] is greater,  
			x = t[n];//than we have a new maximum
	}
	
	return x;
}


int findMaxRec(int A[], int n) 
{ 
    // if size = 0 means whole array has been traversed 
    if (n == 1) 
        return A[0]; 
    return max(A[n-1], findMaxRec(A, n-1));//sprawdzamy czy poprzedni obieg nie 
											//zworcil wiekszej wartosci niz
											// obecna rekurencja 
} 


int maks_rekurencyjne2(int t[], int n, int n2 = 0, int x = 0, int y = 0) {

	if (n == n2) {//check if the same and pick last winner
		if (x < y) {
			x = y;
		}
		return x;
	}

	if (x < t[n - 1]) {//max from left
		x = t[n - 1];
		
	}

	if (y < t[n2]) {//max from right
		y = t[n2];
			
	}

	return maks_rekurencyjne2(t, --n, ++n2, x, y);

}

int main()
{
	srand(time(NULL));
	const int N = 100;
	
	int arr[N];

	for (auto i = 0; i < N; i++) {//filling arr with random data between 1 and 1000
		arr[i] = int( rand() % 1000 + 1);
	}



	cout <<  "iteration: " << max_iter(arr, N) << '\n';
	cout << "recursion: " << findMaxRec(arr, N) << '\n';
	cout << "recursion: " << maks_rekurencyjne2(arr,N) << '\n';

	return 0;
}



