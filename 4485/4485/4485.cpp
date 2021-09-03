#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

queue<pair<int, int>> que;
vector<int> result;

int d_x[4] = { 1, -1, 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };
int n;
int field[126][126];
int value[126][126];

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> field[i][j];
                value[i][j] = INF;
            }
        }

        que.push({ 1, 1 });
        value[1][1] = field[1][1];

        while (!que.empty())
        {
            pair<int, int> now = que.front();
            que.pop();

            for (int i = 0; i < 4; i++)
            {
                if (now.first + d_x[i] > 0 && now.first + d_x[i] <= n &&
                    now.second + d_y[i] > 0 && now.second + d_y[i] <= n &&
                    value[now.first + d_x[i]][now.second + d_y[i]] >
                    value[now.first][now.second] + field[now.first + d_x[i]][now.second + d_y[i]])
                {
                    value[now.first + d_x[i]][now.second + d_y[i]] =
                        value[now.first][now.second] + field[now.first + d_x[i]][now.second + d_y[i]];
                    que.push({ now.first + d_x[i], now.second + d_y[i] });
                }
            }

        }
        result.push_back(value[n][n]);
        
    }

    for (int i = 1; i <= (int)result.size(); i++)
    {
        cout << "Problem " << i << ": " << result[i - 1] << '\n';
    }

    return 0;
}