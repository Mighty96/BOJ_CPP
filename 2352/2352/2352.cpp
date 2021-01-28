#include <iostream>

using namespace std;


int main()
{
    int n;
    int d[40001];
    int a[40001];
    int result = 0;

    cin >> n;

    int arr[40001];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    d[0] = 0;
    a[0] = 0;
    int end = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        flag = false;
        for (int j = 0; j <= end; j++)
        {
            if (a[j] > arr[i])
            {
                a[j] = arr[i];
                d[i] = j;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            end++;
            a[end] = arr[i];
            d[i] = end;
        }
    }

    cout << end << '\n';

    return 0;
}