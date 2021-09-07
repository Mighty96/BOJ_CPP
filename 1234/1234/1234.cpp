#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;

int n, r, g, b;

ll tree[11][101][101][101];

int combination(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int main()
{
    cin >> n >> r >> g >> b;

    memset(tree, 0, sizeof(ll) * 11 * 101 * 101 * 101);

    tree[0][r][g][b] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            for (int k = 0; k <= g; k++)
            {
                for (int l = 0; l <= b; l++)
                {
                    if (j - i >= 0)
                    {
                        tree[i][j - i][k][l] += tree[i - 1][j][k][l];
                    }
                    if (k - i >= 0)
                    {
                        tree[i][j][k - i][l] += tree[i - 1][j][k][l];
                    }
                    if (l - i >= 0)
                    {
                        tree[i][j][k][l - i] += tree[i - 1][j][k][l];
                    }
                }
            }
        }

        if (i % 2 == 0)
        {
            for (int j = 0; j <= r; j++)
            {
                for (int k = 0; k <= g; k++)
                {
                    for (int l = 0; l <= b; l++)
                    {
                        if (j - (i / 2) >= 0 && k - (i / 2) >= 0)
                        {
                            tree[i][j - (i / 2)][k - (i / 2)][l] += tree[i - 1][j][k][l] * combination(i, i / 2);
                        }
                        if (k - (i / 2) >= 0 && l - (i / 2) >= 0)
                        {
                            tree[i][j][k - (i / 2)][l - (i / 2)] += tree[i - 1][j][k][l] * combination(i, i / 2);
                        }
                        if (l - (i / 2) >= 0 && j - (i / 2) >= 0)
                        {
                            tree[i][j - (i / 2)][k][l - (i / 2)] += tree[i - 1][j][k][l] * combination(i, i / 2);
                        }
                    }
                }
            }
        }

        if (i % 3 == 0)
        {
            for (int j = 0; j <= r; j++)
            {
                for (int k = 0; k <= g; k++)
                {
                    for (int l = 0; l <= b; l++)
                    {
                        if (j - (i / 3) >= 0 && k - (i / 3) >= 0 && l - (i / 3) >= 0)
                        {
                            tree[i][j - (i / 3)][k - (i / 3)][l - (i / 3)] += tree[i - 1][j][k][l] * combination(i, i / 3) * combination(i * 2 / 3, i / 3);
                        }
                    }
                }
            }
        }
    }

    ll result = 0;

    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            for (int k = 0; k <= b; k++)
            {
                result += tree[n][i][j][k];
            }
        }
    }

    cout << result << '\n';

    return 0;


}