#include <iostream>

using namespace std;

int n, m, k;
bool card[4000004];
int enemy[10001];
int uf[4000004];

int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return uf[num] = find(uf[num]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    int temp;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        card[temp] = true;
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> enemy[i];
    }

    card[n] = true;
    for (int i = n - 1; i >= 1; i--)
    {
        if (card[i + 1])
            uf[i] = i;
        else
            uf[i] = find(i + 1);
    }

    for (int i = 1; i <= k; i++)
    {
        cout << find(enemy[i]) + 1 << '\n';
        uf[uf[enemy[i]]] = uf[uf[enemy[i]] + 1];
    }
    return 0;
}