#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;



int main()
{
    int n;
    queue<tuple<int, int, int>> que;
    int d_x[4] = { 0,-1,1,0 };
    int d_y[4] = { -1,0,0,1 };
    int time = 0;

    cin >> n;

    vector<vector<int>> field(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int fish_x, fish_y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 9)
            {
                fish_x = j;
                fish_y = i;
            }
        }
    }

    int now_y, now_x;
    int cnt = 0;
    int fish_level = 2;
    int fish_ate = 0;
    bool flag;
    while (true)
    {
        flag = false;
        que.push(make_tuple(fish_y, fish_x, time));
        visited[fish_y][fish_x] = true;
        int least_x = fish_x;
        int least_y = fish_y;
        int least_time = 10000;
        while (!que.empty())
        {
            now_y = get<0>(que.front());
            now_x = get<1>(que.front());
            cnt = get<2>(que.front());
            que.pop();
            
            for (int i = 0; i < 4; i++)
            {
                if (now_y + d_y[i] >= 0 && now_y + d_y[i] < n &&
                    now_x + d_x[i] >= 0 && now_x + d_x[i] < n &&
                    visited[now_y + d_y[i]][now_x + d_x[i]] == false)
                {
                    visited[now_y + d_y[i]][now_x + d_x[i]] = true;
                    if (field[now_y + d_y[i]][now_x + d_x[i]] == fish_level ||
                        field[now_y + d_y[i]][now_x + d_x[i]]  == 0)
                    {
                        que.push(make_tuple(now_y + d_y[i], now_x + d_x[i], cnt + 1));
                    }
                    else if (field[now_y + d_y[i]][now_x + d_x[i]] < fish_level)
                    {
                        que.push(make_tuple(now_y + d_y[i], now_x + d_x[i], cnt + 1));
                        if (least_time > cnt + 1)
                        {
                            least_x = now_x + d_x[i];
                            least_y = now_y + d_y[i];
                            least_time = cnt + 1;
                        }
                        else if (least_time == cnt + 1)
                        {
                            if (least_y > now_y + d_y[i])
                            {
                                least_x = now_x + d_x[i];
                                least_y = now_y + d_y[i];
                                least_time = cnt + 1;
                            }
                            else if (least_y == now_y + d_y[i])
                            {
                                if (least_x > now_x + d_x[i])
                                {
                                    least_x = now_x + d_x[i];
                                    least_y = now_y + d_y[i];
                                    least_time = cnt + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (least_y == fish_y && least_x == fish_x)
            break;
        field[least_y][least_x] = 9;
        fish_ate += 1;
        if (fish_level == fish_ate)
        {
            fish_level = (fish_level + 1 < 7) ? fish_level + 1 : 7 ;
            fish_ate = 0;
        }
        field[fish_y][fish_x] = 0;
        fish_y = least_y;
        fish_x = least_x;
        flag = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = false;
        time = least_time;
    }

    cout << time << '\n';
    return 0;   

}