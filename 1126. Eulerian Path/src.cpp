#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

bool isConnected(vector<vector<int>> matrix)
{
    int node_num = matrix.size();

    vector<bool> visited(node_num, false);

    int first_node = 0;
    queue<int> q;
    q.push(first_node);
    visited[first_node] = true;

    int cnt = 0;

    while (!q.empty())
    {
        int node = q.front();
        for (int i = 0; i < node_num; i++)
        {
            if (matrix[node][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
        q.pop();
        cnt++;
    }
    return cnt == node_num;
}

int main()
{
    int node_num, edge_num;
    cin >> node_num >> edge_num;

    vector<vector<int>> matrix(node_num, vector<int>(node_num, 0));
    vector<int> degree(node_num + 1, 0);

    int node1, node2;

    for (int i = 0; i < edge_num; i++)
    {
        cin >> node1 >> node2;

        matrix[node1 - 1][node2 - 1] = 1;
        matrix[node2 - 1][node1 - 1] = 1;

        degree[node1]++;
        degree[node2]++;
    }

    isConnected(matrix);

    int odd_num = 0;

    for (int i = 1; i < degree.size(); i++)
    {
        if (degree[i] % 2 != 0)
            odd_num++;
        cout << degree[i];
        if (i != degree.size() - 1)
            cout << ' ';
        else
            cout << endl;
    }

    if ((odd_num != 0 && odd_num != 2) || isConnected(matrix) == false)
        cout << "Non-Eulerian" << endl;
    else if (odd_num == 0)
        cout << "Eulerian" << endl;
    else if (odd_num == 2)
        cout << "Semi-Eulerian" << endl;

    return 0;
}
