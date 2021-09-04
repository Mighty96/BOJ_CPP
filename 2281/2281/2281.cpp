#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int dp[1001][1001];

int target[1001];

int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> target[i];

        if (i == 1)
        {
            dp[1][target[i]] = 0;
            continue;
        }

        int temp = INF;
        for (int j = m; j >= 0; j--)
        {
            temp = min(temp, dp[i - 1][j] + (int)pow(m - j, 2));
        }
        dp[i][target[i]] = temp;

        for (int j = target[i] + 2; j <= m; j++)
        {
            if (dp[i - 1][j - target[i] - 1] < dp[i][j])
            {
                dp[i][j] = dp[i - 1][j - target[i] - 1];
            }
        }


    }

    int result = INF;

    for (int i = 1; i <= m; i++)
    {
        result = min(result, dp[n][i]);
    }

    cout << result << '\n';
}