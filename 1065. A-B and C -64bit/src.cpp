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

string getSumPP(string a, string b)
{
    int c = 0;
    string sum = "";
    int ap = a.size() - 1;
    int bp = b.size() - 1;
    int s;
    while (ap >= 0 && bp >= 0)
    {
        s = a[ap] - '0' + b[bp] - '0' + c;
        if (s >= 10)
        {
            s = s % 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        sum += s + '0';
        ap--;
        bp--;
    }
    if (ap < 0 && bp < 0)
    {
        if (c)
            sum += '1';
    }
    else if (ap < 0)
    {
        while (bp >= 0)
        {
            s = b[bp] - '0' + c;
            if (s >= 10)
            {
                s = s % 10;
                c = 1;
            }
            else
            {
                c = 0;
            }
            sum += s + '0';
            bp--;
        }
        if (c)
            sum += '1';
    }
    else if (bp < 0)
    {
        while (ap >= 0)
        {
            s = a[ap] - '0' + c;
            if (s >= 10)
            {
                s = s % 10;
                c = 1;
            }
            else
            {
                c = 0;
            }
            sum += s + '0';
            ap--;
        }
        if (c)
            sum += '1';
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

string getSubPP(string a, string b)
{
    int c = 0;

    int ap = a.length() - 1;
    int bp = b.length() - 1;
    int s;
    string sub = "";
    while (ap >= 0 && bp >= 0)
    {
        s = a[ap] - b[bp] - c;
        if (s < 0)
        {
            c = 1;
            s = s + 10;
        }
        else
        {
            c = 0;
        }
        sub += s + '0';
        ap--;
        bp--;
    }
    while (ap >= 0)
    {
        s = a[ap] - '0' - c;
        if (s < 0)
        {
            c = 1;
            s = s + 10;
        }
        else
        {
            c = 0;
        }
        sub += s + '0';
        ap--;
    }
    reverse(sub.begin(), sub.end());
    int i;
    for (i = 0; i < sub.length(); i++)
    {
        if (sub[i] != '0')
        {
            break;
        }
    }
    return sub.substr(i, sub.length() - i);
}

bool cmpPP(string a, string b)
{
    if (a.length() > b.length())
        return true;
    else if (a.length() < b.length())
        return false;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    return false;
}

int main()
{
    int N;
    string a, b, c;
    vector<string> a_vec;
    vector<string> b_vec;
    vector<string> c_vec;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        a_vec.push_back(a);
        b_vec.push_back(b);
        c_vec.push_back(c);
    }
    vector<bool> res;
    string sum;
    for (int i = 0; i < N; i++)
    {
        if (a_vec[i][0] == '-' && b_vec[i][0] == '-')
        {
            a = a_vec[i].substr(1, a_vec[i].size() - 1);
            b = b_vec[i].substr(1, b_vec[i].size() - 1);
            sum = "-";
            sum += getSumPP(a, b);
        }
        else if (a_vec[i][0] == '-' && b_vec[i][0] != '-')
        {
            a = a_vec[i].substr(1, a_vec[i].size() - 1);
            b = b_vec[i];
            if (cmpPP(a, b)) //a > b
            {
                sum = "-";
                sum += getSubPP(a, b);
            }
            else
            {
                sum = getSubPP(b, a);
            }
        }
        else if (a_vec[i][0] != '-' && b_vec[i][0] == '-')
        {
            a = a_vec[i];
            b = b_vec[i].substr(1, b_vec[i].size() - 1);
            if (cmpPP(a, b)) //a > b
            {
                sum = getSubPP(a, b);
            }
            else
            {
                sum = "-";
                sum += getSubPP(b, a);
            }
        }
        else
        {
            sum = getSumPP(a_vec[i], b_vec[i]);
        }
        c = c_vec[i];
        if (sum[0] == '-' && c[0] == '-')
        {
            sum = sum.substr(1, sum.size() - 1);
            c = c.substr(1, c.size() - 1);
            res.push_back(!cmpPP(sum, c));
        }
        else if (sum[0] != '-' && c[0] == '-')
            res.push_back(true);
        else if (sum[0] == '-' && c[0] != '-')
            res.push_back(false);
        else
            res.push_back(cmpPP(sum, c));

    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << "Case #" << i + 1 << ": ";
        if (res[i])
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}
