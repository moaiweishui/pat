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
#include <string.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX_SIZE 10000

vector<set<int>> station_list(MAX_SIZE);
char line_info[MAX_SIZE][MAX_SIZE];  //记录两个站之间线路是几号线

int getTransferCount(vector<int> path)
{
    char last_line_id = -1;
    char curr_line_id;
    int transfer_cnt = 0;
    for (int i = 1; i < path.size(); i++)
    {
        curr_line_id = line_info[path[i - 1]][path[i]];
        if (last_line_id != -1 && curr_line_id != last_line_id)
        {
            transfer_cnt++;
        }
        last_line_id = curr_line_id;
    }
    return transfer_cnt;
}

void DFS(int node, int target, vector<int>& final_path, vector<int>& path, vector<bool>& vis, int& station_cnt, int& min_path_len, int& min_transfer_cnt)
{
    if (node == target)
    {
        int curr_transfer_cnt = getTransferCount(path);
        if (station_cnt < min_path_len)
        {
            min_path_len = station_cnt;
            min_transfer_cnt = curr_transfer_cnt;
            final_path = path;
        }
        else if (station_cnt == min_path_len && curr_transfer_cnt < min_transfer_cnt)
        {
            min_path_len = station_cnt;
            min_transfer_cnt = curr_transfer_cnt;
            final_path = path;
        }
        
        return;
    }

    for (auto it = station_list[node].begin(); it != station_list[node].end(); it++)
    {
        if (vis[*it] == false)
        {
            vis[*it] = true;
            path.push_back(*it);
            station_cnt++;

            DFS(*it, target, final_path, path, vis, station_cnt, min_path_len, min_transfer_cnt);

            station_cnt--;
            path.pop_back();
            vis[*it] = false;
        }
        
    }

    return;
}

void printPath(vector<int> path)
{
    printf("%d\n", path.size() - 1);

    char last_line_id = -1;
    char curr_line_id;

    int start = path[0];

    for (int i = 1; i < path.size(); i++)
    {
        curr_line_id = line_info[path[i - 1]][path[i]];
        if (last_line_id != -1 && curr_line_id != last_line_id)
        {
            printf("Take Line#%d from %04d to %04d.\n", last_line_id, start, path[i - 1]);
            start = path[i - 1];
        }
        last_line_id = curr_line_id;
    }

    printf("Take Line#%d from %04d to %04d.\n", last_line_id, start, path[path.size() - 1]);
    
    return;
}

int main() {
    
    int N, M;
    cin >> N;

    int station_id;
    
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        int last_station_id = -1;
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &station_id);

            if (last_station_id != -1)
            {
                line_info[last_station_id][station_id] = i + 1;
                line_info[station_id][last_station_id] = i + 1;

                station_list[station_id].insert(last_station_id);
                station_list[last_station_id].insert(station_id);
            }
            last_station_id = station_id;
        }
    }

    cin >> M;
    vector<pair<int, int>> query_list;
    int start, end;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &start, &end);
        query_list.push_back(make_pair(start, end));
    }

    for (int i = 0; i < M; i++)
    {
        vector<int> final_path;
        vector<int> path;
        vector<bool> vis(MAX_SIZE, false);

        int station_cnt = 0;
        int min_path_len = INT_MAX;
        int min_transfer_cnt = INT_MAX;

        start = query_list[i].first;
        end = query_list[i].second;

        path.push_back(start);
        DFS(start, end, final_path, path, vis, station_cnt, min_path_len, min_transfer_cnt);
        
        printPath(final_path);
    }

    return 0;
}
