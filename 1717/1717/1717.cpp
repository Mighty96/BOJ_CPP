#include <iostream>
#include <string>
#include <vector>

using namespace std;

int number[1000001];

int find(int x)
{
	if (number[x] == x)
		return x;
	else
		return number[x] = find(number[x]);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	vector<string> result;
	cin >> n >> m;

	for (int i = 0; i <= n;i++)
		number[i] = i;

	int num1, num2, num3;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2 >> num3;
		if (num1 == 0)
			number[find(num2)] = find(num3);
		else
		{
			if (find(num2) == find(num3))
				result.push_back("YES");
			else
				result.push_back("NO");
		}
	}

	for (int i = 0; i < (int)result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}