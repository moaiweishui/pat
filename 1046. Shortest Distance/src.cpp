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

    vector<int> dist;

    int buf;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        dist.push_back(sum);
        sum += buf;  
    }

    int M;
    cin >> M;

    vector<int> res;

    int p, q, tmp;
    int min_dist;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &p, &q);
        if (q < p)
        {
            tmp = p;
            p = q;
            q = tmp;
        }

        min_dist = dist[q - 1] - dist[p - 1];
        res.push_back(min(min_dist, sum - min_dist));
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}
