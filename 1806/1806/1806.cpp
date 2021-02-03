#include <iostream>
#include <algorithm>
using namespace std;

int number[100001];
int tree[400001];

int main()
{
    int n, s;

    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }

    int start = 1;
    int end = 1;
    int sum = number[1];
    int result = 100001;
    while (end <= n)
    {
        while (sum >= s && start <= end)
        {
            result = min(result, end - start + 1);
            if (result == 1) break;
            sum -= number[start];
            start++;
        }
        
        end++;
        sum += number[end];
    }

    if (result == 100001)
    {
        cout << 0 << '\n';
        return 0;
    }

    cout << result << '\n';
    return 0;
}