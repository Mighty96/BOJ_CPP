#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000001;
int tree[400004][2];
int input[100001];
vector<int> answer;
int n, m;

void make_tree(int front, int back, int node)
{
    if (front == back)
    {
        tree[node][0] = input[front];
        tree[node][1] = front;
        return;
    }

    int mid = (front + back) / 2;

    make_tree(front, mid, node * 2);
    make_tree(mid + 1, back, node * 2 + 1);

    if (tree[node * 2][0] <= tree[node * 2 + 1][0])
    {
        tree[node][0] = tree[node * 2][0];
        tree[node][1] = tree[node * 2][1];
    }
    else
    {
        tree[node][0] = tree[node * 2 + 1][0];
        tree[node][1] = tree[node * 2 + 1][1];
    }
}

void update(int front, int back, int idx, int node, int num)
{
    if (front > idx || back < idx)
        return;

    if (front == back)
    {
        tree[node][0] = num;
        tree[node][1] = idx;
        return;
    }

    int mid = (front + back) / 2;
    update(front, mid, idx, node * 2, num);
    update(mid + 1, back, idx, node * 2 + 1, num);

    if (tree[node * 2][0] <= tree[node * 2 + 1][0])
    {
        tree[node][0] = tree[node * 2][0];
        tree[node][1] = tree[node * 2][1];
    }
    else
    {
        tree[node][0] = tree[node * 2 + 1][0];
        tree[node][1] = tree[node * 2 + 1][1];
    }
    
    return;
}

pair<int, int> find_tree(int front, int back, int start, int end, int node)
{
    if (front > end || back < start)
        return { INF, 0 };

    if (front >= start && back <= end)
        return { tree[node][0], tree[node][1] };

    int mid = (front + back) / 2;

    pair<int, int> a = find_tree(front, mid, start, end, node * 2);
    pair<int, int> b = find_tree(mid + 1, back, start, end, node * 2 + 1);
    if (a.first <= b.first)
        return a;
    else
        return b;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    make_tree(1, n, 1);


    cin >> m;

    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;


        if (temp1 == 1)
            update(1, n, temp2, 1, temp3);
        else
            answer.push_back(find_tree(1, n, temp2, temp3, 1).second);
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}