#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> que;

int n, m;
char field[1002][1002];
bool vis[1002][1002];


int main()
{
    cin >> n >> m;

    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int j = 1; j <= m; j++)
        {
            field[i][j] = temp[j - 1];
        }
    }

    int y, x;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j])
                continue;

            que.push({ i, j });

            while (!que.empty())
            {
                y = que.front().first;
                x = que.front().second;
                que.pop();
                if (field[y][x] == 'D' && !vis[y + 1][x])
                {
                    vis[y + 1][x] = true;
                    que.push({ y + 1, x });
                }
                else if (field[y][x] == 'L' && !vis[y][x - 1])
                {
                    vis[y][x - 1] = true;
                    que.push({ y, x - 1 });
                }
                else if (field[y][x] == 'U' && !vis[y - 1][x])
                {
                    vis[y - 1][x] = true;
                    que.push({ y - 1, x });
                }
                else if (field[y][x] == 'R' && !vis[y][x + 1])
                {
                    vis[y][x + 1] = true;
                    que.push({ y, x + 1 });
                }
                if (field[y + 1][x] == 'U' && !vis[y + 1][x])
                {
                    vis[y + 1][x] = true;
                    que.push({ y + 1,x });
                }
                if (field[y][x - 1] == 'R' && !vis[y][x - 1])
                {
                    vis[y][x - 1] = true;
                    que.push({ y, x - 1 });
                }
                if (field[y - 1][x] == 'D' && !vis[y - 1][x])
                {
                    vis[y - 1][x] = true;
                    que.push({ y - 1, x });
                }
                if (field[y][x + 1] == 'L' && !vis[y][x + 1])
                {
                    vis[y][x + 1] = true;
                    que.push({ y, x + 1 });
                }
            }
            res++;
        }
    }

    cout << res << '\n';

    return 0;
}