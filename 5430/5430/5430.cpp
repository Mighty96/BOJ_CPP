#include <iostream>
#include <vector>
#include <string>

using namespace std;

string arr[100001];
void ac(vector<string> &result)
{
    string func;
    int length;
    string temp;

    cin >> func;
    cin >> length;
    cin >> temp;

    int cur = 1;
    int next;
    for (int i = 0; i < length - 1; i++)
    {
        next = temp.find(",", cur);
        arr[i] = temp.substr(cur, next - cur);
        cur = next + 1;
    }
    if (length != 0)
    {
        arr[length - 1] = temp.substr(cur, temp.length() - cur - 1);
    }
    int front = 0;
    int back = length - 1;
    bool forward = true;

    for (int i = 0; i < func.length(); i++)
    {
        if (func[i] == 'R')
        {
            forward = !forward;
        }
        if (func[i] == 'D')
        {
            if (back < front)
            {
                result.push_back("error");
                return;
            }
            if (forward)
            {
                front++;
            }
            else
            {
                back--;
            }
        }
    }


    string temp_res = "[";

    if (front <= back)
    {
        if (forward)
        {
            for (int i = front; i < back; i++)
            {
                temp_res += arr[i];
                temp_res += ",";
            }
            temp_res += arr[back];
        }
        else
        {
            for (int i = back; i > front; i--)
            {
                temp_res += arr[i];
                temp_res += ",";
            }
            temp_res += arr[front];
        }
    }
    temp_res += "]";
    result.push_back(temp_res);
    return;
}


int main()
{
    int t;
    vector<string> result;

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;


    for (int i = 0; i < t; i++)
    {
        ac(result);
    }

    for (int i = 0; i < t; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}