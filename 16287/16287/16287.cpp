#include <iostream>

using namespace std;

int w, n;
bool d[800000];
int parcel[5001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> w >> n;
    for (int i = 0; i < n; i++)
        cin >> parcel[i];
   
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (parcel[i] + parcel[j] > w) continue;
            if (d[w - parcel[i] - parcel[j]])
            {
                cout << "YES" << '\n';
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (parcel[i] + parcel[j] < w)
                d[parcel[i] + parcel[j]] = true;
        }
    }
    cout << "NO" << '\n';

    return 0;

}