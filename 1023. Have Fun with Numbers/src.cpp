#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    vector<int> vec(10, 0);

    string input;
    cin >> input;
    int len = input.length();
    int c = 0;
    int s;
    vector<int> sum;

    for (int i = len - 1; i >= 0; i--)
    {
        vec[input[i] - '0']++;
        s = input[i] - '0' + input[i] - '0' + c;
        if (s >= 10)
        {
            s = s % 10;
            c = 1;
        }
        else
            c = 0;
        sum.push_back(s);
    }

    if (c)
        sum.push_back(1);

    bool flag = true;
    if (sum.size() != len)
        flag = false;

    for (int i = 0; i < sum.size(); i++)
    {
        vec[sum[i]]--;
    }

    for (int i = 0; i < 10; i++)
    {
        if (vec[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    for (int i = sum.size() - 1; i >= 0; i--)
        cout << sum[i];

    return 0;
}
