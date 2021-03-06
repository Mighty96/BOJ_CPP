#include <iostream>
#include <vector>
using namespace std;

int n;
int seg[4000004];
vector<int> res;

int find(int node, int front, int back, int start, int end)
{
    if (end < front || start > back)
        return 0;
    if (start <= front && end >= back)
        return seg[node];

    int mid = (front + back) / 2;

    return find(node * 2, front, mid, start, end) + find(node * 2 + 1, mid + 1, back, start, end);
}

void update(int node, int front, int back, int idx, int dif)
{
    if (idx < front || idx > back) return;
    seg[node] += dif;
    if (front == back) return;
    int mid = (front + back) / 2;
    update(node * 2, front, mid, idx, dif);
    update(node * 2 + 1, mid + 1, back, idx, dif);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int temp1, temp2, temp3;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp1;
        if (temp1 == 2)
        {
            cin >> temp2 >> temp3;
            update(1, 1, 1000000, temp2, temp3);
        }
        else
        {
            cin >> temp2;
            int node = 1;
            int sum = 0;
            int front = 1, back = 1000000;
            while (true)
            {
                if (front == back)
                {
                    res.push_back(front);
                    update(1, 1, 1000000, front, -1);
                    break;
                }
                if (sum + seg[node * 2] >= temp2)
                {
                    node = node * 2;
                    back = (front + back) / 2;
                }
                else
                {
                    sum += seg[node * 2];
                    node = node * 2 + 1;
                    front = (front + back) / 2 + 1;
                }
            }
        }
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}