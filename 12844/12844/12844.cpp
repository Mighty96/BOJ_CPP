#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;

int seg_tree[2000004];
int input[500001];
int lazy[2000004];
vector<int> answer;

int make_tree(int front, int back, int node)
{
    if (front == back)
        return seg_tree[node] = input[front];

    int mid = (front + back) / 2;

    seg_tree[node] = make_tree(front, mid, node * 2) ^ make_tree(mid + 1, back, node * 2 + 1);
    return seg_tree[node];
}

int find_tree(int front, int back, int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        if ((back - front) % 2 == 0)
            seg_tree[node] ^= lazy[node];

        if (front != back)
        {
            if (lazy[node * 2] == 0)
                lazy[node * 2] = lazy[node];
            else
                lazy[node * 2] ^= lazy[node];
            if (lazy[node * 2 + 1] == 0)
                lazy[node * 2 + 1] = lazy[node];
            else
                lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > back || end < front)
        return -1;

    if (front >= start && back <= end)
        return seg_tree[node];

    int mid = (front + back) / 2;
    int num1 = find_tree(front, mid, start, end, node * 2);
    int num2 = find_tree(mid + 1, back, start, end, node * 2 + 1);
    if (num1 == -1)
        return num2;
    else if (num2 == -1)
        return num1;
    else
        return num1 ^ num2;
}

void make_lazy(int front, int back, int start, int end, int node, int num)
{
    if (lazy[node] != 0)
    {
        if ((back - front) % 2 == 0)
            seg_tree[node] ^= lazy[node];
        if (front != back)
        {
            if (lazy[node * 2] == 0)
                lazy[node * 2] = lazy[node];
            else
                lazy[node * 2] ^= lazy[node];
            if (lazy[node * 2 + 1] == 0)
                lazy[node * 2 + 1] = lazy[node];
            else
                lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > back || end < front)
        return;
    if (front >= start && back <= end)
    {
        if ((back - front) % 2 == 0)
            seg_tree[node] ^= num;
        if (front != back)
        {
            if (lazy[node * 2] == 0)
                lazy[node * 2] = num;
            else
                lazy[node * 2] ^= num;
            if (lazy[node * 2 + 1] == 0)
                lazy[node * 2 + 1] = num;
            else
                lazy[node * 2 + 1] ^= num;
        }
        return;
    }

    int mid = (front + back) / 2;
    make_lazy(front, mid, start, end, node * 2, num);
    make_lazy(mid + 1, back, start, end, node * 2 + 1, num);

    seg_tree[node] = seg_tree[node * 2] ^ seg_tree[node * 2 + 1];

    return;
}

int main()
{
    cin >> n;

    memset(lazy, 0, sizeof(lazy));

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    make_tree(1, n, 1);

    cin >> m;

    int temp1, temp2, temp3, temp4;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1;
        if (temp1 == 1)
        {
            cin >> temp2 >> temp3 >> temp4;
            temp2++;
            temp3++;
            make_lazy(1, n, temp2, temp3, 1, temp4);
        }
        else
        {
            cin >> temp2 >> temp3;
            temp2++;
            temp3++;
            answer.push_back(find_tree(1, n, temp2, temp3, 1));
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}