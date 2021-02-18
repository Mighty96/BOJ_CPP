#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int main()
{
    cin >> n;

    int resMax1, resMax2, resMax3;
    int resMin1, resMin2, resMin3;
    cin >> resMax1 >> resMax2 >> resMax3;
    resMin1 = resMax1; resMin2 = resMax2; resMin3 = resMax3;

    int temp1, temp2, temp3;
    int tempMax1, tempMax2, tempMax3;
    int tempMin1, tempMin2, tempMin3;
    for (int i = 2; i <= n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        tempMax1 = max(resMax1, resMax2) + temp1;
        tempMax2 = max(max(resMax1, resMax2), resMax3) + temp2;
        tempMax3 = max(resMax2, resMax3) + temp3;
        tempMin1 = min(resMin1, resMin2) + temp1;
        tempMin2 = min(min(resMin1, resMin2), resMin3) + temp2;
        tempMin3 = min(resMin2, resMin3) + temp3;

        resMax1 = tempMax1;
        resMax2 = tempMax2;
        resMax3 = tempMax3;
        resMin1 = tempMin1;
        resMin2 = tempMin2;
        resMin3 = tempMin3;
    }

    cout << max(max(resMax1, resMax2), resMax3) << " " << min(min(resMin1, resMin2), resMin3) << '\n';

    return 0;
    
}