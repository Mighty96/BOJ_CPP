#include <iostream>
#include <vector>

using namespace std;

vector<int> input[100001];
bool vis[100001];
int depth[100001];
int dp[100001][18];
vector<int> res;
int n, m;

void make_tree(int num, int dep)
{
    vis[num] = true;
    depth[num] = dep;
    for (int i = 0; i < (int)input[num].size(); i++)
    {
        if (!vis[input[num][i]])
        {
            vis[input[num][i]] = true;
            make_tree(input[num][i], dep + 1);
            dp[input[num][i]][0] = num;
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 17; i >= 0; i--)
        if (depth[a] - depth[b] >= (1 << i))
            a = dp[a][i];

    if (a == b) return a;

    for (int i = 17; i >= 0; i--)
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }

    return dp[a][0];
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int temp1, temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;

        input[temp1].push_back(temp2);
        input[temp2].push_back(temp1);
    }

    make_tree(1, 1);

    for (int i = 1; i <= 17; i++)
        for (int j = 1; j <= n; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        res.push_back(lca(temp1, temp2));
    }

    for (int i = 0; i < m; i++)
        cout << res[i] << '\n';

    return 0;
}