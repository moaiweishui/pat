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

vector<int> weight(101, 0);

void DFS(int node, vector<int>& mem, int& sum, int target, vector<vector<int>>& paths,
    vector<vector<int>>& tree, vector<int>& weight)
{
    if (tree[node].empty())//判断是否是叶子节点
    {
        if (sum == target)
            paths.push_back(mem);
    }
    else
    {
        for (int i = 0; i < tree[node].size(); i++)
        {
            if (sum + weight[tree[node][i]] <= target)  //有效
            {
                mem.push_back(tree[node][i]); //把这个节点加入路径
                sum += weight[tree[node][i]];

                DFS(tree[node][i], mem, sum, target, paths, tree, weight);

                sum -= weight[tree[node][i]];
                mem.pop_back();
            }
        }
    }

    return;
}

bool cmp(vector<int> p, vector<int> q)
{
    int len = min(p.size(), q.size());

    for (int i = 0; i < len; i++)
    {
        if (p[i] > q[i])
            return true;
        else if (p[i] < q[i])
            return false;
    }
    return false;
}

int main()
{
    int N, M, S;
    cin >> N >> M >> S;

    
    int w;
    for (int i = 0; i < N; i++)
    {
        cin >> w;
        weight[i] = w;
    }
    vector<vector<int>> tree(101, vector<int>());
    int node, child_num, child;
    for (int i = 0; i < M; i++)
    {
        cin >> node >> child_num;
        for (int j = 0; j < child_num; j++)
        {
            cin >> child;
            tree[node].push_back(child);
        }
    }

    int root = 0;

    vector<vector<int>> paths;
    vector<int> mem;//存储中间路径
    int sum = 0; //存储路径权重和

    mem.push_back(root);
    sum += weight[root];

    DFS(root, mem, sum, S, paths, tree, weight);

    for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            paths[i][j] = weight[paths[i][j]];
        }
    }

    sort(paths.begin(), paths.end(), cmp);

    for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            if (j == 0)
                cout << paths[i][j];
            else
                cout << ' ' << paths[i][j];
        }
        cout << endl;
    }

    return 0;
}
