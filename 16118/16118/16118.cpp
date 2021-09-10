#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
typedef long long ll;
const int INF = 987654321;

struct way {
    int goal;
    ll cost;
};

struct wolf_way {
    int goal;
    ll cost;
    int speed;
};

struct compare1 {
    bool operator()(way a, way b) {
        return a.cost > b.cost;
    }
};

struct compare2 {
    bool operator()(wolf_way a, wolf_way b) {
        return a.cost > b.cost;
    }
};


ll wolf[4001][2];
ll fox[4001];
bool vis[4001];
int n, m;

priority_queue<way, vector<way>, compare1> que;
priority_queue<wolf_way, vector<wolf_way>, compare2> que2;

vector<way> road[4001];

int main()
{
    cin >> n >> m;

    int temp1, temp2;
    ll temp3;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;

        road[temp1].push_back({ temp2, temp3 * 2 });
        road[temp2].push_back({ temp1, temp3 * 2 });
    }

    for (int i = 1; i <= n; i++)
    {
        fox[i] = INF;
        wolf[i][0] = INF;
        wolf[i][1] = INF;
    }
    fox[1] = 0;

    //fox
    memset(vis, 0, sizeof(bool) * 4001);

    que.push({ 1, 0 });

    while (!que.empty())
    {
        way now = que.top();
        que.pop();
        if (vis[now.goal])
        {
            continue;
        }

        vis[now.goal] = true;

        for (int i = 0; i < (int)road[now.goal].size(); i++)
        {
            if (road[now.goal][i].cost + now.cost < fox[road[now.goal][i].goal])
            {
                fox[road[now.goal][i].goal] = road[now.goal][i].cost + now.cost;
                que.push({ road[now.goal][i].goal, fox[road[now.goal][i].goal] });
            }
        }
    }

    //wolf

    que2.push({ 1, 0, 0 });
    while (!que2.empty())
    {
        wolf_way now = que2.top();
        que2.pop();

        if (now.cost > wolf[now.goal][now.speed])
        {
            continue;
        }

        for (int i = 0; i < (int)road[now.goal].size(); i++)
        {
            if (now.speed == 0)
            {
                if (road[now.goal][i].cost / 2 + now.cost < wolf[road[now.goal][i].goal][1])
                {
                    wolf[road[now.goal][i].goal][1] = road[now.goal][i].cost / 2 + now.cost;
                    que2.push({ road[now.goal][i].goal, wolf[road[now.goal][i].goal][1], 1 });
                }
            }
            else
            {
                if (road[now.goal][i].cost * 2 + now.cost < wolf[road[now.goal][i].goal][0])
                {
                    wolf[road[now.goal][i].goal][0] = road[now.goal][i].cost * 2 + now.cost;
                    que2.push({ road[now.goal][i].goal, wolf[road[now.goal][i].goal][0], 0 });
                }
            }
        }
    }

    int result = 0;

    for (int i = 2; i <= n; i++)
    {
        if (fox[i] < wolf[i][0] && fox[i] < wolf[i][1])
        {
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}