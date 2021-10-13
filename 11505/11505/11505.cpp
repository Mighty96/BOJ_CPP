#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;
const int MOD = 1000000007;
int n, m, k;
ll input[1000001];
ll tree[4000004];

vector<ll> answer;

ll make_tree(int front, int back, int node)
{
    if (front == back)
        return tree[node] = input[front];

    int mid = (front + back) / 2;

    return tree[node] = (make_tree(front, mid, node * 2) * make_tree(mid + 1, back, node * 2 + 1)) % MOD;
}

ll update_tree(int front, int back, int idx, int node, int num)
{
    if (front > idx || back < idx)
        return tree[node];

    if (front == back)
        return tree[node] = num;

    int mid = (front + back) / 2;

    return tree[node] = update_tree(front, mid, idx, node * 2, num) * update_tree(mid + 1, back, idx, node * 2 + 1, num) % MOD;
}

ll find_tree(int front, int back, int start, int end, int node)
{
    if (front > end || back < start)
        return 1;

    if (front >= start && back <= end)
        return tree[node];

    int mid = (front + back) / 2;

    return find_tree(front, mid, start, end, node * 2) * find_tree(mid + 1, back, start, end, node * 2 + 1) % MOD;
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    make_tree(1, n, 1);

    int temp1, temp2, temp3;
    for (int i = 0; i < m + k; i++)
    {
        cin >> temp1 >> temp2 >> temp3;

        if (temp1 == 1)
            update_tree(1, n, temp2, 1, temp3);
        else if (temp1 == 2)
            answer.push_back(find_tree(1, n, temp2, temp3, 1));
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}