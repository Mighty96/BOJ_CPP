#include <iostream>

using namespace std;

int d[1000001];
int past[1000001];

int dp(int num)
{
    if (num == 1)
        return 0;
    if (d[num] != 0)
        return d[num];

    d[num] = dp(num - 1) + 1;
    past[num] = num - 1;

    if (num % 3 == 0 && (dp(num / 3) + 1 < d[num]))
    {
        d[num] = dp(num / 3) + 1;
        past[num] = num / 3;
    }
    if (num % 2 == 0 && (dp(num / 2) + 1 < d[num]))
    {
        d[num] = dp(num / 2) + 1;
        past[num] = num / 2;
    }

    return d[num];
}


int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        dp(i);
    }
    cout << dp(n) << '\n';

    int idx = n;
    while (idx >= 1)
    {
        cout << idx << " ";
        idx = past[idx];
    }

    cout << '\n';
    return 0;
}