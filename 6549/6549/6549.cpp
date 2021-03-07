#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n;
int input[100001];
int tree[400004];
vector<long long> res;

int makeTree(int node, int front, int back)
{
    if (tree[node] != -1)
        return tree[node];
    if (front == back)
        return tree[node] = front;
        
    int mid = (front + back) / 2;

    if (input[makeTree(node * 2, front, mid)] <= input[makeTree(node * 2 + 1, mid + 1, back)])
        tree[node] = makeTree(node * 2, front, mid);
    else
        tree[node] = makeTree(node * 2 + 1, mid + 1, back);

    return tree[node];
}

int find(int node, int front, int back, int start, int end)
{
    if (front > end || back < start)
        return 1000000001;
    if (front >= start && back <= end)
        return tree[node];

    int mid = (front + back) / 2;

    int temp1, temp2;
    temp1 = find(node * 2, front, mid, start, end);
    temp2 = find(node * 2 + 1, mid + 1, back, start, end);
    if (temp1 == 1000000001)
        return temp2;
    else if (temp2 == 1000000001)
        return temp1;
    if (input[temp1] < input[temp2])
        return temp1;
    else
        return temp2;
}

long long dnq(int start, int end)
{
    if (start == end)
        return input[start];
    if (start > end)
        return 0;

    int low = find(1, 1, n, start, end);
    long long tempMax = (long long)input[low] * (long long)(end - start + 1);
    tempMax = max(tempMax, dnq(start, low - 1));
    tempMax = max(tempMax, dnq(low + 1, end));
    return tempMax;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(tree, -1, sizeof(tree));
    while (true)
    {
        cin >> n;
        if (n == 0) break;

        for (int i = 1; i <= n; i++)
        {
            cin >> input[i];
        }
        makeTree(1, 1, n);
        res.push_back(dnq(1, n));

        for (int i = 1; i <= 400003; i++)
            tree[i] = -1;
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}