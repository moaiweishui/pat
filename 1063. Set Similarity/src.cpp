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

int main()
{
    int N;
    cin >> N;
    vector<set<int>> vec;
    int M;
    long buf;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        set<int> _set;
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &buf);
            _set.insert(buf);
        }
        vec.push_back(_set);
    }

    int K;
    cin >> K;
    
    int s1, s2;
    int nc, nt;
    for (int i = 0; i < K; i++)
    {
        set<int> inter;
        cin >> s1 >> s2;
        set_intersection(vec[s1 - 1].begin(), vec[s1 - 1].end(), vec[s2 - 1].begin(), vec[s2 - 1].end(),
            inserter(inter, inter.begin()));
        nc = inter.size();
        nt = vec[s1 - 1].size() + vec[s2 - 1].size() - nc;
        printf("%.1lf%%\n", 100.0*nc/nt);
    }



    return 0;
}
