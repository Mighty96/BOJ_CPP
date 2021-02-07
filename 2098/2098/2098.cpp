#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[17][17];
int cache[17][70000];
int n;
int IMP = 100000000;
int tsp(int current, int visited)
{
    if (visited == (1 << n) - 1)
        return arr[current][1] ? arr[current][1] : IMP;
    if (cache[current][visited] != -1)
        return cache[current][visited];

    int ret = IMP;
    for (int i = 1; i <= n; i++)
    {
        if (visited & (1 << (i - 1))) continue;
        if (arr[current][i] == 0) continue;
        ret = min(ret, tsp(i, visited + (1 << (i - 1))) + arr[current][i]);
    }
    cache[current][visited] = ret;
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    memset(cache, -1, sizeof(cache));
    cout << tsp(1, 1) << '\n';
    return 0;
}