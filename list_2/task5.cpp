#include <iostream>

using namespace std;

struct lnode { 
    int data; 
    struct lnode* next;

    lnode (int data) 
    { 
        this->data = data; 
        next = nullptr; 
    } 
};

class mList{
    lnode* head;//start element of the list

    public: 
    mList(){
        head = nullptr;
    }

    void push(int value){
        lnode* temp = new lnode(value);//create new node
        temp->next = head;//point to previous head
        head = temp;//new element is set to be the new 'head'
    }
    void display() {
        lnode* temp = head;

        cout << "our list values are: "<<endl;
        while(temp != nullptr){
            cout<< temp->data << ' ';
            temp = temp->next;
        }
    }

    int getSize(){

        lnode* temp = head;
        int counter = 0;
        
        while(temp != nullptr){
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    void reverse(){
        lnode* current = head;
        lnode* next = nullptr;
        lnode* prev = nullptr;

        while(current != nullptr){
            //store pointer to next node
            next = current->next;

            //since we have stored pointer 
            //to next node we change current
            // node to point to new
            // node, which is the
            // previous one(first iteration => nullptr(new first element is nullptr))
            current->next = prev;


            //next time, prev is gonna be
            //our 'current' node 
            prev = current;
            //next time current node is gonna be
            //next node of current iteration 
            current = next; 
        
        }
        head = prev;
    }

    void sort() {
        cout<<"sorting"<<endl;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
int main(){
    mList l;
    
    l.push(5);
    l.push(12);
    l.push(1);
    l.push(7);

    cout << "length of an array: " << l.getSize() << endl;
    cout << "list before sorting: " << endl;
    l.display();

    l.reverse();

    cout << endl << "list after reversing: " << endl;
    
    l.display();
    
    return 0;
}

