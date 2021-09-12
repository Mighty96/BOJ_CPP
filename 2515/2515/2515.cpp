#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct picture {
    int height;
    int cost;
};

struct compare {
    bool operator()(picture a, picture b) {
        if (a.height == b.height)
            return a.cost < b.cost;
        return a.height > b.height;
    }
};

int n, s;

priority_queue<picture, vector<picture>, compare> pq;
int h[20000001];

int main()
{
    cin >> n >> s;

    int temp1, temp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1 >> temp2;
        picture temp;
        temp.height = temp1;
        temp.cost = temp2;
        pq.push(temp);
    }

    memset(h, 0, sizeof(int) * 20000001);

    int prev;

    prev = 0;

    int res = 0;
    while (!pq.empty())
    {
        picture now = pq.top();
        pq.pop();
        for (int i = prev; i < now.height; i++)
        {
            h[i] = h[prev];
        }

        h[now.height] = max(max(h[now.height - s] + now.cost, h[now.height - 1]), h[now.height]);
        res = max(res, h[now.height]);

        prev = now.height;
    }
    cout << res << '\n';

}