#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	int known_num;
	queue<int> person;
	queue<int> party;
	int temp = 0;
	int result = 0;

	cin >> n >> m;
	cin >> known_num;
	if (known_num == 0)
	{
		cout << m << '\n';
		return 0;
	}
	for (int i = 0;i < known_num;i++)
	{
		cin >> temp;
		person.push(temp);
	}

	vector<vector<bool>> party_list(m + 1, vector<bool>(n + 1, false));

	vector<bool> person_posible(n + 1, true);
	vector<bool> party_posible(m + 1, true);
	int _temp;
	for (int i = 1; i <= m;i++)
	{
		cin >> temp;
		for (int j = 1; j <= temp; j++)
		{
			cin >> _temp;
			party_list[i][_temp] = true;
		}
	}

	int person_now, party_now;
	while (!person.empty())
	{
		person_now = person.front();
		person.pop();

		for (int i = 1; i <= m; i++)
		{
			if (party_list[i][person_now] == true && party_posible[i] == true)
			{
				party_posible[i] = false;
				party.push(i);
			}
		}
		while (!party.empty())
		{
			party_now = party.front();
			party.pop();

			for (int i = 1; i <= n; i++)
			{
				if (party_list[party_now][i] == true && person_posible[i] == true)
				{
					person_posible[i] = false;
					person.push(i);
				}
			}
		}
	}

	for (int i = 1; i <= m; i++)
		if (party_posible[i])
			result++;

	cout << result << '\n';
	return 0;



}