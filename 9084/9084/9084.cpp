#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, m;
int coin[21];
int dp[21][10001];
vector<int> result;

void dp_f()
{
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= m; i += coin[1])
    {
        dp[1][i] = 1;
    }


    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m; j += coin[i])
        {
            for (int k = 0; k <= m; k++)
            {
                if (k + j > m)
                {
                    break;
                }

                dp[i][k + j] += dp[i - 1][k];
            }
       }
    }
    result.push_back(dp[n][m]);
}


int main()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> coin[j];
        }
        cin >> m;

        dp_f();
    }


    for (int i = 0; i < t; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;


}