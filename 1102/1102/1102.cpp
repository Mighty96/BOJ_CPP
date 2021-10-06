#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 987654321;

int dp[1 << 16];
int n;
int cost[16][16];
int init = 0;
int p;
int answer = INF;

int countBit(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        cnt += (num & 1);
        num = num >> 1;
    }
    return cnt;
}

void d(int bitmask, int c)
{
    dp[bitmask] = c;

    if (countBit(bitmask) >= p)
    {
        answer = min(answer, dp[bitmask]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!(bitmask & (1 << i))) continue;
        for (int j = 0; j < n; j++)
        {
            if (bitmask & (1 << j)) continue;
            if ((dp[bitmask | (1 << j)] == -1) || (dp[bitmask | (1 << j)] > c + cost[i][j]))
                d(bitmask | (1 << j), c + cost[i][j]);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    string temp;
    cin >> temp;

    for (int i = n - 1; i >= 0; i--)
    {
        init = init << 1;
        if (temp[i] == 'Y')
            init++;
    }

    cin >> p;

    memset(dp, -1, sizeof(dp));

    d(init, 0);
    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}