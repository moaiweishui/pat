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

long long convert(string s)
{
    long long res;
    stringstream ss;
    ss << s;
    ss >> res;
    return res;
}

long long GCD(long long a, long long b)
{
    long long m = a;
    long long n = b;
    long long c;
    while (b != 0)
    {
        c = a % b;
        if (c == 0)
            break;
        a = b;
        b = c;
    }
    return b;
}

long long LCM(long long a, long long b)
{
    long long m = a;
    long long n = b;
    long long c;
    while (b != 0)
    {
        c = a % b;
        if (c == 0)
            break;
        a = b;
        b = c;
    }
    return m / b * n;
}

int main()
{
    int N;
    cin >> N;

    vector<long long> numerator;
    vector<long long> denominator;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        int pos = s.find('/');
        numerator.push_back(convert(s.substr(0, pos)));
        denominator.push_back(convert(s.substr(pos + 1, s.length() - pos - 1)));
    }

    long long lcm;
    if (N == 1)
    {
        lcm = denominator[0];
    }
    else
    {
        lcm = LCM(denominator[0], denominator[1]);
        for (int i = 2; i < N; i++)
        {
            lcm = LCM(lcm, denominator[i]);
        }
    }
    long long up = 0;
    for (int i = 0; i < N; i++)
    {
        numerator[i] = lcm / denominator[i] * numerator[i];
        up += numerator[i];
    }

    long long gcd = GCD(up, lcm);

    up = up / gcd;
    lcm = lcm / gcd;

    long long integer = up / lcm;
    up = up % lcm;

    if (up == 0)
    {
        printf("%ld", integer);
    }
    else
    {
        if (integer == 0)
        {
            printf("%ld/", up);
            printf("%ld\n", lcm);
        }
        else
        {
            printf("%ld ", integer);
            printf("%ld/", up);
            printf("%ld\n", lcm);
        }
        
    }

    return 0;
}
