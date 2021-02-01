#include <iostream>

using namespace std;

struct Shark
{
    int pos_y;
    int pos_x;
    int speed;
    int dir;
    int size;
    bool life;
};

int d_x[5] = { 0,0,0,1,-1 };
int d_y[5] = { 0,-1,1,0,0 };

int main()
{
    int result = 0;
    int r, c, m;
    Shark shark[10001];

    cin >> r >> c >> m;
    int field[102][102];
    int temp_r, temp_c, temp_s, temp_d, temp_z;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp_r >> temp_c >> temp_s >> temp_d >> temp_z;
        shark[i].pos_y = temp_r;
        shark[i].pos_x = temp_c;
        shark[i].speed = temp_s;
        shark[i].dir = temp_d;
        shark[i].size = temp_z;
        shark[i].life = true;
        field[temp_r][temp_c] = i;
    }

    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (field[j][i] > 0)
            {
                result += shark[field[j][i]].size;
                shark[field[j][i]].life = false;
                field[j][i] = 0;
                break;
            }
        }
        for (int j = 1; j <= r; j++)
            for (int k = 1; k <= c; k++)
                field[j][k] = 0;
        for (int j = 1; j <= m; j++)
        {
            if (shark[j].life)
            {
                int remain_count = shark[j].speed;
                switch (shark[j].dir)
                {
                case 1:
                    if (r == 1)
                        break;
                    while (remain_count != 0)
                    {
                        if (remain_count < shark[j].pos_y && remain_count > 0)
                        {
                            shark[j].pos_y -= remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (shark[j].pos_y - 1);
                            shark[j].pos_y = 1;
                        }
                        if (shark[j].pos_y == 1)
                            shark[j].dir = 2;
                        if (remain_count <= (r - shark[j].pos_y))
                        {
                            shark[j].pos_y += remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (r - shark[j].pos_y);
                            shark[j].pos_y = r;
                        }
                        if (shark[j].pos_y == r)
                            shark[j].dir = 1;
                    }
                    break;

                case 2:
                    if (r == 1)
                        break;
                    while (remain_count != 0)
                    {
                        if (remain_count <= (r - shark[j].pos_y))
                        {
                            shark[j].pos_y += remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (r - shark[j].pos_y);
                            shark[j].pos_y = r;
                        }
                        if (shark[j].pos_y == r)
                            shark[j].dir = 1;
                        if (remain_count < shark[j].pos_y)
                        {
                            shark[j].pos_y -= remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (shark[j].pos_y - 1);
                            shark[j].pos_y = 1;
                        }
                        if (shark[j].pos_y == 1)
                            shark[j].dir = 2;
                    }
                    break;

                case 3:
                    if (c == 1)
                        break;
                    while (remain_count != 0)
                    {
                        if (remain_count <= (c - shark[j].pos_x))
                        {
                            shark[j].pos_x += remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (c - shark[j].pos_x);
                            shark[j].pos_x = c;
                        }
                        if (shark[j].pos_x == c)
                            shark[j].dir = 4;
                        if (remain_count < shark[j].pos_x)
                        {
                            shark[j].pos_x -= remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (shark[j].pos_x - 1);
                            shark[j].pos_x = 1;
                        }
                        if (shark[j].pos_x == 1)
                            shark[j].dir = 3;
                    }
                    break;

                case 4:
                    if (c == 1)
                        break;
                    while (remain_count != 0)
                    {
                        if (remain_count < shark[j].pos_x)
                        {
                            shark[j].pos_x -= remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (shark[j].pos_x - 1);
                            shark[j].pos_x = 1;
                        }
                        if (shark[j].pos_x == 1)
                            shark[j].dir = 3;
                        if (remain_count <= (c - shark[j].pos_x))
                        {
                            shark[j].pos_x += remain_count;
                            remain_count = 0;
                        }
                        else
                        {
                            remain_count -= (c - shark[j].pos_x);
                            shark[j].pos_x = c;
                        }
                        if (shark[j].pos_x == c)
                            shark[j].dir = 4;
                    }
                    break;
                }
                if (field[shark[j].pos_y][shark[j].pos_x] == 0)
                    field[shark[j].pos_y][shark[j].pos_x] = j;
                else
                {
                    if (shark[field[shark[j].pos_y][shark[j].pos_x]].size < shark[j].size)
                    {
                        shark[field[shark[j].pos_y][shark[j].pos_x]].life = false;
                        field[shark[j].pos_y][shark[j].pos_x] = j;
                    }
                    else
                    {
                        shark[j].life = false;
                    }
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}