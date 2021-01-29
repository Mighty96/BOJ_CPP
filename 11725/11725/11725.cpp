#include <iostream>
#include <vector>

using namespace std;

int n;
int mother[100001];

void dfs(int parent, int child, vector<vector<int>> &vec)
{
    mother[child] = parent;
    for (int i = 0; i < vec[child].size(); i++)
    {
        if (vec[child][i] != parent)
            dfs(child, vec[child][i], vec);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    vector<vector<int>> vec(n + 1);

    int temp1, temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;
        vec[temp1].push_back(temp2);
        vec[temp2].push_back(temp1);
    }

    dfs(0, 1, vec);

    for (int i = 2; i <= n; i++)
        cout << mother[i] << '\n';

    return 0;
}