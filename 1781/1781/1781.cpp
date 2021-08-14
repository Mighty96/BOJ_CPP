#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct quest {
    int deadline;
    int ramen;
};

struct compare {
    bool operator()(quest a, quest b) {
        return a.ramen < b.ramen;
    }

};

int value[200001];
int match[200001];
priority_queue<quest, vector<quest>, compare> que;
int n;

int find(int deadline)
{
    if (value[match[deadline]] == 0)
    {
        return match[deadline];
    }
    else
    {   
        if (match[deadline] = deadline)
        {
            match[deadline] = find(deadline - 1);
        }
        else
        {
            match[deadline] = find(match[deadline]);
        }
        return match[deadline];
    }
}

void push(int deadline, int ramen)
{
    if (find(deadline) == 0)
    {
        return;
    }
    value[find(deadline)] = ramen;
    match[deadline] = match[deadline - 1];
}


int main()
{
    cin >> n;

    int temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        quest q;
        q.deadline = temp1;
        q.ramen = temp2;
        que.push(q);
    }

    for (int i = 0; i <= n; i++)
    {
        value[i] = 0;
        match[i] = i;
    }

    while (!que.empty())
    {
        push(que.top().deadline, que.top().ramen);
        que.pop();
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += value[i];
    }

    cout << result;

    return 0;
}