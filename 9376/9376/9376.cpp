#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 987654321;
struct mv {
    int y;
    int x;
    int cost;
};

int T;

int field[102][102];
int after_field[3][102][102];
int n, m;
int f_x, s_x, f_y, s_y;

int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };

queue<mv> que;
vector<int> answer;

void dijkstra(int order, int y, int x)
{
    mv temp;
    temp.y = y;
    temp.x = x;
    temp.cost = 0;
    after_field[order][y][x] = 0;
    que.push(temp);
    
    while (!que.empty())
    {
        mv now = que.front();
        que.pop();

        if (now.cost > after_field[order][now.y][now.x])
            continue;

        for (int i = 0; i < 4; i++)
        {
            temp.y = now.y + d_y[i];
            temp.x = now.x + d_x[i];
            temp.cost = now.cost + field[temp.y][temp.x];

            if (temp.y >= 0 && temp.y <= n + 1 &&
                temp.x >= 0 && temp.x <= m + 1 &&
                temp.cost < after_field[order][temp.y][temp.x] &&
                field[temp.y][temp.x] != -1)
            {
                after_field[order][temp.y][temp.x] = temp.cost;
                que.push(temp);;
            }
        }
    }
}

int main()
{
    cin >> T;

    for (int _ = 1; _ <= T; _++)
    {
        cin >> n >> m;

        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                field[i][j] = 0;
                after_field[0][i][j] = INF;
                after_field[1][i][j] = INF;
                after_field[2][i][j] = INF;
            }
        }

        string temp;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            for (int j = 1; j <= m; j++)
            {
                if (temp[j - 1] == '*')
                    field[i][j] = -1;
                else if (temp[j - 1] == '#')
                    field[i][j] = 1;
                else if (temp[j - 1] == '.')
                    field[i][j] = 0;
                else
                {
                    field[i][j] = 0;
                    if (!flag)
                    {
                        flag = true;
                        f_x = j;
                        f_y = i;
                    }
                    else
                    {
                        s_x = j;
                        s_y = i;
                    }
                }
            }
        }

        dijkstra(0, 0, 0);
        dijkstra(1, f_y, f_x);
        dijkstra(2, s_y, s_x);

        int temp_res = INF;

        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                if (after_field[0][i][j] == INF)
                    continue;
                int temp_cost = after_field[0][i][j] + after_field[1][i][j] + after_field[2][i][j];
                if (field[i][j] == 1)
                    temp_cost -= 2;
                temp_res = min(temp_res, temp_cost);
            }
        }

        answer.push_back(temp_res);


    }

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }
}