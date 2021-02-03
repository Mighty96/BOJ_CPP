#include <iostream>
#include <algorithm>

using namespace std;

long number[100001];
long tree[400001];
int question[100001][2];


long seg(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = number[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    tree[node] = min(seg(start, mid, node * 2), seg(mid + 1, end, node * 2 + 1));
    return tree[node];
}

long find(int start, int end, int node, int left, int right)
{
    if (left > end || right < start) return 1000000001;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(find(start, mid, node * 2, left, right),find(mid + 1, end, node * 2 + 1, left, right));
}


int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }

    seg(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> question[i][0] >> question[i][1];
    }

    for (int i = 1; i <= m; i++)
    {
        cout << find(1, n, 1, question[i][0], question[i][1]) << '\n';
    }
    return 0;




}