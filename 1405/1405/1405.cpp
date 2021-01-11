#include <iostream>
#include <vector>

using namespace std;
long double result = 0;
long double a, b, c, d;
int n;
vector<vector<bool>> visited(30, vector<bool>(30, false));

void dfs(long double percentage, int count, int pos_x, int pos_y)
{
	visited[pos_y][pos_x] = true;
	
	if (count == n)
	{
		result += percentage;
		return;
	}
	else
	{
		if (visited[pos_y][pos_x + 1] != true)
		{
			dfs(percentage * a, count + 1, pos_x + 1, pos_y);
			visited[pos_y][pos_x + 1] = false;
		}
		if (visited[pos_y][pos_x - 1] != true)
		{
			dfs(percentage * b, count + 1, pos_x - 1, pos_y);
			visited[pos_y][pos_x - 1] = false;
		}
		if (visited[pos_y - 1][pos_x] != true)
		{
			dfs(percentage * c, count + 1, pos_x, pos_y - 1);
			visited[pos_y - 1][pos_x] = false;
		}
		if (visited[pos_y + 1][pos_x] != true)
		{
			dfs(percentage * d, count + 1, pos_x, pos_y + 1);
			visited[pos_y + 1][pos_x] = false;
		}
	}
	return;
}

int main()
{
	cin >> n >> a >> b >> c >> d;
	cout.precision(11); cout << fixed;
	long double percentage = 1;			
	int count = 0;
	int pos_x = 15;
	int pos_y = 15;
	visited[pos_y][pos_x] = true;
	a /= 100;
	b /= 100;
	c /= 100;
	d /= 100;
	dfs(a, count + 1, pos_x + 1, pos_y);
	visited[pos_y][pos_x + 1] = false;
	dfs(b, count + 1, pos_x - 1, pos_y);
	visited[pos_y][pos_x - 1] = false;
	dfs(c, count + 1, pos_x, pos_y - 1);
	visited[pos_y - 1][pos_x] = false;
	dfs(d, count + 1, pos_x, pos_y + 1);
	visited[pos_y + 1][pos_x] = false;

	cout << result << '\n';
}
