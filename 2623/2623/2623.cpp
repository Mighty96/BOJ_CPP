#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;

queue<int> que;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector<vector<int>> order1(n + 1);

    
    int num[1001] = { 0 };

    int temp, temp_arr[1001];
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        for (int j = 1; j <= temp; j++)
        {
            cin >> temp_arr[j];
        }
        for (int j = 1; j < temp; j++)
        {
            for (int k = j + 1; k <= temp; k++)
            {
                order1[temp_arr[j]].push_back(temp_arr[k]);
                num[temp_arr[k]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
            que.push(i);
    }

    vector<int> result;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int)order1[now].size(); i++)
        {
            if (--num[order1[now][i]] == 0)
            {
                que.push(order1[now][i]);
            }
        }
        result.push_back(now);
    }

    if (result.size() != n)
        cout << 0 << '\n';
    else
        for (int i = 0; i < (int)result.size(); i++)
            cout << result[i] << '\n';
    return 0;
}