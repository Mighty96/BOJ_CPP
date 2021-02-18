#include <iostream>
#include <string.h>

using namespace std;

int n;
long long d[101][21];
int input[101];

long long dp(int a, int b)
{
    if (d[a][b] != -1)
        return d[a][b];

    if (a == 1 && b == input[a])
        return d[a][b] = 1;

    d[a][b] = 0;
    if (b - input[a] >= 0)
        d[a][b] += dp(a - 1, b - input[a]);

    if (b + input[a] <= 20)
        d[a][b] += dp(a - 1, b + input[a]);

    return d[a][b];
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
        memset(d[i], -1, 21 * sizeof(long long));
    }

    cout << dp(n - 1, input[n]);
    
    
}