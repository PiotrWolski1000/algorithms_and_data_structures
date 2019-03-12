#include <iostream>

using namespace std; 
  
#define MAX 10 
  
template <class T>
class Stack 
{ 
    int top; 
public: 
    T a[MAX];    //Maximum size of Stack 
  
    Stack(){ 
        this->top = -1; 
    } 
    
    bool push(T x) 
    { 
        if (top >= (MAX-1)) 
        { 
            cout << "Stack Overflow"; 
            return false; 
        } 
        else
        { 
            a[++top] = x; 
            cout<<x <<" pushed into stack\n"; 
            return true; 
        } 
    } 
    
    T pop() 
    { 
        if (top < 0) //is empty
        { 
            cout << "Stack Underflow"; 
            return 0; 
        } 
        else//is not empty and we return last added value
        { 
            int x = a[top--]; 
            return x; 
        } 
    } 
    
    bool isEmpty() 
    { 
        return (top < 0); 
    } 
    
}; 
  
int main() 
{ 
    Stack<int> s_int;
    Stack<float> s_float; 
    
    cout<<"int stack: \n";
    
    s_int.push(10); 
    s_int.push(20); 
    s_int.push(30); 
    cout<<s_int.pop() << " Popped from stack\n"; 
  
    cout<<"float stack: \n";

    s_float.push(10.0); 
    s_float.push(11.33); 
    s_float.push(20.123); 
    cout<<s_float.pop() << " Popped from stack\n"; 
  
    return 0; 
}