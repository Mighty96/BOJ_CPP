#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

long long cnt = 0;
long long answer[300000];
map<int, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    int temp;

    cin >> temp;

    m.insert({ temp, 0 });
    m.insert({ 0, 0 });
    m.insert({ n + 1, 0 });
    answer[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> temp;

        m.insert({ temp, 0 });

        map<int, int>::iterator iter = m.find(temp);
        map<int, int>::iterator l_iter, r_iter;
        l_iter = iter;
        r_iter = iter;

        m[temp] = max((--l_iter)->second, (++r_iter)->second) + 1;
        cnt += m[temp];
        answer[i] = cnt;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}