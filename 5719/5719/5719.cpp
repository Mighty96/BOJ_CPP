#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

typedef long long ll;
using namespace std;
const int INF = 987654321;

struct way {
	int prev;
	int goal;
	int cost;
};

struct compare {
	bool operator()(way a, way b) {
		return a.cost > b.cost;
	}
};

int n, m;
int road[501][501];
int s, d;
int cost[501];
int prev_node[501];

priority_queue<way, vector<way>, compare> que;
queue<pair<int, int>> remove_que;

vector<int> result;

void remove_road(int node)
{
	if (node == s) return;
	int prev = prev_node[node];
	remove_que.push({ prev, node });
	remove_road(prev);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int temp1, temp2, temp3;
	
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}

		cin >> s >> d;

		memset(road, -1, sizeof(int) * 501 * 501);
		for (int i = 0; i < n; i++)
		{
			cost[i] = INF;
		}

		for (int i = 0; i < m; i++)
		{
			cin >> temp1 >> temp2 >> temp3;
			road[temp1][temp2] = temp3;
		}

		int temp_min = -1;;

		que.push({ -1, s, 0 });

		while (!que.empty())
		{
			way now = que.top();
			que.pop();

			if (now.cost > cost[now.goal])
			{
				continue;
			}
			prev_node[now.goal] = now.prev;
			if (now.goal == d)
			{
				if (temp_min == -1)
				{
					temp_min = now.cost;
					remove_road(d);
				}
				else if (temp_min == now.cost)
				{
					remove_road(d);
				}
				else
				{
					break;
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (road[now.goal][i] != -1)
				{
					if (now.cost + road[now.goal][i] <= cost[i])
					{
						cost[i] = now.cost + road[now.goal][i];
						que.push({now.goal, i, cost[i] });
					}
				}
			}
		}

		while (!remove_que.empty())
		{
			pair<int, int> now = remove_que.front();
			remove_que.pop();

			road[now.first][now.second] = -1;
		}

		for (int i = 0; i < n; i++)
		{
			cost[i] = INF;
		}
		que.push({ s, 0 });

		int temp_res = -1;
		while (!que.empty())
		{
			way now = que.top();
			que.pop();

			if (now.cost > cost[now.goal])
			{
				continue;
			}
			if (now.goal == d)
			{
				temp_res = now.cost;
				break;
			}

			for (int i = 0; i < n; i++)
			{
				if (road[now.goal][i] != -1)
				{
					if (now.cost + road[now.goal][i] < cost[i])
					{
						cost[i] = now.cost + road[now.goal][i];
						que.push({ now.goal, i, cost[i] });
					}
				}
			}
		}
		result.push_back(temp_res);
	}

	for (int i = 0; i < (int)result.size(); i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}