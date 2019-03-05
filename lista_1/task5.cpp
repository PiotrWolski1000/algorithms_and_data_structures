#include <iostream>

using namespace std;

struct lnode {
	int key;
	lnode* next;

	lnode(int value, lnode* l = nullptr) {
		key = value;
		next = l;
	}
};

int nty(int n, lnode * l) {
	
	int _n = 1;
	while (l != nullptr) {
		if (_n == n) {
			return l->key;
		}
		else {
			_n++;
			l = l->next;
		}
	}
	return 0;
}


int main(void)
{
	
    //start creating from "the last one"
	lnode third(3);
	lnode second(2, &third);
	lnode first(1, &second);
	
	cout << nty(2, &first) << '\n';
	cout << nty(1, &first) << '\n';
	cout << nty(3, &first) << '\n';
	//out of boundaries
	cout << nty(4, &first) << '\n';

	return 0;
}








