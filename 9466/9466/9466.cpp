#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int arr[100001];
int visited[100001];
int cnt[100001];
vector<int> result;
int temp_result;

void dfs(int num, int count, int judge)
{
    visited[num] = judge;
    cnt[num] = count;

    if (visited[arr[num]] == 0)
    {
        dfs(arr[num], count + 1, judge);
    }
    else if ( visited[arr[num]] == judge)
    {
        temp_result -= (cnt[num] - cnt[arr[num]] + 1);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    int n;

    for (int _ = 1; _ <= t; _++)
    {
        cin >> n;
        temp_result = n;
        for (int i = 1; i <= n; i++)
        {
            visited[i] = 0;
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int judge = 1;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && visited[arr[i]] == 0)
            {
                dfs(i, 1, judge++);
            }
        }
        result.push_back(temp_result);
    }

    for (int i = 0; i < t; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}