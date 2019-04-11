#include <iostream>
#include <array>

using namespace std;

int kta(int n, int number) {//n is nth element of "number as string"
    //indexing digits of number from right to left
    int exp = 1;

    while(n--){//at least once for unit digit
        exp *= 10;
    }

    return (number/exp)%10;
}


int main() {

    std::array<int, 9> values = {{0,1,2,3,4,5,6,7,8}};//(9 elements)need to has same amount of elements as number has digits
    int a = 123456789;//number with 9 digits (e.g.)

    // how many digits?
    int count = 0;

    for(int i = values.size()-1; i >= 0; i--){//printing digits from left to the right
        cout<<"index nr "<<i<<" is: "<<kta(i, a)<<endl;
        count++;
    }

    cout<<"there is " << count << " digits in the given number."<<endl;

    return 0;
}