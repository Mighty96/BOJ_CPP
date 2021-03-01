#include <iostream>
#include <algorithm>

using namespace std;
int n;
int field[11][11];
bool vis1[11];
bool vis2[11];
int temp_res = 0;
int res = 0;
void dfs(int cnt, int x, int y)
{
	if (x > n)
	{
		y++;
		if (x % 2 == 1)
			x = 2;
		else
			x = 1;
	}
	if (y > n)
	{
		temp_res = max(temp_res, cnt);
		return;
	}

	if (field[y][x] == 1 && !vis1[y + x - 1] && !vis2[n + y - x])
	{
		vis1[y + x - 1] = true;
		vis2[n + y - x] = true;
		dfs(cnt + 1, x + 2, y);
		vis1[y + x - 1] = false;
		vis2[n + y - x] = false;
	}

	dfs(cnt, x + 2, y);

}



int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> field[i][j];
		}
	
	dfs(0, 1, 1);
	res += temp_res;
	temp_res = 0;
	dfs(0, 2, 1);
	res += temp_res;
	cout << res << '\n';

	return 0;
}