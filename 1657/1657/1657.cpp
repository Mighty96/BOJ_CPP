#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

string tofu[14];
int dp[14 * 14][1 << 14];
int price[6][6] = {
    {10, 8, 7, 5, 0, 1},
    {8, 6, 4, 3, 0, 1},
    {7, 4, 3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0}
};

int d(int num, int bit)
{
    if (num >= n * m)
        return 0;

    if (dp[num][bit] != -1)
        return dp[num][bit];

    dp[num][bit] = d(num + 1, (bit << 1) & ((1 << m) - 1));

    int y = num / m;
    int x = num % m;

    if (!(bit & (1 << (m - 1))))
    {
        if (!(bit & (1 << (m - 2))) && x < m - 1)
        {
            dp[num][bit] = 
                max(dp[num][bit], price[tofu[y][x] - 'A'][tofu[y][x + 1] - 'A'] + d(num + 2, (bit << 2) & ((1 << m) - 1)));
        }
        if (y < n - 1)
        {
            dp[num][bit] =
                max(dp[num][bit], price[tofu[y][x] - 'A'][tofu[y + 1][x] - 'A'] + d(num + 1, ((bit << 1) + 1) & ((1 << m) - 1)));
        }
    }

    return dp[num][bit];
}


int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> tofu[i];
    
    memset(dp, -1, sizeof(dp));
    
    cout << d(0, 0) << '\n';

    return 0;
}