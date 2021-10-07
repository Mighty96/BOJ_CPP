#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll tree[400004];
ll mul_lazy[400004];
ll add_lazy[400004];
ll input[100001];
vector<ll> answer;

int n, m;

ll make_tree(int front, int back, int node)
{
    mul_lazy[node] = 1;
    add_lazy[node] = 0;
    if (front == back)
        return tree[node] = input[front];

    int mid = (front + back) / 2;

    return tree[node] = (make_tree(front, mid, node * 2) + make_tree(mid + 1, back, node * 2 + 1)) % MOD;
}

void update_lazy(int front, int back, int node)
{
    if (add_lazy[node] == 0 && mul_lazy[node] == 1)
        return;

    if (front != back)
    {
        add_lazy[node * 2] = ((add_lazy[node * 2] * mul_lazy[node]) % MOD + add_lazy[node]) % MOD;
        mul_lazy[node * 2] = mul_lazy[node * 2] * mul_lazy[node] % MOD;
        add_lazy[node * 2 + 1] = ((add_lazy[node * 2 + 1] * mul_lazy[node]) % MOD + add_lazy[node]) % MOD;
        mul_lazy[node * 2 + 1] = mul_lazy[node * 2 + 1] * mul_lazy[node] % MOD;
    }
    tree[node] = (tree[node] * mul_lazy[node] % MOD + (back - front + 1) * add_lazy[node] % MOD) % MOD;
    add_lazy[node] = 0;
    mul_lazy[node] = 1;
    return;
}

void update_range(int front, int back, int start, int end, int node, int mul, int add)
{
    update_lazy(front, back, node);

    if (front > end || back < start) return;

    if (front >= start && back <= end)
    {
        add_lazy[node] = ((add_lazy[node] * mul % MOD) + add) % MOD;
        mul_lazy[node] = mul_lazy[node] * mul % MOD;
        update_lazy(front, back, node);
        return;
    }

    int mid = (front + back) / 2;
    update_range(front, mid, start, end, node * 2, mul, add);
    update_range(mid + 1, back, start, end, node * 2 + 1, mul, add);

    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    return;
}

ll find_tree(int front, int back, int start, int end, int node)
{
    update_lazy(front, back, node);
    if (front > end || back < start)
        return 0;
    if (front >= start && back <= end)
        return tree[node];

    int mid = (front + back) / 2;
    return (find_tree(front, mid, start, end, node * 2) + find_tree(mid + 1, back, start, end, node * 2 + 1)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    make_tree(1, n, 1);

    cin >> m;
    int temp1;
    int temp2, temp3, temp4;

    for (int i = 0; i < m; i++)
    {
        cin >> temp1;
        if (temp1 != 4)
        {
            cin >> temp2 >> temp3 >> temp4;
            if (temp1 == 1)
                update_range(1, n, temp2, temp3, 1, 1, temp4);
            else if (temp1 == 2)
                update_range(1, n, temp2, temp3, 1, temp4, 0);
            else if (temp1 == 3)
                update_range(1, n, temp2, temp3, 1, 0, temp4);
        }
        else
        {
            cin >> temp2 >> temp3;
            answer.push_back(find_tree(1, n, temp2, temp3, 1));
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;

}