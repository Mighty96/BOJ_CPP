#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int union_find[1001];

int find(int num)
{
    while (union_find[num] != num)
        num = union_find[num];
    return num;
}

int main()
{
    int n, m;
    int result = 0;
    int cnt = 0;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        union_find[i] = i;
    vector<tuple<int, int, int>> line;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        line.push_back(make_tuple(c, a, b));
    }
   
    sort(line.begin(), line.end());

    for (int i = 0; i < m; i++)
    {
        if (find(get<1>(line[i])) != find(get<2>(line[i])))
        {
            union_find[find(get<2>(line[i]))] = get<1>(line[i]);
            result += get<0>(line[i]);
            if (++cnt == (n - 1))
                break;
        }
    }

    cout << result << '\n';
    return 0;

}