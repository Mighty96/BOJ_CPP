#include <iostream>
#include <string>
using namespace std;

int w, h;
int cnt[102][102];
int d_x[4] = { 1, -1, 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };
string temp;

void dfs(int y, int x, int field[102][102])
{
    for (int i = 0;i < 4;i++)
    {
        if (field[y + d_y[i]][x + d_x[i]] == 0)
        {
            if (cnt[y + d_y[i]][x + d_x[i]] > cnt[y][x])
            {
                cnt[y + d_y[i]][x + d_x[i]] = cnt[y][x];
                dfs(y + d_y[i], x + d_x[i], field);
            }
        }
        else if (field[y + d_y[i]][x + d_x[i]] == 1)
        {
            if (cnt[y + d_y[i]][x + d_x[i]] > cnt[y][x] + 1)
            {
                field[y + d_y[i]][x + d_x[i]] = 0;
                cnt[y + d_y[i]][x + d_x[i]] = cnt[y][x] + 1;
                dfs(y + d_y[i], x + d_x[i], field);
                field[y + d_y[i]][x + d_x[i]] = 1;
            }
        }
    }
}


int main()
{
    int field[102][102];
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    fill(&field[0][0], &field[101][102], 2);
    fill(&cnt[0][0], &cnt[101][102], 7654321);
    cnt[1][1] = 0;
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        cin >> temp;
        for (int j = 1; j <= w; j++)
            field[i][j] = temp[j - 1] - 48;
    }
    dfs(1, 1, field);

    cout << cnt[h][w] << '\n';

    return 0;
}