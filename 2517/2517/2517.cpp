#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

typedef long long ll;

using namespace std;

int n;
int player[500001];
vector<ll> speed;
map<ll, int> m;
int tree[2000004];
vector<int> result;

int find_tree(int front, int back, int start, int end, int node)
{
    if (start > back || end < front)
    {
        return 0;
    }

    if (start <= front && back <= end)
    {
        return tree[node];
    }

    int mid = (front + back) / 2;

    return find_tree(front, mid, start, end, node * 2) + find_tree(mid + 1, back, start, end, node * 2 + 1);
}

void update_tree(int front, int back, int node, int idx)
{
    tree[node]++;
    if (front == back)
    {
        return;
    }

    int mid = (front + back) / 2;

    if (idx <= mid)
    {
        update_tree(front, mid, node * 2, idx);
    }
    else
    {
        update_tree(mid + 1, back, node * 2 + 1, idx);
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ll temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        m.insert({ temp, i });
        speed.push_back(temp);
    }

    sort(speed.begin(), speed.end());

    for (int i = 0; i < n; i++)
    {
        player[m[speed[i]]] = i + 1;
    }

    memset(tree, 0, sizeof(int) * 2000004);

    for (int i = 1; i <= n; i++)
    {
        cout << find_tree(1, n, player[i], n, 1) + 1<< '\n';
        update_tree(1, n, 1, player[i]);
    }

}