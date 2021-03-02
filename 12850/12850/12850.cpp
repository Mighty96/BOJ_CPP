#include <iostream>
#include <string.h>

using namespace std;

long long time;
long long graph[31][9][9];

int main()
{
    cin >> time;
    graph[0][1][2] = 1;
    graph[0][1][3] = 1;
    graph[0][2][1] = 1;
    graph[0][2][3] = 1;
    graph[0][2][4] = 1;
    graph[0][3][1] = 1;
    graph[0][3][2] = 1;
    graph[0][3][4] = 1;
    graph[0][3][5] = 1;
    graph[0][4][2] = 1;
    graph[0][4][3] = 1;
    graph[0][4][5] = 1;
    graph[0][4][6] = 1;
    graph[0][5][3] = 1;
    graph[0][5][4] = 1;
    graph[0][5][6] = 1;
    graph[0][5][7] = 1;
    graph[0][6][4] = 1;
    graph[0][6][5] = 1;
    graph[0][6][8] = 1;
    graph[0][7][5] = 1;
    graph[0][7][8] = 1;
    graph[0][8][6] = 1;
    graph[0][8][7] = 1;

    long long temp = 0;

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 8; j++)
            for (int k = 1; k <= 8; k++)
            {
                temp = 0;
                for (int l = 1; l <= 8; l++)
                {
                    temp += graph[i - 1][j][l] * graph[i - 1][l][k];
                    temp %= 1000000007;
                }
                graph[i][j][k] = temp;
            }
    }

    long long temp_arr[9][9];
    long long res[9][9];

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
            res[i][j] = 0;
        res[i][i] = 1;
    }
    for (int i = 0; i <= 30; i++)
    {
        if ((time & ((long long)1 << i)) > 0)
        {
            for (int j = 1; j <= 8; j++)
                for (int k = 1; k <= 8; k++)
                {
                    temp = 0;
                    for (int l = 1; l <= 8; l++)
                    {
                        temp += res[j][l] * graph[i][l][k];
                        temp %= 1000000007;
                    }
                    temp_arr[j][k] = temp;
                }
            for (int j = 1; j <= 8; j++)
                for (int k = 1; k <= 8; k++)
                    res[j][k] = temp_arr[j][k];
        }
    }
    cout << res[1][1] << '\n';


    return 0;
}