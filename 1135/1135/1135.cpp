#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

priority_queue<int> que;
vector<int> child[50];
int dp[50];

int dp_f(int idx)
{
    if (dp[idx] != -1)
        return dp[idx];

    if (child[idx].size() == 0)
    {
        dp[idx] = 0;
        return dp[idx];
    }

    for (int i = 0; i < (int)child[idx].size(); i++)
        dp_f(child[idx][i]);

    for (int i = 0; i < (int)child[idx].size(); i++)
        que.push(dp[child[idx][i]]);

    int temp_max = 0;
    int temp_num = 0;
    while (!que.empty())
    {
        temp_num++;
        temp_max = temp_max > que.top() + temp_num ? temp_max : que.top() + temp_num;
        que.pop();
    }

    dp[idx] = temp_max;

    return dp[idx];
}


int main()
{
    cin >> n;

    int temp;
    cin >> temp;
    dp[0] = -1;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        child[temp].push_back(i);

        dp[i] = -1;
    }

    cout << dp_f(0) << '\n';

    return 0;

}