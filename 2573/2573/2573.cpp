#include <iostream>
#include <vector>

using namespace std;
int field[300][300];
bool visited[300][300];
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };
bool flag1 = false;
bool flag2 = false;
int cnt = 0;

void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        if (field[y + d_y[i]][x + d_x[i]] > 0 && !visited[y + d_y[i]][x + d_x[i]])
        {
            dfs(y + d_y[i], x + d_x[i]);
        }
    }
    return;
}


int main()
{
    int n, m;

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }

    while (true)
    {
        ++cnt;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = false;
        
        flag1 = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (field[i][j] > 0)
                {
                    flag1 = true;
                    visited[i][j] = true;
                    for (int k = 0; k < 4; k++)
                        if (field[i + d_y[k]][j + d_x[k]] == 0 && !visited[i + d_y[k]][j + d_x[k]])
                            --field[i][j];
                    if (field[i][j] < 0)
                        field[i][j] = 0;
                }
        if (!flag1)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = false;
        
        flag2 = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (field[i][j] > 0 && !visited[i][j])
                {
                    if (flag2)
                    {
                        cout << cnt << '\n';
                        return 0;
                    }
                    dfs(i, j);
                    flag2 = true;
                }
    }

    cout << 0 << '\n';
    return 0;
}