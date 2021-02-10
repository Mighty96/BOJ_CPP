#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input[1000001];
vector<int> tree[1000001];
bool visited[1000001];
int n;
int result;
int d[1000001][2];
int depth_max;

int cal(int node, bool early)
{
    int &res = d[node][early];
    if (res != 0)
        return res;
    if (early)
    {
        res = 1;
        for (int i = 0; i < (int)tree[node].size(); i++)
            res += min(cal(tree[node][i], true), cal(tree[node][i], false));
    }

    else
    {
        for (int i = 0; i < (int)tree[node].size(); i++)
            res += cal(tree[node][i], true);
    }
    return res;
}

void graph(int node)
{
    visited[node] = true;

    for (int i = 0; i < (int)input[node].size(); i++)
    {
        if (!visited[input[node][i]])
        {
            tree[node].push_back(input[node][i]);
            graph(input[node][i]);
        }
    }
}

int main()
{
    cin >> n;
    int temp1, temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;

        input[temp1].push_back(temp2);
        input[temp2].push_back(temp1);
    }
    graph(1);
    result = min(cal(1, true), cal(1, false));
    
    cout << result << '\n';
   
    return 0;
}