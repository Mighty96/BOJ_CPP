#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int n;

long long res = 0;
stack<pair<int ,int>> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    int num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;

        while (!st.empty() && st.top().first < num)
        {
            res += st.top().second;
            st.pop();
        }

        if (st.empty())
            st.push({ num, 1 });
        else
        {
            if (num == st.top().first)
            {
                pair<int, int> cur = st.top();
                st.pop();

                res += cur.second;

                if (!st.empty())
                    res++;

                cur.second++;
                st.push(cur);
            }
            else
            {
                st.push({ num, 1 });
                res++;
            }
        }
    }

    cout << res << '\n';
    return 0;
}