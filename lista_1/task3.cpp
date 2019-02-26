#include <iostream>
#include <cmath>

using namespace std;

double oblicz(double a[], int n, double x){
    double result = 0.0;//first operation

	for (int i = 0; i < n; i++) {//n operations
		result += a[i] * std::pow(x, n--);//2 operations for each loop step
		// cout << result << '\n';
	}
	
    return result += a[n];//last operation

}// complexity of the algorithm is 2n + 3 (or 3n + 2)?

int main()
{
    
    double polynomial[5] = {2.0, 1.12, 2.132, -5.12, 123.1};
    cout <<"Oblicz function's result: " << oblicz(polynomial, 4, 7.0);
    return 0;
}
