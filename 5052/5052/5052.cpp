#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<string> number[50];
vector<string> res;

bool compare(int& a, int& b)
{
    return a < b;
}

int main()
{
    int n;
    cin >> n;

    int temp;
    string temp2;
    int before_length, after_length;
    int length;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            cin >> temp2;
            number[i].push_back(temp2);
        }

        sort(number[i].begin(), number[i].end());

        flag = false;
        for (int j = 0; j < temp - 1; j++)
        {
            before_length = number[i][j].length();
            after_length = number[i][j + 1].length();
            length = after_length - before_length;
            if (before_length > after_length)
                continue;
            else
            {
                if (number[i][j] == number[i][j + 1].substr(0, before_length))
                {
                    res.push_back("NO");
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
            res.push_back("YES");
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}