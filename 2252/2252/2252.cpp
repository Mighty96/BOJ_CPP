#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

queue<int> que;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<set<int>> set1(n + 1);
    vector<vector<int>> set2(n + 1);
    vector<int> result;

    int temp1, temp2;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        set1[temp2].insert(temp1);
        set2[temp1].push_back(temp2);
    }

    for (int i = 1; i <= n; i++)
    {
        if (set1[i].empty())
        {
            que.push(i);
        }
    }

    int now;
    while (!que.empty())
    {
        now = que.front();
        que.pop();
        result.push_back(now);
        for (int i = 0; i < (int)set2[now].size(); i++)
        {
            set1[set2[now][i]].erase(now);
            if (set1[set2[now][i]].empty())
            {
                que.push(set2[now][i]);
            }
        }

    }

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << '\n';
    return 0;
}