#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, c;

int dp[1 << 13][10][21];

int juwel[13];

int d(int bitmask, int bag, int w)
{
    //cout << bitmask << " " << bag << " " << w << '\n';

    int& res = dp[bitmask][bag][w];
    if (res != -1) return res;
    
    res = 0;

    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & bitmask) continue;
        if (w + juwel[i] <= c)
            res = max(res, d(bitmask | (1 << i), bag, w + juwel[i]));
        if (juwel[i] <= c && bag + 1 < m)
            res = max(res, d(bitmask | (1 << i), bag + 1, juwel[i]));
    }
    return res + 1;
}

int main()
{
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++)
        cin >> juwel[i];

    memset(dp, -1, sizeof(dp));

    cout << d(0, 0, 0) - 1<< '\n';
}