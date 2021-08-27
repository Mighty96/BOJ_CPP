#include <iostream>
#include <queue>

using namespace std;

int n, m;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

const int INF = 987654321;
char field[501][501];
pair<int, int> value[501][501];
pair<int, int> g_value[501][501];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
pair<int, int> start;
pair<int, int> finish;
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> field[i][j];
            value[i][j] = { INF, INF };
            if (field[i][j] == 'S')
            {
                start = { i, j };
                value[i][j] = { 0, 0 };
            }
            if (field[i][j] == 'F')
            {
                finish = { i, j };
            }
        }
    }

   

    pair<int, int> temp_value;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            temp_value = { 0, 0 };
            if (field[i][j] == 'g')
            {
                temp_value.first++;
            }
            else
            {
                for (int k = 0; k < 4; k++)
                {
                    if (i + d_x[k] > 0 && i + d_x[k] <= n &&
                        j + d_y[k] > 0 && j + d_y[k] <= m &&
                        field[i + d_x[k]][j + d_y[k]] == 'g')
                    {
                        temp_value.second++;
                        break;
                    }
                }
            }
            g_value[i][j] = temp_value;
        }
    }

    g_value[start.first][start.second] = { 0, 0 };
    g_value[finish.first][finish.second] = { 0, 0 };

    que.push(start);
    while (!que.empty())
    {
        pair<int, int> now = que.top();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (now.first + d_x[i] > 0 && now.first + d_x[i] <= n &&
                now.second + d_y[i] > 0 && now.second + d_y[i] <= m)
            {
                temp_value = value[now.first][now.second];
                temp_value.first += g_value[now.first + d_x[i]][now.second + d_y[i]].first;
                temp_value.second += g_value[now.first + d_x[i]][now.second + d_y[i]].second;
                if (temp_value.first < value[now.first + d_x[i]][now.second + d_y[i]].first)
                {
                    value[now.first + d_x[i]][now.second + d_y[i]] = temp_value;
                    que.push({ now.first + d_x[i], now.second + d_y[i] });
                }
                else if (temp_value.first == value[now.first + d_x[i]][now.second + d_y[i]].first)
                {
                    if (temp_value.second < value[now.first + d_x[i]][now.second + d_y[i]].second)
                    {
                        value[now.first + d_x[i]][now.second + d_y[i]] = temp_value;
                        que.push({ now.first + d_x[i], now.second + d_y[i] });
                    }
                }
            }
        }
    }

    cout << value[finish.first][finish.second].first << " " << value[finish.first][finish.second].second << '\n';

    return 0;

}