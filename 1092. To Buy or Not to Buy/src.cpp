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
    string s, target;
    cin >> s >> target;

    vector<int> color(128, 0);

    for (int i = 0; i < s.length(); i++)
    {
        color[s[i]]++;
    }

    int cnt = 0;

    for (int i = 0; i < target.length(); i++)
    {
        if (color[target[i]] == 0)
            cnt++;
        else
            color[target[i]]--;
    }

    if (cnt == 0)
    {
        cout << "Yes" << ' ' << s.length() - target.length() << endl;
    }
    else
    {
        cout << "No" << ' ' << cnt << endl;
    }

    return 0;
}
