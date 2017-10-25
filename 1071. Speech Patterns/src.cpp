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

#define MAX_SIZE 1048576

int main() {

    char paragraph[MAX_SIZE + 10];

    cin.getline(paragraph, MAX_SIZE + 5);

    string s = paragraph;

    unordered_map<string, int> hmap;

    string word_buf = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
            word_buf += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
            word_buf += s[i] - 'A' + 'a';
        else
        {
            if (!word_buf.empty())
            {
                hmap[word_buf] += 1;
                word_buf.clear();
            }
        }

    }
      hmap[word_buf] += 1;  
    string res = "";
    int cnt = -1;
    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        if ((*it).second > cnt)
        {
            res = (*it).first;
            cnt = (*it).second;
        }
        else if ((*it).second == cnt && (*it).first < res)
        {
            res = (*it).first;
            cnt = (*it).second;
        }
    }

    cout << res << ' ' << cnt << endl;

    return 0;
}
