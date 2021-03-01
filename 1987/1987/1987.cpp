#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool vis[26];
int r, c;
char field[21][21];
int d_x[4] = { 1,-1,0,0 };
int d_y[4] = { 0,0,1,-1 };
int res = 0;

void dfs(int y, int x, int cnt)
{
    res = max(res, cnt);
    for (int i = 0; i < 4; i++)
    {
        if (y + d_y[i] > 0 && y + d_y[i] <= r &&
            x + d_x[i] > 0 && x + d_x[i] <= c &&
            !vis[field[y + d_y[i]][x + d_x[i]] - 65])
        {
            vis[field[y + d_y[i]][x + d_x[i]] - 65] = true;
            dfs(y + d_y[i], x + d_x[i], cnt + 1);
            vis[field[y + d_y[i]][x + d_x[i]] - 65] = false;
        }
    }
}


int main()
{
    cin >> r >> c;

    string temp;
    for (int i = 1; i <= r; i++)
    {
        cin >> temp;
        for (int j = 1; j <= c; j++)
        {
            field[i][j] = temp[j - 1];
        }
    }

    vis[field[1][1] - 65] = true;
    dfs(1, 1, 1);

    cout << res << '\n';

    return 0;
}