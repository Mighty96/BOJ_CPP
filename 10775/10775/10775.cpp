#include <iostream>

using namespace std;

int n, m;
int plane[100001];
int uf[100001];

int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return uf[num] = find(uf[num]);
}


int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        uf[i] = i;

    for (int i = 0; i < m; i++)
        cin >> plane[i];

    int res = m;
    for (int i = 0; i < m; i++)
    {
        if (find(plane[i]) > 0)
        {
            uf[find(plane[i])] = find(uf[uf[plane[i]] - 1]);
        }
        else
        {
            res = i;
            break;
        }

    }

    cout << res << '\n';

    return 0;


}