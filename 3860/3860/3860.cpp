#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef long long ll;
const ll INF = 9999987654321;

struct hole {
    int x1;
    int x2;
    int y1;
    int y2;
    int time;
};

int w, h;
int g, e;

int field[30][30];
hole hole_list[1000];
ll vp[30][30];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };

vector<string> answer;

int main()
{
    
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;

        cin >> g;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                vp[i][j] = INF;
                field[i][j] = 0;
            }

        int temp1, temp2;
        for (int i = 1; i <= g; i++)
        {
            cin >> temp1 >> temp2;
            field[temp2][temp1] = -1;
        }

        cin >> e;

        for (int i = 1; i <= e; i++)
        {
            hole temp;
            cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2 >> temp.time;
            hole_list[i] = temp;
            field[temp.y1][temp.x1] = 1;
        }


        vp[0][0] = 0;
        for (int i = 1; i < w * h; i++)
        {
            for (int j = 0; j < h; j++)
                for (int k = 0; k < w; k++)
                    if (vp[j][k] < INF && !(j == h - 1 && k == w - 1) && field[j][k] == 0)
                        for (int l = 0; l < 4; l++)
                            if (j + d_y[l] >= 0 && j + d_y[l] < h &&
                                k + d_x[l] >= 0 && k + d_x[l] < w &&
                                field[j + d_y[l]][k + d_x[l]] != -1 &&
                                vp[j][k] + 1 < vp[j + d_y[l]][k + d_x[l]])
                            {
                                vp[j + d_y[l]][k + d_x[l]] = vp[j][k] + 1;
                            }

            for (int j = 1; j <= e; j++)
                if (vp[hole_list[j].y1][hole_list[j].x1] < INF)
                    if (vp[hole_list[j].y1][hole_list[j].x1] + hole_list[j].time
                        < vp[hole_list[j].y2][hole_list[j].x2])
                    {
                        vp[hole_list[j].y2][hole_list[j].x2] =
                            vp[hole_list[j].y1][hole_list[j].x1] + hole_list[j].time;
                    }
        }

        bool flag = false;

        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
                if (vp[j][k] < INF && !(j == h - 1 && k == w - 1) && field[j][k] == 0)
                    for (int l = 0; l < 4; l++)
                        if (j + d_y[l] >= 0 && j + d_y[l] < h &&
                            k + d_x[l] >= 0 && k + d_x[l] < w &&
                            field[j + d_y[l]][k + d_x[l]] != -1 &&
                            vp[j][k] + 1 < vp[j + d_y[l]][k + d_x[l]])
                        {
                            flag = true;
                        }

        for (int j = 1; j <= e; j++)
            if (vp[hole_list[j].y1][hole_list[j].x1] < INF)
                if (vp[hole_list[j].y1][hole_list[j].x1] + hole_list[j].time
                    < vp[hole_list[j].y2][hole_list[j].x2])
                {
                    flag = true;
                    break;
                }

        if (flag)
            answer.push_back("Never");
        else
        {
            if (vp[h - 1][w - 1] == INF)
            {
                answer.push_back("Impossible");
                continue;
            }
            answer.push_back(to_string(vp[h - 1][w - 1]));
        }
            

    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}
