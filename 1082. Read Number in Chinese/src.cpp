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

unordered_map<int, string> hmap;

string read(string s)
{
    int cnt = 4 - s.length();
    while (cnt)
    {
        s = '0' + s;
        cnt--;
    }

    string unit[4];
    unit[0] = " Qian";
    unit[1] = " Bai";
    unit[2] = " Shi";
    unit[3] = "";

    string res = "";

    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '0')
        {
            if (res.length() >= 5 && res.substr(res.length() - 5, 5) == " ling")
                res += "";
            else
                res += " ling";
        }
        else
        {
            res += " " + hmap[s[i] - '0'] + unit[i];
        }
    }

    //if (res.length() >= 5 && res.substr(0, 5) == " ling")
    //    res = res.substr(5, res.length() - 5);

    if (res.length() >= 5 && res.substr(res.length() - 5, 5) == " ling")
        res = res.substr(0, res.length() - 5);

    return res;
}

int main() {
    string s;
    cin >> s;

    hmap[0] = "ling";
    hmap[1] = "yi";
    hmap[2] = "er";
    hmap[3] = "san";
    hmap[4] = "si";
    hmap[5] = "wu";
    hmap[6] = "liu";
    hmap[7] = "qi";
    hmap[8] = "ba";
    hmap[9] = "jiu";

    if (s[0] == '-')
    {
        cout << "Fu ";
        s = s.substr(1, s.length() - 1);
    }

    if (s.length() == 9)
    {
        cout << hmap[s[0] - '0'] << " Yi";

        string res1 = read(s.substr(1, 4));
        string res2 = read(s.substr(5, 4));

        if (res1 != "" && res2 == "")
            cout << res1 << " Wan";
        else if (res1 == "" && res2 != "")
            cout << res1 << res2;
        else if (res1 != "" && res2 != "")
            cout << res1 << " Wan" << res2;
    }
    else if (s.length() > 4)
    {

        string res1 = read(s.substr(0, s.length() - 4));
        string res2 = read(s.substr(s.length() - 4, 4));

        if (res1.length() >= 5 && res1.substr(0, 5) == " ling")
            res1 = res1.substr(5, res1.length() - 5);

        if (res1[0] == ' ')
            res1 = res1.substr(1, res1.length() - 1);

        if (res2 == "")
            cout << res1 << " Wan";
        else
            cout << res1 << " Wan" << res2;
    }
    else
    {
        string res = read(s);

        if (res == "")
            cout << "ling";
        else
        {
            if (res.length() >= 5 && res.substr(0, 5) == " ling")
                res = res.substr(5, res.length() - 5);

            if (res[0] == ' ')
                res = res.substr(1, res.length() - 1);

            cout << res;
        }
            
    }

    return 0;
}
