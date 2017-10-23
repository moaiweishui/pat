#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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

int main()
{
    string s;
    cin >> s;

    string inte_p = s.substr(1, 1);

    int pos = s.find('E');
    string frac_p = s.substr(3, pos - 3);
    string exp_p = s.substr(pos + 1, s.length() - pos + 1);

    int exp;
    stringstream ss;
    ss << exp_p;
    ss >> exp;
    string res;
    if (exp < 0)
    {
        int cnt = -exp - 1;
        res = "0.";
        while (cnt)
        {
            res += '0';
            cnt--;
        }
        res += inte_p;
        res += frac_p;
        if (s[0] == '-')
            res = '-' + res;
    }
    else
    {
        if (exp >= frac_p.length())
        {
            int cnt = exp - frac_p.length();
            res = "";
            res += inte_p;
            res += frac_p;
            while (cnt)
            {
                res += '0';
                cnt--;
            }
        }
        else
        {
            res = "";
            res += inte_p;
            int cnt = exp;
            int p = 0;
            while (cnt)
            {
                res += frac_p[p];
                cnt--;
                p++;
            }
            res += '.';
            for (int i = p; i < frac_p.size(); i++)
                res += frac_p[i];
        }
        if (s[0] == '-')
            res = '-' + res;
    }

    cout << res << endl;

    return 0;
}
