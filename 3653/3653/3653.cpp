#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int tc;
int input[200001];
int cd[100001];
int tree[800008];
int n, m;
vector<int> res[101];

int make_tree(int node, int front, int back)
{
    if (tree[node] != -1)
        return tree[node];
    if (front == back)
        return tree[node] = input[front];

    int mid = (front + back) / 2;

    return tree[node] = make_tree(node * 2, front, mid) + make_tree(node * 2 + 1, mid + 1, back);
}

int find(int node, int front, int back, int start, int end)
{
    if (start > back || end < front)
        return 0;
    if (front >= start && back <= end)
        return tree[node];

    int mid = (front + back) / 2;

    return find(node * 2, front, mid, start, end) + find(node * 2 + 1, mid + 1, back, start, end);
}

void update(int node, int front, int back, int idx, int dif)
{
    if (front > idx || idx > back)
        return;

    tree[node] += dif;

    if (front == back) return;

    int mid = (front + back) / 2;

    update(node * 2, front, mid, idx, dif);
    update(node * 2 + 1, mid + 1, back, idx, dif);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;

    memset(tree, -1, sizeof(tree));

    for (int _ = 1; _ <= tc; _++)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            input[i] = 1;
            cd[i] = n - i + 1;
        }
        int floor = n;
        make_tree(1, 1, n + m);
        int cur;
        for (int i = 1; i <= m; i++)
        {
            cin >> cur;
            if (cd[cur] == floor)
            {
                res[_].push_back(0);
                continue;
            }
            res[_].push_back(find(1, 1, n + m, cd[cur] + 1, floor));
            floor++;
            update(1, 1, n + m, cd[cur], -1);
            cd[cur] = floor;
            update(1, 1, n + m, cd[cur], 1);
        }

        for (int i = 1; i <= 800000; i++)
            tree[i] = -1;

        for (int i = 1; i <= n; i++)
        {
            cd[i] = 0;
            input[i] = 0;
        }

    }

    for (int i = 1; i <= tc; i++)
    {
        for (int j = 0; j < (int)res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << '\n';
    }

    return 0;
}