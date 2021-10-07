#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll tree[400004];
ll input[100001];
ll lazy[400004];
vector<ll> answer;
int n, m;

ll make_tree(int front, int back, int node)
{
    if (front == back)
        return tree[node] = input[front] - input[front - 1];

    int mid = (front + back) / 2;
    return tree[node] = make_tree(front, mid, node * 2) + make_tree(mid + 1, back, node * 2 + 1);
}

void update_lazy(int front, int back, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] = tree[node] + lazy[node] * (back - front + 1);
        if (front != back)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}

void update_range(int front, int back, int start, int end, int node, int v)
{
    update_lazy(front, back, node);

    if (back < start || front > end)
        return;
    if (front >= start && back <= end)
    {
        lazy[node] = v;
        update_lazy(front, back, node);
        return;
    }

    int mid = (front + back) / 2;

    update_range(front, mid, start, end, node * 2, v);
    update_range(mid + 1, back, start, end, node * 2 + 1, v);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}

ll find_tree(int front, int back, int start, int end, int node)
{
    update_lazy(front, back, node);

    if (back < start || front > end)
        return 0;
    if (front >= start && back <= end)
        return tree[node];

    int mid = (front + back) / 2;

    return find_tree(front, mid, start, end, node * 2) + find_tree(mid + 1, back, start, end, node * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> input[i];

    make_tree(1, n, 1);

    cin >> m;

    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1;
        if (temp1 == 1)
        {
            cin >> temp2 >> temp3;
            update_range(1, n, temp2, temp3, 1, 1);
            if (temp3 < n)
                update_range(1, n, temp3 + 1, temp3 + 1, 1, -(temp3 - temp2 + 1));
        }
        else
        {
            cin >> temp2;
            answer.push_back(find_tree(1, n, 1, temp2, 1));
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}