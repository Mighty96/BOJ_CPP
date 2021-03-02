#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int command[100001];
int n = 1;
int d[5][5][100001];

int cal(int pos, int now)
{
    if (now == 1)
    {
        if (pos == 1)
            return 1;
        else if (pos == 2 || pos == 4)
            return 3;
        else if (pos == 0)
            return 2;
        else if (pos == 3)
            return 4;
    }
    else if (now == 2)
    {
        if (pos == 1 || pos == 3)
            return 3;
        else if (pos == 0)
            return 2;
        else if (pos == 2)
            return 1;
        else if (pos == 4)
            return 4;
    }
    else if (now == 3)
    {
        if (pos == 2 || pos == 4)
            return 3;
        else if (pos == 0)
            return 2;
        else if (pos == 3)
            return 1;
        else if (pos == 1)
            return 4;
    }
    else
    {
        if (pos == 1 || pos == 3)
            return 3;
        else if (pos == 0)
            return 2;
        else if (pos == 4)
            return 1;
        else
            return 4;
    }

    return 0;
}

int dp(int left, int right, int num)
{
    if (num == 0)
    {
        if (left == 0 && right == 0)
            return 0;
        else
            return 100000000;
    }
    if (d[left][right][num] != -1)
        return d[left][right][num];

    if (command[num] == command[num - 1])
        return d[left][right][num] = dp(left, right, num - 1) + 1;
    
    d[left][right][num] = 100000000;

    if (command[num] != left && command[num] != right)
        return d[left][right][num];

    if (command[num] == left)
    {
        for (int i = 0; i <= 4; i++)
            d[left][right][num] = min(d[left][right][num], dp(i, right, num - 1) + cal(i, left));
    }
    else if (command[num] == right)
    {
        for (int i = 0; i <= 4; i++)
            d[left][right][num] = min(d[left][right][num], dp(left, i, num - 1) + cal(i, right));
    }


    return d[left][right][num];

}

int main()
{
    while (true)
    {
        cin >> command[n];
        if (command[n] == 0)
            break;
        n++;
    }
    n--;
    
    memset(d, -1, sizeof(d));

    int res = 100000000;

    for (int i = 0; i <= 4; i++)
    {
        res = min(res, dp(i, command[n], n));
        res = min(res, dp(command[n], i, n));
    }

    cout << res << '\n';

    return 0;
}