#include <iostream>

using namespace std;


int iteration_power(int a, int pow){//a^pow
    int result = 1;
    int steps = pow / 2;     
    if(pow == 0){
        return 1;
    }
    else if(pow % 2 == 0){
        while(steps > 0){
            result *= a;
            steps--;
        }
        return result * result;
    }
    else{
        return result * result * a;
    }
    return 0;
}

int recursive_power(int a, int pow){//a^pow
    if(pow == 0){
        return 1;
    }
    else{
        if(pow % 2 == 0){
            return recursive_power(a * a, pow / 2);
        }   
        else{
            return a * recursive_power(a * a, pow / 2);
        } 
    }
}

main(){

    int x, n;
    cout<<"x: \n";
    cin >> x;
    cout<<"n: \n";
    cin >> n;

    cout << "Iteratively solved equation's result is: " << iteration_power(x, n) << "\n";
    cout << "Recursively solved equation's result is: " << recursive_power(x, n);
    
    return 0;
}