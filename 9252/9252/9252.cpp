#include <iostream>

using namespace std;

string a;
string b;
string lcs[1002][1002];
int main()
{
    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= (int)a.length(); i++)
    {
        for (int j = 1 ; j <= (int)b.length(); j++)
        {
            if (a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + a[i];
            else
            {
                if (lcs[i - 1][j].length() > lcs[i][j - 1].length())
                    lcs[i][j] = lcs[i - 1][j];
                else
                    lcs[i][j] = lcs[i][j - 1];
            }
        }
    }
    
    if (lcs[a.length()][b.length()].length() - 1 == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    cout << lcs[a.length()][b.length()].length() - 1 << '\n';
    cout << lcs[a.length()][b.length()] << '\n';

    return 0;
}