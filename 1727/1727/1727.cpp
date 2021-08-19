#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int n, m;

int a[1001];
int b[1001];
int dp[1001][1001];
const int INF = 987654321;

int main()
{
    cin >> n >> m;

    if (n <= m)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
        }
        int temp = n;
        n = m;
        m = temp;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = INF;
        }
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            dp[i][j] = min(abs(a[i] - b[j]) + dp[i - 1][j - 1], dp[i][j - 1]);
        }

    }

    cout << dp[n][m] << '\n';

    return 0;
    
}