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

bool valid1(char c)
{
    if (c >= 'A' && c <= 'N')
        return true;
    else if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool valid2(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    else if (c >= 'a' && c <= 'z')
        return true;
    else
        return false;
}

string getDay(int day)
{
    string res = "";
    switch (day)
    {
    case 1:res = "MON"; break;
    case 2:res = "TUE"; break;
    case 3:res = "WED"; break;
    case 4:res = "THU"; break;
    case 5:res = "FRI"; break;
    case 6:res = "SAT"; break;
    case 7:res = "SUN"; break;
    default:break;
    }

    return res;
}

int main()
{
    string s1, s2, s3, s4;

    cin >> s1 >> s2 >> s3 >> s4;
    int day;
    int hh, mm;
    int i;
    for (i = 0; i < s1.length() && i < s2.length(); i++)
    {
        if (s1[i] == s2[i] 
            && (s1[i] >= 'A' && s1[i] <= 'G'))
        {
            day = s1[i] - 'A' + 1;
            break;
        }
    }

    for (int j = i + 1; j < s1.length() && j < s2.length(); j++)
    {
        if (s1[j] == s2[j] && valid1(s1[j]))
        {
            if (s1[j] >= 'A' && s1[j] <= 'N')
                hh = s1[j] - 'A' + 10;
            else
                hh = s1[j] - '0';
            break;
        }
    }
    
    for (int j = 0; j < s3.length() && j < s4.length(); j++)
    {
        if (s3[j] == s4[j] && valid2(s3[j]))
        {
            mm = j;
            break;
        }
    }

    printf("%s %02d:%02d\n", getDay(day).c_str(), hh, mm);

    return 0;
}
