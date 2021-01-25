#include <iostream>
#include <vector>

using namespace std;
int field[501][501];
int d[501][501];
int n;
int d_x[4] = { 0,0,-1,1 };
int d_y[4] = { 1,-1,0,0 };
int result = 0;

int dp(int y, int x)
{
    if (d[y][x] != 1)
        return d[y][x];

    for (int i = 0; i < 4; i++)
    {
        if (y + d_y[i] >= 0 && x + d_x[i] >= 0 &&
            y + d_y[i] < n && x + d_x[i] < n)
        {
            if (field[y + d_y[i]][x + d_x[i]] < field[y][x])
            {
                d[y][x] = (d[y][x] > dp(y + d_y[i], x + d_x[i]) + 1) ?
                    d[y][x] : dp(y + d_y[i], x + d_x[i]) + 1;
            }
        }
    }

    result = (result > d[y][x]) ? result : d[y][x];
    return d[y][x];
}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> field[i][j];
            d[i][j] = 1;
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp(i, j);
        }
    }

    cout << result << '\n';

    return 0;
}