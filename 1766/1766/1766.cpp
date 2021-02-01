#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    vector<vector<int>> book(n + 1);
    
    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> indegree(n + 1, 0);
    vector<bool> visited(n + 1);

    int temp1, temp2;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        book[temp1].push_back(temp2);
        indegree[temp2]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
            visited[i] = true;
        }
    }
    while (!que.empty())
    {
        int now = que.top();
        que.pop();
        for (int i = 0; i < (int)book[now].size(); i++)
        {
            if (!visited[book[now][i]])
            {
                indegree[book[now][i]]--;
                if (indegree[book[now][i]] == 0)
                {
                    que.push(book[now][i]);
                    visited[book[now][i]] = true;
                }
            }
        }
        cout << now << " ";
    }
    cout << '\n';
    return 0;
}