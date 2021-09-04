#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 987654321;

struct t {
    int goal;
    int cost;
    int time;
};

struct compare {
    bool operator()(t a, t b)
    {
        return a.time > b.time;
    }
};

int T;
int n, m, k;
int dp[101][10001];
vector<string> result;


priority_queue<t, vector<t>, compare> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for (int _ = 1; _ <= T; _++)
    {
        vector<t> ticket[10001];
        cin >> n >> m >> k;

        int temp1, temp2, temp3, temp4;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = INF;
            }
        }


        for (int i = 0; i < k; i++)
        {
            cin >> temp1 >> temp2 >> temp3 >> temp4;

            t temp_t;
            temp_t.goal = temp2;
            temp_t.cost = temp3;
            temp_t.time = temp4;

            ticket[temp1].push_back(temp_t);
        }

        t temp_t;
        temp_t.goal = 1;
        temp_t.cost = 0;
        temp_t.time = 0;
        que.push(temp_t);
        dp[1][0] = 0;

        while (!que.empty())
        {
            t now = que.top();
            que.pop();

            if (now.time > dp[now.goal][now.cost])
            {
                continue;
            }

            for (int i = 0; i < (int)ticket[now.goal].size(); i++)
            {
                if (ticket[now.goal][i].cost + now.cost <= m &&
                    dp[now.goal][now.cost] + ticket[now.goal][i].time < dp[ticket[now.goal][i].goal][ticket[now.goal][i].cost + now.cost])
                {
                    dp[ticket[now.goal][i].goal][ticket[now.goal][i].cost + now.cost] = dp[now.goal][now.cost] + ticket[now.goal][i].time;
                    t temp_t;
                    temp_t.goal = ticket[now.goal][i].goal;
                    temp_t.cost = now.cost + ticket[now.goal][i].cost;
                    temp_t.time = dp[ticket[now.goal][i].goal][ticket[now.goal][i].cost + now.cost];
                    que.push(temp_t);
                }
            }
        }

        int temp_result = INF;
        for (int i = 0; i <= m; i++)
        {
            temp_result = min(temp_result, dp[n][i]);
        }

        if (temp_result < INF)
        {
            result.push_back(to_string(temp_result));
        }
        else
        {
            result.push_back("Poor KCM");
        }
    }

    for (int i = 0; i < T; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;

}
