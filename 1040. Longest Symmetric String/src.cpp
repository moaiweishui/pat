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

int main()
{
 
    char buffer[1001];

    cin.getline(buffer, 1001);
    string s;
    s = buffer;

    int len = s.length();
    vector<vector<bool>> P(len, vector<bool>(len, false));

    for (int i = 0; i < len; i++)
        P[i][i] = true;

    int p, q;

    int max_len = 1;

    for (int i = 0; i < len; i++)
    {
        p = 0;
        q = i;
        while (p < len && q < len)
        {
            if (i == 0)
                P[p][q] = true;
            else if (i == 1)
            {
                if (s[p] == s[q])
                {
                    P[p][q] = true;
                    max_len = 2;
                }
            }
            else
            {
                if (P[p + 1][q - 1] && s[p] == s[q])
                {
                    P[p][q] = true;
                    if (q - p + 1 > max_len)
                        max_len = q - p + 1;
                }
            }
            p++;
            q++;
        }
    }

    cout << max_len;

    return 0;
}
