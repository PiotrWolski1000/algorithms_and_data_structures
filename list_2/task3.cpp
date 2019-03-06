#include <iostream>
#include <vector>
#include <cmath>

#define N 2

using namespace std;


int iloczynSkalarny(vector<int> & x, vector<int> & y) {
    int value = 0;

    for(int i=0;i< x.size();i++){
        value += x.at(i) * y.at(i);
    }

    return value;
}


int wartoscWielomianu(vector<int>& x, int value){//vektor podany jako argumentw zawiera liste wspolczynnikow przy odpowiadajacemu mu indeksowi w vectorze(x)
//drugi argumentw to wartosc parametru x
    int wartosc_wielomianu = 0;

    for(int i = 0; i < x.size()-1;i++){
        
        wartosc_wielomianu += x.at(i) * pow(value, i);
        
    }
    
    wartosc_wielomianu += x.back();//ostatni element(indeks = 0) jest stala dlatego osobny 

    return wartosc_wielomianu;
}

int iloczynDwochWielomianow(vector<int>& x,  vector<int>& y, int xx) {

    int row_value = 0;
    int value = 0;
    for(int i = 0; i<x.size();i++){
        for(int j = 0;j<y.size(); j++){
            row_value += x.at(i)* pow(xx, i) * y.at(j) * pow(xx, j);
        }
        value += row_value;
    }

    return value;
}

void multiplyMatrixes(int A[][2], int B[][2], int C[][2])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int wyznacznikMacierzy(int macierz[][5], int n) {
    
    int positive = 1;
    int negative = 1;

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(i == j)
                positive *= macierz[i][j];
        }
    }

    for(int i = n-1;i>=0;i--) {
        for(int j = 0;j<n;j++) {
            if(i == j)
                negative *= macierz[i][j];
        }
    }

    


    return positive-negative;
}


void uzupelnijMacierz(int tab[][5], int n) {

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            tab[i][i] = i*j;
        }
    }
}

int main() {    
    vector<int> a1 = {5,4,0,2,1};
    vector<int> a2 = {5, 0, 0, 0, 1};



    //podpunkt a
    cout<<"iloczyn skalarny dwoch zadanych wektorow wynosi: "<<iloczynSkalarny(a1, a2)<<endl;
    
    //podpunkt b
    cout<<"wartosc wielomianu wynosi: "<<wartoscWielomianu(a1, 3)<<endl;


    //podpunkt c
    cout<<"wartosc iloczynu 2 wielomianow wynosi: "<<iloczynDwochWielomianow(a1, a2, 3)<<endl;


    int a[2][2] = {
        {1,1},
         {2,2}
    };

    int b[2][2] = {
        {1,2},
         {3,4}
    };
    
    int c[2][2] = {
        {0,0},
        {0,0}
    };
    

    //podpunkt d
    cout<<"wartosc iloczynu dwoch macierzy wynosi: " << endl;
    multiplyMatrixes(a, b, c);

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            cout<< c[i][j]<<", ";
        }    
        cout<<endl;
    }

    //podpunkt e

    int n = 5;

    int matrix[5][5];
    uzupelnijMacierz(matrix, n);//wypelniamy randomowymi wartosciami nasza macierz

    cout<<"wyznacznik macierzy "<< n <<" x "<<n<<"wynosi: "<<wyznacznikMacierzy(matrix, n)<<'\n';


    
    return 0;
}