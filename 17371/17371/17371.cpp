#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int con[1001][2];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> con[i][0] >> con[i][1];
    }
    
    int min_idx = 0, max_idx = 0;
    int max_length = 0;
    int min_length = 1000000000;
    int temp;

    for (int i = 0; i < n; i++)
    {
        max_idx = i;
        max_length = -1;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            temp = pow(con[i][0] - con[j][0], 2) + pow(con[i][1] - con[j][1], 2);
            if (max_length < temp)
            {
                max_idx = i;
                max_length = temp;
            }
        }
        if (max_length < min_length)
        {
            min_length = max_length;
            min_idx = max_idx;
        }
    }

    cout << con[min_idx][0] << " " << con[min_idx][1] << '\n';

    return 0;

}