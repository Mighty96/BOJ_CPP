#include <iostream>

using namespace std;

const int INF = 987654321;

int route[201][201];
int result[201][201];
int n, m;

int main()
{
    cin >> n >> m;

    int temp1, temp2, temp3;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            route[i][j] = INF;
            result[i][j] = 0;
        }

        route[i][i] = 0;
    }


    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2 >> temp3;

        route[temp1][temp2] = temp3;
        route[temp2][temp1] = temp3;
        result[temp1][temp2] = temp2;
        result[temp2][temp1] = temp1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
            if (i == j) continue;
                if (route[i][j] > route[i][k] + route[k][j])
                {
                    result[i][j] = result[i][k];
                    route[i][j] = route[i][k] + route[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (result[i][j] == 0)
            {
                cout << "-" << " ";
            }
            else {
                cout << result[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}