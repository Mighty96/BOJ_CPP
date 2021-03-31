#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int s, d;
vector<pair<int, int>> field[1001];
int dist[1001][1001];
int res[1001];
const int inf = 987654321;

struct compare {
    bool operator () (tuple<int, int, int>& a, tuple<int, int, int>& b)
    {
        return get<1>(a) > get<1>(b);
    }
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> que;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    cin >> s >> d;

    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        field[temp1].push_back({ temp2, temp3 });
        field[temp2].push_back({ temp1, temp3 });
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = inf;

    que.push({ s, 0, 0 });

    while (!que.empty())
    {
        temp1 = get<0>(que.top());
        temp2 = get<1>(que.top());
        temp3 = get<2>(que.top());
        que.pop();
        
        if (dist[temp1][temp3] < temp2) continue;
        if (temp3 >= n) continue;
        for (int i = 0; i < (int)field[temp1].size(); i++)
        {
            if (temp2 + field[temp1][i].second < dist[field[temp1][i].first][temp3 + 1])
            {
                dist[field[temp1][i].first][temp3 + 1] = temp2 + field[temp1][i].second;
                que.push({ field[temp1][i].first, dist[field[temp1][i].first][temp3 + 1], temp3 + 1 });
            }
        }

    }

    int up;

    for (int i = 0; i <= k; i++)
    {
        if (i != 0)
        {
            cin >> up;
            for (int j = 1; j <= n; j++)
                dist[d][j] += up * j;
        }

        int mini = inf;

        for (int j = 1; j <= n; j++)
            mini = min(mini, dist[d][j]);

        res[i] = mini;
    }

    for (int i = 0; i <= k; i++)
        cout << res[i] << '\n';

    return 0;


}