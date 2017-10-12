#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool isPalindromic(string num)
{
    int len = num.length() / 2;
    for (int i = 0; i < len; i++)
    {
        if (num[i] != num[num.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

string getSum(string a, string b)
{
    int len = a.length();
    string res;
    int c = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int s = a[i] - '0' + b[i] - '0' + c;
        if (s >= 10)
        {
            s = s % 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        res += s + '0';
    }
    if (c)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    string num;
    int max_step;
    cin >> num >> max_step;

      if (isPalindromic(num))
    {
        cout << num << endl;
        cout << 0 << endl;
        return 0;
    }
  
    int i;
    bool flag = false;
    string rev;
    for (i = 0; i < max_step; i++)
    {
        rev = num;
        reverse(rev.begin(), rev.end());
        num = getSum(num, rev);
        if (isPalindromic(num))
        {
            flag = true;
            break;
        }
    }
    
    if (flag)
    {
        cout << num << endl;
        cout << i + 1 << endl;
    }
    else
    {
        cout << num << endl;
        cout << i << endl;
    }

    return 0;
}
