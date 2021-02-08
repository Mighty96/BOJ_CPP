#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int depth[100001];
int dp[100001][21];
vector<int> tree[100001];
vector<int> result;
bool visited[100001];


void dfs(int n, int dep)
{
    
    depth[n] = dep;
    for (int i = 0; i < (int)tree[n].size(); i++)
    {
        if (!visited[tree[n][i]])
        {
            visited[tree[n][i]] = true;
            dfs(tree[n][i], dep + 1);
            dp[tree[n][i]][0] = n;
        }
    }
}


int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 20; i >= 0; i--)
        if (depth[a] - depth[b] >= pow(2, i))
            a = dp[a][i];

    if (a == b) return a;

    for (int i = 20; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    return dp[a][0];
}


int main()
{
    int n, m;

    cin >> n;

    int temp1, temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }



    visited[1] = true;
    dfs(1, 0);


    for (int j = 1; j < 21; j++)
        for (int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        result.push_back(lca(temp1, temp2));
    }

    for (int i = 0; i < m; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}