#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool prime_generate[1000001];


void prime_number_generate(int num, vector<int>& prime)
{
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (!prime_generate[i])
            continue;

        prime.push_back(i);
        for (int j = i; j <= num;)
        {
            prime_generate[j] = false;
            j += i;
        }
    }
    for (int i = (int)sqrt(num) + 1; i <= num;i++)
    {
        if (prime_generate[i])
            prime.push_back(i);
    }
}

int main()
{
    fill(&prime_generate[0], &prime_generate[1000000], true);
    vector<int> prime;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int num;

    cin >> num;

    prime_number_generate(num, prime);

    if (num > 0 && num < 8)
    {
        cout << "-1\n";
        return 0;
    }

    if (num % 2 == 0)
    {
        num -= 4;
        for (int i = 0; i < (int)prime.size(); i++)
            for (int j = i; j < (int)prime.size(); j++)
                if (prime[i] + prime[j] == num)
                {
                    cout << "2 2 " << prime[i] << " " << prime[j] << '\n';
                    return 0;
                }
    }
    else
    {
        num -= 5;
        for (int i = 0; i < (int)prime.size(); i++)
            for (int j = i; j < (int)prime.size(); j++)
                if (prime[i] + prime[j] == num)
                {
                    cout << "2 3 " << prime[i] << " " << prime[j] << '\n';
                    return 0;
                }
    }

    cout << "-1\n";
    return 0;
}