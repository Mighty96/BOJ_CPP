#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> vec[100001];
vector<bool> resBool[100001];
int start, goal;
queue<int> que;
int maxCost[100001];
int preNum[100001];
int res = 0;

bool dfs(int num)
{
    bool temp_bool = false;
    if (num == goal)
        return true;
    for (int i = 0; i < (int)vec[num].size(); i++)
    {
        if (resBool[num][i]) return true;
        if (maxCost[num] + vec[num][i].second == maxCost[vec[num][i].first])
        {
            if (dfs(vec[num][i].first))
            {    
                if (!resBool[num][i])
                {
                    resBool[num][i] = true;
                    res++;
                }
                temp_bool = true;
            }
        }
    }
    return temp_bool;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int temp1, temp2, temp3;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        vec[temp1].push_back({ temp2, temp3 });
        resBool[temp1].push_back(false);
        preNum[temp2]++;
    }

    cin >> start >> goal;

    que.push(start);

    int cur;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        for (int i = 0; i < (int)vec[cur].size(); i++)
        {
            maxCost[vec[cur][i].first] = max(maxCost[vec[cur][i].first], maxCost[cur] + vec[cur][i].second);
            if (--preNum[vec[cur][i].first] == 0)
                que.push(vec[cur][i].first);
        }
    }

    dfs(start);

    cout << maxCost[goal] << '\n' << res << '\n';

    return 0;
}