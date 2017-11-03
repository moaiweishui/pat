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

string convert(int num, int radix)
{
    string res = "";
    int x = num;
    while (x)
    {
        res = char(x % radix + '0') + res;
        x = x / radix;
    }
    return res;
}

int returnToDec(string s, int radix)
{
    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        res *= radix;
        res += s[i] - '0';
    }
    return res;
}

int reverseNum(int num, int radix)
{
    string s = convert(num, radix);
    reverse(s.begin(), s.end());

    return returnToDec(s, radix);
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    else if (num <= 3)
        return true;

    for (int i = 2; i < sqrt(num) + 1; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {
    int N, D;
    vector<pair<int, int>> vec;

    while (1)
    {
        cin >> N;
        if (N < 0)
            break;

        cin >> D;
        vec.push_back(make_pair(N, D));
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (isPrime(vec[i].first)
            && isPrime(reverseNum(vec[i].first, vec[i].second)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }


    return 0;
}
