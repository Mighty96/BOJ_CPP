#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<long long> liquid;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        liquid.push_back(temp);
    }

    sort(liquid.begin(), liquid.end());
    long long result = 3000000000;
    int print_front = 0;
    int print_mid = 0;
    int print_end = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            long long temp = liquid[i] + liquid[j];
            int new_front = i + 1;
            int new_end = j;
            while (new_front < new_end)
            {
                int mid = (new_front + new_end) / 2;
                if (abs(temp + liquid[mid]) < result)
                {
                    result = abs(temp + liquid[mid]);
                    print_front = i;
                    print_mid = mid;
                    print_end = j;
                }
                if (temp + liquid[mid] > 0)
                {
                    new_end = mid;
                }
                else if (temp + liquid[mid] == 0)
                {
                    cout << liquid[i] << " " << liquid[mid] << " " << liquid[j] << '\n';
                    return 0;
                }
                else
                {
                    new_front = mid + 1;
                }
            }
        }
    }
    cout << liquid[print_front] << " " << liquid[print_mid] << " " << liquid[print_end] << '\n';
    return 0;

}