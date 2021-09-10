#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;
const ll INF = 19876543210;
using namespace std;

struct way {
    int goal;
    int dist;
};

struct mv {
    int goal;
    ll cost;
    ll min_cost;
};

struct compare {
    bool operator()(mv a, mv b) {
        return a.cost > b.cost;
    }
};

int n, m;

ll oil[2501];
vector<way> road[4001];
ll dp[2501][2501];

priority_queue<mv, vector<mv>, compare> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> oil[i];
    }

    int temp1, temp2, temp3;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        road[temp1].push_back({ temp2, temp3 });
        road[temp2].push_back({ temp1, temp3 });
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2500; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[1][oil[1]] = 0;

    que.push({ 1, 0, oil[1] });

    ll result = INF;
    while (!que.empty())
    {
        mv now = que.top();
        que.pop();

        if (dp[now.goal][now.min_cost] < now.cost)
        {
            continue;
        }

        for (int i = 0; i < (int)road[now.goal].size(); i++)
        {
            int temp_min_cost = min(now.min_cost, oil[road[now.goal][i].goal]);
            if (now.cost + now.min_cost * road[now.goal][i].dist < dp[road[now.goal][i].goal][temp_min_cost])
            {
                dp[road[now.goal][i].goal][temp_min_cost] = now.cost + now.min_cost * road[now.goal][i].dist;
                if (road[now.goal][i].goal != n)
                {
                    que.push({ road[now.goal][i].goal, dp[road[now.goal][i].goal][temp_min_cost], temp_min_cost });
                }
                else
                {
                    result = min(result, dp[road[now.goal][i].goal][temp_min_cost]);
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}