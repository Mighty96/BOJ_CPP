#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;
int n;
int d[501][501];
vector<int> res;

int dp(int a, int b)
{
    if (a == b) return 0;
    if (d[a][b] != -1)
        return d[a][b];
    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += d[i][i];
    }
    d[a][b] = 987654321;
    for (int i = a; i < b; i++)
    {    
        d[a][b] = min(d[a][b], dp(a, i) + dp(i + 1, b) + sum);
    }
    return d[a][b];
}


int main()
{
    int tc;
    cin >> tc;

    for (int _ = 1; _ <= tc; _++)
    {
        cin >> n;
        for (int i = 0 ; i < 501 ; i++)
            memset(d[i], -1, sizeof(int) * 501);
        for (int i = 1; i <= n; i++)
            cin >> d[i][i];

        res.push_back(dp(1, n));
    }

    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}