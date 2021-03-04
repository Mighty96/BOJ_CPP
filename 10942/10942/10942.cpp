#include <iostream>

using namespace std;

int n;
int arr[2001];
int m;
bool pal[2001][2001];
int res[1000001];

void make_pal(int num1, int num2)
{
    int temp = 0;
    while (num1 - temp > 0 && num2 + temp <= n)
    {
        if (pal[num1 - temp][num2 + temp])
            break;
        if (arr[num1 - temp] == arr[num2 + temp])
            pal[num1 - temp][num2 + temp] = true;
        else
            break;
        temp++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> m;

    int num1, num2, num3;
    for (int i = 1; i <= m; i++)
    {
        cin >> num1 >> num2;
        num3 = (num2 - num1) / 2;
        make_pal(num1 + num3, num2 - num3);
        res[i] = pal[num1][num2];
    }

    for (int i = 1; i <= m; i++)
        cout << res[i] << '\n';

    return 0;
}