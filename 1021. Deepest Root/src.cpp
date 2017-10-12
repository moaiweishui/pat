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

#define MAX_NODE_NUM 10000

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second < b.second)
        return false;
    else
    {
        return a.first < b.first;
    }
}

void DFS(int node, int& len, int& depth, set<int>& res, int& N, vector<vector<bool>>& matrix, vector<bool>& vis)
{
    bool flag = false;
    for (int i = 1; i <= N; i++)
    {
        if (matrix[node][i] && vis[i] == false)
        {
            flag = true;
            vis[i] = true;
            len++;
            DFS(i, len, depth, res, N, matrix, vis);
            len--;
            vis[i] = false;
        }
    }

    if (!flag)
    {
        if (len > depth)
        {
            depth = len;
            res.clear();
            res.insert(node);
        }
        else if (len == depth)
        {
            res.insert(node);
        }
            
        return;
    }
}

void BFS(int node, int N, vector<vector<bool>>& matrix, vector<bool>& vis)
{
    bool flag = false;

    queue<int> q;
    q.push(node);

    vis[node] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (matrix[curr][i] && vis[i] == false)
            {
                flag = true;
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int getComponentsNum(int N, vector<vector<bool>>& matrix)
{
    vector<bool> vis(MAX_NODE_NUM + 1, false);
    int num = 0;
    bool flag;
    while (1)
    {
        flag = false;
        for (int i = 1; i <= N; i++)
        {
            if (vis[i] == false)
            {
                BFS(i, N, matrix, vis);
                flag = true;
                break;
            }
        }
        if (!flag)
            break;
        else
            num++;
    }

    return num;
}

set<int> getFarthestNode(int start, int& N, vector<vector<bool>>& matrix)
{
    int len = 0, depth = 0;
    vector<bool> vis(MAX_NODE_NUM + 1, false);
    set<int> _set;
    vis[start] = true;
    DFS(start, len, depth, _set, N, matrix, vis);
    _set.insert(start);
    return _set;
}

int main()
{
    vector<vector<bool>> matrix(MAX_NODE_NUM + 1, vector<bool>(MAX_NODE_NUM + 1, false));
    
    int N;
    cin >> N;
  
  if(N == 1)
  {
    cout << N<<endl;
    return 0;
  }
  
    int node1, node2;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> node1 >> node2;
        matrix[node1][node2] = true;
        matrix[node2][node1] = true;
    }

    int comp_num = getComponentsNum(N, matrix);

    

    if (comp_num == 1)
    {
        set<int> res;
        int node = 3;

        int len = 0, depth = 0;
        vector<bool> vis(MAX_NODE_NUM + 1, false);
        DFS(node, len, depth, res, N, matrix, vis);

        int start = *res.begin();
        
        set<int> _set = getFarthestNode(start, N, matrix);

        for (auto it = _set.begin(); it != _set.end(); it++)
            res.insert(*it);

        vector<int> vec(res.begin(), res.end());

        sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size(); i++)
            printf("%d\n", vec[i]);

    }
    else
    {
        printf("Error: %d components\n", comp_num);
    }

    return 0;
}
