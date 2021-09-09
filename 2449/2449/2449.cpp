#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, m;
int new_n;

int input[201];
vector<int> ball;
int dp[201][201];

int f(int left, int right)
{
    if (dp[left][right] != INF)
    {
        return dp[left][right];
    }

    int bonus;
    for (int i = left; i < right; i++)
    {
        if (ball[left] == ball[i + 1])
        {
            bonus = 0;
        }
        else
        {
            bonus = 1;
        }
        dp[left][right] = min(dp[left][right], f(left, i) + f(i + 1, right) + bonus);
    }

    return dp[left][right];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
    }
    
    ball.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (input[i] != input[i + 1])
        {
            ball.push_back(input[i]);
        }
    }
    ball.push_back(input[n]);

    new_n = (int)ball.size() - 1;


    for (int i = 1; i <= new_n; i++)
    {
        for (int j = 1; j <= new_n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                dp[i][j] = INF;
            }
        }
        dp[i][i] = 0;
    }
    
    int result = INF;

    for (int i = 1; i <= m; i++)
    {
        result = min(result, f(1, new_n));
    }

    cout << result << '\n';

    return 0;


}