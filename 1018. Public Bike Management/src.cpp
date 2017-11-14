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

#define MAX_SIZE 510

int Cmax, N, Sp, M;

vector<vector<int>> matrix(MAX_SIZE, vector<int>(MAX_SIZE, -1));
vector<int> bike_num_list(MAX_SIZE, 0);
vector<vector<int>> adj_list(MAX_SIZE);
vector<bool> vis(MAX_SIZE, false);

void DFS(int node, int target, vector<int>& path, vector<int>& final_path, int& len, int& min_len, 
    int& send_cnt, int& min_send_cnt, int& back_cnt, int& min_back_cnt)
{
    if (node == target)
    {
        if (len < min_len
            || (len == min_len && send_cnt < min_send_cnt)
            || (len == min_len && send_cnt == min_send_cnt && back_cnt < min_back_cnt))
        {
            min_len = len;
            min_send_cnt = send_cnt;
            min_back_cnt = back_cnt;
            final_path = path;
        }
        return;
    }
    
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if (!vis[adj_list[node][i]])
        {
            path.push_back(adj_list[node][i]);
            vis[adj_list[node][i]] = true;
            len += matrix[node][adj_list[node][i]];

            //备份
            int back_cnt_backup = back_cnt;
            int send_cnt_backup = send_cnt;

            int cnt = Cmax - bike_num_list[adj_list[node][i]];
            if (cnt >= 0)  //这个点车不够
            {
                if (back_cnt >= cnt)  //直接从back的部分拿
                {
                    back_cnt -= cnt;
                }
                else   //back的不够，从PBMC额外再send
                {                   
                    send_cnt += cnt - back_cnt;
                    back_cnt = 0;
                }
            }
            else  //这个点车太多
            {
                back_cnt -= cnt;
            }

            DFS(adj_list[node][i], target, path, final_path, len, min_len, send_cnt, min_send_cnt, back_cnt, min_back_cnt);

            send_cnt = send_cnt_backup;
            back_cnt = back_cnt_backup;
            len -= matrix[node][adj_list[node][i]];
            vis[adj_list[node][i]] = false;
            path.pop_back();
        }
    }

}

int main() {
    
    cin >> Cmax >> N >> Sp >> M;
    Cmax = Cmax / 2;

    int buf;
    for (int i = 1; i <= N; i++)
    {
        cin >> buf;
        bike_num_list[i] = buf;
    }

    int node1, node2, w;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &node1, &node2, &w);
        matrix[node1][node2] = w;
        matrix[node2][node1] = w;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    vis[0] = true;

    int len = 0;
    int min_len = INT_MAX;
    int send_cnt = 0;
    int min_send_cnt = INT_MAX;
    int back_cnt = 0;
    int min_back_cnt = INT_MAX;

    vector<int> path;
    vector<int> final_path;

    DFS(0, Sp, path, final_path, len, min_len, send_cnt, min_send_cnt, back_cnt, min_back_cnt);
    
    printf("%d %d", min_send_cnt, 0);
    for (int i = 0; i < final_path.size(); i++)
    {
        printf("->%d", final_path[i]);
    }
    printf(" %d\n", min_back_cnt);


    return 0;
}
