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
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int N;
    cin >> N;
    string buf;

    vector<vector<string>> vec(10, vector<string>());
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        vec[buf[0] - '0'].push_back(buf);
    }

    string res = "";

    for (int i = 0; i < 10; i++)
    {
        sort(vec[i].begin(), vec[i].end(), cmp);
        for (int j = 0; j < vec[i].size(); j++)
            res += vec[i][j];
    }

    int pos = -1;

    for (int i = 0; i < res.size(); i++)
    { 
        if (res[i] != '0')
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << 0 << endl;
    else
    {
        for (int i = pos; i < res.size(); i++)
            cout << res[i];

        cout << endl;
    }


    return 0;
}
