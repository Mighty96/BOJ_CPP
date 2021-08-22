#include <iostream>
#include <queue>

using namespace std;

int r, c;

int d_x[4] = { 1, -1 , 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };

char field[1502][1502];
queue<pair<int, int>> bfs_que;
queue<pair<int, int>> que;
queue<pair<int, int>> buff_que;
bool move_a[1502][1502];
bool move_b[1502][1502];

int main()
{
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> field[i][j];

			move_a[i][j] = false;
			move_b[i][j] = false;
		}
	}

	bool flag = true;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (field[i][j] == '.' || field[i][j] == 'L')
			{
				for (int k = 0; k < 4; k++)
				{
					if (field[i + d_x[k]][j + d_y[k]] == 'X')
					{
						que.push({ i + d_x[k], j + d_y[k] });
					}
				}
			}

			if (field[i][j] == 'L' && flag)
			{
				flag = false;
				move_a[i][j] = true;
				bfs_que.push({ i, j });
				while (!bfs_que.empty())
				{
					pair<int, int> now = bfs_que.front();
					bfs_que.pop();

					for (int k = 0; k < 4; k++)
					{
						if (field[now.first + d_x[k]][now.second + d_y[k]] == '.'
							&& !move_a[now.first + d_x[k]][now.second + d_y[k]])
						{
							move_a[now.first + d_x[k]][now.second + d_y[k]] = true;
							bfs_que.push({ now.first + d_x[k], now.second + d_y[k] });
						}
					}

				}
			}
			else if (field[i][j] == 'L' && !flag)
			{
				move_b[i][j] = true;
				bfs_que.push({ i, j });
				while (!bfs_que.empty())
				{
					pair<int, int> now = bfs_que.front();
					bfs_que.pop();

					for (int k = 0; k < 4; k++)
					{
						if (field[now.first + d_x[k]][now.second + d_y[k]] == '.'
							&& !move_b[now.first + d_x[k]][now.second + d_y[k]])
						{
							move_b[now.first + d_x[k]][now.second + d_y[k]] = true;
							bfs_que.push({ now.first + d_x[k], now.second + d_y[k] });
						}
					}

				}
			}
		}
	}

	int result = 0;

	while (true)
	{
		result++;
		while (!que.empty())
		{
			pair<int, int> now = que.front();
			que.pop();

			if (field[now.first][now.second] == '.')
			{
				continue;
			}

			bool flag_a = false;
			bool flag_b = false;
			for (int k = 0; k < 4; k++)
			{
				if (move_a[now.first + d_x[k]][now.second + d_y[k]])
				{
					flag_a = true;
					if (flag_b)
					{
						cout << result << '\n';
						return 0;
					}

					move_a[now.first][now.second] = true;
				}
				else if (move_b[now.first + d_x[k]][now.second + d_y[k]])
				{
					flag_b = true;
					if (flag_a)
					{
						cout << result << '\n';
						return 0;
					}

					move_b[now.first][now.second] = true;
				}
				else if (field[now.first + d_x[k]][now.second + d_y[k]] == 'X')
				{
					buff_que.push({ now.first + d_x[k], now.second + d_y[k] });
				}
			}

			field[now.first][now.second] = '.';

			if (move_a[now.first][now.second])
			{
				for (int k = 0;k < 4; k++)
				{
					if (field[now.first + d_x[k]][now.second + d_y[k]] == '.'
						&& !move_a[now.first + d_x[k]][now.second + d_y[k]])
					{
						bfs_que.push({ now.first + d_x[k], now.second + d_y[k] });
						move_a[now.first + d_x[k]][now.second + d_y[k]] = true;

						while (!bfs_que.empty())
						{
							pair<int, int> inner_now = bfs_que.front();
							bfs_que.pop();

							if (move_b[inner_now.first][inner_now.second])
							{
								cout << result << '\n';
								return 0;
							}

							for (int l = 0; l < 4; l++)
							{
								if (field[inner_now.first + d_x[l]][inner_now.second + d_y[l]] == '.'
									&& !move_a[inner_now.first + d_x[l]][inner_now.second + d_y[l]])
								{
									bfs_que.push({ inner_now.first + d_x[l], inner_now.second + d_y[l] });
									move_a[inner_now.first + d_x[l]][inner_now.second + d_y[l]] = true;
								}
							}
						}
					}
				}
			}

			if (move_b[now.first][now.second])
			{
				for (int k = 0;k < 4; k++)
				{
					if (field[now.first + d_x[k]][now.second + d_y[k]] == '.'
						&& !move_b[now.first + d_x[k]][now.second + d_y[k]])
					{
						bfs_que.push({ now.first + d_x[k], now.second + d_y[k] });
						move_b[now.first + d_x[k]][now.second + d_y[k]] = true;

						while (!bfs_que.empty())
						{
							pair<int, int> inner_now = bfs_que.front();
							bfs_que.pop();

							if (move_a[inner_now.first][inner_now.second])
							{
								cout << result << '\n';
								return 0;
							}

							for (int l = 0; l < 4; l++)
							{
								if (field[inner_now.first + d_x[l]][inner_now.second + d_y[l]] == '.'
									&& !move_b[inner_now.first + d_x[l]][inner_now.second + d_y[l]])
								{
									bfs_que.push({ inner_now.first + d_x[l], inner_now.second + d_y[l] });
									move_b[inner_now.first + d_x[l]][inner_now.second + d_y[l]] = true;
								}
							}
						}
					}
				}
			}
		}

		while (!buff_que.empty())
		{
			que.push(buff_que.front());
			buff_que.pop();
		}
	}


	return 0;

}