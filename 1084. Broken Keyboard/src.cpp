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
    string input_s, output_s;
    cin >> input_s >> output_s;

    vector<bool> keyStatus(127, false);

    vector<char> res;

    for (int i = 0; i < output_s.length(); i++)
        keyStatus[output_s[i]] = true;

    for (int i = 0; i < input_s.length(); i++)
    {
        if (keyStatus[input_s[i]] == false)
        {
            char c = input_s[i];
            if (c >= 'a' && c <= 'z')
            {
                c -= 32;
            }

            auto it = find(res.begin(), res.end(), c);
            if (it == res.end())
            {
                res.push_back(c);
            }

        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i];

    return 0;
}
