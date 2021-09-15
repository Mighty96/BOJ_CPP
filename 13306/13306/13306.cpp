#include <iostream>
#include <vector>

using namespace std;

int parent[200001];
int uf[200001];

int n, q;

vector<vector<int>> command;

vector<string> answer;

int uf_find(int node)
{
    if (uf[node] == node)
        return node;

    return uf[node] = uf_find(uf[node]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    int x, b, c, d;

    parent[1] = 1;
    uf[1] = 1;
    command.push_back({ 0 });
    answer.push_back("");
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        uf[i] = i;
    }

    for (int i = 1; i <= n + q - 1; i++)
    {
        cin >> x;
        if (x == 0)
        {
            cin >> b;
            
            command.push_back({ x, b });
        }
        else
        {
            cin >> c >> d;

            command.push_back({ x, c, d });
        }
    }

    for (int i = n + q - 1; i >= 1; i--)
        if (command[i][0] == 0)
            uf[command[i][1]] = uf_find(parent[command[i][1]]);
        else
            if (uf_find(command[i][1]) == uf_find(command[i][2]))
                answer.push_back("YES");
            else
                answer.push_back("NO");

    for (int i = q ; i > 0; i--)
        cout << answer[i] << '\n';

    return 0;

}