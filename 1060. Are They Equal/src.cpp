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

string removeLeadZero(string num_str)
{
    while (num_str.length() > 0 && num_str[0] == '0')
        num_str.erase(num_str.begin());
        
    return num_str;
}

string convert(string num_str, int N)
{
    //去除前导零
    num_str = removeLeadZero(num_str);

    int e = 0;//指数

    if (num_str[0] == '.') //整数部分为0
    {
        num_str.erase(num_str.begin()); //去除小数点
        while (num_str.length() > 0 && num_str[0] == '0')
        {
            num_str.erase(num_str.begin());
            e--;
        }
    }
    else
    {
        int dot_pos = num_str.find('.');
        if (dot_pos != -1) //存在小数点
        {
            e += dot_pos;
            num_str.erase(num_str.begin() + dot_pos); //去除小数点
        }
        else
        {
            e += num_str.length();
        }
    }

    if (num_str.length() == 0)
    {
        e = 0;
    }
    string res = "0.";
    int cnt = 0;

    while (cnt < N)
    {
        if (cnt < num_str.length())
            res += num_str[cnt];
        else
            res += '0';
        cnt++;
    }

    stringstream ss;
    ss << e;
    string e_str;
    ss >> e_str;

    res += "*10^" + e_str;

    return res;
}

int main() {

    int N;
    cin >> N;
    string num1, num2;
    cin >> num1 >> num2;

    num1 = convert(num1, N);
    num2 = convert(num2, N);

    if (num1 == num2)
        cout << "YES " << num1 << endl;
    else
        cout << "NO " << num1 << ' ' << num2 << endl;

    return 0;
}
