#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int parent[501];
int past[501];
bool child[501][501];
bool vis[501];
int T;
int n, m;
queue<int> que;
vector<int> answer[101];

int main()
{
    cin >> T;

    int temp;
    int team1, team2;
    for (int _ = 1; _ <= T; _++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            past[temp] = i;
        }
        cin >> m;

        memset(child, 0, sizeof(child));
        memset(vis, 0, sizeof(vis));
        memset(parent, 0, sizeof(parent));

        for (int i = 1; i <= m; i++)
        {
            cin >> team1 >> team2;
            if (past[team1] < past[team2])
            {
                child[team2][team1] = true;
                parent[team1]++;
            }
            else
            {
                child[team1][team2] = true;
                parent[team2]++;
            }
        }

        for (int j = 1; j < n; j++)
            for (int k = j + 1; k <= n; k++)
                if (past[j] < past[k] && !child[k][j])
                {
                    child[j][k] = true;
                    parent[k]++;
                }
                else if (past[j] > past[k] && !child[j][k])
                {
                    child[k][j] = true;
                    parent[j]++;
                }

        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == 0)
            {
                que.push(i);
                break;
            }
        }


        int score = 0;
        answer[_].push_back(n);

        if (que.empty())
            answer[_][0] = -1;
        while (!que.empty())
        {
            score++;
            int now = que.front();
            que.pop();

            if (vis[now] || !que.empty())
            {
                answer[_][0] = -1;
                break;
            }
            vis[now] = true;
            answer[_].push_back(now);

            for (int i = 1; i <= n; i++)
            {
                if (child[now][i])
                {
                    parent[i]--;
                    if (parent[i] == 0)
                        que.push(i);
                }
            }
        }
        if (score < n)
            answer[_][0] = -1;
    }

    for (int i = 1; i <= T; i++)
    {
        if (answer[i][0] == -1)
            cout << "IMPOSSIBLE" << '\n';
        else
        {
            for (int j = 1; j <= answer[i][0]; j++)
                cout << answer[i][j] << " ";
            cout << '\n';
        }
    }

    return 0;
}