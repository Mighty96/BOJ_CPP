#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;

struct mv {
    int start;
    int end;
    int cost;
};

int T;

int n, m, w;

int vp[501];

vector<string> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    int s, e, t;
    for (int _ = 1; _ <= T; _++)
    {
        cin >> n >> m >> w;
        vector<mv> vec;
        for (int i = 1; i <= m; i++)
        {
            cin >> s >> e >> t;
            mv temp;
            temp.start = s;
            temp.end = e;
            temp.cost = t;
            vec.push_back(temp);
            temp.start = e;
            temp.end = s;
            vec.push_back(temp);
        }
        for (int i = 1; i <= w; i++)
        {
            cin >> s >> e >> t;
            mv temp;
            temp.start = s;
            temp.end = e;
            temp.cost = -t;
            vec.push_back(temp);
        }
        for (int i = 1; i <= n; i++)
            vp[i] = INF;
        bool flag = false;
        for (int k = 1; k <= n; k++)
        {
            if (vp[k] < INF) continue;

            vp[k] = 0;
            for (int i = 1; i <= n - 1; i++)
            {
                for (int j = 0; j < (int)vec.size(); j++)
                {
                    if (vp[vec[j].start] < INF)
                    {
                        if (vp[vec[j].end] > vp[vec[j].start] + vec[j].cost)
                        {
                            vp[vec[j].end] = vp[vec[j].start] + vec[j].cost;
                        }
                    }
                }
            }

            for (int i = 0; i < (int)vec.size(); i++)
            {
                if (vp[vec[i].start] < INF)
                {
                    if (vp[vec[i].end] > vp[vec[i].start] + vec[i].cost)
                    {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag)
                break;
        }


        if (flag)
            answer.push_back("YES");
        else
            answer.push_back("NO");
        

    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}