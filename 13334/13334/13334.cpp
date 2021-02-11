#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> que;

bool compare(pair<int, int> a,pair<int ,int> b)
{
    if ( a.second== b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    int d;
    cin >> n;

    int temp1, temp2;
    
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        if (temp1 < temp2)
            arr.push_back(make_pair(temp1, temp2));
        else
            arr.push_back(make_pair(temp2, temp1));
    }

    cin >> d; 

    sort(arr.begin(), arr.end(), compare);


    int front;
    int end;
    int res = 0;
    for (int i = 0 ; i < n ; i++)
    {
        front = arr[i].second - d;
        end = arr[i].second;
        if (arr[i].first >= front)
            que.push(arr[i].first);
        else
            continue;
        while (que.top() < front)
            que.pop();
        res = max(res, (int)que.size());
    }

    cout << res << '\n';
    return 0;

}