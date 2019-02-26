#include <iostream>
#include <cmath>
//26.02.2019, Bisection Method, https://eduinf.waw.pl/inf/alg/005_root/m0010.php


using namespace std;

double f(double d){
	return 2 * d - 1;//sample function
}

double mZeros(double f(double), double a, double b){
    const double EPS0 = 0.0000000001; //accuracy of comparison with zero
	const double EPSX = 0.0000000001; //accuracy of determining the element


    //boundary values of our function
    double fa = f(a);
    double fb = f(b);

    double x0 = (a + b) / 2; //determining middle point of our range 
    double f0 = f(x0); //function f's value in the middle point of our range

    while(1){
        if(fabs(a - b) > EPSX){
            break;
        }
        else{//logic 
            x0 = (a + b) / 2;
            f0 = f(x0);
            if (fabs(f0) < EPS0) break;
            if (fa * f0 < 0){
                a = x0;
            } 
            else{
                b = x0; 
                fa = f0;
            }
        }
    }
    return x0;
}

int main()
{
    // cout << "f(0): " << f(0) << "\n";
    // cout << "f(1): " << f(1) << "\n";
    double a,b;
    cout << "Range <a,b>\nType in a: ";
    cin >> a;
    cout<<"\nType in b: ";
    cin >> b;
    cout<<"\nZero places: " << mZeros(f, a, b);




    return 0;
}
