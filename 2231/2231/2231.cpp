#include <iostream>

using namespace std;

int n;
int sum;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        sum = i;
        while(num > 0)
        {
            sum += (num % 10);
            num /= 10;
        }
        if (sum == n)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';

    return 0;
}