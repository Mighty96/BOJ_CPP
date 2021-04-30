#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  n, m;
int field[701][701];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            field[i][j] = 1;
        }
    }

    

    int num1, num2, num3;
    for (int i = 0; i < n; i++)
    {
        int new_x = 0;
        int new_y = m - 1;
        cin >> num1 >> num2 >> num3;

        for (int j = 0 ; j < num1 ; j++)
        {
            if (new_y != 0)
            {
                new_y--;
            }
            else
            {
                new_x++;
            }
        }
        for (int j = 0 ; j < num2 ; j++)
        {
            field[new_y][new_x] += 1;
            if (new_y != 0)
            {
                new_y--;
            }
            else
            {
                new_x++;
            }
        }
        for (int j = 0 ; j < num3 ; j++)
        {
            field[new_y][new_x] += 2;
            if (new_y != 0)
            {
                new_y--;
            }
            else
            {
                new_x++;
            }
        }
    }


    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            field[i][j] = field[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << '\n';
    }
}