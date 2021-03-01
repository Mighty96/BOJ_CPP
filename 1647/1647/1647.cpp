#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > que;
int union_find[100001];
int res = 0;

int find(int num)
{
    if (union_find[num] == num)
        return num;
    else
        return union_find[num] = find(union_find[num]);
}

bool merge(int num1, int num2)
{
    num1 = find(num1);
    num2 = find(num2);

    if (num1 == num2) return false;

    union_find[num1] = num2;
    return true;
}

int main()
{
    cin >> n >> m;
    int cnt = n - 2;
    int max_cost = 0;
    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;

        que.push({ temp3, temp1, temp2 });
    }

    for (int i = 1; i <= n; i++)
        union_find[i] = i;

    while (!que.empty())
    {
        if (cnt == 0) break;
        temp1 = get<1>(que.top());
        temp2 = get<2>(que.top());
        temp3 = get<0>(que.top());
        que.pop();
        if (merge(temp1, temp2))
        {
            res += temp3;
            cnt--;
        }
    }

    cout << res << '\n';

    return 0;

}