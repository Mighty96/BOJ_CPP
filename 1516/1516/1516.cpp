#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> que;

int n;
vector<int> build1[100001];
vector<int> build2[100001];
int cnt[100001];
int cost[100001];
int d[100001];


int main()
{
    cin >> n;

    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        while (true)
        {
            cin >> temp;
            if (temp == -1)
                break;
            else
            {
                build1[i].push_back(temp);
                build2[temp].push_back(i);
                cnt[i]++;
            }
        }
        
        if ((int)build1[i].size() == 0)
        {
            que.push(i);
            d[i] = cost[i];
        }
    }

    while (!que.empty())
    {
        int now = que.front();
        que.pop();

        if (d[now] == 0)
        {
            for (int i = 0; i < (int)build1[now].size(); i++)
            {
                d[now] = max(d[now], d[build1[now][i]] + cost[now]);
            }
        }
            

        for (int i = 0; i < (int)build2[now].size(); i++)
        {
            cnt[build2[now][i]]--;
            if (cnt[build2[now][i]] == 0)
                que.push(build2[now][i]);
        }
        

    }
    
    for (int i = 1; i <= n; i++)
        cout << d[i] << '\n';

    return 0;

}