#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int cost[10001];
int number[10001]; // 해당인덱스를 가리키는

queue<int> que;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> work1(n + 1); // 해당 인덱스가 가리키는
	vector<vector<int>> work2(n + 1); // 해당 인덱스를 가리키는
	
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		cin >> number[i];
		for (int j = 0; j < number[i]; j++)
		{
			cin >> temp;
			work1[temp].push_back(i);
			work2[i].push_back(temp);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if ((int)work2[i].size() == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		int now = que.front();
		que.pop();

		for (int i = 0; i < (int)work1[now].size(); i++)
		{
			number[work1[now][i]]--;
			if (number[work1[now][i]] == 0)
			{
				que.push(work1[now][i]);
				int temp = 0;
				for (int j = 0; j < (int)work2[work1[now][i]].size(); j++)
				{
					temp = max(temp, cost[work2[work1[now][i]][j]]);
				}
				cost[work1[now][i]] += temp;
			}
		}

	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, cost[i]);
	}
	cout << result << '\n';
	return 0;



}