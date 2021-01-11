#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const int mid, const vector<int>& house, const int n, const int c)
{
    int count = 1;
    int position_now = 1;
    int position_next = 1;
    while (position_next < n)
    {
        position_next++;
        if (house[position_next] - house[position_now] >= mid)
        {
            count++;
            position_now = position_next;
        }
    }
    if (count >= c) return true;
    else return false;
}



int main()
{
    int n, c;
    cin >> n >> c;
    cin.clear();

    vector<int> house(1, 0);
    int temp;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        house.push_back(temp);
    }
    
    sort(house.begin(), house.end());

    int front{ 1 };
    int end{ (house[n] - house[1]) / (c - 1) + 1 };
    int mid{ end / 2 };

    if (end == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    while (front + 1 != end)
    {
        if (binary_search(mid, house, n, c))
        {
            front = mid;
            mid = (front + end) / 2;
        }
        else
        {
            end = mid;
            mid = (front + end) / 2;
        }
        
    }

    cout << mid << '\n';

}