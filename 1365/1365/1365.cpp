#include <iostream>

using namespace std;

int n;
int line[100001];
int a[100001];
int result = 0;

void find_num(int front, int back, int num)
{

    if (front == back)
    {
        a[front] = num;
    }

    int mid = (front + back) / 2;

    if (a[mid] == num)
    {
        return;
    }
    else if (a[mid] > num)
    {
        find_num(front, mid, num);
    }
    else
    {
        find_num(mid + 1, back, num);
    }
}


int main()
{
    cin >> n;

    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> line[i];
        a[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[result] < line[i])
        {
            result++;
            a[result] = line[i];
            continue;
        }
        else if (a[result] == line[i])
        {
            continue;
        }
        else
        {
            find_num(1, result, line[i]);
        }

    }

    cout << n - result << '\n';
}