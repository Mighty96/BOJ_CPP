#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct merge_sort_tree {
    vector<ll> arr;
};

merge_sort_tree merge_tree[400004];
ll input[100001];

int n;
int m;

void make_tree(int front, int back, int node)
{
    if (front == back)
        return merge_tree[node].arr.push_back(input[front]);

    int mid = (front + back) / 2;
    
    make_tree(front, mid, node * 2); make_tree(mid + 1, back, node * 2 + 1);

    int idx_1 = 0;
    int idx_2 = 0;
    
    while (idx_1 < merge_tree[node * 2].arr.size() && idx_2 < merge_tree[node * 2 + 1].arr.size())
    {
        if (merge_tree[node * 2].arr[idx_1] < merge_tree[node * 2 + 1].arr[idx_2])
        {
            merge_tree[node].arr.push_back(merge_tree[node * 2].arr[idx_1]);
            idx_1++;
        }
        else
        {
            merge_tree[node].arr.push_back(merge_tree[node * 2 + 1].arr[idx_2]);
            idx_2++;
        }
    }

    while (idx_1 < merge_tree[node * 2].arr.size())
    {
        merge_tree[node].arr.push_back(merge_tree[node * 2].arr[idx_1]);
        idx_1++;
    }

    while (idx_2 < merge_tree[node * 2 + 1].arr.size())
    {
        merge_tree[node].arr.push_back(merge_tree[node * 2 + 1].arr[idx_2]);
        idx_2++;
    }
}

int find_tree(int front, int back, int start, int end, int node, ll target)
{
    if (front > end || back < start)
        return 0;
    if (front >= start && back <= end)
    {
        return merge_tree[node].arr.end() 
            - upper_bound(merge_tree[node].arr.begin(), merge_tree[node].arr.end(), target);
    }

    int mid = (front + back) / 2;

    return find_tree(front, mid, start, end, node * 2, target)
        + find_tree(mid + 1, back, start, end, node * 2 + 1, target);

}

vector<ll> answer;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    make_tree(1, n, 1);

    cin >> m;

    int s, e, t;

    for (int i = 1; i <= m; i++)
    {
        cin >> s >> e >> t;

        answer.push_back(find_tree(1, n, s, e, 1, t));
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;

}