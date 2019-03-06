#include <iostream>

using namespace std;

struct lnode {
	int key;
	lnode* next;

	lnode(int value, lnode* l = nullptr) {
		key = value;
		cout << "my value: " << key << '\n';
		next = l;
	}
};

int nty(int n, lnode * l) {
	
	int _n = 1;

	while (l != nullptr) {
		if (_n == n) {
			cout << "found: ";
			return l->key;
		}
		else {
			cout <<"next!\n";
			_n++;
			l = l->next;
		}
	}
	return 0;
}


int main()
{
	
    //start creating from "the last one"
	lnode third(3);//first is actually "the last one"
	lnode second(2, &third);
	lnode first(1, &second);
	

	cout << "2: \n" << nty(2, &first) << '\n';
	cout << "1: \n" << nty(1, &first) << '\n';
	cout << "3 \n" << nty(3, &first) << '\n';
	//out of boundaries
	cout << "out of boundaries(10): \n" << nty(10, &first) << '\n';

	return 0;
}








