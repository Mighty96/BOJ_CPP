#include <iostream>
#include <vector>

using namespace std;

int n, m;
int army[500001];
int tree[2000004];
vector<int> result;

int make_tree(int front, int back, int node)
{
    if (front == back)
    {
        tree[node] = army[front];
        return tree[node];
    }

    int mid = (front + back) / 2;

    tree[node] = make_tree(front, mid, node * 2) + make_tree(mid + 1, back, node * 2 + 1);
    return tree[node];
}

int find_tree(int front, int back, int num, int sum, int node)
{

    if (front == back)
    {
        return front;
    }
    
    int mid = (front + back) / 2;

    if (sum + tree[node * 2] >= num)
    {
        return find_tree(front, mid, num, sum, node * 2);
    }
    else
    {
        return find_tree(mid + 1, back, num, sum + tree[node * 2], node * 2 + 1);
    }
}

void update_tree(int front, int back, int idx, int num, int node)
{
    tree[node] += num;

    if (front == back)
    {
        return;
    }

    int mid = (front + back) / 2;
    if (idx <= mid)
    {
        update_tree(front, mid, idx, num, node * 2);
    }
    else
    {
        update_tree(mid + 1, back, idx, num, node * 2 + 1);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> army[i];
    }

    make_tree(1, n, 1);

    cin >> m;

    int temp1, temp2, temp3;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1;
        if (temp1 == 1)
        {
            cin >> temp2 >> temp3;
            update_tree(1, n, temp2, temp3, 1);
        }
        else
        {
            cin >> temp2;
            result.push_back(find_tree(1, n, temp2, 0, 1));
        }
    }

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}