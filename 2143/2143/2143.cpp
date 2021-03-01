#include <iostream>
#include <vector>
#include <set>


using namespace std;

int t;
int n, m;
int a[1001];
int b[1001];
long long res = 0;
multiset<int> set1;
multiset<int> set2;


int main()
{
    cin >> t;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = 0;
        for (int j = i; j <= n; j++)
        {
            temp += a[j];
            set1.insert(temp);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        temp = 0;
        for (int j = i; j <= m; j++)
        {
            temp += b[j];
            set2.insert(t - temp);
        }
    }

    multiset<int>::iterator iter;

    iter = set1.begin();

    int num = 0;

    while (iter != set1.end())
    {
        num = *iter;
        res += set1.count(num) * set2.count(num);
        iter = set1.upper_bound(num);
    }

    cout << res << '\n';

    return 0;
}