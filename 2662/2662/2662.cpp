#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;


struct for_dp {
    ll cost;
    int cnt;
};

int n, m;

for_dp dp[21][301];

ll money[21][301];

stack<ll> res;

int main()
{
    cin >> n >> m;


    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int j = 1; j <= m; j++)
        {
            cin >> money[j][i];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = j; k <= n; k++)
            {
                if (dp[i - 1][j].cost + money[i][k - j] > dp[i][k].cost)
                {
                    dp[i][k].cost = dp[i - 1][j].cost + money[i][k - j];
                    dp[i][k].cnt = k - j;
                }
            }
        }
    }

    ll answer = dp[m][n].cost;

    int idx = n;

    for (int i = m; i > 0; i--)
    {
        res.push(dp[i][idx].cnt);
        idx = idx - dp[i][idx].cnt;
    }

    cout << answer << '\n';
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }

    return 0;

}