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

#define MAX_SIZE 1000+10+1

int convertIndex(string s, int N)
{
    int res = 0;
    if (s[0] == 'G')
    {
        s = s.substr(1, s.length() - 1);
        stringstream ss;
        ss << s;
        ss >> res;
        res += N;
    }
    else
    {
        stringstream ss;
        ss << s;
        ss >> res;
    }
    return res;
}

void Dijkstra(int N, int M, int root_id, vector<int>& dist, vector<vector<int>> matrix)
{
    set<int> S;
    set<int> T;
    
    for (int i = 1; i <= N + M; i++)
    {
        dist[i] = matrix[root_id][i];
        if (i != root_id)
            T.insert(i);
    }

    S.insert(root_id);
    dist[root_id] = 0;

    while (!T.empty())
    {
        int min_dist = INT_MAX;
        int shortest_node;
        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (dist[*it] != -1 && dist[*it] < min_dist)
            {
                shortest_node = *it;
                min_dist = dist[*it];
            }
        }

        auto findit = T.find(shortest_node);
        T.erase(findit);
        S.insert(shortest_node);

        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (matrix[*it][shortest_node] != -1)
            {
                if (dist[*it] == -1)
                    dist[*it] = dist[shortest_node] + matrix[*it][shortest_node];
                else if (dist[shortest_node] + matrix[*it][shortest_node] < dist[*it])
                    dist[*it] = dist[shortest_node] + matrix[*it][shortest_node];
            }
        }
    }


    return;
}

pair<int, int> findShortestDist(vector<int> dist, int root_id, int N, int Ds)
{
    int min_dist = INT_MAX;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] > Ds)
            return make_pair(-1, -1);
        else{
            sum += dist[i];
            if (dist[i] < min_dist)
                min_dist = dist[i];
        }
    }
    return make_pair(min_dist, sum);
}

int main() {

    int N, M, K, Ds;
    cin >> N >> M >> K >> Ds;

    vector<vector<int>> matrix(MAX_SIZE, vector<int>(MAX_SIZE, -1));

    char id1[5];
    char id2[5];
    int dis_buf;
    for (int i = 0; i < K; i++)
    {
        scanf("%s %s %d", id1, id2, &dis_buf);
        matrix[convertIndex(id1, N)][convertIndex(id2, N)] = dis_buf;
        matrix[convertIndex(id2, N)][convertIndex(id1, N)] = dis_buf;
    }

    

    int gas_station_id;

    bool find_flag = false;

    double min_dist = 0;
    double min_sum = DBL_MAX;
    int min_gas_station_id;

    for (int i = N + 1; i <= N + M; i++)
    {
        vector<int> dist(N + M + 1, -1);
        vector<bool> vis(N + M + 1, false);
        gas_station_id = i;
        Dijkstra(N, M, gas_station_id, dist, matrix);

        pair<int, int> mindist_sum = findShortestDist(dist, gas_station_id, N, Ds);

        if (mindist_sum.first != -1) // 未超过距离限制
        {
            find_flag = true;
            if (mindist_sum.first > min_dist
                || (mindist_sum.first == min_dist && mindist_sum.second < min_sum))
            {
                min_dist = 1.0 * mindist_sum.first;
                min_sum = 1.0 * mindist_sum.second;
                min_gas_station_id = gas_station_id;
            }
        }

    }

    if (find_flag)
    {
        printf("G%d\n", min_gas_station_id - N);
        printf("%.1lf %.1lf\n", min_dist, min_sum / N);
    }
    else
    {
        printf("No Solution\n");
    }
    return 0;
}
