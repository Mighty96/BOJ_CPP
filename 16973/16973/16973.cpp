#include <iostream>
#include <queue>

using namespace std;

int field[1002][1002];
bool vis[1002][1002];
int n, m;

int d_y[4] = { 0, 0, 1 ,-1 };
int d_x[4] = { 1, -1, 0, 0 };

struct rec {
	int sy;
	int sx;
	int ey;
	int ex;
	int cnt;
};

queue<rec> que;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> field[i][j];

	for (int i = 0; i <= n + 1; i++)
	{
		field[i][0] = 1;
		field[i][m + 1] = 1;
	}
	for (int i = 0; i <= m + 1; i++)
	{
		field[0][i] = 1;
		field[n + 1][i] = 1;
	}

	int h, w, sy, sx, ey, ex;

	cin >> h >> w >> sy >> sx >> ey >> ex;

	rec first;
	first.sy = sy;
	first.sx = sx;
	first.ey = sy + h - 1;
	first.ex = sx + w - 1;
	first.cnt = 0;
	vis[sy][sx] = true;


	bool flag = true;
	que.push(first);

	while (!que.empty())
	{
		rec now = que.front();
		que.pop();
		if (now.sy == ey && now.sx == ex)
		{
			cout << now.cnt << '\n';
			return 0;
		}

		flag = true;
		if (!vis[now.sy][now.sx - 1])
		{
			for (int i = now.sy; i <= now.ey; i++)
			{
				if (field[i][now.sx - 1])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				vis[now.sy][now.sx - 1] = true;
				rec temp;
				temp.sy = now.sy;
				temp.sx = now.sx - 1;
				temp.ey = now.ey;
				temp.ex = now.ex - 1;
				temp.cnt = now.cnt + 1;
				que.push(temp);
			}
		}

		flag = true;
		if (!vis[now.sy - 1][now.sx])
		{
			for (int i = now.sx; i <= now.ex; i++)
			{
				if (field[now.sy - 1][i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				vis[now.sy - 1][now.sx] = true;
				rec temp;
				temp.sy = now.sy - 1;
				temp.sx = now.sx;
				temp.ey = now.ey - 1;
				temp.ex = now.ex;
				temp.cnt = now.cnt + 1;
				que.push(temp);
			}
		}

		flag = true;
		if (!vis[now.sy][now.sx + 1])
		{
			for (int i = now.sy; i <= now.ey; i++)
			{
				if (field[i][now.ex + 1])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				vis[now.sy][now.sx + 1] = true;
				rec temp;
				temp.sy = now.sy;
				temp.sx = now.sx + 1;
				temp.ey = now.ey;
				temp.ex = now.ex + 1;
				temp.cnt = now.cnt + 1;
				que.push(temp);
			}
		}

		flag = true;
		if (!vis[now.sy + 1][now.sx])
		{
			for (int i = now.sx; i <= now.ex; i++)
			{
				if (field[now.ey + 1][i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				vis[now.sy + 1][now.sx] = true;
				rec temp;
				temp.sy = now.sy + 1;
				temp.sx = now.sx;
				temp.ey = now.ey + 1;
				temp.ex = now.ex;
				temp.cnt = now.cnt + 1;
				que.push(temp);
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}