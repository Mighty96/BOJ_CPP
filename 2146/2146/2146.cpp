#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int n;
int field[101][101];
bool visited[101][101];
bool new_visited[101][101];
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };
queue<tuple<int, int, int>> que;
int result = 10000;

void dfs(int y, int x)
{
	visited[y][x] = true;
	que.push(make_tuple(y, x, 0));

	for (int i = 0; i < 4; i++)
	{
		if (x + d_x[i] >= 0 && x + d_x[i] < n &&
			y + d_y[i] >= 0 && y + d_y[i] < n &&
			!visited[y + d_y[i]][x + d_x[i]] &&
			field[y + d_y[i]][x + d_x[i]] == 1)
			dfs(y + d_y[i], x + d_x[i]);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> field[i][j];

	for (int i = 0 ; i < n ; i++)
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && field[i][j] == 1)
			{
				dfs(i, j);
				while (!que.empty())
				{
					int now_y = get<0>(que.front());
					int now_x = get<1>(que.front());
					int cnt = get<2>(que.front());
					que.pop();
					for (int k = 0; k < 4; k++)
					{
						if (now_x + d_x[k] >= 0 && now_x + d_x[k] < n &&
							now_y + d_y[k] >= 0 && now_y + d_y[k] < n &&
							!visited[now_y + d_y[k]][now_x + d_x[k]])
						{
							if (field[now_y + d_y[k]][now_x + d_x[k]] == 1)
							{
								result = (result < cnt) ? result : cnt;
								while (!que.empty())
									que.pop();
								break;
							}
							else if (!new_visited[now_y + d_y[k]][now_x + d_x[k]])
							{
								que.push(make_tuple(now_y + d_y[k], now_x + d_x[k], cnt + 1));
								new_visited[now_y + d_y[k]][now_x + d_x[k]] = true;
							}
						}
							
					}


				}
				for (int k = 0; k < n; k++)
					for (int l = 0; l < n; l++)
						new_visited[k][l] = false;
			}
		}
	
	cout << result << '\n';
	return 0;

}