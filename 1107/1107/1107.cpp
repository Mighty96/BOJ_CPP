#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;
bool button[10];
int length;
int result;
int channel;

int number(int num)
{
    int cnt = 1;
    while (num >= 10)
    {
        num /= 10;
        cnt++;
    }

    return cnt;
}
void dfs(int ch, int cnt)
{
    result = (result < abs(ch - channel) + number(ch)) ? result : (abs(ch - channel) + number(ch));

    if (cnt == 6)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
        if (button[i])
            dfs(ch + i * (int)pow(10, cnt), cnt + 1);

    return;
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    
    cin >> channel;
    length = number(channel);
    int num;
    cin >> num;

    int temp;
    memset(&button[0], true, sizeof(button));
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        button[temp] = false;
    }

    result = abs(channel - 100);
    for (int i = 0; i < 10; i++)
        if (button[i])
            dfs(i, 1);

    cout << result << '\n';
    
    return 0;
}