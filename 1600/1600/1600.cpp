#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int k;
int w, h;
int move_x[4] = { 1, -1, 0, 0 };
int horse_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int move_y[4] = { 0, 0, 1, -1 };
int horse_y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
bool field[200][200];
bool visited[200][200][31];
queue<tuple<short, short, short, short>> que;

void bfs()
{
    que.push(make_tuple(0, 0, 0, 0));

    while (!que.empty())
    {
        int x = get<1>(que.front());
        int y = get<0>(que.front());
        int cnt = get<2>(que.front());
        int horse_cnt = get<3>(que.front());
        que.pop();
        if (x == w - 1 && y == h - 1)
        {
            cout << cnt << '\n';
            return;
        }
        for (int i = 0; i < 4;i++)
            if (x + move_x[i] >= 0 && x + move_x[i] < w && y + move_y[i] >= 0 && y + move_y[i] < h && field[y + move_y[i]][x + move_x[i]] == 0)
                if (!visited[y + move_y[i]][x + move_x[i]][horse_cnt])
                {
                    visited[y + move_y[i]][x + move_x[i]][horse_cnt] = true;
                    que.push(make_tuple(y + move_y[i], x + move_x[i], cnt + 1, horse_cnt));
                }

        for (int i = 0; i < 8; i++)
            if (x + horse_x[i] >= 0 && x + horse_x[i] < w && y + horse_y[i] >= 0 && y + horse_y[i] < h && horse_cnt < k && field[y + horse_y[i]][x + horse_x[i]] == 0)
                if (!visited[y + horse_y[i]][x + horse_x[i]][horse_cnt + 1])
                {
                    visited[y + horse_y[i]][x + horse_x[i]][horse_cnt + 1] = true;
                    que.push(make_tuple(y + horse_y[i], x + horse_x[i], cnt + 1, horse_cnt + 1));
                }
    }
    cout << "-1" << '\n';
    return;
}


int main()
{


    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> k;
    cin >> w >> h;
    int _temp;

    for (int i = 0; i < h;i++)
    {
        for (int j = 0;j < w;j++)
        {
            cin >> _temp;
            field[i][j] = _temp;
        }
    }

    bfs();
    return 0;
}