#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

pair<int, int> tower[100];
bool visited[100];
int depth[100][100];
queue<int> que;
vector<int> possible;
int n, r, d, x, y;
const int INF = 987654321;

bool between(pair<int, int> p1, pair<int, int> p2)
{
    double bet_x, bet_y;

    if (p1.first > p2.first)
    {
        bet_x = p1.first - p2.first;
    }
    else
    {
        bet_x = p2.first - p1.first;
    }

    if (p1.second > p2.second)
    {
        bet_y = p1.second - p2.second;
    }
    else
    {
        bet_y = p2.second - p1.second;
    }
    if (bet_x * bet_x + bet_y * bet_y <= r * r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    cin >> n >> r >> d >> x >> y;

    for (int i = 0; i < n; i++)
    {
        cin >> tower[i].first >> tower[i].second;
        if (between(tower[i], { x, y }))
        {
            possible.push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            depth[i][j] = INF;
        }
    }

    for (int i = 0; i < (int)possible.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[j] = false;
        }
        que.push(possible[i]);
        visited[possible[i]] = true;
        depth[possible[i]][possible[i]] = 0;

        while (!que.empty())
        {
            int idx = que.front();
            que.pop();

            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && between(tower[idx], tower[j]))
                {
                    visited[j] = true;
                    depth[possible[i]][j] = depth[possible[i]][idx] + 1;
                    que.push(j);
                }
            }
        }
    }

    double result = 0;

    for (int i = 0; i < n; i++)
    {
        double mini = INF;
        for (int j = 0; j < (int)possible.size(); j++)
        {
            mini = mini < depth[possible[j]][i] ? mini : depth[possible[j]][i];
        }

        if (mini != INF)
        {
            result += (d * pow(0.5, mini));
        }
    }

    result = round(result * 100) / 100;
    
    cout << result << '\n';

    return 0;
}