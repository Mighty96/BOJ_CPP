#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = 987654321;

// y , x , 회전횟수 , 방향
int dp[101][101][201][2];
int T;
int n, m, l, g;

int drive_right[101][101];
int drive_bottom[101][101];

vector<int> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    for (int _ = 1; _ <= T; _++)
    {
        cin >> n >> m >> l >> g;


        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k <= n + m; k++)
                {
                    dp[i][j][k][0] = INF;
                    dp[i][j][k][1] = INF;
                }
            }
        }

        dp[1][1][0][0] = 0;
        dp[1][1][0][1] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                cin >> drive_right[i][j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> drive_bottom[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k < n + m; k++)
                {
                    if (k != 0)
                    {
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j][k - 1][1]);
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i][j][k - 1][0]);
                    }

                    if (i != 1)
                    {
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k][0] + drive_bottom[i - 1][j]);
                    }
                    if (j != 1)
                    {
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i][j - 1][k][1] + drive_right[i][j - 1]);
                    }
                }
            }
        }

        bool flag = false;

        for (int i = 0; i < n + m; i++)
        {
            if (dp[n][m][i][0] <= g || dp[n][m][i][1] <= g)
            {
                answer.push_back(i + l * (n + m - 2));
                flag = true;
                break;
            }
        }
        if (!flag)
            answer.push_back(-1);
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}