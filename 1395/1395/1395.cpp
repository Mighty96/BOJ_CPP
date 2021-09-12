#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int tree[400001];
bool lazy[400001];
vector<int> answer;
int n, m;

int find_tree(int front, int back, int start, int end, int node)
{
    if (start > back || end < front)
    {
        return 0;
    }

    if (start <= front && back <= end)
    {
        if (lazy[node])
            return (back - front + 1) - tree[node];
        return tree[node];
    }

    int mid = (front + back) / 2;

    if (lazy[node])
    {
        lazy[node * 2] = (lazy[node * 2] == 0);
        lazy[node * 2 + 1] = (lazy[node * 2 + 1] == 0);
        tree[node] = back - front + 1 - tree[node];
        lazy[node] = false;
    }

    return find_tree(front, mid, start, end, node * 2) + find_tree(mid + 1, back, start, end, node * 2 + 1);
}

void update_tree(int front, int back, int start, int end, int node)
{
    if (start > back || end < front)
        return;

    if (start <= front && back <= end)
    {
        lazy[node] = (lazy[node] == 0);
        return;
    }

    int mid = (front + back) / 2;

    update_tree(front, mid, start, end, node * 2);
    update_tree(mid + 1, back, start, end, node * 2 + 1);

    tree[node] = 0;
    if (lazy[node * 2])
        tree[node] = mid - front + 1 - tree[node * 2];
    else
        tree[node] = tree[node * 2];
    if (lazy[node * 2 + 1])
        tree[node] += back - mid - tree[node * 2 + 1];
    else
        tree[node] += tree[node * 2 + 1];

    return;

}

int main()
{
    cin >> n >> m;

    memset(tree, 0, sizeof(int) * 400001);
    memset(lazy, 0, sizeof(bool) * 400001);
    int o, s, t;
    for (int i = 1; i <= m; i++)
    {
        cin >> o >> s >> t;
        if (o == 0)
        {
            update_tree(1, n, s, t, 1);
        }
        else
        {
            answer.push_back(find_tree(1, n, s, t, 1));
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}