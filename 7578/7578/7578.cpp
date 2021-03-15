#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n;
int input[500001];
map<int, int> sc;
int tree[2000004];
long long res = 0;

int make_tree(int node, int front, int back)
{
    if (tree[node] != -1)
        return tree[node];

    if (front == back)
        return tree[node] = 0;

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

void update(int node, int front, int back, int idx)
{
    if (idx < front || idx > back)
        return;

    tree[node]++;

    if (front == back)
        return;

    int mid = (front + back) / 2;
    update(node * 2, front, mid, idx);
    update(node * 2 + 1, mid + 1, back, idx);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
    }

    int temp;
    for (int i = 1; i <= n;i++)
    {
        cin >> temp;
        sc.insert({ temp, i });
    }

    memset(tree, -1, sizeof(tree));
    make_tree(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, n, sc[input[i]]);
        if (sc[input[i]] != n)
        {
            res += find(1, 1, n, sc[input[i]] + 1, n);
        }
    }

    cout << res << '\n';

    return 0;
}