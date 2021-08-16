#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
long long k;
long long dp[101][101];

long long make_dynamic(int x, int y)
{
    if (dp[x][y] == -1)
    {
        dp[x][y] = make_dynamic(x - 1, y) + make_dynamic(x, y - 1);
    }
    if (dp[x][y] > 1000000000)
    {
        dp[x][y] = 1000000001;
    }

    return dp[x][y];
}

int main()
{
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(long long) * 101 * 101);

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 1;
    }
    make_dynamic(n, m);

    string result = "";
    
    while (n != 0 && m != 0)
    {
        if (dp[n - 1][m] >= k)
        {
            n--;
            result += "a";
        }
        else
        {
            k -= dp[n - 1][m];
            m--;
            result += "z";

        }
    }

    if (k > 1)
    {
        cout << -1 << '\n';
        return 0;
    }

    while (n > 0)
    {
        n--;
        result += "a";
    }

    while (m > 0)
    {
        m--;
        result += "z";
    }

    cout << result << '\n';

    return 0;


}