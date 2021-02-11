#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> hole[1000];
int n;


int main()
{
    cin >> n;

    int temp1;
    string temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1;

        for (int j = 0; j < temp1; j++)
        {
            cin >> temp2;
            hole[i].push_back(temp2);
        }
    }

    sort(hole, hole+n);
    
    string result[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)hole[i].size(); j++)
        {
            if (result[j] == hole[i][j])
            {
                continue;
            }
            else
            {
                for (int k = j; k < 20; k++)
                    result[k] = "";
                result[j] = hole[i][j];
                for (int k = 0; k < j; k++)
                    cout << "--";
                cout << result[j] << '\n';
            }
        }
    }


    return 0;
}