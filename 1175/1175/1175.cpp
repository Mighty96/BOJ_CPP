#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 0: µ¿ 1: ³² 2: ¼­ 3: ºÏ
int d_y[4] = { 0, 1, 0, -1 };
int d_x[4] = { 1, 0, -1, 0 };

int n, m;

char field[51][51];
int value[51][51][5][2][2];
const int INF = 987654321;

struct command {
    int x;
    int y;
    int dir;
    bool b;
    bool c;
};

queue<command> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> field[i][j];
            for (int k = 0; k < 5; k++)
            {
                value[i][j][k][0][0] = INF;
                value[i][j][k][0][1] = INF;
                value[i][j][k][1][0] = INF;
                value[i][j][k][1][1] = INF;
            }

            if (field[i][j] == 'S')
            {
                command temp;
                temp.y = i;
                temp.x = j;
                temp.dir = 4;
                temp.b = false;
                temp.c = false;
                que.push(temp);
                for (int k = 0; k < 5; k++)
                {
                    value[i][j][k][0][0] = 0;
                }
            }

            if (field[i][j] == 'C')
            {
                if (!flag)
                {
                    field[i][j] = 'B';
                    flag = true;
                }
            }
        }
    }

    while (!que.empty())
    {
        command now = que.front();
        que.pop();
        //cout << now.y << " " << now.x << " " << now.dir << " " << '\n';
        for (int i = 0; i < 4; i++)
        {
            if (now.dir == i)
            {
                continue;
            }


            if (now.y + d_y[i] > 0 && now.y + d_y[i] <= n &&
                now.x + d_x[i] > 0 && now.x + d_x[i] <= m && field[now.y + d_y[i]][now.x + d_x[i]] != '#')
            {
                command temp;
                temp.y = now.y + d_y[i];
                temp.x = now.x + d_x[i];
                temp.dir = i;
                if (field[now.y + d_y[i]][now.x + d_x[i]] == '.' ||
                    field[now.y + d_y[i]][now.x + d_x[i]] == 'S')
                {
                    temp.b = now.b;
                    temp.c = now.c;
                }
                else if (field[now.y + d_y[i]][now.x + d_x[i]] == 'B')
                {
                    temp.b = true;
                    temp.c = now.c;
                }
                else if (field[now.y + d_y[i]][now.x + d_x[i]] == 'C')
                {
                    temp.b = now.b;
                    temp.c = true;
                }

                if (temp.b && temp.c)
                {
                    cout << value[now.y][now.x][now.dir][now.b][now.c] + 1 << '\n';
                    return 0;
                }
                else
                {
                    if (value[now.y][now.x][now.dir][now.b][now.c] + 1 < value[temp.y][temp.x][temp.dir][temp.b][temp.c])
                    {
                        value[temp.y][temp.x][temp.dir][temp.b][temp.c] = value[now.y][now.x][now.dir][now.b][now.c] + 1;
                        que.push(temp);
                    }
                }
            }
        }
    }

    cout << -1 << '\n';

    return 0;
    
}