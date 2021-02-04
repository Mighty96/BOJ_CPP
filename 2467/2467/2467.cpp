#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long liquid[100001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> liquid[i];
	}

	int front = 1; int end = n;
	long result = 2000000000;
	long result_front = 0;
	long result_end = 0;
	while (front < end)
	{
		long temp = liquid[front] + liquid[end];
		if (temp == 0)
		{
			cout << liquid[front] << " " << liquid[end] << '\n';
			return 0;
		}
		
		if (abs(temp) < result)
		{
			result = abs(temp);
			result_front = liquid[front];
			result_end = liquid[end];
		}
		result = min(abs(temp), result);
		if (temp < 0)
		{
			front++;
		}
		else if (temp > 0)
		{
			end--;
		}

	}
	cout << result_front << " " << result_end << '\n';
	return 0;
}