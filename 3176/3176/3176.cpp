#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, int>> road[100001];
vector<pair<int, int>> res;
int max_cost[100001][17];
int min_cost[100001][17];
bool vis[100001];
int depth[100001];
int dp[100001][17];
int n, m;

int min_res, max_res;

void make_tree(int num, int dep)
{
    vis[num] = true;
    depth[num] = dep;
    for (int i = 0; i < (int)road[num].size(); i++)
    {
        if (!vis[road[num][i].first])
        {
            make_tree(road[num][i].first, dep + 1);
            max_cost[road[num][i].first][0] = road[num][i].second;
            min_cost[road[num][i].first][0] = road[num][i].second;
            dp[road[num][i].first][0] = num;
        }
    }
}

void lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 16; i >= 0; i--)
    {
        if (depth[a] - depth[b] >= (1 << i))
        {
            min_res = min(min_res, min_cost[a][i]);
            max_res = max(max_res, max_cost[a][i]);
            a = dp[a][i];
        }
    }

    if (a == b)
    {
        res.push_back(make_pair(min_res, max_res));
        return;
    }

    for (int i = 16; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i])
        {
            min_res = min(min_res, min_cost[a][i]);
            min_res = min(min_res, min_cost[b][i]);
            max_res = max(max_res, max_cost[a][i]);
            max_res = max(max_res, max_cost[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    min_res = min(min_res, min_cost[a][0]);
    min_res = min(min_res, min_cost[b][0]);
    max_res = max(max_res, max_cost[a][0]);
    max_res = max(max_res, max_cost[b][0]);

    res.push_back(make_pair(min_res, max_res));

    return;
}

int main()
{
    cin >> n;

    int temp1, temp2, temp3;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;

        road[temp1].push_back(make_pair(temp2, temp3));
        road[temp2].push_back(make_pair(temp1, temp3));
    }

    make_tree(1, 1);

    for (int j = 1; j <= 16; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
            min_cost[i][j] = min(min_cost[i][j - 1], min_cost[dp[i][j - 1]][j - 1]);
            max_cost[i][j] = max(max_cost[i][j - 1], max_cost[dp[i][j - 1]][j - 1]);
        }
    }


    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        min_res = 1000001;
        max_res = 0;
        lca(temp1, temp2);
    }

    for (int i = 0; i < m; i++)
    {
        cout << res[i].first << " " << res[i].second << '\n';
    }

    return 0;
}