#include <iostream>
#include <cmath>

using namespace std;

void P(int k, int n, double p) {
	int result = 1;
	int result2 = 1;

	for (int i = 1; i <= k; i++)
	{
		result2 *= n / i;
		result += result2 * std::pow(p, i);
		n--;
	}

	cout << result << '\n';
}

int main()
{
	P(100, 10, 4.56);
	cin.get ();
	return 0;
}

