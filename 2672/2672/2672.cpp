#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;

struct square {
    int x;
    int y1, y2;
    bool left;
};

struct compare {
    bool operator()(square a, square b) {
        return a.x > b.x;
    }
};

priority_queue<square, vector<square>, compare> que;

int res = 0;
int num[20002];

int main()
{
    cin >> n;

    double temp1, temp2, temp3, temp4;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1 >> temp2 >> temp3 >> temp4;
        temp1 *= 10;
        temp2 *= 10;
        temp3 *= 10;
        temp4 *= 10;
        square s;
        s.x = temp1;
        s.y1 = temp2;
        s.y2 = temp2 + temp4;
        s.left = true;
        que.push(s);
        s.x = temp1 + temp3;
        s.left = false;
        que.push(s);
    }

    int temp_y = 0;
    int pre_x = 0;
    while (!que.empty())
    {
        square now = que.top();
        que.pop();

        temp_y = 0;
        for (int i = 1; i <= 20001; i++)
        {
            if (num[i] > 0)
                temp_y++;
        }
        res += (now.x - pre_x) * temp_y;

        if (now.left)
        {
            for (int i = now.y1 + 1; i <= now.y2; i++)
                num[i]++;
        }
        else
        {
            for (int i = now.y1 + 1 ; i <= now.y2 ; i++)
                num[i]--;
        }
        pre_x = now.x;
    }


    if (res % 100 == 0)
        cout << res / 100 << '\n';
    else
    {
        cout << fixed;
        cout.precision(2);
        cout << (double)res / 100 << '\n';
    }

    return 0;

    
}