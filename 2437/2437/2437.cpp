#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long sum = 0;
    long long input[1000];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input, input + n);

    for (int i = 0; i < n; i++)
    {
        if (input[i] == 1)
        {
            sum += 1;
            continue;
        }
        if (sum < (input[i] - 1))
        {
            cout << sum + 1 << '\n';
            return 0;
        }
        else
            sum += input[i];
    }
    cout << sum + 1 << '\n';

    return 0;
}