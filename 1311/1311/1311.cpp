#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<int>> vec;
int cost[21][21];
int dp[21][1100000];
int n;


int main()
{
    cin >> n;

    vec.push_back({});

    for (int i = 1; i <= n; i++)
    {
        vec.push_back({});
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(int) * 21 * 1100000);

    for (int i = 1; i <= n; i++)
    {
        dp[1][1 << (i - 1)] = cost[1][i];
        vec[1].push_back(1 << (i - 1));
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < vec[i - 1].size(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((vec[i - 1][j] & (1 << k)) == 0)
                {
                    if (dp[i][vec[i - 1][j] + (1 << k)] == -1)
                    {
                        dp[i][vec[i - 1][j] + (1 << k)] = dp[i - 1][vec[i - 1][j]] + cost[i][k + 1];
                        vec[i].push_back(vec[i - 1][j] + (1 << k));
                    }
                    dp[i][vec[i - 1][j] + (1 << k)] = min(dp[i][vec[i - 1][j] + (1 << k)], dp[i - 1][vec[i - 1][j]] + cost[i][k + 1]);
                }
            }
        }
    }

    cout << dp[n][(int)pow(2, n) - 1] << '\n';
    return 0;
}