#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;
vector<int> vec;
vector<int> l;
int p[1000000];


int main()
{
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
        if (l.empty() || temp > l[(int)l.size() - 1])
        {
            l.push_back(temp);
            p[i] = (int)l.size();
        }
        else
        {
            auto itr = lower_bound(l.begin(), l.end(), temp);
            *lower_bound(l.begin(), l.end(), temp) = temp;
            p[i] = distance(l.begin(), itr) + 1;
        }
    }
    cout << (int)l.size() << '\n';

    int idx1 = n;
    int idx2 = (int)l.size();
    while (idx1 > 0)
    {
        idx1--;
        if (p[idx1] == idx2)
        {
            st.push(vec[idx1]);
            idx2--;
        }
    }
    for (int i = 0; i < (int)l.size(); i++)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
    return 0;
}