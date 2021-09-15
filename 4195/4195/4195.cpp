#include <iostream>
#include <map>
#include <vector>

using namespace std;

int T;

int uf[200001];
int sum[200001];

map<string, int> m;

vector<int> answer;

int uf_find(int node)
{
    if (uf[node] == node)
        return node;

    return uf[node] = uf_find(uf[node]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int _ = 1; _ <= T; _++)
    {
        int f;
        cin >> f;
        
        m.clear();

        string temp1, temp2;
        for (int i = 1; i <= f; i++)
        {
            cin >> temp1 >> temp2;

            if (m.find(temp1) == m.end())
            {
                m.insert({ temp1, m.size() });
                uf[m[temp1]] = m[temp1];
                sum[m[temp1]] = 1;
            }
            if (m.find(temp2) == m.end())
            {
                m.insert({ temp2, m.size() });
                uf[m[temp2]] = m[temp2];
                sum[m[temp2]] = 1;
            }

            if (uf_find(m[temp1]) == uf_find(m[temp2]))
            {
                answer.push_back(sum[uf_find(m[temp1])]);
                continue;
            }
               
            sum[uf_find(m[temp1])] += sum[uf_find(m[temp2])];
            uf[uf_find(m[temp2])] = uf_find(m[temp1]);
            answer.push_back(sum[uf[m[temp1]]]);
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}