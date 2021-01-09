#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n;
    long long m;
    cin >> n >> m;
    vector<long long> tree(n + 1, 0);
    int max = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> tree[i];
    }
    
    sort(tree.begin(), tree.end());

    int front = 0;
    int end = n;
    int mid = n / 2;

    while ((front + 1) != end)
    {
        long long sum = 0;
        for (int i = mid; i <= n; i++)
        {
            sum += (tree[i] - tree[mid]);
        }
        if (sum < m) end = mid;
        else if (sum == m)
        {
            cout << tree[mid] << '\n';
            return 0;
        }
        else front = mid;
        mid = (front + end) / 2;
    }

    long long _sum = 0;
    long long answer = tree[mid];
    for (int i = mid; i <= n; i++)
    {
        _sum += (tree[i] - tree[mid]);
    }
    while (_sum >= m)
    {
        _sum -= (n - mid);
        answer++;
    }

    cout << answer - 1 << '\n';

    return 0;
}
