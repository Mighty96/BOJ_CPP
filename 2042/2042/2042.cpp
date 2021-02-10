#include <iostream>
#include <vector>

using namespace std;

long long tree[4000000];
long long number[1000001];
int idx[1000001];
vector<long long> result;
int n, m, k;

long long seg(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = number[start];
        idx[start] = node;
        return tree[node];
    }

    int mid = (start + end) / 2;

    tree[node] = seg(start, mid, node * 2) + seg(mid + 1, end, node * 2 + 1);
    return tree[node];
}

long long find(int start, int end, int node, int left, int right)
{
    if (left > end || right < start) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return find(start, mid, node * 2, left, right) + find(mid + 1, end, node * 2 + 1, left, right);

}

void change(int before, long long after)
{
    long long temp_sub = after - tree[idx[before]];
    int temp_idx = idx[before];
    while (temp_idx > 0)
    {
        tree[temp_idx] += temp_sub;
        temp_idx /= 2;
    }
}


int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }
    seg(1, n, 1);
    

    
    int temp1, temp2;
    long long temp3;
    for (int j = 1; j <= m + k; j++)
    {
        cin >> temp1 >> temp2 >> temp3;

        if (temp1 == 1)
        {
            change(temp2, temp3);
        }
        else if (temp1 == 2)
        {
            result.push_back(find(1, n, 1, temp2, (int)temp3));
        }
    }

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}