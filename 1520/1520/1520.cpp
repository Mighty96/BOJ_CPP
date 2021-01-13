#include <iostream>
#include <vector>

using namespace std;

int h, w;
long long result = 0;
int field[502][502];
int d[502][502];


int dfs(int y, int x)
{
	if (x == w && y == h)
		return 1;
	if (x <1 && y < 1 && x > w && y > h) return 0;
	if (d[y][x] != -1) return d[y][x];
	d[y][x] = 0;

	if (field[y][x] > field[y - 1][x])
		d[y][x] += dfs(y - 1, x);
	if (field[y][x] > field[y + 1][x])
		d[y][x] += dfs(y + 1, x);
	if (field[y][x] > field[y][x - 1])
		d[y][x] += dfs(y, x - 1);
	if (field[y][x] > field[y][x + 1])
		d[y][x] += dfs(y, x + 1);
	return d[y][x];
}

int main()
{
	fill(&field[0][0], &field[501][502], 10000);
	fill(&d[0][0], &d[501][502], -1);
	cin >> h >> w;
	for (int i = 1; i <= h;i++)
		for (int j = 1; j <= w; j++)
		{
			cin >> field[i][j];
		}
	cout << dfs(1, 1) << '\n';
	return 0;
}