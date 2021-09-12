#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;

const int INF = 987654321;

int n;
int song[2001];
int dp[2001][2001];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> song[i];
    }


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;
    dp[0][1] = 0;
    dp[1][2] = 0;
    dp[2][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            dp[i][j] = dp[i - 1][j] + abs(song[i] - song[i - 1]);
            dp[j][i] = dp[j][i - 1] + abs(song[i] - song[i - 1]);
        }
        dp[i][i - 1] = min(dp[i][i - 1], dp[0][i - 1]);
        dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][0]);
        for (int j = 1; j < i - 1; j++)
        {
            dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + abs(song[i] - song[j]));
            dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + abs(song[i] - song[j]));
        }
    }

    int res = INF;
    for (int i = 0; i < n; i++)
    {
        res = min(res, dp[n][i]);
    }

    cout << res << '\n';

    return 0;
}