#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string convert(int num)
{
    int x = num;
    string res;
    char c;
    while (x)
    {
        c = x % 10 + '0';
        res = c + res;
        x = x / 10;
    }

    return res;
}

int main() {

    int a, b;
    cin >> a >> b;

    int c = a + b;

    if (c == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int num;
    bool postive = true;
    if (c < 0)
    {
        postive = false;
        num = -c;
    }
    else
    {
        num = c;
    }

    string res = convert(num);

    if (res.length() < 4)
    {
        if (!postive)
            cout << '-';
        cout << res << endl;
    }
    else
    {
        if (!postive)
            cout << '-';
        int len = res.length();
        for (int i = 0; i < len; i++)
        {
            cout << res[i];
           
            if ((len - i) % 3 == 1 && i != res.length() - 1)
                cout << ',';
        }
    }

    return 0;
}
