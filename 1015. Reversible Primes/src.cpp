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

int reverse(int num)
{
    string s;
    stringstream ss;
    ss << num;
    ss >> s;

    reverse(s.begin(), s.end());
    stringstream res_ss;
    int res;

    res_ss << s;
    res_ss >> res;

    return res;
}

bool isPrime(int num, int radix)
{




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
        if (isPrime(vec[i].first, vec[i].second)
            && isPrime(reverse(vec[i].first), vec[i].second))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }


    return 0;
}
