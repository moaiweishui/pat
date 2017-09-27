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

int main()
{
    int k;
    cin >> k;

    vector<bool> key_status(128, false); //-1: unchecked 1: normal 2: borken

    string s;
    cin >> s;



    for (int i = 0; i < s.length();)
    {
        if (key_status[s[i]])
        {
            i++;
        }
        else
        {
            int p = 1;
            while (i + p < s.length() && s[i + p] == s[i])
            {
                p++;
            }
            if (p % k != 0)
            {
                key_status[s[i]] = true;
            }
            i += p;
        }
    }

    string res = "";
    string broken_key = "";

    for (int i = 0; i < s.length();)
    {
        if (key_status[s[i]] == 1)
        {
            res += s[i];
            i++;
        }
        else
        {
            res += s[i];

            auto findit = find(broken_key.begin(), broken_key.end(), s[i]);
            if (findit == broken_key.end())
                broken_key.push_back(s[i]);

            i += k;
        }
    }

    cout << broken_key << endl;
    cout << res << endl;


    return 0;
}
