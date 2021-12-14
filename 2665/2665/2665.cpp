#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
int n;
int map[51][51];
int cnt[51][51];
int d_y[4] = { 0, 0, 1, -1 };
int d_x[4] = { 1, -1, 0, 0 };

struct p {
	int y;
	int x;
	int cost;
	p(int y, int x, int cost) : y(y), x(x), cost(cost) {}

	bool operator<(const p b)const {
		return cost > b.cost;
	}
};

priority_queue<p> pq;

int main()
{
	cin >> n;

	memset(cnt, 0x3f, sizeof(int) * 51 * 51);

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	cnt[0][0] = 0;
	pq.push(p(0, 0, 0));

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		if (now.cost > cnt[now.y][now.x])
			continue;

		if (now.y == n - 1 && now.x == n - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (now.y + d_y[i] >= 0 && now.y + d_y[i] < n &&
				now.x + d_x[i] >= 0 && now.x + d_x[i] < n) {
				if (map[now.y + d_y[i]][now.x + d_x[i]] == 1 && cnt[now.y + d_y[i]][now.x + d_x[i]] > now.cost) {
					cnt[now.y + d_y[i]][now.x + d_x[i]] = now.cost;
					pq.push(p(now.y + d_y[i], now.x + d_x[i], now.cost));
				}
				else if (map[now.y + d_y[i]][now.x + d_x[i]] == 0 && cnt[now.y + d_y[i]][now.x + d_x[i]] > now.cost + 1) {
					cnt[now.y + d_y[i]][now.x + d_x[i]] = now.cost + 1;
					pq.push(p(now.y + d_y[i], now.x + d_x[i], now.cost + 1));
				}
			}
		}
	}

	cout << cnt[n - 1][n - 1] << '\n';
	return 0;
}