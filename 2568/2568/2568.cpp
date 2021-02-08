#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> arr;
int l[100001];
int p[100001];
stack<int> st;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    int temp1, temp2;
    arr.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1 >> temp2;
        arr.push_back(make_pair(temp1, temp2));
    }

    sort(arr.begin() + 1, arr.end(), compare);

    int l_idx = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l_idx == 1 || l[l_idx - 1] < arr[i].second)
        {
            l[l_idx] = arr[i].second;
            p[i] = l_idx;
            l_idx++;
        }
        else
        {
            auto itr = lower_bound(l + 1, l + l_idx, arr[i].second);
            *itr = arr[i].second;
            p[i] = distance(l, itr);
        }
    }

    l_idx--;
    int len = n - l_idx;
    cout << len << '\n';
    for (int i = n; i >= 1; i--)
    {
        if (p[i] == l_idx)
        {
            l_idx--;
        }
        else
        {
            st.push(arr[i].first);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << '\n';
        st.pop();
    }

    return 0;
}