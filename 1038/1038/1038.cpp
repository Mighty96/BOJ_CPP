#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;

    string num = "0";

    if (n == 1022)
    {
        cout << "9876543210";
        return 0;
    }
    if (n > 1022)
    {
        cout << -1;
        return 0;
    }

    while(true)
    {
        bool flag = true;
        for (int j = 0; j < num.length() - 1; j++)
        {
            if ((int)num[j] <= (int)num[j + 1])
            {
                flag = false;
                if (num[j] == '9')
                {
                    num = to_string(num.length() * (long)pow(10, num.length()));
                    for (int i = 1; i < num.length(); i++)
                    {
                        num[i] = ((int)num[i - 1] - 1);
                    }
                }
                else
                {
                    num[j] = ((int)num[j] + 1);
                    for (int i = j + 1; i < num.length(); i++)
                    {
                        num[i] = '0';
                    }
                }
                break;
            }
        }

        if (flag)
        {
            if (n == cnt)
            {
                cout << num;
                return 0;
            }
            cnt++;
            num = to_string(stol(num) + 1);
        }
    }

    cout << -1;

    return 0;
}