#include <iostream>

using namespace std;

template<typename T=size_t>

void printArray(const T*const arr,const size_t& n = 0) 
{
    for(size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void counting_sort(size_t*const& t,const size_t& n,size_t c)
{
    size_t occurrences[10] = {0};//buckets
    size_t temp[n];//temp array 

    size_t exp = 1;

    while(c--)//checks by which digit we want to sort by 
        exp *= 10;

    for(size_t i = 0; i < n; ++i) 
        ++occurrences[(t[i]/exp)%10];//counting elements and storing its value in appropriate index of temp array

    for(size_t i = 1; i < 10; ++i) 
        occurrences[i] += occurrences[i-1];//adding previous counts
    
    for(int i = n-1; i >= 0; --i) 
        temp[--occurrences[(t[i]/exp)%10]] = t[i];//merge sorted array
    
    for(size_t i = 0; i < n; ++i)
        t[i] = temp[i];//modifying original array
}

int main()
{
    
    size_t t[] = {25,99,61,63,53,24,137,37,16,90};

    const size_t n = sizeof(t)/sizeof(*t);//size of our array

    cout<<"array before counting sort(unit digit): "<<endl;
    printArray(t,n);

    counting_sort(t,n,0);// 0 means that we're sorting array by unit digit, 1 tens digit and so on

    cout<<"array after counting sort(unit digit): "<<endl;
    printArray(t,n);

    cout<<endl;

    cout<<"array before counting sort(ten digit): "<<endl;
    printArray(t,n);

    counting_sort(t,n,1);// 0 means that we're sorting array by unit digit, 1 tens digit and so on

    cout<<"array after counting sort(ten digit): "<<endl;
    printArray(t,n);



}