#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>,
    less<pair<int, int>>> jewel;
multiset<int> bag;
long long result = 0;

bool desc(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first > b.first)
        return true;
    else
        return false;
}

int main()
{
    int n, k;

    cin >> n >> k;

    int temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        jewel.push(make_pair(temp2, temp1));
    }

    int temp;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        bag.insert(temp);
    }

    while (!jewel.empty() && !bag.empty())
    {
        auto it = bag.lower_bound(jewel.top().second);
        if (*it >= jewel.top().second)
        {
            result += jewel.top().first;
            bag.erase(it);
        }
        jewel.pop();
    }

    cout << result << '\n';
    return 0;
}