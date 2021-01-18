#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
vector<string> field;

int h, w;
int result = 0;
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };

void bfs(int y, int x, int cnt, vector<vector<int>> &visited)
{
    result = (cnt > result) ? cnt : result;
    for (int i = 0; i < 4; i++)
    {
        if (y + d_y[i] >= 0 && y + d_y[i] < h && x + d_x[i] >= 0 && x + d_x[i] < w &&
            field[y + d_y[i]][x + d_x[i]] == 'L' &&
            visited[y + d_y[i]][x + d_x[i]] == false)
        {
            visited[y + d_y[i]][x + d_x[i]] = true;
            bfs(y + d_y[i], x + d_x[i], cnt + 1, visited);
        }
    }
}

int main()
{
    cin >> h >> w;

    string temp;
    queue<pair<int, int>> que1;
    queue<tuple<int, int, int>> que2;
    for (int i = 0; i < h; i++)
    {
        cin >> temp;
        field.push_back(temp);
        for (int j = 0; j < w; j++)
        {
            if (field[i][j] == 'L')
                que1.push(make_pair(i, j));
        }
    }

    vector<vector<int>> visited(h, vector<int>(w, false));
    while (!que1.empty())
    {
        que2.push(make_tuple(que1.front().first, que1.front().second, 0));
        que1.pop();

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                visited[i][j] = false;
            }
        }
        visited[get<0>(que2.front())][get<1>(que2.front())] = true;
        while (!que2.empty())
        {
            int y = get<0>(que2.front());
            int x = get<1>(que2.front());
            int cnt = get<2>(que2.front());
            que2.pop();
            for (int i = 0; i < 4; i++)
            {
                if (y + d_y[i] >= 0 && y + d_y[i] < h && x + d_x[i] >= 0 && x + d_x[i] < w &&
                    field[y + d_y[i]][x + d_x[i]] == 'L' &&
                    visited[y + d_y[i]][x + d_x[i]] == false)
                {
                    visited[y + d_y[i]][x + d_x[i]] = true;
                    que2.push(make_tuple(y + d_y[i], x + d_x[i], cnt + 1));
                }
            }
            result = (result > cnt) ? result : cnt;
        }

    }

    cout << result << '\n';
    return 0;
}