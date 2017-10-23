#define _CRT_SECURE_NO_DEPRECATE
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
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    int root, N, K;
    cin >> root >> N >> K;

    vector<pair<int, int>> link_list(100000, make_pair(0, -1));
    int addr, key, next;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &addr, &key, &next);
        link_list[addr] = make_pair(key, next);
    }
    
    vector<pair<int, int>> vec;
    int p = root;
    while (p != -1)
    {
        vec.push_back(make_pair(p, link_list[p].first));
        p = link_list[p].second;
    }

    int cnt = vec.size() / K;
    int pos = 0;
    while (cnt)
    {
        reverse(vec.begin() + pos, vec.begin() + pos + K);
        pos += K;
        cnt--;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0)
            printf("%05d %d ", vec[i].first, vec[i].second);
        else
            printf("%05d\n%05d %d ", vec[i].first, vec[i].first, vec[i].second);
    }
    printf("-1\n");
    return 0;
}
