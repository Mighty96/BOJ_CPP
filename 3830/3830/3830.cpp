#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n, m;
int uf[100001];
int weight[100001];
vector<string> res;

int find(int num)
{
    if (num == uf[num])
        return num;

    int temp = find(uf[num]);
    weight[num] += weight[uf[num]];
    uf[num] = temp;
    return temp;
}

void uni(int a, int b, int w)
{
    int temp_a = find(a);
    int temp_b = find(b);

    if (temp_a != temp_b)
    {
        uf[temp_a] = temp_b;
        weight[temp_a] = w + weight[b] - weight[a];
    }
}

int find_weight(int num)
{
    if (num == uf[num]) return 0;
    return find_weight(uf[num]) + weight[num];
}

int main()
{
    char question;
    int temp1, temp2, temp3;

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (true)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            uf[i] = i;
            weight[i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> question;
            if (question == '!')
            {
                cin >> temp1 >> temp2 >> temp3;
                uni(temp1, temp2, temp3);
            }
            else if (question == '?')
            {
                cin >> temp1 >> temp2;
                if (find(temp1) != find(temp2))
                    res.push_back("UNKNOWN");
                else
                {
                    res.push_back(to_string(find_weight(temp1) - find_weight(temp2)));
                }
            }
        }
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}