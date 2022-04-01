#include <iostream>
#include <queue>

using namespace std;

struct point {
    int h;
    int x;
    int y;
};

int m, n, h;
int tomato[102][102][102];
int cnt = 0;
int d_h[6] = { 0, 0, 0, 0, 1, -1 };
int d_x[6] = { 0, 0, 1, -1, 0, 0 };
int d_y[6] = { 1, -1, 0, 0, 0, 0 };
int day = 0;
queue<point> que;

int main()
{
    cin >> n >> m >> h;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    point p;
                    p.h = i;
                    p.x = j;
                    p.y = k;
                    que.push(p);
                    cnt++;
                }
                else if (tomato[i][j][k] == -1)
                    cnt++;
                    
            }
        }
    }

    while (!que.empty()) {
        point now = que.front();
        que.pop();

        for (int i = 0; i < 6; i++) {
            if (now.h + d_h[i] > 0 && now.x + d_x[i] > 0 && now.y + d_y[i] > 0 &&
                now.h + d_h[i] <= h && now.x + d_x[i] <= m && now.y + d_y[i] <= n &&
                tomato[now.h + d_h[i]][now.x + d_x[i]][now.y + d_y[i]] == 0)
            {
                point p;
                p.h = now.h + d_h[i];
                p.x = now.x + d_x[i];
                p.y = now.y + d_y[i];
                que.push(p);
                cnt++;
                day = tomato[now.h][now.x][now.y];
                tomato[now.h + d_h[i]][now.x + d_x[i]][now.y + d_y[i]] = day + 1;
            }
        }
    }

    if (cnt < h * m * n) {
        cout << "-1" << '\n';
    }
    else {
        cout << day << '\n';
    }
    return 0;

}