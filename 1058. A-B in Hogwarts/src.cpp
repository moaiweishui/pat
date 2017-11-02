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

int main() {

    string a, b;
    cin >> a >> b;

    int pos1 = a.find('.');
    int pos2 = a.find('.', pos1 + 1);
    long long a_g = convert(a.substr(0, pos1));
    long long a_s = convert(a.substr(pos1 + 1, pos2 - pos1 - 1));
    long long a_k = convert(a.substr(pos2 + 1, a.length() - pos2 + 1));

    pos1 = b.find('.');
    pos2 = b.find('.', pos1 + 1);
    long long b_g = convert(b.substr(0, pos1));
    long long b_s = convert(b.substr(pos1 + 1, pos2 - pos1 - 1));
    long long b_k = convert(b.substr(pos2 + 1, b.length() - pos2 + 1));

    long long c = 0;

    long long res_k = a_k + b_k;
    if (res_k >= 29)
    {
        res_k = res_k % 29;
        c = 1;
    }

    long long res_s = a_s + b_s + c;
    if (res_s >= 17)
    {
        res_s = res_s % 17;
        c = 1;
    }
    else
        c = 0;

    long long res_g = a_g + b_g + c;
    
    cout << res_g << '.' << res_s << '.' << res_k << endl;

    return 0;
}
