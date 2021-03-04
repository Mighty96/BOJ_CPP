#include <iostream>
#include <string>

using namespace std;

int n, m;
int field[1004][1004];
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };
int num = 1;
int cnt = 0;
int arr[1000004];
int res[1004][1004];

void dfs(int y, int x)
{
    cnt++;
    field[y][x] = num;
    for (int k = 0; k < 4; k++)
    {
        if (x + d_x[k] > 0 && x + d_x[k] <= m &&
            y + d_y[k] > 0 && y + d_y[k] <= n &&
            field[y + d_y[k]][x + d_x[k]] == 0)
        {
            dfs(y + d_y[k], x + d_x[k]);
        }
    }
}

int main()
{
    cin >> n >> m;

    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int j = 1; j <= m; j++)
        {
            field[i][j] = temp[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (field[i][j] == 0)
            {
                cnt = 0;
                num++;
                dfs(i, j);
                arr[num] = cnt;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (field[i][j] == 1)
            {
                res[i][j] += 1;
                if (field[i - 1][j] > 1)
                    res[i][j] += arr[field[i - 1][j]];
                if (field[i][j - 1] > 1 && field[i][j - 1] != field[i - 1][j])
                    res[i][j] += arr[field[i][j - 1]];
                if (field[i + 1][j] > 1 && field[i + 1][j] != field[i - 1][j] &&
                    field[i + 1][j] != field[i][j - 1])
                    res[i][j] += arr[field[i + 1][j]];
                if (field[i][j + 1] > 1 && field[i][j + 1] != field[i - 1][j] &&
                    field[i][j + 1] != field[i][j - 1] && field[i][j + 1] != field[i + 1][j])
                    res[i][j] += arr[field[i][j + 1]];
                res[i][j] %= 10;
            }
            else
                res[i][j] = 0;
            cout << res[i][j];
        }
        cout << '\n';
    }
    return 0;
}