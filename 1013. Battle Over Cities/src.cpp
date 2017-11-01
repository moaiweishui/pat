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

#define MAX_SIZE 1000

int getUnionNum(int N, vector<pair<int, int>>& connect, int remove_node)
{
    vector<int> nodeUnionType(N, 0);
    remove_node--;
    int union_num = N;

    for (int i = 0; i < N; i++)
        nodeUnionType[i] = i;
    int node1, node2;
    for (int i = 0; i < connect.size(); i++)
    {
        node1 = connect[i].first - 1;
        node2 = connect[i].second - 1;
        if (node1 != remove_node && node2 != remove_node)
        {
            if (nodeUnionType[node1] < nodeUnionType[node2])
            {
                for (int j = 0; j < nodeUnionType.size(); j++)
                {
                    if (nodeUnionType[j] == nodeUnionType[node2])
                        nodeUnionType[j] = nodeUnionType[node1];
                }
                union_num--;
            }
            else if (nodeUnionType[node1] > nodeUnionType[node2])
            {
                for (int j = 0; j < nodeUnionType.size(); j++)
                {
                    if (nodeUnionType[j] == nodeUnionType[node1])
                        nodeUnionType[j] = nodeUnionType[node2];
                }
                union_num--;
            }
        }
    }

    return union_num;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> connect;
    int node1, node2;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &node1, &node2);
        connect.push_back(make_pair(node1, node2));
    }

    vector<int> remove_node_list;
    int node;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &node);
        remove_node_list.push_back(node);
    }

    for (int i = 0; i < K; i++)
    {
        int res = getUnionNum(N, connect, remove_node_list[i]);
        cout << res - 2 << endl;
    }


    return 0;
}
