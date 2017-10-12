#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int getWidth(int num, int base)
{
    int x = num;
    int cnt = 0;
    while (x)
    {
        x = x / base;
        cnt++;
    }
    return cnt;
}

vector<int> convert(int num, int base)
{
    int w = getWidth(num, base);
    int x = num;
    vector<int> res;
    for (int i = w - 1; i >= 0; i--)
    {
        int cof = pow(base, i);
        res.push_back(x / cof);
        x = x % cof;
    }
    return res;
}

bool isPalindromic(vector<int> num)
{
    int n = num.size() / 2;
    bool res = true;
    for (int i = 0; i < 2; i++)
    {
        if (num[i] != num[num.size() - 1 - i])
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
 
    int num, base;
    cin >> num >> base;

    if (num == 0)
    {
        cout << "Yes" << endl;
        cout << 0 << endl;
        return 0;
    }

    vector<int> res = convert(num, base);

    if (isPalindromic(res))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ' ';
        else
            cout << endl;
    }
   

    return 0;
}
