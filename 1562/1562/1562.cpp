#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int dp[101][10][1025];

int n;


int main()
{
    cin >> n;

    memset(dp, 0, sizeof(int) * 101 * 10 * 1025);

    for (int i = 0; i < 10; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int k = 0; k < 1025; k++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (dp[i - 1][j + 1][k] != 0)
                {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                    dp[i][j][k | (1 << j)] %= 1000000000;
                }
            }
            for (int j = 1; j < 10; j++)
            {
                if (dp[i - 1][j - 1][k] != 0)
                {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                    dp[i][j][k | (1 << j)] %= 1000000000;
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i < 10; i++)
    {
        result += dp[n][i][(int)pow(2, 10) - 1];
        result %= 1000000000;
    }

    cout << result << '\n';

    return 0;
}