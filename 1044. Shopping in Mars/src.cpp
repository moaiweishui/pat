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

int binaryFind(vector<int>& dist, int left, int right, int target, vector<int>& pos)
{
    int p = left;
    int q = right;
    int mid;

    while (p < q)
    {
        mid = (p + q) / 2;
        if (dist[mid] == target)
        {
            pos[left] = mid;
            return target;
        }
        else if (dist[mid] > target)
        {
            q = mid;
        }
        else
        {
            p = mid + 1;
        }
    }
    pos[left] = q;

    return dist[q];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> nums;
    int buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        nums.push_back(buf);
    }

    vector<int> dist;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += nums[i];
        dist.push_back(sum);
    }
     
    vector<pair<int, int>> res;
    int min = INT_MAX;
    int tmp;
    vector<int> pos(N, 0);
    int target;
    for (int i = 0; i < N; i++)
    {
        if (dist[N - 1] - dist[i] + nums[i] == M)
        {
            res.clear();
            min = 0;
            res.push_back(make_pair(i, N - 1));
        }
        else if (dist[N - 1] - dist[i] + nums[i] > M)
        {
            target = dist[i] + M - nums[i];
            tmp = binaryFind(dist, i, N - 1, target, pos);
            if (tmp - target < min)
            {
                res.clear();
                min = tmp - target;
                res.push_back(make_pair(i, pos[i]));
            }
            else if (tmp - target == min)
                res.push_back(make_pair(i, pos[i]));
        }       
    }

    for (int i = 0; i < res.size(); i++)
    {
      printf("%d-%d\n", res[i].first + 1, res[i].second + 1);
        //cout << res[i].first + 1 << '-' << res[i].second + 1 << endl;
    }

    return 0;
}
