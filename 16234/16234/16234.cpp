#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int n, l, r;
int temp_sum, temp_div;
int cnt;
int time = 0;
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };
bool flag = false;
queue<pair<int, int>> que;


void bfs(int y, int x, vector<vector<int>> &field, vector<vector<bool>> &visited)
{
	que.push(make_pair(y, x));
	temp_sum += field[y][x];
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		if (y + d_y[i] >= 0 && y + d_y[i] < n && x + d_x[i] >= 0 && x + d_x[i] < n &&
			!visited[y + d_y[i]][x + d_x[i]] &&
			abs(field[y + d_y[i]][x + d_x[i]] - field[y][x]) >= l &&
			abs(field[y + d_y[i]][x + d_x[i]] - field[y][x]) <= r)
		{
			flag = true;
			visited[y + d_y[i]][x + d_x[i]] = true;
			bfs(y + d_y[i], x + d_x[i], field, visited);
		}

	}
}

int main()
{

	
	cin >> n >> l >> r;
	
	vector<vector<int>> field(n, vector<int>(n, 0));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> field[i][j];
		}
	}

	while (true)
	{
		flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					temp_sum = 0;
					cnt = 0;
					visited[i][j] = true;
					bfs(i, j, field, visited);
					temp_div = temp_sum / cnt;
					while (!que.empty())
					{
						field[que.front().first][que.front().second] = temp_div;
						que.pop();
					}
				}
			}
		}
		if (!flag)
		{
			cout << time << '\n';
			return 0;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		time++;
	}

}
