#include <iostream>
#include <vector>

using namespace std;

int t, n, d;
int mapNum[101];
long long map[101][401][401];
long long remap[30][401][401];
long long res[21][21];
long long temp_res[21][21];

int main()
{
    cin >> t >> n >> d;

    int temp1, temp2, temp3;
    for (int i = 1; i <= t; i++)
    {
        cin >> mapNum[i];
        for (int j = 1; j <= mapNum[i]; j++)
        {
            cin >> temp1 >> temp2 >> temp3;
            map[i][temp1][temp2] = temp3;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res[i][i] = 1;
        remap[0][i][i] = 1;
    }

    for (int tc = 1; tc <= t; tc++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                temp_res[i][j] = 0;
                for (int k = 1; k <= n; k++)
                {
                    temp_res[i][j] += remap[0][i][k] * map[tc][k][j];
                    temp_res[i][j] %= 1000000007;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                remap[0][i][j] = temp_res[i][j];
            }
        }
    }

    int num = 1;
    while (t * (1 << num) <= d)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                temp_res[i][j] = 0;
                for (int k = 1; k <= n; k++)
                {
                    temp_res[i][j] += remap[num - 1][i][k] * remap[num - 1][k][j];
                    temp_res[i][j] %= 1000000007;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                remap[num][i][j] = temp_res[i][j];
        }
        num++;
    }

    for (int tc = num; tc >= 0; tc--)
    {
        if (t * (1 << tc) <= d)
        {
            d -= t * (1 << tc);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    temp_res[i][j] = 0;
                    for (int k = 1; k <= n; k++)
                    {
                        temp_res[i][j] += res[i][k] * remap[tc][k][j];
                        temp_res[i][j] %= 1000000007;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    res[i][j] = temp_res[i][j];
                }
            }
        }
    }

    for (int tc = 1; tc <= d; tc++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                temp_res[i][j] = 0;
                for (int k = 1; k <= n;k++)
                {
                    temp_res[i][j] += res[i][k] * map[tc][k][j];
                    temp_res[i][j] %= 1000000007;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                res[i][j] = temp_res[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}