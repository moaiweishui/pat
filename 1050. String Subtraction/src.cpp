#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
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

int main()
{
    char s1_buf[10001];
    char s2_buf[10001];
    
    cin.getline(s1_buf, 10001);
    cin.getline(s2_buf, 10001);

    string s1, s2;
    s1 = s1_buf;
    s2 = s2_buf;

    vector<bool> key(127, false);

    for (int i = 0; i < s2.length(); i++)
        key[s2[i]] = true;

    for (int i = 0; i < s1.length(); i++)
    {
        if (key[s1[i]] == false)
            cout << s1[i];
    }

    return 0;
}
