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
    int n, record_num;
    cin >> n >> record_num;

    vector<vector<int>> family(n + 1, vector<int>(0));
    vector<int> level(n + 1, 0);

    for (int i = 0; i < record_num; i++)
    {
        int pid, child_num;
        cin >> pid >> child_num;
        
        int child_id;

        for (int j = 0; j < child_num; j++)
        {
            cin >> child_id;
            family[pid].push_back(child_id);
        }    
    }

    int root = 1;
    level[root] = 1;

    queue<int> q;
    q.push(root);

    vector<int> cnt_vec(n + 1, 0);

    while (!q.empty())
    {
        int curr_id = q.front();
        int curr_level = level[curr_id];
        cnt_vec[level[curr_id]]++;

        for (int i = 0; i < family[curr_id].size(); i++)
        {
            level[family[curr_id][i]] = curr_level + 1;
            q.push(family[curr_id][i]);
        }

        q.pop();
    }

    int max_generation = 0;
    int max = 0;

    for (int i = 1; i <= n; i++)
    {
        if (cnt_vec[i] > max)
        {
            max = cnt_vec[i];
            max_generation = i;
        }
        if (cnt_vec[i] == 0)
            break;
    }

    printf("%d %d", max, max_generation);

    return 0;
}
