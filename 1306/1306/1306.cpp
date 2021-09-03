#include <iostream>
#include <algorithm>

using namespace std;

int tree[4000004];
int n, m;
int light[1000001];

int make_tree(int front, int back, int node)
{
    if (front == back)
    {
        tree[node] = light[front];
        return tree[node];
    }

    int mid = (front + back) / 2;

    tree[node] = max(make_tree(front, mid, node * 2), make_tree(mid + 1, back, node * 2 + 1));

    return tree[node];
}

int find_tree(int front, int back, int start, int end, int node)
{
    if (end < front || start > back)
    {
        return 0;
    }

    if (start <= front && end >= back)
    {
        return tree[node];
    }

    int mid = (front + back) / 2;

    return max(find_tree(front, mid, start, end, node * 2), find_tree(mid + 1, back, start, end, node * 2 + 1));
}


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> light[i];
    }

    make_tree(1, n, 1);
    for (int i = m; i <= (n - m + 1); i++)
    {

        cout << find_tree(1, n, i - m + 1, i + m - 1, 1) << " ";
    }

    cout << '\n';
    return 0;



}