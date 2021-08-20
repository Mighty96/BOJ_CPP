#include <iostream>
#include <algorithm>

using namespace std;

bool dp[31][40001];
int n, m;
int weight[31];
int ball[7];


int main()
{
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 40001; j++)
        {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        dp[i][0] = true;
        dp[i][weight[i]] = true;
    }

    cin >> m;

    for (int i = 0 ; i < m; i++)
    {
        cin >> ball[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 40001; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][abs(j + weight[i])] = true;
                dp[i][abs(j - weight[i])] = true;
                dp[i][j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (dp[n][ball[i]])
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }

    cout << '\n';

    return 0;
}