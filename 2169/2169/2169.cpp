#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int field[1001][1001];
int value[1001][1001];
int temp[1001][1001][2];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> field[i][j];
        }
    }

    value[1][1] = field[1][1];
    for (int i = 2; i <= m; i++)
    {
        value[1][i] = value[1][i - 1] + field[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            temp[i][j][0] = value[i - 1][j] + field[i][j];
            temp[i][j][1] = value[i - 1][j] + field[i][j];
        }
        for (int j = 2; j <= m; j++)
        {
            temp[i][j][0] = max(value[i - 1][j], temp[i][j - 1][0]) + field[i][j];
        }
        for (int j = m - 1; j >= 1; j--)
        {
            temp[i][j][1] = max(value[i - 1][j], temp[i][j + 1][1]) + field[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            value[i][j] = max(temp[i][j][0], temp[i][j][1]);
        }
    }

    cout << value[n][m] << '\n';
    return 0;
    
}