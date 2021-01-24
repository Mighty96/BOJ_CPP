#include <iostream>

using namespace std;

int main()
{
    int field[101][101];
    int n, l;
    int now, before;
    bool flag;
    int result = 0;

    cin >> n >> l;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> field[i][j];

    for (int i = 0; i < n; i++)
    {
        now = 0;
        before = 0;

        //세로줄
        flag = true;
        while (now < n - 1)
        {
            if (field[now + 1][i] == field[now][i])
            {
                now += 1;
                continue;
            }
            if (field[now + 1][i] > field[now][i] + 1 ||
                field[now + 1][i] < field[now][i] - 1)
            {
                flag = false;
                break;
            }
            if (field[now + 1][i] == field[now][i] + 1)
            {
                if (now + 1 - before >= l)
                {
                    now += 1;
                    before = now;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (field[now + 1][i] == field[now][i] - 1)
            {
                if (now + l >= n)
                {
                    flag = false;
                    break;
                }
                for (int j = now + 1; j <= now + l; j++)
                {
                    if (field[j][i] != field[now + 1][i])
                    {
                        flag = false;
                        break;
                    }
                }
                now += l;
                before = now + 1;
                continue;
            }
        }
        if (flag)
        {
            result += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        now = 0;
        before = 0;

        //가로줄
        flag = true;
        while (now < n - 1)
        {
            if (field[i][now + 1] == field[i][now])
            {
                now += 1;
                continue;
            }
            if (field[i][now + 1] > field[i][now] + 1 ||
                field[i][now + 1] < field[i][now] - 1)
            {
                flag = false;
                break;
            }
            if (field[i][now + 1] == field[i][now] + 1)
            {
                if (now + 1 - before >= l)
                {
                    now += 1;
                    before = now;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (field[i][now + 1] == field[i][now] - 1)
            {
                if (now + l >= n)
                {
                    flag = false;
                    break;
                }
                for (int j = now + 1; j <= now + l; j++)
                {
                    if (field[i][j] != field[i][now + 1])
                    {
                        flag = false;
                        break;
                    }
                }
                now += l;
                before = now + 1;
                continue;
            }
        }
        if (flag)
        {
            result += 1;
        }
    }

    cout << result << '\n';
    return 0;
}