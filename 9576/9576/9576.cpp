#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;
int n, m;

struct book {
    int a;
    int b;
};

struct compare1 {
    bool operator()(book a, book b) {
        if (a.a == b.a)
        {
            return a.b > b.b;
        }
        return a.a > b.a;
    }
};

struct compare2 {
    bool operator()(book a, book b) {
        return a.b > b.b;
    }
};

priority_queue<book, vector<book>, compare1> que1;
priority_queue<book, vector<book>, compare2> que2;
vector<int> result;

int main()
{
    cin >> t;
    
    int temp1, temp2;

    for (int _ = 0; _ < t; _++)
    {
        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> temp1 >> temp2;

            book bk;
            bk.a = temp1;
            bk.b = temp2;
            que1.push(bk);
        }

        int page = 1;
        int temp_result = 0;
        while (page <= n)
        {
            while (!que1.empty() && que1.top().a <= page)
            {
                que2.push(que1.top());
                que1.pop();
            }

            while (!que2.empty() && que2.top().b < page)
            {
                que2.pop();
            }

            if (!que2.empty())
            {
                temp_result++;
                que2.pop();
            }
            page++;
        }
        result.push_back(temp_result);


    }

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}