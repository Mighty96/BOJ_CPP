#include <iostream>
#include <vector>

using namespace std;
int n;
int result = 0;

void dfs(vector<vector<int>> field, int cnt, int c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result = (result > field[i][j]) ? result : field[i][j];
        }
    }

    if (cnt == 5)
        return;

    switch (c)
    {
    case 0:
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (field[j][i] != 0)
                    for (int k = 0; k <= j; k++)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (field[j][i] == field[j + 1][i] != 0)
                {
                    field[j][i] = 0;
                    for (int k = 0; k <= j; k++)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j + 1][i] * 2;
                            break;
                        }
                    field[j + 1][i] = 0;
                }
                else
                {
                    for (int k = 0; k <= j; k++)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
                }
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (field[j][i] != 0)
                    for (int k = 0; k <= j; k++)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
        break;
    case 1:
        for (int i = 0; i < n; i++)
            for (int j = n - 2; j >= 0; j--)
                if (field[j][i] != 0)
                    for (int k = n - 1; k >= j; k--)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (field[j][i] == field[j - 1][i] != 0)
                {
                    field[j][i] = 0;
                    for (int k = n - 1; k >= j; k--)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j - 1][i] * 2;
                            break;
                        }
                    field[j - 1][i] = 0;
                }
                else
                {
                    for (int k = n - 1; k >= j; k--)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
                }
        for (int i = 0; i < n; i++)
            for (int j = n - 2; j >= 0; j--)
                if (field[j][i] != 0)
                    for (int k = n - 1; k >= j; k--)
                        if (field[k][i] == 0)
                        {
                            field[k][i] = field[j][i];
                            field[j][i] = 0;
                            break;
                        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (field[i][j] != 0)
                    for (int k = 0; k <= j; k++)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (field[i][j] == field[i][j + 1] != 0)
                {
                    field[i][j] = 0;
                    for (int k = 0; k <= j; k++)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j + 1] * 2;
                            break;
                        }
                    field[i][j + 1] = 0;
                }
                else
                {
                    for (int k = 0; k <= j; k++)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
                }
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (field[i][j] != 0)
                    for (int k = 0; k <= j; k++)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
        break;
    case 3:
        for (int i = 0; i < n; i++)
            for (int j = n - 2; j >= 0; j--)
                if (field[i][j] != 0)
                    for (int k = n - 1; k >= j; k--)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (field[i][j] == field[i][j - 1] != 0)
                {
                    field[i][j] = 0;
                    for (int k = n - 1; k >= j; k--)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j - 1] * 2;
                            break;
                        }
                    field[i][j - 1] = 0;
                }
                else
                {
                    for (int k = n - 1; k >= j; k--)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
                }
        for (int i = 0; i < n; i++)
            for (int j = n - 2; j >= 0; j--)
                if (field[i][j] != 0)
                    for (int k = n - 1; k >= j; k--)
                        if (field[i][k] == 0)
                        {
                            field[i][k] = field[i][j];
                            field[i][j] = 0;
                            break;
                        }
        break;
    }
    for (int i = 0; i < 4; i++)
    {
        dfs(field, cnt + 1, i);
    }
}

int main()
{
    cin >> n;

    vector<vector<int>> field(n);

    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            field[i].push_back(temp);
        }

    for (int i = 0; i < 4; i++)  // »óÇÏÁÂ¿ì
    {
        dfs(field, 0, i);
    }

    cout << result << '\n';
    return 0;
}