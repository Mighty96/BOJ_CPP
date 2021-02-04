#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr1[4001];
long long arr2[4001];
long long arr3[4001];
long long arr4[4001];
long long sum1[16000001];
long long sum2[16000001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
    }
    
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1[idx] = arr1[i] + arr2[j];
            sum2[idx++] = arr3[i] + arr4[j];
        }
    }
    sort(sum2, sum2 + n*n);
    long long result = 0;
    for (int i = 0; i < n * n; i++)
    {
        int front = 0;
        int end = n*n;
        while (front < end)
        {
            int mid = (front + end) / 2;
            if (sum1[i] + sum2[mid] == 0)
            {
                result += upper_bound(sum2, sum2 + n * n, sum2[mid]) -
                    lower_bound(sum2, sum2 + n * n, sum2[mid]);
                break;
            }
            else if (sum1[i] + sum2[mid] > 0)
            {
                end = mid;
            }
            else
            {
                front = mid + 1;
            }
        }
    }

    cout << result << '\n';
}