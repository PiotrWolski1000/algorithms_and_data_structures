#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int i, n, w;
	bool * mBoolArray;

	cout << "Type range: ";
	cin >> n;

	mBoolArray = new bool[n + 1];


    //setting up the whole array to be true, just for now
	for (i = 2; i <= n; i++) 
        mBoolArray[i] = true;
	
    for (i = 2; i <= (unsigned int)sqrt(n); i++)
		if (mBoolArray[i] == true){

			w = i * i;

			while (w <= n){
				
                mBoolArray[w] = false; 
                w += i;
			
            }
		}


    //display if bool array of i is equal to true
	for (i = 2; i <= n; i++) 
        if(mBoolArray[i]) 
            cout << i << " ";
	

    cout<<"\n";

    delete[] mBoolArray;
	return 0;
}



