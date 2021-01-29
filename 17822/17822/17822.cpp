#include <iostream>
#include <vector>

using namespace std;
int n, m, t;
int field[51][100];
bool visited[51][50];
int d_x[4] = { 0,0,-1,1 };
int d_y[4] = { 1,-1,0,0 };
bool flag = false;

void dfs(int y, int x, int num)
{
    for (int i = 0; i < 4; i++)
    {
        if (y + d_y[i] > 0 && y + d_y[i] <= n &&
            x + d_x[i] >= 0 && x + d_x[i] < m &&
            !visited[y + d_y[i]][x + d_x[i]] &&
            field[y + d_y[i]][x + d_x[i]] == num)
        {
            flag = true;
            field[y][x] = 0;
            field[y + d_y[i]][x + d_x[i]] = 0;
            visited[y + d_y[i]][x + d_x[i]] = true;
            dfs(y + d_y[i], x + d_x[i], num);
        }
        if (x == 0 && field[y][m - 1] == num)
        {
            flag = true;
            field[y][x] = 0;
            field[y][m - 1] = 0;
            visited[y][m - 1] = true;
            dfs(y, m - 1, num);
        }
        if (x == m - 1 && field[y][0] == num)
        {
            flag = true;
            field[y][x] = 0;
            field[y][0] = 0;
            visited[y][0] = true;
            dfs(y, 0, num);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];

    int x, d, k;
    for (int _ = 0; _ < t; _++)
    {
        cin >> x >> d >> k;
        if (d == 1)
        {
            k = m - k;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % x == 0)
            {
               
                for (int j = m - 1; j >= 0; j--)
                {
                    field[i][j + k] = field[i][j];
                }
                for (int j = k; j < k + m; j++)
                {
                    field[i][j % m] = field[i][j];
                }
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < m; j++)
            {
                if (field[i][j] == 0)
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }

        flag = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    visited[i][j] = true;
                    dfs(i, j, field[i][j]);
                }
            }
        }
        if (!flag)
        {
            double sum = 0;
            int sum_num = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < m; j++)
                    if (field[i][j] != 0)
                    {
                        sum += field[i][j];
                        sum_num++;
                    }
            sum /= sum_num;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (field[i][j] != 0)
                    {
                        if (field[i][j] > sum)
                            field[i][j]--;
                        else if (field[i][j] < sum)
                            field[i][j]++;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] != 0)
                result += field[i][j];

    cout << result << '\n';
    return 0;
}