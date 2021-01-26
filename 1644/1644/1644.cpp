#include <iostream>
#include <vector>

using namespace std;
int prime_judge[4000001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> prime_number;

    int n;
    cin >> n;
    
    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    else if (n == 2 || n == 3)
    {
        cout << 1 << '\n';
        return 0;
    }
    

    for (int i = 1; i <= 4000000; i++)
    {
        prime_judge[i] = true;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (prime_judge[i])
        {
            for (int j = 2; j <= n / i; j++)
            {
                prime_judge[i * j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        if (prime_judge[i])
            prime_number.push_back(i);

    int front = 0;
    int end = 0;
    int sum = 0;
    int result = 0;

    while (front < (int)prime_number.size())
    {
        sum += prime_number[end];
        if (sum == n)
        {
            result++;
            front++;
            end = front;
            sum = 0;
        }
        else if (sum > n)
        {
            front++;
            end = front;
            sum = 0;
        }
        else if (sum < n)
        {
            end++;
            if (end == (int)prime_number.size())
            {
                break;
            }
        }
    }

    cout << result << '\n';
    return 0;
}