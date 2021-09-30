#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;

/*
0: U
1: D
2: F
3: B
4: L
5: R
*/
char cube[6][3][3];
vector<string> answer;

int n;

void my_swap(char &a, char &b, char &c, char &d)
{
    char temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}

void turn(char side, char dir)
{
    char temp;
    int temp_f;

    if (side == 'U')
    {
        temp_f = 0;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[2][0][i], cube[5][0][i], cube[3][0][i], cube[4][0][i]);
        }
        else if (dir == '-')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[2][0][i], cube[4][0][i], cube[3][0][i], cube[5][0][i]);
        }
    }
    else if (side == 'D')
    {
        temp_f = 1;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[2][2][i], cube[4][2][i], cube[3][2][i], cube[5][2][i]);
        }
        else if (dir == '-')
        {

            for (int i = 0; i < 3; i++)
                my_swap(cube[2][2][i], cube[5][2][i], cube[3][2][i], cube[4][2][i]);
        }
    }
    else if (side == 'F')
    {
        temp_f = 2;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][2][i], cube[4][2 - i][2], cube[1][0][2 - i], cube[5][i][0]);
        }
        else if (dir == '-')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][2][i], cube[5][i][0], cube[1][0][2 - i], cube[4][2 - i][2]);
        }
    }
    else if (side == 'B')
    {
        temp_f = 3;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][0][i], cube[5][i][2], cube[1][2][2 - i], cube[4][2 - i][0]);
        }
        else if (dir == '-')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][0][i], cube[4][2 - i][0], cube[1][2][2 - i], cube[5][i][2]);
        }
    }
    else if (side == 'L')
    {
        temp_f = 4;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][i][0], cube[3][2 - i][2], cube[1][i][0], cube[2][i][0]);
        }
        else if (dir == '-')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][i][0], cube[2][i][0], cube[1][i][0], cube[3][2 - i][2]);
        }
    }
    else if (side == 'R')
    {
        temp_f = 5;
        if (dir == '+')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][2 - i][2], cube[2][2 - i][2], cube[1][2 - i][2], cube[3][i][0]);
        }
        else if (dir == '-')
        {
            for (int i = 0; i < 3; i++)
                my_swap(cube[0][2 - i][2], cube[3][i][0], cube[1][2 - i][2], cube[2][2 - i][2]);
        }
    }

    if (dir == '+')
    {
        my_swap(cube[temp_f][0][0], cube[temp_f][2][0], cube[temp_f][2][2], cube[temp_f][0][2]);
        my_swap(cube[temp_f][0][1], cube[temp_f][1][0], cube[temp_f][2][1], cube[temp_f][1][2]);
    }
    else if (dir == '-')
    {
        my_swap(cube[temp_f][0][0], cube[temp_f][0][2], cube[temp_f][2][2], cube[temp_f][2][0]);
        my_swap(cube[temp_f][0][1], cube[temp_f][1][2], cube[temp_f][2][1], cube[temp_f][1][0]);
    }
}

int main()
{
    cin >> T;

    for (int _ = 1; _ <= T; _++)
    {
        cin >> n;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                cube[0][i][j] = 'w';
                cube[1][i][j] = 'y';
                cube[2][i][j] = 'r';
                cube[3][i][j] = 'o';
                cube[4][i][j] = 'g';
                cube[5][i][j] = 'b';
            }

        string command;
        for (int i = 1; i <= n; i++)
        {
            cin >> command;
            turn(command[0], command[1]);
            
        }

        for (int i = 0; i < 3; i++)
        {
            string line = { cube[0][i][0], cube[0][i][1], cube[0][i][2] };
            answer.push_back(line);
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}