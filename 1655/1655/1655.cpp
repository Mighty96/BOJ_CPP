#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

long long cache[49][49];

long long dp(int n, int k)
{
    if (cache[n][k] != -1)
        return cache[n][k];

    if (n == k || k == 0)
        return cache[n][k] = 1;
    else
        return cache[n][k] = dp(n - 1, k) + dp(n - 1, k - 1);
}

int main()
{
    int n;
    cin >> n;

    memset(cache, -1, sizeof(cache));
    long long res = 0;

    if (n < 4)
        res = 0;
    else
    {
        for (int i = 1; i <= (n / 4); i++)
        {
            res += dp(13, i) * dp(52 - 4 * i, n - 4 * i) *(long long)pow((double)-1, (double)i - 1) ;
        }
        res %= 10007;
    }

    cout << res << '\n';
}