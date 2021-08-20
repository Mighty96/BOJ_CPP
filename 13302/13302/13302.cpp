#include <iostream>
#include <algorithm>

using namespace std;

/*
    0: ½°
    1: 1ÀÏ
    2: 3ÀÏ
    3: 5ÀÏ
    4: ÄíÆù
*/
int dp[101][5][6][26];
int n, m;
bool day[101];
const int INF = 987654321;
const int day1 = 10000;
const int day3 = 25000;
const int day5 = 37000;

int main()
{
    
    cin >> n >> m;

    int temp;

    for (int i = 1; i <= n; i++)
    {
        day[i] = false;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        day[temp] = true;
    }

    dp[1][1][1][0] = day1;
    dp[1][2][1][1] = day3;
    dp[1][3][1][2] = day5;
    if (day[1])
    {
        dp[1][0][0][0] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (day[i])
            {
                dp[i][0][0][j] = min(dp[i][0][0][j], dp[i - 1][0][0][j]);
                dp[i][0][0][j] = min(dp[i][0][0][j], dp[i - 1][1][1][j]);
                dp[i][0][0][j] = min(dp[i][0][0][j], dp[i - 1][2][3][j]);
                dp[i][0][0][j] = min(dp[i][0][0][j], dp[i - 1][3][5][j]);
                dp[i][0][0][j] = min(dp[i][0][0][j], dp[i - 1][4][0][j]);
            }
            dp[i][1][1][j] = min(dp[i][1][1][j], dp[i - 1][0][0][j] + day1);
            dp[i][1][1][j] = min(dp[i][1][1][j], dp[i - 1][1][1][j] + day1);
            dp[i][1][1][j] = min(dp[i][1][1][j], dp[i - 1][2][3][j] + day1);
            dp[i][1][1][j] = min(dp[i][1][1][j], dp[i - 1][3][5][j] + day1);
            dp[i][1][1][j] = min(dp[i][1][1][j], dp[i - 1][4][0][j] + day1);

            dp[i][2][1][j + 1] = min(dp[i][2][1][j + 1], dp[i - 1][0][0][j] + day3);
            dp[i][2][1][j + 1] = min(dp[i][2][1][j + 1], dp[i - 1][1][1][j] + day3);
            dp[i][2][1][j + 1] = min(dp[i][2][1][j + 1], dp[i - 1][2][3][j] + day3);
            dp[i][2][1][j + 1] = min(dp[i][2][1][j + 1], dp[i - 1][3][5][j] + day3);
            dp[i][2][1][j + 1] = min(dp[i][2][1][j + 1], dp[i - 1][4][0][j] + day3);

            dp[i][2][2][j] = dp[i - 1][2][1][j];
            dp[i][2][3][j] = dp[i - 1][2][2][j];

            dp[i][3][1][j + 2] = min(dp[i][3][1][j + 2], dp[i - 1][0][0][j] + day5);
            dp[i][3][1][j + 2] = min(dp[i][3][1][j + 2], dp[i - 1][1][1][j] + day5);
            dp[i][3][1][j + 2] = min(dp[i][3][1][j + 2], dp[i - 1][2][3][j] + day5);
            dp[i][3][1][j + 2] = min(dp[i][3][1][j + 2], dp[i - 1][3][5][j] + day5);
            dp[i][3][1][j + 2] = min(dp[i][3][1][j + 2], dp[i - 1][4][0][j] + day5);

            dp[i][3][2][j] = dp[i - 1][3][1][j];
            dp[i][3][3][j] = dp[i - 1][3][2][j];
            dp[i][3][4][j] = dp[i - 1][3][3][j];
            dp[i][3][5][j] = dp[i - 1][3][4][j];

            if (j >= 3)
            {
                dp[i][4][0][j - 3] = min(dp[i][4][0][j - 3], dp[i - 1][0][0][j]);
                dp[i][4][0][j - 3] = min(dp[i][4][0][j - 3], dp[i - 1][1][1][j]);
                dp[i][4][0][j - 3] = min(dp[i][4][0][j - 3], dp[i - 1][2][3][j]);
                dp[i][4][0][j - 3] = min(dp[i][4][0][j - 3], dp[i - 1][3][5][j]);
                dp[i][4][0][j - 3] = min(dp[i][4][0][j - 3], dp[i - 1][4][0][j]);
            }
        }
    }

    int result = INF;


    for (int i = 0; i <= 20; i++)
    {
        if (day[n])
        {
            result = min(result, dp[n][0][0][i]);
        }
        result = min(result, dp[n][1][1][i]);
        result = min(result, dp[n][2][1][i]);
        result = min(result, dp[n][2][2][i]);
        result = min(result, dp[n][2][3][i]);
        result = min(result, dp[n][3][1][i]);
        result = min(result, dp[n][3][2][i]);
        result = min(result, dp[n][3][3][i]);
        result = min(result, dp[n][3][4][i]);
        result = min(result, dp[n][3][5][i]);
        result = min(result, dp[n][4][0][i]);
    }

    cout << result << '\n';

    return 0;
}