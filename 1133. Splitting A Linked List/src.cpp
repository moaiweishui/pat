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

    int first_addr;
    cin >> first_addr;

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(100000, make_pair(0, 0));

    int addr, val, next_addr;

    for (int i = 0; i < n; i++)
    {
        cin >> addr >> val >> next_addr;

        vec[addr] = make_pair(val, next_addr);
    }

    vector<int> res;
    
    int p = first_addr;
    int v;

    while (p != -1)
    {
        v = vec[p].first;
        if (v < 0)
        {
            res.push_back(p);
        }
        p = vec[p].second;
    }

    p = first_addr;
    while (p != -1)
    {
        v = vec[p].first;
        if (v >= 0 && v <= k)
        {
            res.push_back(p);
        }
        p = vec[p].second;
    }

    p = first_addr;
    while (p != -1)
    {
        v = vec[p].first;
        if (v > k)
        {
            res.push_back(p);
        }
        p = vec[p].second;
    }
    
    for (int i = 0; i < res.size(); i++)
    {
        if (i == 0)
            printf("%05d %d ", res[i], vec[res[i]].first);
        else
            printf("%05d\n%05d %d ", res[i], res[i], vec[res[i]].first);
       
        if (i == res.size() - 1)
        {
            printf("-1\n");
            return 0;
        }
    }

    return 0;
}
