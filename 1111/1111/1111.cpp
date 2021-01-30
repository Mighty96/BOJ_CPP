#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[50];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 2 && arr[0] == arr[1])
    {
        cout << arr[0] << '\n';
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << "A" << '\n';
        return 0;
    }

    if (arr[0] == arr[1])
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] != arr[i + 1])
            {
                cout << "B" << '\n';
                return 0;
            }
        }
        cout << arr[0] << '\n';
        return 0;
    }

    int a, b;

    if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0)
    {
        cout << "B" << '\n';
        return 0;
    }
    a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
    b = arr[1] - a * arr[0];

    if (n == 3)
    {
        cout << arr[2] * a + b << '\n';
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] != (arr[i] * a + b))
        {
            cout << "B" << '\n';
            return 0;
        }
    }

    cout << arr[n - 1] * a + b << '\n';
    return 0;
}