#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char field[10][10];
int h, w;
int hole_y, hole_x;
int d_y[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int d_x[4] = { 0,0,-1,1 }; //»óÇÏÁÂ¿ì
int flag;

class info {
public:
    int red_y;
    int red_x;
    int blue_y;
    int blue_x;
    int cnt;
    int c;

    info(int red_y, int red_x, int blue_y, int blue_x, int cnt, int c)
    {
        this->red_y = red_y;
        this->red_x = red_x;
        this->blue_y = blue_y;
        this->blue_x = blue_x;
        this->cnt = cnt;
        this->c = c;
    }
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;
    int red_y, red_x;
    int blue_y, blue_x;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 'R')
            {
                red_y = i;
                red_x = j;
                field[i][j] = '.';
            }
            else if (field[i][j] == 'B')
            {
                blue_y = i;
                blue_x = j;
                field[i][j] = '.';
            }
            else if (field[i][j] == 'O')
            {
                hole_y = i;
                hole_x = j;
            }
        }

    queue<info> que;

    for (int i = 0; i < 4; i++)
    {
        que.push(info(red_y, red_x, blue_y, blue_x, 1, i));
    }

    while (!que.empty())
    {
        info now = que.front();
        que.pop();
        
        if (now.cnt > 10)
            break;

        switch (now.c)
        {
        case 0:
            flag = false;
            if (now.blue_y < now.red_y && now.blue_x == now.red_x)
            {
                while (field[now.blue_y - 1][now.blue_x] == '.')
                {
                    now.blue_y--;
                    flag = true;
                }
                if (field[now.blue_y - 1][now.blue_x] == 'O')
                    break;
                while (field[now.red_y - 1][now.red_x] == '.' &&
                    now.red_y - 1 != now.blue_y)
                {
                    now.red_y--;
                    flag = true;
                }
                if (field[now.red_y - 1][now.red_x] == 'O')
                {
                    cout << now.cnt << '\n';
                    return 0;
                }
            }
            else
            {
                while (field[now.red_y - 1][now.red_x] == '.')
                {
                    now.red_y--;
                    flag = true;
                }
                if (field[now.red_y - 1][now.red_x] == 'O')
                {
                    while (field[now.blue_y - 1][now.blue_x] == '.')
                    {
                        now.blue_y--;
                        flag = true;
                    }
                    if (field[now.blue_y - 1][now.blue_x] == 'O')
                        break;
                    cout << now.cnt << '\n';
                    return 0;
                }
                while (field[now.blue_y - 1][now.blue_x] == '.' &&
                    (now.blue_y - 1 != now.red_y ||
                        now.blue_x != now.red_x))
                {
                    now.blue_y--;
                    flag = true;
                }
                if (field[now.blue_y - 1][now.blue_x] == 'O')
                    break;
            }
            if (flag)
            {
                for (int i = 0; i < 4; i++)
                {
                    que.push(info(now.red_y, now.red_x, now.blue_y, now.blue_x, now.cnt + 1, i));
                }
            }
            break;
            
        case 1:
            flag = false;
            if (now.blue_y > now.red_y && now.blue_x == now.red_x)
            {
                while (field[now.blue_y + 1][now.blue_x] == '.')
                {
                    now.blue_y++;
                    flag = true;
                }
                if (field[now.blue_y + 1][now.blue_x] == 'O')
                    break;
                while (field[now.red_y + 1][now.red_x] == '.' &&
                    now.red_y + 1 != now.blue_y)
                {
                    now.red_y++;
                    flag = true;
                }
                if (field[now.red_y + 1][now.red_x] == 'O')
                {
                    cout << now.cnt << '\n';
                    return 0;
                }
            }
            else
            {
                while (field[now.red_y + 1][now.red_x] == '.')
                {
                    now.red_y++;
                    flag = true;
                }
                if (field[now.red_y + 1][now.red_x] == 'O')
                {
                    while (field[now.blue_y + 1][now.blue_x] == '.')
                    {
                        now.blue_y++;
                        flag = true;
                    }
                    if (field[now.blue_y + 1][now.blue_x] == 'O')
                        break;
                    cout << now.cnt << '\n';
                    return 0;
                }
                while (field[now.blue_y + 1][now.blue_x] == '.' &&
                    (now.blue_y + 1 != now.red_y ||
                        now.blue_x != now.red_x))
                {
                    now.blue_y++;
                    flag = true;
                }
                if (field[now.blue_y + 1][now.blue_x] == 'O')
                    break;
            }
            if (flag)
            {
                for (int i = 0; i < 4; i++)
                {
                    que.push(info(now.red_y, now.red_x, now.blue_y, now.blue_x, now.cnt + 1, i));
                }
            }
            break;

        case 2:
            flag = false;
            if (now.blue_x < now.red_x && now.blue_y == now.red_y)
            {
                while (field[now.blue_y][now.blue_x - 1] == '.')
                {
                    now.blue_x--;
                    flag = true;
                }
                if (field[now.blue_y][now.blue_x - 1] == 'O')
                    break;
                while (field[now.red_y][now.red_x - 1] == '.' &&
                    now.red_x - 1 != now.blue_x)
                {
                    now.red_x--;
                    flag = true;
                }
                if (field[now.red_y][now.red_x - 1] == 'O')
                {
                    cout << now.cnt << '\n';
                    return 0;
                }
            }
            else
            {
                while (field[now.red_y][now.red_x - 1] == '.')
                {
                    now.red_x--;
                    flag = true;
                }
                if (field[now.red_y][now.red_x - 1] == 'O')
                {
                    while (field[now.blue_y][now.blue_x - 1] == '.')
                    {
                        now.blue_x--;
                        flag = true;
                    }
                    if (field[now.blue_y][now.blue_x - 1] == 'O')
                        break;
                    cout << now.cnt << '\n';
                    return 0;
                }
                while (field[now.blue_y][now.blue_x - 1] == '.' &&
                    (now.blue_x - 1 != now.red_x ||
                        now.blue_y != now.red_y))
                {
                    now.blue_x--;
                    flag = true;
                }
                if (field[now.blue_y][now.blue_x - 1] == 'O')
                    break;
            }
            if (flag)
            {
                for (int i = 0; i < 4; i++)
                {
                    que.push(info(now.red_y, now.red_x, now.blue_y, now.blue_x, now.cnt + 1, i));
                }
            }
            break;
        case 3:
            flag = false;
            if (now.blue_x > now.red_x && now.blue_y == now.red_y)
            {
                while (field[now.blue_y][now.blue_x + 1] == '.')
                {
                    now.blue_x++;
                    flag = true;
                }
                if (field[now.blue_y][now.blue_x + 1] == 'O')
                    break;
                while (field[now.red_y][now.red_x + 1] == '.' &&
                    now.red_x + 1 != now.blue_x)
                {
                    now.red_x++;
                    flag = true;
                }
                if (field[now.red_y][now.red_x + 1] == 'O')
                {
                    cout << now.cnt << '\n';
                    return 0;
                }
            }
            else
            {
                while (field[now.red_y][now.red_x + 1] == '.')
                {
                    now.red_x++;
                    flag = true;
                }
                if (field[now.red_y][now.red_x + 1] == 'O')
                {
                    while (field[now.blue_y][now.blue_x + 1] == '.')
                    {
                        now.blue_x++;
                        flag = true;
                    }
                    if (field[now.blue_y][now.blue_x + 1] == 'O')
                        break;
                    cout << now.cnt << '\n';
                    return 0;
                }
                while (field[now.blue_y][now.blue_x + 1] == '.' &&
                    (now.blue_x + 1 != now.red_x ||
                        now.blue_y != now.red_y))
                {
                    now.blue_x++;
                    flag = true;
                }
                if (field[now.blue_y][now.blue_x + 1] == 'O')
                    break;
            }
            if (flag)
            {
                for (int i = 0; i < 4; i++)
                {
                    que.push(info(now.red_y, now.red_x, now.blue_y, now.blue_x, now.cnt + 1, i));
                }
            }
            break;
        }
    }
    
    cout << -1 << '\n';
    return 0;
}