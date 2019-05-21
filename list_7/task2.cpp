#include <iostream>

using namespace std;

int f(const int& n)
{
    return __builtin_popcount(n); 
}

int main()
{
    cout << f(11);
}