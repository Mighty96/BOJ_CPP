#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long double> x;
    vector<long double> y;

    int temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        x.push_back(temp1);
        y.push_back(temp2);
    }

    long double result = 0;

    for (int i = 0; i < n - 1; i++)
    {
        result += (x[i] * y[i + 1] - x[i + 1] * y[i]);
    }
    result += x[n - 1] * y[0] - x[0] * y[n - 1];

    result = abs(result);
    result *= 5;
    result = floor(result + 0.5);
    result /= 10;

    cout << fixed;
    cout.precision(1);
    cout << result << '\n';
    return 0;
}