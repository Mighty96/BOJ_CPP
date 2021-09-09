#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int n, m;
ll dp[21][21];

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return  gcd(b, a % b);
    }
}

ll f(int box, int boom)
{
    if (box == 0)
    {
        dp[box][boom] = 1;
        return dp[box][boom];
    }
    if (boom == 0)
    {
        dp[box][boom] = 0;
        return dp[box][boom];
    }

    if (dp[box][boom] != 0)
    {
        return dp[box][boom];
    }

    dp[box][boom] = f(box - 1, boom - 1) + f(box - 1, boom) * (box - 1);
    return dp[box][boom];
}

int main()
{
    cin >> n >> m;

    memset(dp, 0, sizeof(int) * 21 * 21);

    dp[1][1] = 1;


    ll div = gcd(f(n,n), f(n,m));

    cout << dp[n][m] / div << "/" << dp[n][n] / div << '\n';

    return 0;

    

}