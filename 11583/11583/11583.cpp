#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int rock[100001];
int d_2[100001];
int d_5[100001];
vector<int> result;
bool vis[100001];

int find2(int num)
{
    int count = 0;
    while (num % 2 == 0)
    {
        num /= 2;
        count++;
    }

    return count;
}

int find5(int num)
{
    int count = 0;
    while (num % 5 == 0)
    {
        num /= 5;
        count++;
    }

    return count;
}

int main()
{
    int t;

    cin >> t;

    for (int _ = 1; _ <= t; _++)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> rock[i];
            vis[i] = false;
        }

        d_2[1] = find2(rock[1]);
        d_5[1] = find5(rock[1]);
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= i + k; j++)
            {
                if (j > n) continue;
                if (!vis[j])
                {
                    d_2[j] = d_2[i] + find2(rock[j]);
                    d_5[j] = d_5[i] + find5(rock[j]);
                    vis[j] = true;
                }
                else
                {
                   /* if (min(d_2[i] + find2(rock[j]), d_5[i] + find5(rock[j])) <
                        min(d_2[j], d_5[j]))
                    {*/
                        d_2[j] = min(d_2[j], d_2[i] + find2(rock[j]));
                        d_5[j] = min(d_5[j], d_5[i] + find5(rock[j]));
                    //}
                }
            }
        }
        result.push_back(min(d_2[n], d_5[n]));
    }

    for (int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}