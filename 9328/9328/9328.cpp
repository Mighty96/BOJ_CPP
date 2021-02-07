#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
char field[102][102];
int result[101];
queue<pair<int, int>> que;
queue<pair<int, int>> temp_que;
int waiting[10000][3];
bool visited[102][102];

int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;

    cin >> t;

    int h, w;
    string temp;
    long long key;

    int current_x, current_y;

    for (int _ = 1; _ <= t; _++)
    {
        cin >> h >> w;
        for (int i = 1; i <= h; i++)
        {
            cin >> temp;
            for (int j = 1; j <= w; j++)
            {
                field[i][j] = temp[j - 1];
                visited[i][j] = false;
            }
        }


        cin >> temp;
        key = 0;
        if (temp != "0")
        {
            for (int i = 0; i < (int)temp.length(); i++)
            {
                key = key | (long long)1 << (temp[i] - 97);
            }
        }

        for (int i = 1; i <= h; i++)
        {
            temp_que.push(make_pair(i, 1));
            temp_que.push(make_pair(i, w));
        }

        for (int i = 2; i <= w - 1; i++)
        {
            temp_que.push(make_pair(1, i));
            temp_que.push(make_pair(h, i));
        }

        int temp_y, temp_x;

        int wait_idx = 0;
        while (!temp_que.empty())
        {
            temp_y = temp_que.front().first;
            temp_x = temp_que.front().second;
            temp_que.pop();

            if (field[temp_y][temp_x] == '$')
            {
                result[_]++;
                field[temp_y][temp_x] = '.';
            }
            else if (field[temp_y][temp_x] >= 65 && field[temp_y][temp_x] <= 90)
            {
                if (key & (long long)1 <<(field[temp_y][temp_x] - 65))
                    field[temp_y][temp_x] = '.';
                else
                {
                    waiting[wait_idx][0] = field[temp_y][temp_x];
                    waiting[wait_idx][1] = temp_y;
                    waiting[wait_idx][2] = temp_x;
                    wait_idx++;
                    visited[temp_y][temp_x] = true;
                }
            }
            else if (field[temp_y][temp_x] >= 97 && field[temp_y][temp_x] <= 122)
            {
                if (~key & ((long long)1 << (field[temp_y][temp_x] - 97)))
                {
                    key |= (long long)1 << (field[temp_y][temp_x] - 97);
                    for (int i = 0; i < wait_idx; i++)
                    {
                        if (waiting[i][0] == field[temp_y][temp_x] - 32)
                        {
                            waiting[i][0] = 0;
                            field[waiting[i][1]][waiting[i][2]] = '.';
                            que.push(make_pair(waiting[i][1], waiting[i][2]));
                        }
                    }
                }
                field[temp_y][temp_x] = '.';
            }
            if (field[temp_y][temp_x] == '.')
            {
                que.push(make_pair(temp_y, temp_x));
                visited[temp_y][temp_x] = true;
            }
        }

        while (!que.empty())
        {
            current_y = que.front().first;
            current_x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++)
            {
                if (current_y + d_y[i] > 0 && current_y + d_y[i] <= h &&
                    current_x + d_x[i] > 0 && current_x + d_x[i] <= w)
                {
                    if (field[current_y + d_y[i]][current_x + d_x[i]] == '$')
                    {
                        result[_]++;
                        field[current_y + d_y[i]][current_x + d_x[i]] = '.';
                    }
                    else if (field[current_y + d_y[i]][current_x + d_x[i]] >= 65 &&
                        field[current_y + d_y[i]][current_x + d_x[i]] <= 90)
                    {
                        if (key & ((long long)1 << (field[current_y + d_y[i]][current_x + d_x[i]] - 65)))
                            field[current_y + d_y[i]][current_x + d_x[i]] = '.';
                        else
                        {
                            waiting[wait_idx][0] = field[current_y + d_y[i]][current_x + d_x[i]];
                            waiting[wait_idx][1] = current_y + d_y[i];
                            waiting[wait_idx][2] = current_x + d_x[i];
                            wait_idx++;
                            visited[current_y + d_y[i]][current_x + d_x[i]] = true;
                        }
                    }
                    else if (field[current_y + d_y[i]][current_x + d_x[i]] >= 97 &&
                        field[current_y + d_y[i]][current_x + d_x[i]] <= 122)
                    {
                        if (~key & ((long long)1 << (field[current_y + d_y[i]][current_x + d_x[i]] - 97)))
                        {
                            key |= ((long long)1 << (field[current_y + d_y[i]][current_x + d_x[i]] - 97));
                            
                            for (int j = 0; j < wait_idx; j++)
                            {
                                if (waiting[j][0] == field[current_y + d_y[i]][current_x + d_x[i]] - 32)
                                {
                                    waiting[j][0] = 0;
                                    field[waiting[j][1]][waiting[j][2]] = '.';
                                    que.push(make_pair(waiting[j][1], waiting[j][2]));
                                }
                            }
                        }
                        field[current_y + d_y[i]][current_x + d_x[i]] = '.';
                    }
                    if (field[current_y + d_y[i]][current_x + d_x[i]] == '.')
                    {
                        if (!visited[current_y + d_y[i]][current_x + d_x[i]])
                        {
                            que.push(make_pair(current_y + d_y[i], current_x + d_x[i]));
                            visited[current_y + d_y[i]][current_x + d_x[i]] = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= t; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}