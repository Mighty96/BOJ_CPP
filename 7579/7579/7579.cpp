#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

int d[101][10001];
int n, m;

int memory[101];
int cost[101];
int result = 100000;
int dp(int num, int c)
{
    if (num == 0)
        return 0;
    if (cost[num] == 0)
    {
        d[num][c] = dp(num - 1, c) + memory[num];
    }
    else if (d[num][c] != 0)
        return d[num][c];
    else if (cost[num] > c)
    {
        d[num][c] = dp(num - 1, c);
    }
    else if (dp(num - 1, c - cost[num]) + memory[num] > dp(num - 1, c))
    {
        d[num][c] = dp(num - 1, c - cost[num]) + memory[num];
    }
    else
    {
        d[num][c] = dp(num - 1, c);
    }
    if (d[num][c] >= m)
        result = min(result, c);
    return d[num][c];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> memory[i];

    int costSum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        costSum += cost[i];
    }
    for (int i = 0 ; i <= costSum ; i++)
        dp(n, i);
    cout << result << '\n';

    return 0;
}