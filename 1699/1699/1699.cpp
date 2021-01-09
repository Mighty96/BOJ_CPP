#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int d(int n, vector<int> &number)
{
	if (n == 0) return 0;
	if (number[n] != 0) return number[n];
	int min = n;
	for (int i = 1; i <= (int)sqrt(n);i++)
	{
		int temp = d(n - (i * i), number) + 1;
		min = (min > temp) ? temp : min;
	}
	number[n] = min;
	return min;
}


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> number(n + 1, 0);
	
	cout << d(n, number) << '\n';

	return 0;
}