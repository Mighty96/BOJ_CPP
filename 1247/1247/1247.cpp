#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vec1;
vector<long long> vec2;
vector<long long> vec3;

string cal(vector<long long> vec, int end)
{
	sort(vec.begin(), vec.end());
	long long sum = 0;
	int front = 0;
	sum += vec[front];
	front++;
	while (front <= end)
	{
		if (sum > 0)
		{
			if (vec[front] >= 0)
				return "+";
			sum += vec[front];
			front++;
		}
		else if (sum < 0)
		{
			if (vec[end] <= 0)
				return "-";
			sum += vec[end];
			end--;
		}
		else
		{
			sum += vec[front];
			front++;
		}
	}

	if (sum > 0)
		return "+";
	else if (sum < 0)
		return "-";
	else
		return "0";
}

int main()
{
	int n;
	long long temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec1.push_back(temp);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec2.push_back(temp);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec3.push_back(temp);
	}
	cout << cal(vec1, (int)vec1.size() - 1) << '\n';
	cout << cal(vec2, (int)vec2.size() - 1) << '\n';
	cout << cal(vec3, (int)vec3.size() - 1) << '\n';

	return 0;
}