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

int M, N, L, T;

vector<vector<vector<bool>>> matrix(61, vector<vector<bool>>(1287, vector<bool>(129)));
vector<vector<vector<bool>>> vis(61, vector<vector<bool>>(1287, vector<bool>(129, false)));

struct Node{
    int i;
    int j;
    int k;
    Node(int i, int j, int k) :i(i), j(j), k(k){}
};

bool isValid(int i, int j, int k)
{
    if (i < 0 || i > L - 1)
        return false;
    if (j < 0 || j > M - 1)
        return false;
    if (k < 0 || k > N - 1)
        return false;

    return true;
}

int BFS(int i, int j, int k)
{

    int cnt = 0;
    queue<Node*> q;

    Node* node = new Node(i, j, k);
    q.push(node);
    Node* new_node = NULL;
    while (!q.empty())
    {
        node = q.front();
        //上下
        if (isValid(node->i + 1, node->j, node->k) && vis[node->i + 1][node->j][node->k] == false && matrix[node->i + 1][node->j][node->k] == true)
        {
            new_node = new Node(node->i + 1, node->j, node->k);
            q.push(new_node);
            vis[node->i + 1][node->j][node->k] = true;
        }        
        if (isValid(node->i - 1, node->j, node->k) && vis[node->i - 1][node->j][node->k] == false && matrix[node->i - 1][node->j][node->k] == true)
        {
            new_node = new Node(node->i - 1, node->j, node->k);
            q.push(new_node);
            vis[node->i - 1][node->j][node->k] = true;
        }

        //左右
        if (isValid(node->i, node->j + 1, node->k) && vis[node->i][node->j + 1][node->k] == false && matrix[node->i][node->j + 1][node->k] == true)
        {
            new_node = new Node(node->i, node->j + 1, node->k);
            q.push(new_node);
            vis[node->i][node->j + 1][node->k] = true;
        }
        if (isValid(node->i, node->j - 1, node->k) && vis[node->i][node->j - 1][node->k] == false && matrix[node->i][node->j - 1][node->k] == true)
        {
            new_node = new Node(node->i, node->j - 1, node->k);
            q.push(new_node);
            vis[node->i][node->j - 1][node->k] = true;
        }

        //前后
        if (isValid(node->i, node->j, node->k + 1) && vis[node->i][node->j][node->k + 1] == false && matrix[node->i][node->j][node->k + 1] == true)
        {
            new_node = new Node(node->i, node->j, node->k + 1);
            q.push(new_node);
            vis[node->i][node->j][node->k + 1] = true;
        }
        if (isValid(node->i, node->j, node->k - 1) && vis[node->i][node->j][node->k - 1] == false && matrix[node->i][node->j][node->k - 1] == true)
        {
            new_node = new Node(node->i, node->j, node->k - 1);
            q.push(new_node);
            vis[node->i][node->j][node->k - 1] = true;
        }

        q.pop();
        cnt++;
    }

    if (cnt >= T)
        return cnt;
    else
        return 0;

}

int main() {
    
    cin >> M >> N >> L >> T;

    int buf;
    
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> buf;
                if (buf)
                    matrix[i][j][k] = true;
                else
                    matrix[i][j][k] = false;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (vis[i][j][k] == false && matrix[i][j][k] == true)
                {
                    vis[i][j][k] = true;
                    res += BFS(i, j, k);
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
