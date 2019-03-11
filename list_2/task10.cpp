#include <iostream>

using namespace std;

struct lnode {
    int val;
    lnode* left;
    lnode* right;
    
    lnode (int data) 
    { 
        this->val = data; 
        this->left = nullptr; 
        this->right = nullptr; 
    } 

};

class BST {

    lnode* root;
    
    public:
    BST(int val){    
        root = new lnode(val);
        cout<<"Created BST tree with root = "<<root->val<<endl;
    }
    void Print() {
        lnode* temp = root;

        while(temp != nullptr){
            
            cout << "my val: " << temp->val << endl;


            if(temp->left != nullptr)
                temp = temp->left;
            else if(temp->right != nullptr){
                temp = temp->right;
            }
        }

    }

    void Insert(int newVal){
        lnode* temp = root;//we're operating on real root(we're passing an adresse to root object)
        cout<<"inserting to bst.." <<endl;
        int iter = 0;
        while(temp){
            // cout<<"Looper step nr:  "<<iter;
            // if(newVal >= temp->val){//if new value is greater/equal from our temp node key
            //     cout<<"is greater!" << endl;
            //     if(temp->right)//check if right node exists, if yes, we change temp var to child node
            //         temp = temp->right;
            //     else{//if right child is empty we just set up a new node in here
            //         temp->right = new lnode(newVal);
            //         cout<<"created new node!"<<endl;
            //     }
            // } else{
            //     cout<<"is less!" << endl;

            //     if(temp->left)//check if left node is there, if yes, we change temp var to child node
            //         temp = temp->left;
            //     else{//if left child is empty we just set up a new node in here
            //         temp->left = new lnode(newVal);
            //         cout<<"created new node!"<<endl;
            //     }
            // }
            // iter++;
            if(newVal<temp->val)
			    temp=temp->left;
		    else
			    temp=temp->right;

        }
        
    }
};


int main(){

    cout << "Preparing BST.."<<endl;
    BST myTree(5);//setting up BST tree with root as param
    // myTree.Insert(10);
    // myTree.Insert(12);
    myTree.Insert(2);
    // cout<<"BST tree prepared." <<endl;
    // cout<<"printing our tree: ";
    // myTree.Print();
    // cout<<endl;
    return 0;
}