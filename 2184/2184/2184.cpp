#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n, l;
int dp[1001][1001][2];
int dist[1001];

int delivery(int left, int right, int dir, int depth)
{
    if (dp[left][right][dir] != 0)
    {
        return dp[left][right][dir];
    }

    if (left == right)
    {
        dp[left][right][0] = abs(l - dist[left]) * depth;
        dp[left][right][1] = abs(l - dist[left]) * depth;
        return dp[left][right][0];
    }

    if (dir == 0)
    {
        dp[left][right][0] = min(
            delivery(left + 1, right, 0, depth + 1) + (abs(dist[left] - dist[left + 1]) * depth), 
            delivery(left + 1, right, 1, depth + 1) + (abs(dist[left] - dist[right]) * depth)
        );
    }
    else
    {
        dp[left][right][1] = min(
            delivery(left, right - 1, 0, depth + 1) + (abs(dist[right] - dist[left]) * depth),
            delivery(left, right - 1, 1, depth + 1) + (abs(dist[right] - dist[right - 1]) * depth)
        );
    }

    return dp[left][right][dir];
}


int main()
{
    cin >> n >> l;

    for (int i = 1; i <= n; i++)
    {
        cin >> dist[i];
        for (int j = 1; j <= n; j++)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }

    sort(dist + 1, dist + n + 1);


    cout << min(delivery(1, n, 0, 1), delivery(1, n, 1, 1));

    return 0;


}