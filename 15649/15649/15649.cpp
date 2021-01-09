#include <iostream>
#include <vector>
#include <string>
using namespace std;


void dfs(int now, string str, int count, const int n, const int m, vector<bool> visited)
{
    visited[now] = true;
    if (count == m)
        cout << str << '\n';
    else
    {
        for (int i = 1; i <= n ; i++)
        {
            if (visited[i] == false)
            {                
                dfs(i, str + " " + to_string(i), count + 1, n, m, visited);
            }
        }
    }
}


int main()
{
    int n, m;

    cin >> n >> m;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        dfs(i, to_string(i), 1, n, m, visited);
    }

    return 0;
}