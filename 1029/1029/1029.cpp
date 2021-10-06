#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int price[16][16];

// 비트, 마지막사람, 마지막가격 = 사람수
int dp[(1 << 16)][16][10];

int d(int bitmask, int person_idx, int p)
{
	if (bitmask != 1 && dp[bitmask][person_idx][p] != -1) return dp[bitmask][person_idx][p];

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (bitmask & (1 << i)) continue;
		if (p > price[person_idx][i]) continue;
		res = max(res, d(bitmask | (1 << i), i, price[person_idx][i]));
	}
	res++;
	return dp[bitmask][person_idx][p] = res;
}

int main()
{
	cin >> n;

	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
			price[i][j] = temp[j] - '0';
	}

	memset(dp, -1, sizeof(dp));

	cout << d(1, 0, 0) << '\n';
}