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

long long getMinRadix(string s)
{
    char c;
    long long min_radix = 0;
    long long tmp;
    for (int i = 0; i < s.length(); i++)
    {
        c = s[i];       
        if (c >= '0' && c <= '9')
            tmp = c - '0' + 1;
        else if (c >= 'a' && c <= 'z')
            tmp = c - 'a' + 11;

        if (tmp > min_radix)
            min_radix = tmp;
    }
    return min_radix;
}

long long convert(string s, long long radix)
{
    long long res = 0;
    char c;
    long long e = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        c = s[i];

        if (c >= '0' && c <= '9')
        {
            res += (c - '0') * e;
        }
        else if (c >= 'a' && c <= 'z')
        {
            res += (c - 'a' + 10) * e;
        }
        e *= radix;
    }
    return res;
}

int main()
{
    string N1, N2;
    int tag;
    long long radix;
    cin >> N1 >> N2 >> tag >> radix;

    string s1, s2;
    if (tag == 1)
    {
        s1 = N1;
        s2 = N2;
    }
    else
    {
        s1 = N2;
        s2 = N1;
    }

    if (s1 == "1" && s2 == "1")
    {
        cout << 2 << endl;
        return 0;
    }
    else if (s1 == s2)
    {
        cout << radix << endl;
        return 0;
    }

    long long num1, num2;

    num1 = convert(s1, radix);

    long long min_radix = getMinRadix(s2);
    long long max_radix = min_radix;

    if (convert(s2, max_radix) > num1)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    while (convert(s2, max_radix) < num1)
    {
        max_radix *= 2;
    }

    if (convert(s2, max_radix) == num1)
        cout << max_radix << endl;
    else
    {
        long long p = max_radix / 2;
        long long q = max_radix;
        long long mid;
        long long buf;

        while (p <= q)
        {
            mid = (p + q) / 2;
            buf = convert(s2, mid);
            if (buf == num1)
            {
                cout << mid << endl;
                return 0;
            }
            else if (buf > num1)
            {
                q = mid - 1;
            }
            else if (buf < num1)
            {
                p = mid + 1;
            }
                
        }

        cout << "Impossible" << endl;
    }

    return 0;
}
