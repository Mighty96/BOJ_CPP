#include <iostream>
#include <string.h>

using namespace std;

int time;
int graph[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 0}
};

long long d[9][100001];

int main()
{
    cin >> time;

    d[1][0] = 1;

    for (int i = 1; i <= time; i++)
        for (int j = 1; j <= 8; j++)
        {
            for (int k = 1; k <= 8; k++)
                if (graph[j][k] == 1)
                    d[j][i] += d[k][i - 1];
            d[j][i] %= 1000000007;
        }

    cout << d[1][time] << '\n';

    return 0;
}