#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int n, m, k;

long long input[1000001];
long long tree[4000001];
long long lazy[4000001];
vector<long long> answer;


long long make_tree(int front, int back, int node)
{
    if (front == back)
    {
        tree[node] = input[front];
        return tree[node];
    }

    int mid = (front + back) / 2;
    tree[node] = make_tree(front, mid, node * 2) + make_tree(mid + 1, back, node * 2 + 1);

    return tree[node];
}

long long find_sum(int front, int back, int start, int end, int node)
{
    if (start > back || end < front)
    {
        return 0;
    }

    if (start <= front && end >= back)
    {
        return tree[node] + lazy[node] * (back - front + 1);
    }

    int mid = (front + back) / 2;
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    tree[node] += lazy[node] * (back - front + 1);
    lazy[node] = 0;

    return find_sum(front, mid, start, end, node * 2) + find_sum(mid + 1, back, start, end, node * 2 + 1);
}

void update_tree(int front, int back, int start, int end, int node, int num)
{
    if (start > back || end < front)
        return;

    if (start <= front && end >= back)
    {
        lazy[node] += num;
        return;
    }

    int mid = (front + back) / 2;
    update_tree(front, mid, start, end, node * 2, num);
    update_tree(mid + 1, back, start, end, node * 2 + 1, num);

    tree[node] = tree[node * 2] + lazy[node * 2] * (mid - front + 1)
        + tree[node * 2 + 1] + lazy[node * 2 + 1] * (back - mid);
    return;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
    }

    make_tree(1, n, 1);

    int a, b, c, d;
    for (int i = 1; i <= m + k; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update_tree(1, n, b, c, 1, d);
        }
        else
        {
            cin >> b >> c;
            answer.push_back(find_sum(1, n, b, c, 1));
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
    
}