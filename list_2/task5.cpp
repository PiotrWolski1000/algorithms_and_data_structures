#include<iostream> 
using namespace std; 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next;

    Node (int data) 
    { 
        this->data = data; 
        next = NULL; 
    } 
}; 
  
struct LinkedList 
{ 
    Node *head; 
    LinkedList() 
    { 
        head = NULL; 
    } 
  
  
    /* Function to reverse the linked list */
    void reverse() 
    { 
        // Initialize current, previous and 
        // next pointers 
        Node *current = head; //we start from the beggining of the list
        Node *prev = NULL, *next = NULL; 
  
  
        while (current != NULL) //if not first?
        { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
  
    /* Function to print linked list */
    void print() 
    { 
        struct Node *temp = head; 
        while (temp != NULL) 
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 
  
    void push(int data)//adding new element at front of our list 
    { 
        Node *temp = new Node(data); 
        temp->next = head; 
        head = temp; 
    } 
}; 
  
/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    LinkedList ll; 
    ll.push(20); 
    ll.push(4); 
    ll.push(15); 
    ll.push(85); 
  
    cout << "Given linked list\n"; 
    ll.print(); 
  
    ll.reverse(); 
  
    cout << "\nReversed Linked list \n"; 
    ll.print(); 
    return 0; 
// 	Time Complexity: O(n)
// Space Complexity: O(1)
} 

