#include <iostream>
#include <algorithm>

using namespace std;

int ff, fs, sf, ss;

int main()
{
    cin >> ff >> fs >> sf >> ss;

    int result = 0;

    if (ff == 0 && fs == 0)
    {
        if (sf == 0)
        {
            cout << ss << '\n';
        }
        else
        {
            cout << ss + 1 << '\n';
        }
        return 0;
    }

    if (fs == 0)
    {
        cout << ff << '\n';
        return 0;
    }
    else
    {
        result += ff + ss;

        if (fs > sf)
        {
            result = result + (sf * 2) + 1;
        }
        else
        {
            result = result + (fs * 2);
        }

        cout << result << '\n';

        return 0;
    }

    
}