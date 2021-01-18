#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int main()
{
    int end, start, goal, up, down;

    cin >> end >> start >> goal >> up >> down;

    vector<int> ele(end + 1, -1);
    queue<int> que;
    ele[start] = 0;
    
    que.push(start);

    while (!que.empty())
    {
        if (que.front() + up <= end)
            if (ele[que.front() + up] == -1)
            {
                que.push(que.front() + up);
                ele[que.front() + up] = ele[que.front()] + 1;
            }

        if (que.front() - down > 0)
            if (ele[que.front() - down] == -1)
            {
                que.push(que.front() - down);
                ele[que.front() - down] = ele[que.front()] + 1;
            }
        que.pop();
    }

    if (ele[goal] == -1)
        cout << "use the stairs" << '\n';
    else
        cout << ele[goal] << '\n';
    return 0;



}