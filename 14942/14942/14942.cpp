#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int ant[100001];
vector<pair<int, int>> hole[100001];
queue<int> que;
bool vis[100001];
int parent[100001][2];
vector<int> answer;

int cal(int num, int idx)
{
    if (idx == 1)
        return 1;

    if (num < parent[idx][1])
        return idx;

    return cal(num - parent[idx][1], parent[idx][0]);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> ant[i];

    int temp1, temp2, temp3;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        hole[temp1].push_back({ temp2, temp3 });
        hole[temp2].push_back({ temp1, temp3 });
    }

    que.push(1);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        vis[now] = true;
        if (hole[now].empty())
            continue;

        for (int i = 0; i < (int)hole[now].size(); i++)
        {
            if (vis[hole[now][i].first])
                continue;
            parent[hole[now][i].first][0] = now;
            parent[hole[now][i].first][1] = hole[now][i].second;
            que.push(hole[now][i].first);
        }
    }

    for (int i = 1; i <= n; i++)
        answer.push_back(cal(ant[i], i));

    for (int i = 0; i < n; i++)
        cout << answer[i] << '\n';

    return 0;
}