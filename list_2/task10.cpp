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

    
    
    public:
    lnode* root;
    BST(int val){    
        root = new lnode(val);
        cout<<"Created BST tree with root = "<<root->val<<endl;
    }

    lnode* getRoot(){
        return this->root;
    }

    // void Print() {
    //     lnode* temp = root;

    //     while(temp != nullptr){
            
    //         cout << "my val: " << temp->val << endl;


    //         if(temp->left != nullptr)
    //             temp = temp->left;
    //         else if(temp->right != nullptr){
    //             temp = temp->right;
    //         }
    //     }

    // }

    // void Insert(int newVal){
    //     lnode* temp = this->root;//we're operating on real root(we're passing an adresse to root object)
    //     // cout<<"inserting to bst.." <<endl;
    //     while(temp){
    //         if(newVal<temp->val)
	// 		    temp=temp->left;
	// 	    else
	// 		    temp=temp->right;
    //     }
    //     temp=new lnode(newVal);   
    // }

};

void inorder(lnode *t){  // wypisanie kluczy w porządku "in order"
    // lnode* temp = t;

    if(t)
    {
        inorder(t->left);
        cout<<t->val<<" ";
        inorder(t->right);

    }
}   
void insert(lnode *& t, int x) // wstawianie (nierekurencyjna)
{
	lnode **t1=&t;//first time is root of BST
	while(*t1)
		if(x<(*t1)->val)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new lnode(x);
}  

void remove(lnode *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	lnode **t1=&t;//wskaznik na wartosc adresu roota?
	
    //szukanie miejsca dla x
    while (*t1 && (*t1)->val!=x)//czy nie null i wartosc != x(inna niz root(pozniej temp)
	{
		if(x<(*t1)->val) //mniejsze?
			t1=&((*t1)->left); //zmieniamy temp na lewy node
		else
			t1=&((*t1)->right); //zmieniamy temo na prawy node
	}
	if(*t1)
	{
		if((*t1)->right && (*t1)->left)
		{
			lnode **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->val=(*t2)->val;
			t1=t2;
		}	
		if((*t1)->left==nullptr)
		{
			lnode *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    lnode *d=(*t1)->left;	
			delete *t1;
			(*t1)=d;
		}
	}
}

lnode* find(lnode* t,int x)  // wyszukiwanie klucza (bez rekurencji)
{
	while(t && t->val!=x)
	{
		if(x<t->val) 
			t=t->left; 
		else
			t=t->right; 
	}
	return t;
}

int main(){

    cout << "Preparing BST.."<<endl;
    BST myTree(5);//setting up BST with root 
    insert(myTree.root, 7);
    insert(myTree.root, -2);
    insert(myTree.root, 12);
    insert(myTree.root, 6);
 
    cout<<"bst tree: ", inorder(myTree.root);


    cout<<endl<<"find 6: "<<find(myTree.root, 6)->val<<endl;

    cout<<endl<<"removing node";
    remove(myTree.root, -2);

    cout<<endl<<"bst tree: ", inorder(myTree.root);


    return 0;
}