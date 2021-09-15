#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct customer {
    int uid;
    int time;
    int kid;
};

struct compare {
    bool operator()(customer a, customer b)
    {
        if (a.time == b.time)
            return a.kid < b.kid;
        return a.time > b.time;
    }
};

int n, k;
int cur_time = 0;

priority_queue<customer, vector<customer>, compare> pq;
priority_queue<int, vector<int>, greater<int>> kq;
vector<int> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
        kq.push(i);
    answer.push_back(0);

    int temp1, temp2;

    customer c;
    customer now;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1 >> temp2;

        if (kq.empty())
        {
            cur_time = pq.top().time;

            while (!pq.empty() && pq.top().time == cur_time)
            {
                now = pq.top();
                pq.pop();
                kq.push(now.kid);
                answer.push_back(now.uid);
            }
        }
        c.uid = temp1;
        c.time = cur_time + temp2;
        c.kid = kq.top();
        kq.pop();
        pq.push(c);
    }

    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        answer.push_back(now.uid);
    }

    long long res = 0;
    for (long long i = 1; i <= n; i++)
        res += i * answer[i];

    cout << res << '\n';
}