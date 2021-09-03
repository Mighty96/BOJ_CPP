#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF = 98765432100;
struct road {
    int goal;
    ll cost;
};

struct dijkstra {
    int node;
    int pr;
    ll cost;
};

struct compare {
    bool operator()(dijkstra a, dijkstra b)
    {
        return a.cost > b.cost;
    }
};

int n, m, k;
ll dp[10001][21];
bool vis[10001][21];
vector<road> r[10001];
priority_queue<dijkstra, vector<dijkstra>, compare> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    int temp1, temp2;
    ll temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        r[temp1].push_back({ temp2, temp3 });
        r[temp2].push_back({ temp1, temp3 });
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            dp[i][j] = INF;
            vis[i][j] = false;
        }
    }

    dp[1][0] = 0;
    vis[1][0] = true;
    for (int i = 0; i < (int)r[1].size(); i++)
    {
        que.push({ r[1][i].goal, 0, r[1][i].cost });
        dp[r[1][i].goal][0] = r[1][i].cost;
        que.push({ r[1][i].goal, 1, 0 });
        dp[r[1][i].goal][1] = 0;
    }

    while (!que.empty())
    {
        dijkstra now = que.top();
        que.pop();

        if (vis[now.node][now.pr])
        {
            continue;
        }
        vis[now.node][now.pr] = true;

        if (now.pr < k)
        {
            for (int i = 0; i < (int)r[now.node].size(); i++)
            {
                if (dp[r[now.node][i].goal][now.pr + 1] > dp[now.node][now.pr])
                {
                    dp[r[now.node][i].goal][now.pr + 1] = dp[now.node][now.pr];
                    que.push({ r[now.node][i].goal, now.pr + 1, dp[r[now.node][i].goal][now.pr + 1] });
                }
            }
        }

        for (int i = 0; i < (int)r[now.node].size(); i++)
        {
            if (dp[r[now.node][i].goal][now.pr] > dp[now.node][now.pr] + r[now.node][i].cost)
            {
                dp[r[now.node][i].goal][now.pr] = dp[now.node][now.pr] + r[now.node][i].cost;
                que.push({ r[now.node][i].goal, now.pr, dp[r[now.node][i].goal][now.pr] });
            }
        }
    }

    ll result = INF;

    for (int i = 0; i <= k; i++)
    {
        result = min(result, dp[n][i]);
    }

    cout << result << '\n';

    return 0;
}