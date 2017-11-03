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

#define MAX_SIZE 201

vector<pair<string, int>> city_info;
unordered_map<string, pair<int, int>> city_hmap;

vector<vector<int>> matrix(MAX_SIZE, vector<int>(MAX_SIZE, -1));
vector<vector<int>> city_list(MAX_SIZE, vector<int>());

void DFS(int node, int target, int cost, int& min_cost,
    vector<vector<int>>& mem, vector<int>& path, vector<bool>& vis)
{
    if (cost > min_cost)
        return;

    if (node == target)
    {
        if (cost < min_cost)
        {
            min_cost = cost;
            mem.clear();
            mem.push_back(path);
        }
        else if (cost == min_cost)
        {
            mem.push_back(path);
        }

        return;
    }

    int next_city_id;
    for (int i = 0; i < city_list[node].size(); i++)
    {
        next_city_id = city_list[node][i];
        if (vis[next_city_id] == false)
        {
            vis[next_city_id] = true;
            path.push_back(next_city_id);
            cost += matrix[node][next_city_id];

            DFS(next_city_id, target, cost, min_cost, mem, path, vis);

            cost -= matrix[node][next_city_id];
            path.pop_back();
            vis[next_city_id] = false;
        }
    }
}

int main() {
    int N, K;
    string start_city;
    cin >> N >> K >> start_city;

    city_info.push_back(make_pair(start_city, 0));
    city_hmap[start_city] = make_pair(0, 0);

    char city_name[4];
    int happiness;
    for (int i = 1; i < N; i++)
    {
        scanf("%s %d", city_name, &happiness);
        city_info.push_back(make_pair(city_name, happiness));
        city_hmap[city_name] = make_pair(i, happiness);
    }

    char city1[4], city2[4];
    int city_id_1, city_id_2;
    int cost;
    for (int i = 0; i < K; i++)
    {
        scanf("%s %s %d", city1, city2, &cost);
        city_id_1 = city_hmap[city1].first;
        city_id_2 = city_hmap[city2].first;
        
        matrix[city_id_1][city_id_2] = cost;
        matrix[city_id_2][city_id_1] = cost;

        city_list[city_id_1].push_back(city_id_2);
        city_list[city_id_2].push_back(city_id_1);
    }

    vector<vector<int>> mem;
    vector<int> path;
    vector<bool> vis(MAX_SIZE, false);

    int start_id = 0;
    int end_id = city_hmap["ROM"].first;

    vis[start_id] = true;
    cost = 0;
    int min_cost = INT_MAX;

    DFS(start_id, end_id, cost, min_cost, mem, path, vis);

    int sum;
    double avg;
    
    int path_index = -1;
    int max_happiness = -1;
    double max_avg;

    for (int i = 0; i < mem.size(); i++)
    {
        sum = 0;
        for (int j = 0; j < mem[i].size(); j++)
            sum += city_info[mem[i][j]].second;
        avg = sum / mem[i].size();

        if (sum > max_happiness
            || (sum == max_happiness && avg > max_avg))
        {
            max_happiness = sum;
            path_index = i;
            max_avg = avg;
        }
    }

    printf("%d %d %d %d\n", mem.size(), min_cost, max_happiness, (int)max_avg);
    printf("%s", start_city.c_str());
    for (int i = 0; i < mem[path_index].size(); i++)
        printf("->%s", city_info[mem[path_index][i]].first.c_str());

    return 0;
}
