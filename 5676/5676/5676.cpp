#include <iostream>
#include <queue>

using namespace std;

int n, k;
int num[100001];

int tree[400004];

queue<string> result;

int make_tree(int front, int back, int node)
{
    if (front >= back)
    {
        tree[node] = num[front];
        return tree[node];
    }

    int mid = (front + back) / 2;

    tree[node] = make_tree(front, mid, node * 2) * make_tree(mid + 1, back, node * 2 + 1);
    return tree[node];
}

int find_tree(int front, int back, int start, int end, int node)
{
    if (start > back || end < front)
    {
        return 1;
    }

    if (front >= start && back <= end)
    {
        return tree[node];
    }

    int mid = (front + back) / 2;

    return find_tree(front, mid, start, end, node * 2) * find_tree(mid + 1, back, start, end, node * 2 + 1);
}

void update(int front, int back, int idx, int node, int update_num)
{
    if (front == back)
    {
        tree[node] = update_num;
        return;
    }
    tree[node] = find_tree(1, n, front, idx - 1, 1) * find_tree(1, n, idx + 1, back, 1) * update_num;
    int mid = (front + back) / 2;

    if (mid >= idx)
    {
        update(front, mid, idx, node * 2, update_num);
    }
    else
    {
        update(mid + 1, back, idx, node * 2 + 1, update_num);
    }

    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    while (cin >> n >> k)
    {

        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
            if (num[i] > 0)
            {
                num[i] = 1;
            }
            else if (num[i] < 0)
            {
                num[i] = -1;
            }
        }

        make_tree(1, n, 1);

        char comm;
        int num1, num2;

        for (int i = 0; i < k; i++)
        {
            cin >> comm >> num1 >> num2;
            if (comm == 'C')
            {
                if (num2 > 0)
                {
                    num2 = 1;
                }
                else if (num2 < 0)
                {
                    num2 = -1;
                }
                update(1, n, num1, 1, num2);
                num[num1] = num2;
            }
            else
            {
                int find_num = find_tree(1, n, num1, num2, 1);

                if (find_num > 0)
                {
                    result.push("+");
                }
                else if (find_num < 0)
                {
                    result.push("-");
                }
                else
                {
                    result.push("0");
                }
            }
        }

        while (!result.empty())
        {
            cout << result.front();
            result.pop();
        }
        cout << '\n';

    }
}