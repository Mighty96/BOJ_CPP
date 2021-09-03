#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, l;
vector<int> fw[200001];
int back[200001];
int success[200001];

queue<int> que;
bool result[200001];;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int temp;

    for (int i = 1; i <= n; i++)
    {
        result[i] = false;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> back[i];

        for (int _ = 0; _ < back[i]; _++)
        {
            cin >> temp;
            fw[temp].push_back(i);

        }
        cin >> success[i];
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        cin >> temp;
        que.push(temp);
    }

    int res_cnt = 0;

    while (!que.empty())
    {
        
        int now = que.front();
        que.pop();
        
        if (result[now])
        {
            continue;
        }
        
        for (int i = 0; i < (int)fw[now].size(); i++)
        {
            back[fw[now][i]]--;
            if (back[fw[now][i]] == 0)
            {
                que.push(success[fw[now][i]]);
            }
        }

        result[now] = true;
        res_cnt++;
    }

    cout << res_cnt << '\n';

    for (int i = 1; i <= n; i++)
    {
        if (result[i])
        {
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;


}