#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;

    vector<pair<int, int>> forward[1001];
    vector<pair<int, int>> backward[1001];
    vector<int> v1(n + 1, 987654321);
    vector<int> v2(n + 1, 987654321);
    vector<bool> visited1(n + 1, false);
    vector<bool> visited2(n + 1, false);
    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        forward[temp1].push_back(make_pair(temp2, temp3));
        backward[temp2].push_back(make_pair(temp1, temp3));
    }
    
    int now, temp;
    que.push(make_pair(0, x));
    v1[x] = 0;
    while(!que.empty())
    {
        temp = que.top().first;
        now = que.top().second;
        que.pop();

        if (temp == 987654321) continue;

        for (int i = 0; i < (int)forward[now].size(); i++)
        {
            if (v1[forward[now][i].first] > v1[now] + forward[now][i].second)
            {
                v1[forward[now][i].first] = v1[now] + forward[now][i].second;
                que.push(make_pair(v1[forward[now][i].first], forward[now][i].first));
            }
        }
    }

    que.push(make_pair(0, x));
    v2[x] = 0;
    while (!que.empty())
    {
        temp = que.top().first;
        now = que.top().second;
        que.pop();

        if (temp == 987654321) break;

        for (int i = 0; i < (int)backward[now].size(); i++)
        {
            if (v2[backward[now][i].first] > v2[now] + backward[now][i].second)
            {
                v2[backward[now][i].first] = v2[now] + backward[now][i].second;
                que.push(make_pair(v2[backward[now][i].first], backward[now][i].first));
            }
        }
    }
    
    while (!que.empty())
    {
        que.pop();
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = (result > v1[i] + v2[i]) ? result : v1[i] + v2[i];
    }

    cout << result << '\n';
    return 0;

}