#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;



int d[1001][1001];
int n, w;
vector<pair<int, int>> car1;
vector<pair<int, int>> car2;
vector<int> trace;

int dp(int num1, int num2)
{
    if (num1 == w || num2 == w)
        return 0;

    if (d[num1][num2] != -1)
        return d[num1][num2];

    int next = max(num1, num2) + 1;
    int temp1 = dp(next, num2) +
        abs(car1[num1].first - car1[next].first) + abs(car1[num1].second - car1[next].second);

    int temp2 = dp(num1, next) +
        abs(car2[num2].first - car2[next].first) + abs(car2[num2].second - car2[next].second);

    d[num1][num2] = min(temp1, temp2);
    return d[num1][num2];
}

void tracking(int num1, int num2)
{
    if (num1 == w || num2 == w)
        return;

    int next = max(num1, num2) + 1;
    int temp1 = d[next][num2] +
        abs(car1[num1].first - car1[next].first) + abs(car1[num1].second - car1[next].second);

    int temp2 = d[num1][next] +
        abs(car2[num2].first - car2[next].first) + abs(car2[num2].second - car2[next].second);

    if (temp1 < temp2)
    {
        trace.push_back(1);
        tracking(next, num2);
    }
    else
    {
        trace.push_back(2);
        tracking(num1, next);
    }
}

int main()
{
    cin >> n >> w;

    car1.push_back({ 1, 1 });
    car2.push_back({ n,n });

    int x, y;
    for (int i = 1; i <= w; i++)
    {
        cin >> x >> y;
        car1.push_back({ x,y });
        car2.push_back({ x,y });
    }

    memset(d, -1, sizeof(d));
    int result = dp(0, 0);
    
    
    tracking(0, 0);

    cout << result << '\n';
    for (int i = 0; i < (int)trace.size(); i++)
        cout << trace[i] << '\n';

    return 0;

}