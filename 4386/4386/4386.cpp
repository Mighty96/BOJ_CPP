#include <iostream>
#include <math.h>
#include <queue>
#include <tuple>

using namespace std;

int n;
double star[101][2];
double line[101][101];
priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>> > que;
int uf[101];

int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return find(uf[num]);
}

void merge(int num1, int num2)
{
    num1 = find(num1);
    num2 = find(num2);

    if (num1 != num2)
    {
        uf[num2] = num1;
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> star[i][0] >> star[i][1];
        uf[i] = i;
    }

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            que.push({ sqrt(pow(star[i][0] - star[j][0], 2) + pow(star[i][1] - star[j][1], 2)), i, j});

    int cnt = n - 1;

    double res = 0.0;
    double temp1;
    int temp2, temp3;
    while (cnt != 0)
    {
        temp1 = get<0>(que.top());
        temp2 = get<1>(que.top());
        temp3 = get<2>(que.top());
        que.pop();

        if (find(temp2) != find(temp3))
        {
            cnt--;
            merge(temp2, temp3);
            res += temp1;
        }

    }

    cout << res << '\n';

    return 0;

}