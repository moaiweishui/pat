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
    ios::sync_with_stdio(false);

    vector<double> res(1001, 0);

    int k;
    
    int exp;
    double cof;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> exp >> cof;
        res[exp] += cof;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> exp >> cof;
        res[exp] += cof;
    }
    int cnt = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (res[i] != 0)
            cnt++;
    }

    cout << cnt;
    for (int i = 1000; i >= 0; i--)
    {
        if (res[i] != 0)
            printf(" %d %.1f", i, res[i]);
    }

    return 0;
}
