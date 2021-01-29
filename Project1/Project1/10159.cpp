#include <iostream>
#include <vector>
using namespace std;

int item[101][101] = { 0 };
int n, m;

void lighter(int heavy, int light);

void heavier(int heavy, int light)
{
	for (int i = 1; i <= n; i++)
	{
		if (item[i][heavy] == 1)
		{
			if (item[i][light] != 1)
			{
				item[i][light] = 1;
				item[light][i] = -1;
				heavier(i, light);
				lighter(i, light);
			}
		}
	}
}

void lighter(int heavy, int light)
{
	for (int i = 1; i <= n; i++)
	{
		if (item[i][light] == -1)
		{
			if (item[i][heavy] != -1)
			{
				item[i][heavy] = -1;
				item[heavy][i] = 1;
				heavier(heavy, i);
				lighter(heavy, i);
			}
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	
	cin >> n >> m;

	int temp1, temp2;
	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		item[temp1][temp2] = 1;
		item[temp2][temp1] = -1;
		heavier(temp1, temp2);
		lighter(temp1, temp2);
	}
	
	vector<int> result;

	for (int i = 1; i <= n; i++)
	{
		int temp_sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (item[i][j] == 0)
				temp_sum++;
		}
		result.push_back(temp_sum - 1);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << '\n';

	return 0;
			
   
}