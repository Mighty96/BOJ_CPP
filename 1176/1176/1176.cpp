#include <iostream>

using namespace std;

int n, k;

int student[16];
long long dp[1 << 16][16];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> student[i];

    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = 1;
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (i & (1 << l)) continue;
                if (abs(student[j] - student[l]) > k)
                {
                    dp[i | (1 << l)][l] += dp[i][j];
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i < n; i++)
        answer += dp[(1 << n) - 1][i];
    cout << answer << '\n';

    return 0;
}