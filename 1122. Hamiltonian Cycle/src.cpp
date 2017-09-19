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
