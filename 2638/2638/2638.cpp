#include <iostream>
#include <queue>

using namespace std;

int n, m;
int d_x[4] = { 1,-1,0,0 };
int d_y[4] = { 0,0,1,-1 };
int board[102][102];

void fill_board(int y, int x)
{
    queue<pair<int, int>> que;
    que.push({ y, x });
    board[y][x] = 2;
    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (now.first + d_y[i] > 0 && now.first + d_y[i] <= n &&
                now.second + d_x[i] > 0 && now.second + d_x[i] <= m &&
                board[now.first + d_y[i]][now.second + d_x[i]] == 0)
            {
                board[now.first + d_y[i]][now.second + d_x[i]] = 2;
                que.push({ now.first + d_y[i], now.second + d_x[i] });
            }
        }
    }
}

int main()
{


    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    fill_board(1, 1);

    bool flag = false;
    int result = -1;

    while (!flag)
    {
        flag = true;
        result++;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (board[i][j] == 1)
                {
                    flag = false;
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        if (board[i + d_y[k]][j + d_x[k]] == 2)
                        {
                            cnt++;
                        }
                    }
                    if (cnt >= 2)
                    {
                        board[i][j] = 3;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (board[i][j] == 3)
                {
                    fill_board(i, j);
                }
            }
        }
    }


    cout << result;

    return 0;
}