#include <vector>
#include <iostream>

using namespace std;

bool move(int** t, const int& tab_size, int mCase, int x, int y, int& pos_x, int& pos_y) {
	// cases of knight proper moves
	switch (mCase) {
		case 1:
			pos_x = x + 1;
			pos_y = y - 2;
			break;
		case 2:
			pos_x = x + 2;
			pos_y = y - 1;
			break;
		case 3:
			pos_x = x + 2;
			pos_y = y + 1;
			break;
		case 4:
			pos_x = x + 1;
			pos_y = y + 2;
			break;
		case 5:
			pos_x = x - 1;
			pos_y = y + 2;
			break;
		case 6:
			pos_x = x - 2;
			pos_y = y + 1;
			break;
		case 7:
			pos_x = x - 2;
			pos_y = y - 1;
			break;
		case 8:
			pos_x = x - 1;
			pos_y = y - 2;
			break;
	}
	//if the choosen case is legal(is still inside our array size), we return true
	if (0 <= pos_x && 
		pos_x < tab_size &&
		0 <= pos_y && 
		pos_y < tab_size &&
		t[pos_x][pos_y] == 0)
		return true;
	//otherwise return false
	return false;
}

bool knight(int** t, const int& arr_size, int x, int y, int nth) {
	int pos_x, pos_y, mCase;

	// setting value of an array to nth
	t[x][y] = nth;
 
	if (nth == arr_size * arr_size) {//if nth is equal to arr_size^2 it means that we are finished(we reached each square)
		for (int i = 0; i < arr_size; i++) {
			for (int j = 0; j < arr_size; j++)
				cout << t[i][j] << " ";
			cout << endl;
		}
		return 1;
	} else {//else make a move
		//iterate through each case(legal knight move)
		for (mCase = 1; mCase<9; mCase++)
			if (move(t, arr_size, mCase, x, y, pos_x, pos_y))
				//if move function returns true(if move is legal), 
				//we're invoking knight funct recursively till we 
				//reach every square of chessboard
				if (knight(t, arr_size, pos_x, pos_y, nth + 1))
					return true;
		t[x][y] = 0;
	}

	return false;
}

int main() {
	int max = 8;
	int start_x, start_y = max-1;//start position
	
	// creating array size of [max][max]
	int** tab = new int*[max];
	for (int i = 0; i<max; i++)
		tab[i] = new int[max];

	for (int i = 0; i< max; i++)
		for (int j = 0; j< max; j++)
			tab[i][j] = 0;

	knight(tab, max, start_x, start_y, 1);

		
	/*to prevent memory leak*/
	for (int i = 0; i < max; i++) {
		delete[] tab[i];
	}
	delete[] tab;

	return 0;
}