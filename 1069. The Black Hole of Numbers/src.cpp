#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <sstream>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string fillWidth(string s)
{
    if (s.length() == 4)
        return s;
    else
    {
        int cnt = 4 - s.length();
        string res = "";
        while (cnt)
        {
            res += "0";
            cnt--;
        }
        return res + s;
    }
}

string sub(string a, string b)
{
    int c = 0;
    string res = "0000";
    for (int i = 3; i >= 0; i--)
    {
        if (a[i] - c >= b[i])
        {
            res[i] = a[i] - c - b[i] + '0';
            c = 0;
        }
        else
        {
            res[i] = a[i] - c + 10 - b[i] + '0';
            c = 1;
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    s = fillWidth(s);


    if (s[0] == s[1]
        && s[0] == s[2]
        && s[0] == s[3])
    {
        printf("%s - %s = 0000\n", s.c_str(), s.c_str());
        return 0;
    }

    string a = s;
    string b = s;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    string new_s = sub(a, b);

    while (new_s != "6174")
    {
        printf("%s - %s = %s\n", a.c_str(), b.c_str(), new_s.c_str());
        s = new_s;
        a = s;
        b = s;
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        new_s = sub(a, b);
    }

    printf("%s - %s = %s\n", a.c_str(), b.c_str(), new_s.c_str());

    return 0;
}
