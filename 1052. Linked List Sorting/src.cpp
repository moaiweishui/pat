#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int N, root;
    cin >> N >> root;

    vector<pair<int, int>> link_list(100000, make_pair(0, -1));

    int addr, key, next;
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &addr, &key, &next);
        if (addr == root)
            flag = true;
        link_list[addr] = make_pair(key, next);        
    }
    if (!flag)
    {
        printf("0 -1\n");
        return 0;
    }

    vector<pair<int, int>> vec;
    int p = root;
    
    while (p != -1)
    {
        addr = p;
        key = link_list[p].first;
        vec.push_back(make_pair(addr, key));
        p = link_list[p].second;
    }

    sort(vec.begin(), vec.end(), cmp);
    
    printf("%d %05d\n", vec.size(), vec[0].first);

    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0)
        {
            printf("%05d %d ", vec[i].first, vec[i].second);
        }
        else
        {
            printf("%05d\n%05d %d ", vec[i].first, vec[i].first, vec[i].second);
        }
    }
    printf("-1\n");

    return 0;
}
