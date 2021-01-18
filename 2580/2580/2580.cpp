#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<pair<int, int>> que;
int cnt = 0;
bool flag = false;

void bt(vector<vector<int>> &sudoku, vector<bool> judge, int now)
{
    if (flag)
        return;

    if (now >= cnt)
    {
        flag = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i < 10; i++)
        judge[i] = true;

    for (int i = 0; i < 9 ; i++)
    {
        judge[sudoku[que[now].first][i]] = false;
        judge[sudoku[i][que[now].second]] = false;
    }
    for (int i = (que[now].first / 3) * 3; i < (que[now].first / 3) * 3 + 3; i++)
        for (int j = (que[now].second / 3) * 3; j < (que[now].second / 3) * 3 + 3; j++)
            judge[sudoku[i][j]] = false;
    for (int i = 1; i < 10; i++)
    {
        if (judge[i])
        {
            sudoku[que[now].first][que[now].second] = i;
            bt(sudoku, judge, now + 1);
            sudoku[que[now].first][que[now].second] = 0;
        }
    }

    return;
}

int main()
{

    vector<bool> judge(10, true);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> sudoku(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
            {
                que.push_back(make_pair(i, j));
                cnt++;
            }
        }
    
    bt(sudoku, judge, 0);

    return 0;


}