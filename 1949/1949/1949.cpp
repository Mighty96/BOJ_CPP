#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>


using namespace std;

int n;
int people[10001];
vector<int> tree[10001];
int dp[10001][2];
bool vis[10001];

int dfs(int node, int use)
{
    if (vis[node])
    {
        return dp[node][use];
    }
    vis[node] = true;

    if (dp[node][use] != 0)
    {
        return dp[node][use];
    }
    if (use == 1)
    {
        dp[node][use] = people[node];
    }

    bool flag = false;
    for (int i = 0; i < (int)tree[node].size(); i++)
    {
        if (vis[tree[node][i]])
        {
            continue;
        }
        flag = true;
        dp[node][0] += max(dfs(tree[node][i],0), dfs(tree[node][i],1));
        dp[node][1] += dfs(tree[node][i],0);
    }

    if (!flag)
    {
        dp[node][0] = 0;
        dp[node][1] = people[node];
    }

    return dp[node][use];
}


int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }

    int temp1, temp2;

    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;

        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }

    memset(dp, 0, sizeof(int) * 10001 * 2);
    memset(vis, 0, sizeof(bool) * 10001);

    cout << max(dfs(1, 0), dfs(1, 1)) << '\n';

    return 0;
}