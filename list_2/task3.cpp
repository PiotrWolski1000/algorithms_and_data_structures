#include <iostream>
#include <vector>
#include <cmath>

#define N 2

using namespace std;


int scalar(vector<int> & x, vector<int> & y) {
    int value = 0;

    for(int i=0;i< x.size();i++){
        value += x.at(i) * y.at(i);
    }

    return value;
}


int polynomial_val(vector<int>& v, int x){//count of multiplication: ((n+1)n)/2, which is O(n^2) (we coutn powers)
    int result = 0;

    for(int i = 0; i < v.size()-1;i++){
        
        result += v.at(i) * pow(x, i);
        
    }
    
    result += v.back();//ostatni element(indeks = 0) jest stala dlatego osobny 

    return result;
}

int multiplicationTwoPolimonials(vector<int>& v1,  vector<int>& v2, int x) {//O(N^2)

    int row_value = 0;
    int value = 0;

    for(int i = 0; i < v1.size();i++){
        for(int j = 0;j < v2.size(); j++){
            row_value += v1.at(i)* pow(x, i) * v2.at(j) * pow(x, j);
        }
        value += row_value;
    }

    return value;
}

int main() {
    srand(time(NULL));

    vector<int> a1 = {1,2,-2,0,1};
    vector<int> a2 = {2, 1, 5, 3, 2};

    cout<<"scalar: "<<scalar(a1, a2)<<'\n';//task a)    
    cout<<"polynomial's value: "<<polynomial_val(a1, 3)<<'\n';//task b)
    cout<<"multiplication of 2 polynomials: "<<multiplicationTwoPolimonials(a1, a2, 3)<<'\n';

    //matrixes
    int a[2][2] = {
        {1,2},
         {2,1}
    };

    int b[2][2] = {
        {1,3},
         {3,3}
    };
    
    int c[2][2] = {
        {0,0},
        {0,0}
    };
    

    
    return 0;
}