#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int cost[10001];
int uf[10001];

int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return uf[num] = find(uf[num]);
}

void merge(int num1, int num2)
{
    num1 = find(num1);
    num2 = find(num2);

    uf[num2] = num1;
    cost[num1] = min(cost[num1], cost[num2]);
}
int main()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++)
    {
        uf[i] = i;
        cin >> cost[i];
    }

    int temp1, temp2;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;

        if (find(temp1) != find(temp2))
        {
            merge(temp1, temp2);
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (uf[i] == i)
            res += cost[i];
    }
    if (res > k)
        cout << "Oh no" << '\n';
    else
        cout << res << '\n';

    return 0;

    
}