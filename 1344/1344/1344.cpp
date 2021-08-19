#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int n, m;
double dp_a[19][19];
double dp_b[19][19];

int main()
{
    cin >> n >> m;
    
    dp_a[0][0] = 1;
    dp_a[0][1] = 0;
    dp_b[0][0] = 1;
    dp_b[0][1] = 0;

    for (int i = 1; i <= 18; i++)
    {
        dp_a[i][0] = dp_a[i - 1][0] * (100 - n) / 100;
        dp_b[i][0] = dp_b[i - 1][0] * (100 - m) / 100;
        for (int j = 1; j <= i; j++)
        {
            dp_a[i][j] = dp_a[i - 1][j] * (100 - n) / 100 + dp_a[i - 1][j - 1] * n / 100;
            dp_b[i][j] = dp_b[i - 1][j] * (100 - m) / 100 + dp_b[i - 1][j - 1] * m / 100;
        }
    }

    int prime_number[] = { 2, 3, 5, 7, 11, 13, 17 };

    double result = 1.0;

    for (int i = 0; i <= 18; i++)
    {
        if (find(begin(prime_number), end(prime_number), i) != end(prime_number))
        {
            continue;
        }
        for (int j = 0; j <= 18; j++)
        {
            if (find(begin(prime_number), end(prime_number), j) != end(prime_number))
            {
                continue;
            }
            result = result - (dp_a[18][i] * dp_b[18][j]);
        }
    }
    cout << result << '\n';

    return 0;
}