#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int h, w;
vector<tuple<int, int, int>> cctv;

int num = 0;
int result = 100;

void up(int y, int x, vector<vector<int>>& field)
{
    while (y > 0)
    {
        y--;
        if (field[y][x] == 0 || field[y][x] == 7)
            field[y][x] = 7;
        else if (field[y][x] == 6)
            break;
    }
}

void down(int y, int x, vector<vector<int>>& field)
{
    while (y < h - 1)
    {
        y++;
        if (field[y][x] == 0 || field[y][x] == 7)
            field[y][x] = 7;
        else if (field[y][x] == 6)
            break;
    }
}

void left(int y, int x, vector<vector<int>>& field)
{
    while (x > 0)
    {
        x--;
        if (field[y][x] == 0 || field[y][x] == 7)
            field[y][x] = 7;
        else if (field[y][x] == 6)
            break;
    }
}

void right(int y, int x, vector<vector<int>>& field)
{
    while (x < w - 1)
    {
        x++;
        if (field[y][x] == 0 || field[y][x] == 7)
            field[y][x] = 7;
        else if (field[y][x] == 6)
            break;
    }
}
void dfs(int y, int x, int number, int cnt, vector<vector<int>> &field)
{
    vector<vector<int>> new_field = field;
 
    if (cnt == num)
    {
        int temp_result = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (field[i][j] == 0)
                    temp_result++;
            }
        }
        result = (result < temp_result) ? result : temp_result;
        return;
    }
    switch (number)
    {
    case 1:
        up(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        right(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        left(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        break;
    case 2:
        up(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        left(y, x, new_field);
        right(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        break;
    case 3:
        up(y, x, new_field);
        right(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        right(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        left(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        up(y, x, new_field);
        left(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        break;
    case 4:
        up(y, x, new_field);
        right(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        left(y, x, new_field);
        right(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        up(y, x, new_field);
        right(y, x, new_field);
        left(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        new_field = field;
        up(y, x, new_field);
        left(y, x, new_field);
        down(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        break;
    case 5:
        up(y, x, new_field);
        right(y, x, new_field);
        down(y, x, new_field);
        left(y, x, new_field);
        dfs(get<0>(cctv[cnt + 1]), get<1>(cctv[cnt + 1]), get<2>(cctv[cnt + 1]), cnt + 1, new_field);
        break;
    }


}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;
    vector<vector<int>> field(h, vector<int>(w, 0));
    
    int temp;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> temp;
            field[i][j] = temp;
            if (temp == 0 || temp == 6) continue;
           
            for (int k = 1; k < 6; k++)
            {
                if (temp == k)
                {
                    cctv.push_back(make_tuple(i, j, k));
                    num++;
                    break;
                }

            }

        }
    }
    cctv.push_back(make_tuple(0, 0, 0));

    int up_cnt = 0;
    dfs(get<0>(cctv[0]), get<1>(cctv[0]), get<2>(cctv[0]), up_cnt, field);

    cout << result << '\n';

    return 0;
}