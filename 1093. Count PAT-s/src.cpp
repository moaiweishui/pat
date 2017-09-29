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
    string s;
    cin >> s;

    int n = s.length();

    vector<long long> T(n, 0);
    vector<long long> AT(n, 0);
    vector<long long> PAT(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            T[i] = (s[i] == 'T') ? 1 : 0;
        else
        {
            T[i] = (s[i] == 'T') ? T[i + 1] + 1 : T[i + 1];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'A')
        {
            AT[i] = AT[i + 1] + T[i + 1];
        }
        else
        {
            AT[i] = AT[i + 1];
        }
    }

    for (int i = n - 3; i >= 0; i--)
    {
        if (s[i] == 'P')
        {
            PAT[i] = PAT[i + 1] + AT[i + 1];
        }
        else
        {
            PAT[i] = PAT[i + 1];
        }
    }

    cout << PAT[0] % 1000000007 << endl;
    return 0;
}
