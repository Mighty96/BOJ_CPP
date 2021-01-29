#include <iostream>
#include <tuple>
#include <stack>

using namespace std;

stack<tuple<int, int, int>> st;
int n;
int weight[10001] = { 0 };
int result = 0;

int main()
{
    cin >> n;

    int temp1, temp2, temp3;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        st.push(make_tuple(temp1, temp2, temp3));
    }

    int parent, child, w;

    while (!st.empty())
    {
        parent = get<0>(st.top());
        child = get<1>(st.top());
        w = get<2>(st.top());

        st.pop();

        if (weight[parent] == 0)
        {
            weight[parent] = weight[child] + w;
            result = (result > weight[parent]) ? result : weight[parent];
        }
        else
        {
            result = (result > weight[parent] + weight[child] + w) ?
                result : weight[parent] + weight[child] + w;
            weight[parent] = (weight[parent] > weight[child] + w) ?
                weight[parent] : weight[child] + w;
        }
    }

    cout << result << '\n';
    return 0;
}