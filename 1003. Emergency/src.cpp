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

#define MAX_SIZE 500

void DFS(vector<vector<int>>& matrix, vector<vector<int>>& vec, vector<int>& team_num_list,
    int node, int target, 
    vector<vector<int>>& mem, vector<int>& path, vector<int>& team, vector<bool>& vis, int length, int team_num, int& min_len)
{
    if (node == target && length <= min_len)
    {
        if (length < min_len)
        {
            min_len = length;
            mem.clear();
            team.clear();
            mem.push_back(path);
            team.push_back(team_num);
        }
        else if (length == min_len)
        {
            mem.push_back(path);
            team.push_back(team_num);
        }
      
        return;
    }
    int next_node;
    for (int i = 0; i < vec[node].size(); i++)
    {
        next_node = vec[node][i];
        if (vis[next_node] == false)
        {
            path.push_back(next_node);
            length += matrix[node][next_node];
            team_num += team_num_list[next_node];
            vis[next_node] = true;
            DFS(matrix, vec, team_num_list, next_node, target, mem, path, team, vis, length, team_num, min_len);
            vis[next_node] = false;
            team_num -= team_num_list[next_node];
            length -= matrix[node][next_node];
            path.pop_back();
        }
    }

}

int getMaxNumOfTeam(vector<int> vec)
{
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}

int main() {
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;

    vector<int> team_num_list(N, 0);
    int buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        team_num_list[i] = buf;
    }

    vector<vector<int>> matrix(MAX_SIZE, vector<int>(MAX_SIZE, -1));
    vector<vector<int>> vec(MAX_SIZE);
    int node1, node2, len;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &node1, &node2, &len);

        matrix[node1][node2] = len;
        matrix[node2][node1] = len;

        vec[node1].push_back(node2);
        vec[node2].push_back(node1);
    }

    vector<vector<int>> mem;
    vector<int> team;
    vector<int> path;
    vector<bool> vis(N, false);

    vis[C1] = true;
    int length = 0;
    int min_len = INT_MAX;
    int team_num = team_num_list[C1];

    DFS(matrix, vec, team_num_list, C1, C2, mem, path, team, vis, length, team_num, min_len);

    team_num = getMaxNumOfTeam(team);

    printf("%d %d\n", mem.size(), team_num);

    return 0;
}
