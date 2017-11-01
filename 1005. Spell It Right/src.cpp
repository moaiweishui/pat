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

long long getSum(string s)
{
    long long res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res += s[i] - '0';
    }
    return res;
}

string convert(long long num)
{
    string res;
    stringstream ss;
    ss << num;
    ss >> res;

    return res;
}

void read(string s)
{
    map<int, string> hmap;
    hmap[0] = "zero";
    hmap[1] = "one";
    hmap[2] = "two";
    hmap[3] = "three";
    hmap[4] = "four";
    hmap[5] = "five";
    hmap[6] = "six";
    hmap[7] = "seven";
    hmap[8] = "eight";
    hmap[9] = "nine";

    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0)
            cout << hmap[s[i] - '0'];
        else
            cout << ' ' << hmap[s[i] - '0'];
    }
    return;
}

int main() {
    string s;
    cin >> s;

    long long d = getSum(s);
    s = convert(d);

    read(s);

    return 0;
}
