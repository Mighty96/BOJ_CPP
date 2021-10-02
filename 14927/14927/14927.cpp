#include <iostream>
#include <vector>

using namespace std;
const int INF = 987;
int n;
int answer = INF;

void touch(int y, int x, vector<vector<int>> &field)
{
    if (y > 0)
        field[y - 1][x] ^= 1;
    if (x > 0)
        field[y][x - 1] ^= 1;
    if (y + 1 < n)
        field[y + 1][x] ^= 1;
    if (x + 1 < n)
        field[y][x + 1] ^= 1;
    field[y][x] ^= 1;
}

void after_line(int cnt, vector<vector<int>> field)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i - 1][j] == 1)
            {
                cnt++;
                touch(i, j, field);
            }
            if (cnt >= answer)
                return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (field[n - 1][i])
            return;
    }
    answer = cnt;
}

void first_line(int x, int cnt, vector<vector<int>> field)
{
    cnt++;
    touch(0, x, field);

    after_line(cnt, field);

    for (int i = x + 1; i < n; i++)
        first_line(i, cnt, field);

    return;
}


int main()
{
    cin >> n;
    vector<vector<int>> field;

    int temp;
    for (int i = 0; i < n; i++)
    {
        field.push_back({});
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            field[i].push_back(temp);
        }

    }

    after_line(0, field);

    for (int i = 0; i < n; i++)
        first_line(i, 0, field);

    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';


    return 0;
}