#include <iostream>

using namespace std;

int n;
int answer = 0;

void bt(int num, int arr[])
{
    if (num == n)
    {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= num; j++)
        {
            if (i - j < 0)
                break;
            if (arr[num - j] == (i - j))
            {
                flag = false;
                break;
            }
            
        }
        for (int j = 1; j <= num; j++)
        {
            if (i + j >= n)
                break;
            if (arr[num - j] == (i + j))
            {
                flag = false;
                break;
            }
        }
        for (int j = 0; j < num; j++)
        {
            if (arr[j] == i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            arr[num] = i;
            bt(num + 1, arr);
        }
    }

}


int main()
{
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    else if (n == 2 || n == 3)
    {
        cout << 0 << '\n';
        return 0;
    }

    int arr[16];

    bt(0, arr);

    cout << answer << '\n';
}