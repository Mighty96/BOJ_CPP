#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

const int MAX = 50;
int h, w;
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };

void time(vector<string> &field)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (field[i][j] == '*')
                for (int k = 0; k < 4; k++)
                    if ((i + d_y[k] >= 0) && (j + d_x[k] >= 0) && (i + d_y[k] < h) && (j + d_x[k] < w))
                        if (field[i + d_y[k]][j + d_x[k]] == '.')
                            field[i + d_y[k]][j + d_x[k]] = ',';

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (field[i][j] == ',')
                field[i][j] = '*';
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<string> field;
    queue<tuple<int, int, int>> que;

    cin >> h >> w;
    string temp;
    int pos_h, pos_w;
    for (int i = 0; i < h; i++)
    {
        cin >> temp;
        field.push_back(temp);
        for (int j = 0; j < w; j++)
            if (field[i][j] == 'S')
            {
                pos_h = i;
                pos_w = j;
                field[i][j] = '.';
            }
    }

    int cnt = 0;
    que.push(make_tuple(pos_h, pos_w, 1));
    int now_h, now_w;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[pos_h][pos_w] = true;
    while (!que.empty())
    {
        if (get<2>(que.front()) > cnt)
        {
            time(field);
            cnt++;
        }
        now_h = get<0>(que.front());
        now_w = get<1>(que.front());
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (now_h + d_y[i] >= 0 && now_w + d_x[i] >= 0 && now_h + d_y[i] < h && now_w + d_x[i] < w)
            {
                if (field[now_h + d_y[i]][now_w + d_x[i]] == 'D')
                {
                    cout << cnt << '\n';
                    return 0;
                }
                else if (field[now_h + d_y[i]][now_w + d_x[i]] == '.' && (!visited[now_h + d_y[i]][now_w + d_x[i]]))
                {
                    que.push(make_tuple(now_h + d_y[i], now_w + d_x[i], cnt + 1));
                    visited[now_h + d_y[i]][now_w + d_x[i]] = true;
                }
            }
        }
    }

    cout << "KAKTUS" << '\n';
    return 0;
}