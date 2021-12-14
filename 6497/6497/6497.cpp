#include <iostream>
#include <queue>

using namespace std;

int m, n;

struct road {
    int a;
    int b;
    int cost;

    road(int a, int b, int cost) : a(a), b(b), cost(cost) {};

    bool operator<(const road& r)const {
        return cost > r.cost;
    }
};

priority_queue<road> pq;
int uf[200001];
int sum_all = 0;
int sum_on = 0;
int cnt;

int find_uf(int node) {
    if (uf[node] == node)
        return node;

    return uf[node] = find_uf(uf[node]);
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int temp1, temp2, temp3;

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        cnt = m - 1;
        sum_all = 0;
        sum_on = 0;

        while (!pq.empty())
            pq.pop();

        for (int i = 0; i < n; i++) {
            cin >> temp1 >> temp2 >> temp3;
            pq.push(road(temp1, temp2, temp3));
            sum_all += temp3;
        }

        for (int i = 0; i < m; i++) {
            uf[i] = i;
        }

        while (!pq.empty()) {
            road now = pq.top();
            pq.pop();

            if (find_uf(now.a) == find_uf(now.b))
                continue;

            sum_on += now.cost;
            uf[find_uf(now.a)] = find_uf(now.b);

            if (--cnt == 0)
                break;
        }

        cout << sum_all - sum_on << '\n';
    }
    

    return 0;
    
}