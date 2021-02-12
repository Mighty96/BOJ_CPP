#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> input[40001];
bool visited[40001];
vector<int> tree[40001];
int cost[40001];
int depth[40001];
int dp[40001][20];
int result[10000];

void makeTree(int num, int dep)
{
    visited[num] = true;
    depth[num] = dep;
    for (int i = 0; i < (int)input[num].size(); i++)
    {
        if (!visited[input[num][i].first])
        {
            tree[num].push_back(input[num][i].first);
            cost[input[num][i].first] = cost[num] + input[num][i].second;
            makeTree(input[num][i].first, dep + 1);
            dp[input[num][i].first][0] = num;
        }
    }
}

int lca(int a, int b)
{
    int res = 0;
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 15; i >= 0; i--)
    {
        if (depth[a] - depth[b] >= (1 << i))
        {
            a = dp[a][i];
        }
    }
    if (a == b) return a;
    
    for (int i = 15; i >= 0; i--)
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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;

    int temp1, temp2, temp3;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        input[temp1].push_back(make_pair(temp2, temp3));
        input[temp2].push_back(make_pair(temp1, temp3));
    }

    makeTree(1, 1);

    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }


    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        result[i] = cost[temp1] + cost[temp2] - 2 * cost[lca(temp1, temp2)];
    }
    for (int i = 0; i < m; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;

}