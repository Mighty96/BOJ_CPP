#include <iostream>

using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;

    long long sub = y - x;
    
    if (sub == 0)
    {
        cout << "0\n";
        return 0;
    }

    long long num = 0;
    while (sub > 0)
    {
        num += 2;
        sub -= num;
    }

    if (sub + (num / 2) > 0)
        cout << num << '\n';
    else
        cout << num - 1 << '\n';


    return 0;
}