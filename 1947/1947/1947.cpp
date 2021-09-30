#include <iostream>

using namespace std;

long long dp[1000001];
int n;
int main()
{
	dp[1] = 0;;
	dp[2] = 1;
	dp[3] = 2;

	cin >> n;

	for (long long i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % 1000000000;
	}

	cout << dp[n] << '\n';

	return 0;
}