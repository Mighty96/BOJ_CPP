#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

string tofu[14];
long long dp[14 * 14][1 << 14];
int price[100][100];


int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> tofu[i];
    price['A']['A'] = 10;
    price['A']['B'] = 8;
    price['A']['C'] = 7;
    price['A']['D'] = 5;
    price['A']['F'] = 1;
    price['B']['A'] = 8;
    price['B']['B'] = 6;
    price['B']['C'] = 4;
    price['B']['D'] = 3;
    price['B']['F'] = 1;
    price['C']['A'] = 7;
    price['C']['B'] = 4;
    price['C']['C'] = 3;
    price['C']['D'] = 2;
    price['C']['F'] = 1;
    price['D']['A'] = 5;
    price['D']['B'] = 3;
    price['D']['C'] = 2;
    price['D']['D'] = 2;
    price['D']['F'] = 1;
    price['F']['A'] = 1;
    price['F']['B'] = 1;
    price['F']['C'] = 1;
    price['F']['D'] = 1;
    price['F']['F'] = 0;

    long long max_num = 0;

    //층수
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            for (int k = 0; k < m - 1; k++)
            {
                if (j & (1 << k)) continue;

                //가로
                if (!(j & (1 << (k + 1))))
                {
                    dp[i][j | (1 << k) | (1 << (k + 1))] =
                        max(dp[i][j | (1 << k) | (1 << (k + 1))], dp[i][j] + price[tofu[i][k]][tofu[i][k + 1]]);
                    max_num = max(max_num, dp[i][j | (1 << k) | (1 << (k + 1))]);
                }

                //세로
                if (i < n - 1)
                {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + price[tofu[i][k]][tofu[i + 1][k]]);
                    max_num = max(max_num, dp[i + 1][j]);
                }
            }
        }
    }

    
}