#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, m;
vector<int> tube[1001];
vector<int> station[100001];
bool end_tube[1001];
bool vis[1001];
queue<pair<int, int>> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> m;

    int temp;
    for (int i = 1; i <= m; i++)
    {
        vis[i] = false;
        end_tube[i] = false;
        for (int j = 1; j <= k; j++ )
        {
            cin >> temp;
            tube[i].push_back(temp);
            station[temp].push_back(i);
            if (temp == 1)
            {
                que.push({ i, 1 });
                vis[i] = true;
            }
            if (temp == n)
            {
                end_tube[i] = true;
            }
        }
       
    }
    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        if (end_tube[now.first])
        {
            cout << now.second + 1 << '\n';
            return 0;
        }

        for (int i = 0; i < (int)tube[now.first].size(); i++)
        {
            for (int j = 0; j < (int)station[tube[now.first][i]].size(); j++)
            {
                if (vis[station[tube[now.first][i]][j]])
                {
                    continue;
                }
                vis[station[tube[now.first][i]][j]] = true;
                que.push({ station[tube[now.first][i]][j], now.second + 1 });
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}