#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>

using namespace std;

int n;
vector<tuple<int, int, int, int>> planet;
int uf[100001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;


int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return uf[num] = find(uf[num]);
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

bool compare1(tuple<int, int, int, int> &a, tuple<int, int, int, int>& b)
{
    return  get<1>(a) < get<1>(b);
}

bool compare2(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b)
{
    return  get<2>(a) < get<2>(b);
}

bool compare3(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b)
{
    return  get<3>(a) < get<3>(b);
}



int main()
{
    cin >> n;

    int temp1, temp2, temp3;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        planet.push_back({ i + 1, temp1, temp2, temp3 });
        uf[i] = i;
    }

    sort(planet.begin(), planet.end(), compare1);

    for (int i = 1; i < n; i++)
        que.push({ min(min(abs(get<1>(planet[i]) - get<1>(planet[i - 1])), 
            abs(get<2>(planet[i]) - get<2>(planet[i - 1]))),
            abs(get<3>(planet[i]) - get<3>(planet[i - 1]))), 
            get<0>(planet[i]), get<0>(planet[i - 1])});

    sort(planet.begin(), planet.end(), compare2);

    for (int i = 1; i < n; i++)
        que.push({ min(min(abs(get<1>(planet[i]) - get<1>(planet[i - 1])),
            abs(get<2>(planet[i]) - get<2>(planet[i - 1]))),
            abs(get<3>(planet[i]) - get<3>(planet[i - 1]))),
            get<0>(planet[i]), get<0>(planet[i - 1]) });

    sort(planet.begin(), planet.end(), compare3);

    for (int i = 1; i < n; i++)
        que.push({ min(min(abs(get<1>(planet[i]) - get<1>(planet[i - 1])),
            abs(get<2>(planet[i]) - get<2>(planet[i - 1]))),
            abs(get<3>(planet[i]) - get<3>(planet[i - 1]))),
            get<0>(planet[i]), get<0>(planet[i - 1]) });




    int cnt = n - 1;

    int res = 0;
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