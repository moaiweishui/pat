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
    int N, M, start, end;
    cin >> N >> M >> start >> end;

    vector<vector<long>> dis_matrix(500, vector<long>(500, INT_MAX));
    vector<vector<long>> cost_matrix(500, vector<long>(500, INT_MAX));

    int node1, node2, dist, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> node1 >> node2 >> dist >> cost;
        dis_matrix[node1][node2] = dist;
        dis_matrix[node2][node1] = dist;
        cost_matrix[node1][node2] = cost;
        cost_matrix[node2][node1] = cost;       
    }

    vector<long> dis(500, 0);
    vector<long> cos(500, 0);
    vector<int> prev(500, 0);

    unordered_set<int> S_set;
    unordered_set<int> T_set;
    S_set.insert(start);

    for (int i = 0; i < N; i++)
    {
        if (i != start)
        {
            T_set.insert(i);
            dis[i] = dis_matrix[i][start];
            cos[i] = cost_matrix[i][start];
            if (dis_matrix[i][start] == INT_MAX)
                prev[i] = -1;
            else
                prev[i] = start;
        }
    }

    while (!T_set.empty())
    {
        int shortest_node;
        int shortest_dis = INT_MAX;
        int lowest_cost = INT_MAX;

        for (auto it = T_set.begin(); it != T_set.end(); it++)
        {
            if (dis[(*it)] < shortest_dis || (dis[(*it)] == shortest_dis && cos[(*it)] < lowest_cost))
            {
                shortest_node = (*it);
                shortest_dis = dis[shortest_node];
                lowest_cost = cos[shortest_node];
            }
        }

        S_set.insert(shortest_node);
        auto findit = T_set.find(shortest_node);
        T_set.erase(findit);

        for (auto it = T_set.begin(); it != T_set.end(); it++)
        {
            int curr_node = (*it);
            if (dis_matrix[curr_node][shortest_node] != INT_MAX)
            {
                if (dis_matrix[curr_node][shortest_node] + shortest_dis < dis[curr_node])
                {
                    dis[curr_node] = dis_matrix[curr_node][shortest_node] + shortest_dis;
                    cos[curr_node] = cost_matrix[curr_node][shortest_node] + lowest_cost;

                    prev[curr_node] = shortest_node;
                }
                else if (dis_matrix[curr_node][shortest_node] + shortest_dis == dis[curr_node]
                    && cost_matrix[curr_node][shortest_node] + lowest_cost < cos[curr_node])
                {
                    dis[curr_node] = dis_matrix[curr_node][shortest_node] + shortest_dis;
                    cos[curr_node] = cost_matrix[curr_node][shortest_node] + lowest_cost;

                    prev[curr_node] = shortest_node;
                }
            }
        }

    }

    vector<int> path;
    int pt = end;
    while (pt != start)
    {
        path.push_back(pt);
        pt = prev[pt];
    }
    path.push_back(start);

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';

    cout << dis[end] << ' ' << cos[end];


    return 0;
}
