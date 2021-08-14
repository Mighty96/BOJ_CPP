#include <iostream>
#include <queue>

using namespace std;

int cost[801][801];
int n, e;
int v1, v2;
const int inf = 87654321;

int dijkstra(int start, int end)
{
	int dcost[801];
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> que;

	for (int i = 1; i <= n; i++)
	{
		dcost[i] = cost[start][i];
		if (i != 0)
		{
			que.push({ cost[start][i], i });
		}
	}

	while (!que.empty() && que.top().first < inf)
	{
		pair<int, int> temp = que.top();
		que.pop();
		if (temp.first < dcost[temp.second])
		{
			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			if (dcost[i] > dcost[temp.second] + cost[temp.second][i])
			{
				dcost[i] = dcost[temp.second] + cost[temp.second][i];
				que.push({ dcost[i], i });
			}
		}
	}

	return dcost[end];
}


int main()
{
	cin >> n >> e;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cost[i][j] = inf;
		}
		cost[i][i] = 0;
	}

	int temp1, temp2, temp3;
	for (int i = 0; i < e; i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		cost[temp1][temp2] = temp3;
		cost[temp2][temp1] = temp3;
	}
	cin >> v1 >> v2;

	int result = -1;
	int route1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
	int route2 = dijkstra(1, v2) + dijkstra(v1, v2) + dijkstra(v1, n);
	if (route1 < inf)
	{
		result = route1;
	}
	if (route2 < inf && route2 < route1)
	{
		result = route2;
	}

	cout << result;

	return 0;
}