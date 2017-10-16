#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length();

    int a, b;
    int max = -1;
    for (int i = 3; i <= len; i++)
    {
        if ((len + 2 - i) % 2 == 0)
        {
            a = (len + 2 - i) / 2;
            if (a <= i && a > max)
            {
                max = a;
            }

        }
    }

    b = len - 2 * max;

    for (int i = 0; i < max - 1; i++)
    {
        cout << s[i];
        for (int j = 0; j < b; j++)
            cout << ' ';
        cout << s[len - 1 - i]<<endl;
    }

    for (int i = max - 1; i < max + b + 1; i++)
        cout << s[i];

    return 0;
}
