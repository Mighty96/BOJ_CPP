#include <iostream>

using namespace std;

int n;
int dp[1001];
int ask[1001];

int main()
{
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ask[i];
        if (max_num < ask[i])
            max_num = ask[i];
    }

    for (int i = 4; i <= max_num; i++)
        dp[i] = dp[i - 1] + dp[i - 2] * 5 + dp[i - 3] - dp[i - 4];

    for (int i = 0; i < n; i++)
        cout << dp[ask[i]] << '\n';
}