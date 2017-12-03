/*********************** Solution 1 **************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    int vertex_num, edge_num;
    cin >> vertex_num >> edge_num;

    vector<vector<int>> matrix(vertex_num, vector<int>(vertex_num, 0));

    int start_buf, end_buf;
    for (int i = 0; i < edge_num; i++)
    {
        cin >> start_buf >> end_buf;
        matrix[start_buf - 1][end_buf - 1] = 1;
        matrix[end_buf - 1][start_buf - 1] = 1;
    }

    int query_num;
    cin >> query_num;

    vector<bool> res;

    for (int i = 0; i < query_num; i++)
    {
        bool flag = true;
        int cnt = 0;
        cin >> cnt;

        int vertex_buf;
        int last_vertex;

        vector<int> vertex_vec;
        set<int> vertex_set;

        cin >> vertex_buf;
        vertex_vec.push_back(vertex_buf);

        for (int j = 1; j < cnt; j++)
        {
            cin >> vertex_buf;
            vertex_vec.push_back(vertex_buf);
            vertex_set.insert(vertex_buf);

            if (matrix[vertex_vec[j - 1] - 1][vertex_buf - 1] == 0)
            {
                flag = false;
            }
        }

        if (flag && cnt != vertex_num + 1)
        {
            flag = false;
        }

        if (flag)
        {
            if (vertex_vec[0] != vertex_vec[cnt - 1] || vertex_set.size() != vertex_num)
            {
                flag = false;
            }
        }

        res.push_back(flag);
    }

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


/*********************** Solution 2 **************************/
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

int N, M;

bool check(vector<vector<bool>>& graph, vector<int> query){

    // Is this a circle?
    if (query[0] != query[query.size() - 1])
        return false;
    
    // Is this a simple circle and cover all vertexs?
    vector<int> vis(graph.size(), false);

    if (query.size() != graph.size())
        return false;
   
    for (int i = 0; i < query.size(); i++){
        if (vis[query[i]] == false){
            vis[query[i]] = true;
        }
        else{
            if (i != query.size() - 1)
                return false;
        }

        if (i != 0 && !graph[query[i - 1]][query[i]])
            return false;

    }

    return true;
}

int main() {
    

    cin >> N >> M;

    vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));

    int v1, v2;
    for (int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }

    int K;
    cin >> K;

    vector<vector<int>> queries;
    vector<int> tmpv;
    int v, v_num;
    for (int i = 0; i < K; i++){
        scanf("%d", &v_num);
        tmpv.clear();
        for (int j = 0; j < v_num; j++){
            scanf("%d", &v);
            tmpv.push_back(v);
        }
        queries.push_back(tmpv);
    }

    for (int i = 0; i < K; i++){
        if (check(graph, queries[i]))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
