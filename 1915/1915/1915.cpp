#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n, m;

int maxSize[1001][1001];

int dp(int a, int b)
{
    if (maxSize[a][b] == 0)
        return 0;

    if (a == 1 || b == 1)
        return maxSize[a][b];

    if (maxSize[a - 1][b - 1] == 0)
        return maxSize[a][b];

    int temp = maxSize[a - 1][b - 1];

    int x = temp, y = temp;
    for (int i = 1; i <= temp; i++)
    {
        if (maxSize[a - i][b] == 0)
            y = i - 1;
    }
    for (int i = 1; i <= temp; i++)
    {
        if (maxSize[a][b - i] == 0)
            x = i - 1;
    }
    
    return min(x, y) + 1;

}


int main()
{
    cin >> n >> m;

    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int j = 1; j <= m; j++)
        {
            
            maxSize[i][j] = temp[j - 1] - 48;
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maxSize[i][j] = dp(i, j);
            result = max(result, dp(i, j));
        }
    }
    cout << result * result << '\n';

    return 0;
    
}