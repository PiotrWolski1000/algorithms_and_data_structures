#include <iostream>
#include <cmath>

using namespace std;

double oblicz(double a[], int n, double x){
    double result = 0.0;//first operation
    int pow = n;
	for (int i = 0; i < n; i++) {//n operations
		result += a[i] * std::pow(x, pow--);//2 operations for each loop step
        
		// cout << result << '\n';
	}
	
    return result += a[n];//last operation

}//the number of multiplication is n + (n) + (n -1) + (n-2) + (n-3)..?

int main()
{
    
    // int n = 7;
    int n = 4;
    // int x = 2.4;
    int x = 2;
    // double polynomial[10] = {4, 5, 3, 2,2,3,4,8,0,9};
    double polynomial[4] = {2,1,3,4};
    cout <<"Oblicz function's result: " << oblicz(polynomial, n, x)<<'\n';
    return 0;
}
