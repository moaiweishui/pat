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

bool cmp(pair<int, double> a, pair<int, double> b)
{
    return a.first >= b.first;
}

int main()
{
    ios::sync_with_stdio(false);

    vector<pair<int, double>> poly1;
    vector<pair<int, double>> poly2;

    int k, exp;
    double cof;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> exp;
        cin >> cof;
        poly1.push_back(make_pair(exp, cof));
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> exp;
        cin >> cof;
        poly2.push_back(make_pair(exp, cof));
    }

    unordered_map<int, double> hmap;

    for (int i = 0; i < poly1.size(); i++)
    {
        for (int j = 0; j < poly2.size(); j++)
        {
            exp = poly1[i].first + poly2[j].first;
            cof = poly1[i].second * poly2[j].second;

            auto it = hmap.find(exp);
            if (it != hmap.end())
            {
                (*it).second += cof;
            }
            else
            {
                hmap[exp] = cof;
            }
        }
    }

    

    vector<pair<int, double>> res;

    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        if ((*it).second != 0)
            res.push_back(make_pair((*it).first, (*it).second));
    }

    sort(res.begin(), res.end(), cmp);

    cout << res.size();
    for (int i = 0; i < res.size(); i++)
    {
        printf(" %d %.1f", res[i].first, res[i].second);
    }

    return 0;
}
