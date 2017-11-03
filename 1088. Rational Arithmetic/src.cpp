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
//提取分数
pair<long long, long long> parseFraction(string s)
{
    bool potive_flag = true;
    if (s[0] == '-')
    {
        potive_flag = false;
        s = s.substr(1, s.length() - 1);
    }

    int pos = s.find('/');
    string numerator = s.substr(0, pos);
    string denominator = s.substr(pos + 1, s.length() - pos - 1);
    stringstream ss1;
    stringstream ss2;
    ss1 << numerator;
    ss2 << denominator;

    long long x;
    long long y;

    ss1 >> x;
    ss2 >> y;

    if (!potive_flag)
        x = -x;

    return make_pair(x, y);
}
//求最大公约数
long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
//化简
pair<long long, long long> reduceFraction(pair<long long, long long> x)
{
    bool postive_flag = true;
    if (x.first < 0 && x.second >= 0)
    {
        x.first = -x.first;
        postive_flag = false;
    }
    else if (x.first >= 0 && x.second < 0)
    {
        x.second = -x.second;
        postive_flag = false;
    }
    else if (x.first < 0 && x.second < 0)
    {
        x.first = -x.first;
        x.second = -x.second;
    }

    long long gcd = GCD(x.first, x.second);
    if (postive_flag)
        return make_pair(x.first / gcd, x.second / gcd);
    else
        return make_pair(0 - x.first / gcd, x.second / gcd);
}

pair<long long, long long> getSum(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.second + b.first * a.second;
    long long denominator = a.second * b.second;

    return reduceFraction(make_pair(numerator, denominator));
}

pair<long long, long long> getDiff(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.second - b.first * a.second;
    long long denominator = a.second * b.second;

    return reduceFraction(make_pair(numerator, denominator));
}

pair<long long, long long> getProd(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.first;
    long long denominator = a.second * b.second;

    return reduceFraction(make_pair(numerator, denominator));
}

pair<long long, long long> getQuot(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.second;
    long long denominator = a.second * b.first;

    return reduceFraction(make_pair(numerator, denominator));
}
//分离出整数部分，并转化为string
string convert(pair<long long, long long> x)
{
    if (x.first == 0)
        return "0";

    string res = "";
    bool postive_flag = true;

    if (x.first < 0)
    {
        postive_flag = false;
        x.first = -x.first;
    }

    long long k = x.first / x.second;
    long long numerator = x.first % x.second;

    
    
    if (k == 0)
    {
        stringstream numerator_ss, denominator_ss;
        string  numerator_s, denominator_s;
        numerator_ss << numerator;
        numerator_ss >> numerator_s;
        
        denominator_ss << x.second;
        denominator_ss >> denominator_s;
        
        res = numerator_s + '/' + denominator_s;
    }
    else if (numerator == 0)
    {
        stringstream k_ss;
        string k_s;

        k_ss << k;
        k_ss >> k_s;

        res = k_s;
    }
    else
    {
        stringstream k_ss, numerator_ss, denominator_ss;
        string k_s, numerator_s, denominator_s;

        k_ss << k;
        k_ss >> k_s;

        numerator_ss << numerator;
        numerator_ss >> numerator_s;

        denominator_ss << x.second;
        denominator_ss >> denominator_s;

        res = k_s + ' ' + numerator_s + '/' + denominator_s;
    }

    if (!postive_flag)
        res = "(-" + res + ")";

    return res;
}

string display(pair<long long, long long> a, pair<long long, long long> b, 
    pair<long long, long long> res, char op)
{
    string row = convert(a) + ' ' + op + ' ' + convert(b) + " = ";

    if (res.first == 0)
        row += '0';
    else if (res.second == 0)
        row += "Inf";
    else
        row += convert(res);

    return row;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    pair<long long, long long> a = parseFraction(s1);
    pair<long long, long long> b = parseFraction(s2);

    pair<long long, long long> sum = getSum(a, b);
    pair<long long, long long> diff = getDiff(a, b);
    pair<long long, long long> prod = getProd(a, b);
    pair<long long, long long> quot = getQuot(a, b);

    string sum_in_string = display(reduceFraction(a), reduceFraction(b), sum, '+');
    string diff_in_string = display(reduceFraction(a), reduceFraction(b), diff, '-');
    string prod_in_string = display(reduceFraction(a), reduceFraction(b), prod, '*');
    string quot_in_string = display(reduceFraction(a), reduceFraction(b), quot, '/');

    cout << sum_in_string << endl;
    cout << diff_in_string << endl;
    cout << prod_in_string << endl;
    cout << quot_in_string << endl;

    return 0;
}
