#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct mv {
    int goal;
    int cost;
    bool must;
};

struct road {
    int goal;
    int cost;
};

struct compare {
    bool operator()(mv a, mv b)
    {
        if (a.cost == b.cost)
        {
            if (b.must)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return a.cost > b.cost;
    }
};


int T;
int n, m, t;
int s, g, h;
bool maybe_goal[2001];
int value[2001];
bool visited[2001];
vector<int> result[101];
bool temp_result[2001];

priority_queue<mv, vector<mv>, compare> que;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> T;

    int temp1, temp2, temp3;
    for (int _ = 1; _ <= T; _++)
    {
        vector<road> rd[2001];
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= n; i++)
        {
            maybe_goal[i] = false;
            value[i] = INF;
            visited[i] = false;
            temp_result[i] = false;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> temp1 >> temp2 >> temp3;
            road r;
            r.goal = temp2;
            r.cost = temp3;
            rd[temp1].push_back(r);
            r.goal = temp1;
            rd[temp2].push_back(r);
        }
        
        for (int i = 0; i < t; i++)
        {
            cin >> temp1;
            maybe_goal[temp1] = true;
        }

        
        value[s] = 0;
        mv m;
        m.cost = 0;
        m.goal = s;
        m.must = false;
        que.push(m);

        while (!que.empty())
        {
            mv now = que.top();
            que.pop();

            if (visited[now.goal])
            {
                continue;
            }

            if (maybe_goal[now.goal] && now.must)
            {
                temp_result[now.goal] = true;
            }

            visited[now.goal] = true;


            for (int i = 0; i < (int)rd[now.goal].size(); i++)
            {
                if (value[now.goal] + rd[now.goal][i].cost <= value[rd[now.goal][i].goal])
                {
                    value[rd[now.goal][i].goal] = value[now.goal] + rd[now.goal][i].cost;
                    mv m;
                    m.cost = value[rd[now.goal][i].goal];
                    m.goal = rd[now.goal][i].goal;
                    m.must = now.must;
                    if ((now.goal == g && rd[now.goal][i].goal == h) ||
                        (now.goal == h && rd[now.goal][i].goal == g))
                    {
                        m.must = true;
                    }
                    que.push(m);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (temp_result[i])
            {
                result[_].push_back(i);
            }
        }
    }

    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j < (int)result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;


}