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

int main() {

    int N, L;
    cin >> N >> L;

    vector<vector<int>> user_fans_list(N + 1);

    int fans_num;
    for (int i = 1; i <= N; i++)
    {
        cin >> fans_num;
        int fans_id;
        for (int j = 0; j < fans_num; j++)
        {
            scanf("%d", &fans_id);
            user_fans_list[fans_id].push_back(i);
        }       
    }

    int query_num;
    vector<int> query_vec;
    int query_buf;
    cin >> query_num;

    for (int i = 0; i < query_num; i++)
    {
        scanf("%d", &query_buf);
        query_vec.push_back(query_buf);
    }

    
    for (int i = 0; i < query_vec.size(); i++)
    {
        vector<bool> vis(N + 1, false);
        set<int> candidate;

        int forwards_cnt = 0;
        candidate.insert(query_vec[i]);
        vis[query_vec[i]] = true;
        int level_cnt = 0;
        while (!candidate.empty())
        {
            set<int> _set;
            for (auto it = candidate.begin(); it != candidate.end(); it++)
            {
                for (int j = 0; j < user_fans_list[*it].size(); j++)
                {
                    if (vis[user_fans_list[*it][j]] == false)
                    {
                        _set.insert(user_fans_list[*it][j]);
                        vis[user_fans_list[*it][j]] = true;
                        forwards_cnt++;
                    }                       
                }
                
            }
            candidate.clear();
            for (auto it = _set.begin(); it != _set.end(); it++)
                candidate.insert(*it);
            level_cnt++;
            if (level_cnt == L)
                break;
        }

        printf("%d\n", forwards_cnt);

    }

    return 0;
}
