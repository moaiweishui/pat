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

#define MAX_SIZE 500

int N, M;

vector<vector<int>> matrix_dist(MAX_SIZE, vector<int>(MAX_SIZE, -1));
vector<vector<int>> matrix_time(MAX_SIZE, vector<int>(MAX_SIZE, -1));

int findShortestPath(int start, int end, vector<int>& path)
{
    vector<int> dist(N, -1);
    vector<int> time(N, -1);
    vector<int> pre(N, start);

    set<int> S;
    set<int> T;

    for (int i = 0; i < N; i++)
    {
        if (i != start)
            T.insert(i);

        if (matrix_dist[start][i] != -1)
        {
            dist[i] = matrix_dist[start][i];
            time[i] = matrix_time[start][i];
        }
    }

    S.insert(start);

    while (!T.empty())
    {
        int shortest_node;
        int shortest_dist = INT_MAX;
        int take_time;
        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (dist[*it] != -1 && dist[*it] < shortest_dist)
            {
                shortest_node = *it;
                shortest_dist = dist[*it];
                take_time = time[*it];
            }
        }

        S.insert(shortest_node);
        T.erase(shortest_node);

        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (dist[*it] == -1)
            {
                if (matrix_dist[shortest_node][*it] != -1)
                {
                    dist[*it] = shortest_dist + matrix_dist[shortest_node][*it];
                    time[*it] = take_time + matrix_time[shortest_node][*it];
                    pre[*it] = shortest_node;
                }
            }
            else if (matrix_dist[shortest_node][*it] != -1)
            {
                if (shortest_dist + matrix_dist[shortest_node][*it] < dist[*it])
                {
                    dist[*it] = shortest_dist + matrix_dist[shortest_node][*it];
                    time[*it] = take_time + matrix_time[shortest_node][*it];
                    pre[*it] = shortest_node;
                }
                else if (shortest_dist + matrix_dist[shortest_node][*it] == dist[*it]
                    && take_time + matrix_time[shortest_node][*it] < time[*it])
                {
                    dist[*it] = shortest_dist + matrix_dist[shortest_node][*it];
                    time[*it] = take_time + matrix_time[shortest_node][*it];
                    pre[*it] = shortest_node;
                }
            }
        }

    }

    int p = end;
    while (p != start)
    {
        path.push_back(p);
        p = pre[p];
    }
    path.push_back(p);

    reverse(path.begin(), path.end());

    return dist[end];
}

int findFastestPath(int start, int end, vector<int>& path)
{
    vector<int> time(N, -1);
    vector<int> mid_node_num(N, 0); //从起点到各节点，中间节点（包含最后一个）的数量，即路段的数量
    vector<int> pre(N, start);

    set<int> S;
    set<int> T;

    for (int i = 0; i < N; i++)
    {
        if (i != start)
            T.insert(i);
        if (matrix_time[start][i] != -1)
        {
            time[i] = matrix_time[start][i];
            mid_node_num[i] = 1;
        }
    }

    S.insert(start);

    while (!T.empty())
    {
        int fastest_node;
        int fastest_time = INT_MAX;

        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (time[*it] != -1 && time[*it] < fastest_time)
            {
                fastest_node = *it;
                fastest_time = time[*it];
            }
        }

        S.insert(fastest_node);
        T.erase(fastest_node);

        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (time[*it] == -1)
            {
                if (matrix_time[fastest_node][*it] != -1)
                {
                    time[*it] = fastest_time + matrix_time[fastest_node][*it];
                    pre[*it] = fastest_node;
                    mid_node_num[*it] = 1;
                }
            }
            else if (matrix_time[fastest_node][*it] != -1)
            {
                if (fastest_time + matrix_time[fastest_node][*it] < time[*it])
                {
                    time[*it] = fastest_time + matrix_time[fastest_node][*it];
                    pre[*it] = fastest_node;
                    mid_node_num[*it]++;
                }
                else if (fastest_time + matrix_time[fastest_node][*it] == time[*it]
                    && mid_node_num[fastest_node] + 1 < mid_node_num[*it])
                {
                    time[*it] = fastest_time + matrix_time[fastest_node][*it];
                    pre[*it] = fastest_node;
                    mid_node_num[*it] = mid_node_num[fastest_node] + 1;
                }
            }
        }

    }

    int p = end;
    while (p != start)
    {
        path.push_back(p);
        p = pre[p];
    }
    path.push_back(p);

    reverse(path.begin(), path.end());

    return time[end];

}

int main() {
    
    cin >> N >> M;

    int node1, node2, one_way, dist, time;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d %d", &node1, &node2, &one_way, &dist, &time);

        if (one_way)
        {
            matrix_dist[node1][node2] = dist;
            matrix_time[node1][node2] = time;
        }
        else
        {
            matrix_dist[node1][node2] = dist;
            matrix_dist[node2][node1] = dist;
            matrix_time[node1][node2] = time;
            matrix_time[node2][node1] = time;           
        }
    }

    int start, end;
    cin >> start >> end;

    vector<int> shortest_path;
    int shortest_dist = findShortestPath(start, end, shortest_path);

    vector<int> fastest_path;
    int fastest_time = findFastestPath(start, end, fastest_path);

    if (shortest_path == fastest_path)
    {
        printf("Distance = %d; Time = %d: ", shortest_dist, fastest_time);
        for (int i = 0; i < shortest_path.size(); i++)
        {
            if (i == 0)
                printf("%d", shortest_path[i]);
            else
                printf(" -> %d", shortest_path[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Distance = %d: ", shortest_dist);
        for (int i = 0; i < shortest_path.size(); i++)
        {
            if (i == 0)
                printf("%d", shortest_path[i]);
            else
                printf(" -> %d", shortest_path[i]);
        }
        printf("\n");

        printf("Time = %d: ", fastest_time);
        for (int i = 0; i < fastest_path.size(); i++)
        {
            if (i == 0)
                printf("%d", fastest_path[i]);
            else
                printf(" -> %d", fastest_path[i]);
        }
        printf("\n");

    }

    return 0;
}
