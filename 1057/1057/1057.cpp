#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int num, p_a, p_b;

	cin >> num >> p_a >> p_b;

	vector<bool> player(num + 1, true);
	int left_player = num;
	int first_player;
	int second_player;
	int count = 0;

	while (true)
	{
		int now_player = 1;
		count++;
		for (int i = 1; i <= left_player / 2; i++)
		{
			while (player[now_player] == false) now_player++;
			first_player = now_player;
			now_player++;
			while (player[now_player] == false) now_player++;
			second_player = now_player;
			now_player++;

			if (first_player == p_a)
			{
				if (second_player == p_b)
				{
					cout << count << '\n';
					return 0;
				}
				else
				{
					player[second_player] = false;
				}
			}
			else if (first_player == p_b)
			{
				if (second_player == p_a)
				{
					cout << count << '\n';
					return 0;
				}
				else
				{
					player[second_player] = false;
				}
			}
			else if (second_player == p_a)
			{
				player[first_player] = false;
			}
			else if (second_player == p_b)
			{
				player[first_player] = false;
			}
			else
				player[second_player] = false;
		}
		left_player -= (left_player / 2);
	}

	return -1;
}