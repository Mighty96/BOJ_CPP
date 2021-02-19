#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
char input[51][51];
int dp[51][51];
bool vis[51][51];
int res;
bool cflag;

void dfs(int a, int b, int cnt)
{
	if (cflag) return;
	

	if (a < 0 || b < 0 || a >= n || b >= m || input[a][b] == 'H')
	{
		res = max(res, cnt);
		return;
	}

	if (vis[a][b])
	{
		cflag = true;
		res = 0;
		return;
	}
	if (dp[a][b] >= cnt)
		return;
	else
		dp[a][b] = cnt;
	vis[a][b] = true;

	dfs(a + (input[a][b] - '0'), b, cnt + 1);
	dfs(a - (input[a][b] - '0'), b, cnt + 1);
	dfs(a, b + (input[a][b] - '0'), cnt + 1);
	dfs(a, b - (input[a][b] - '0'), cnt + 1);

	vis[a][b] = false;

	return;
}



int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	dfs(0, 0, 1);
	

	cout << res - 1 << '\n';

	return 0;
}