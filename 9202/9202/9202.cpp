#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;

struct answer {
	int score;
	string len_max;
	int cnt;
};

string word[300000];
string bobble[30][4];
bool vis[4][4];

answer res[30];

bool find(int w_idx, int b_idx, int idx, int y, int x)
{
	if (idx >= word[w_idx].length())
	{
		res[b_idx].cnt++;
		if (res[b_idx].len_max.length() < word[w_idx].length())
			res[b_idx].len_max = word[w_idx];
		else if (res[b_idx].len_max.length() == word[w_idx].length() && res[b_idx].len_max > word[w_idx])
			res[b_idx].len_max = word[w_idx];
		if (word[w_idx].length() < 3)
			;
		else if (word[w_idx].length() < 5)
			res[b_idx].score += 1;
		else if (word[w_idx].length() < 6)
			res[b_idx].score += 2;
		else if (word[w_idx].length() < 7)
			res[b_idx].score += 3;
		else if (word[w_idx].length() < 8)
			res[b_idx].score += 5;
		else
			res[b_idx].score += 11;

		return true;
	}

	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + 1; j++)
			if (i >= 0 && j >= 0 && i < 4 && j < 4 && !vis[i][j] && bobble[b_idx][i][j] == word[w_idx][idx])
			{
				vis[i][j] = true;
				if (find(w_idx, b_idx, idx + 1, i, j))
				{
					vis[i][j] = false;
					return true;
				}
				vis[i][j] = false;
			}
				

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word[i];
	}
		

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> bobble[i][j];
		res[i].cnt = 0;
		res[i].len_max = "";
		res[i].score = 0;
	}

	bool flag;
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			flag = false;
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					if (bobble[i][k][l] == word[j][0])
					{
						vis[k][l] = true;
						flag = find(j, i, 1, k, l);
						vis[k][l] = false;
					}
					if (flag) break;
				}
					
				if (flag) break;
			}
		}


	for (int i = 0; i < m; i++)
		cout << res[i].score << " " << res[i].len_max << " " << res[i].cnt << '\n';

	return 0;
}