#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int _max = 19;

vector<vector<int>> arr;
long long volume;
int result;
bool flag = true;

void sep(int length, int width, int height, int idx)
{
    if (!flag) return;

    if (idx < 0)
    {
        flag = false;
        return;
    }

    if (length == 0 || width == 0 || height == 0)
        return;
    
    int len = pow(2, arr[idx][0]);
    int vol = pow(len, 3);

    if (arr[idx][1] > 0 && len <= length && len <= width && len <= height)
    {
        result++;
        arr[idx][1]--;
        volume -= pow(len, 3);

        sep(length - len, width, height, idx);
        sep(len, width - len, height, idx);
        sep(len, len, height - len, idx);
    }
    else
        sep(length, width, height, --idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int length, width, height;
    int n;
    cin >> length >> width >> height;
    cin >> n;

    volume = (long long)(length * width * height);

    for (int i = 0;i < n;i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr.push_back(vector<int>{temp1, temp2});
    }
    std::sort(arr.begin(), arr.end());

    sep(length, width, height, n - 1);
    
    if (!flag)
    {
        cout << "-1" << '\n';
        return 0;
    }

    if (volume <= 0)
        cout << result << '\n';
    else
        cout << "-1" << '\n';

    return 0;
}