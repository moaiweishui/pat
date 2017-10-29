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

int main() {
    int N;
    cin >> N;
    
    char sentence[300];
    vector<string> vec;
    string s_buf;
    int min_len = INT_MAX;

    cin.getline(sentence, 300);

    for (int i = 0; i < N; i++)
    {
        cin.getline(sentence, 300);
        s_buf = sentence;
        reverse(s_buf.begin(), s_buf.end());
        if (s_buf.length() < min_len)
            min_len = s_buf.length();
        vec.push_back(s_buf);

    }

    string res = "";
    bool flag = true;
    for (int i = 0; i < min_len; i++)
    {
        char c = vec[0][i];
        for (int j = 1; j < vec.size(); j++)
        {
            if (vec[j][i] != c)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
        else
            res += c;
    }

    if (res.length())
    {
        reverse(res.begin(), res.end());
        if (res[0] == ' ')
            res = res.substr(1, res.length() - 1);
    }
    else
        res = "nai";

    cout << res << endl;

    return 0;
}
