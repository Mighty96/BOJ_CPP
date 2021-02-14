#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long num, now;
long long res = 1;

void gcd()
{
    bool flag = false;
    while (now <= sqrt(num))
    {
        if (num % now == 0)
        {
            flag = true;
            break;
        }
        now++;
    }

    if (flag)
    {
        int count = 0;
        while (num % now == 0)
        {
            num /= now;
            count++;
        }
        res *= (pow(now, count) - pow(now, count - 1));
        now++;
    }
}

int main()
{
    cin >> num;
    now = 2;
    while (now <= sqrt(num))
    {
        gcd();
    }
    if (num != 1)
    {
        res *= (num - 1);
    }
    cout << res << '\n';

    return 0;
}