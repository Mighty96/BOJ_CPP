#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int T;
int n;
int card[1001];
int dp[1001][1001];
vector<int> answer;

int dp_f(int left, int right, int p)
{
    if (left > right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];

    if (p == 0)
        return dp[left][right] = max(dp_f(left + 1, right, 1) + card[left], dp_f(left, right - 1, 1) + card[right]);
    else
        return dp[left][right] = min(dp_f(left + 1, right, 0), dp_f(left, right - 1, 0));
}

int main()
{
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
            cin >> card[j];

        memset(dp, -1, sizeof(dp));

        answer.push_back(dp_f(1, n, 0));

    }

    for (int i = 0; i < T; i++)
        cout << answer[i] << '\n';

    return 0;
}