#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int input[100001];
int max_tree[400004];
int min_tree[400004];

int makeMaxTree(int start, int end, int node)
{
    if (max_tree[node] != 0) return max_tree[node];
    if (start == end)
    {
        max_tree[node] = input[start];
        return max_tree[node];
    }

    int mid = (start + end) / 2;

    max_tree[node] = max(makeMaxTree(start, mid, node * 2), makeMaxTree(mid + 1, end, node * 2 + 1));
        return max_tree[node];
}

int makeMinTree(int start, int end, int node)
{
    if (min_tree[node] != 0) return min_tree[node];
    if (start == end)
    {
        min_tree[node] = input[start];
        return min_tree[node];
    }

    int mid = (start + end) / 2;

    min_tree[node] = min(makeMinTree(start, mid, node * 2), makeMinTree(mid + 1, end, node * 2 + 1));
        return min_tree[node];
}

int findMax(int start, int end, int node, int left, int right)
{
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return max_tree[node];

    int mid = (start + end) / 2;
    return max(findMax(start, mid, node * 2, left, right), findMax(mid + 1, end, node * 2 + 1, left, right));
}

int findMin(int start, int end, int node, int left, int right)
{
    if (start > right || end < left) return 1000000001;
    if (start >= left && end <= right) return min_tree[node];

    int mid = (start + end) / 2;
    return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    vector<pair<int, int>> res;
    makeMaxTree(1, n, 1);
    makeMinTree(1, n, 1);
    int left, right;
    for (int i = 0; i < m; i++)
    {
        cin >> left >> right;

        res.push_back(make_pair(findMin(1, n, 1, left, right), findMax(1, n, 1, left, right)));
    }

    for (int i = 0; i < m; i++)
    {
        cout << res[i].first << " " << res[i].second << '\n';
    }

    return 0;

}