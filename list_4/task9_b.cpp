
#include <iostream>

using namespace std;

void partition (double t[], int n)
{
  int k = -1;
  double x = t[0];
  cout<<"size t(n): "<<n;
  for(;;)
  {
    cout<<endl<<"another iteration's n value is: "<<n<<endl;
     while (t[--n] > x){
         cout<<"n: "<<n<<endl;
     };
    cout<<endl<<"another iteration's k value is: "<<k<<endl;    
     while (t[++k] < x){
         cout<<"k: "<<k<<endl;
     };
     if(k < n){
       std::swap(t[k],t[n]);

       for(int i = 0; i <= 6; i++)
       {
         cout<<t[i]<< " ";
       }
       
      }
     else break;
      cout << endl;
  }
}


int main()
{
    double t [] = {7,6,5,4,3,2,1};
    partition(t,7);


    return 0;
}
