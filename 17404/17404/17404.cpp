#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];
int d[1001][3];
int n;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> house[i][0] >> house[i][1] >> house[i][2];

	d[1][0] = house[1][0];
	d[1][1] = 10000000;
	d[1][2] = 10000000;

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house[i][2];
	}

	int res = min(d[n][1], d[n][2]);

	d[1][0] = 10000000;
	d[1][1] = house[1][1];
	d[1][2] = 10000000;

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house[i][2];
	}

	res = min(res, min(d[n][0], d[n][2]));

	d[1][0] = 10000000;
	d[1][1] = 10000000;
	d[1][2] = house[1][2];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house[i][2];
	}

	res = min(res, min(d[n][0], d[n][1]));

	cout << res << '\n';

	return 0;
}