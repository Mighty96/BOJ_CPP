#include <iostream>
#include <vector>

using namespace std;

int t;
int n, k;
int cost[1001];
int d[1001];
vector<vector<int>> forBuild;

int dp(int now)
{
    if (d[now] != -1)
        return d[now];
    if (forBuild[now].empty())
    {
        d[now] = cost[now];
    }
    else
    {
        for (auto& e : forBuild[now])
        {
            d[now] = (d[now] > dp(e) + cost[now]) ? d[now] : (dp(e) + cost[now]);
        }
    }
    return d[now];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int temp1, temp2;
    int w;
    vector<int> result;

    cin >> t;
    for (int l = 0 ; l < t ; l++)
    {
        cin >> n >> k;
        forBuild.clear();

        for (int i = 0; i <= n; i++)
            forBuild.push_back(vector<int>(0, 0));

        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
            d[i] = -1;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> temp1 >> temp2;
            forBuild[temp2].push_back(temp1);
        }
        cin >> w;
        
        result.push_back(dp(w));
        
    }

    for (int i = 0; i < t; i++)
        cout << result[i] << '\n';

    return 0;
    
}