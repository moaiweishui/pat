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

struct Window{
    int end_time;
    queue<int> que;
};

int findFirstEndWin(vector<Window*>& win_list)  //返回最早完成事务的那个窗口的编号
{
    int first_end_time = INT_MAX;
    int idx;
    for (int i = 0; i < win_list.size(); i++)
    {
        if (win_list[i]->end_time < first_end_time)
        {
            first_end_time = win_list[i]->end_time;
            idx = i;
        }
    }

    return idx;
}

pair<int, int> convertEndTime(int user_id, int time_in_minute, vector<int>& process_time_list)
{
    if (time_in_minute - process_time_list[user_id - 1] >= 540) //起始时间超过5点
        return make_pair(-1, -1);

    int hh = time_in_minute / 60;
    int mm = time_in_minute % 60;
    return make_pair(hh + 8, mm);
}

int main() {

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<int> process_time_list;
    int process_time;
    for (int i = 0; i < K; i++)
    {
        cin >> process_time;
        process_time_list.push_back(process_time);
    }

    vector<int> query_list;
    int query_id;
    for (int i = 0; i < Q; i++)
    {
        cin >> query_id;
        query_list.push_back(query_id);
    }

    vector<Window*> win_list;
    for (int i = 0; i < N; i++)
    {
        Window* new_win = new Window();
        win_list.push_back(new_win);
    }

    vector<int> user_list(K, 0);

    if (K > N * M)    //有人需要等待在黄线外
    {
        for (int i = 0; i < N * M; i++) //把黄线内的人安排好
            win_list[i % N]->que.push(i + 1);

        for (int i = 0; i < N; i++)  // 初始化第一波用户的事务结束时间
            win_list[i]->end_time = process_time_list[i];

        queue<int> out_que;
        for (int i = N * M; i < K; i++) //排在黄线外的队列
            out_que.push(i + 1);

        int first_index; //最早完成事务的窗口编号
        int user_id;
        int curr_time;
        while (!out_que.empty())
        {
            first_index = findFirstEndWin(win_list);
            //用户出列，并记录下其事务结束时间
            user_id = win_list[first_index]->que.front();           
            user_list[user_id - 1] = win_list[first_index]->end_time;
            win_list[first_index]->que.pop();
            //更新当前时间
            curr_time = user_list[user_id - 1];
            
            //黄线外的第一个用户进入
            win_list[first_index]->que.push(out_que.front());
            out_que.pop();

            //更新该窗口的事务结束时间
            win_list[first_index]->end_time = curr_time 
                + process_time_list[win_list[first_index]->que.front() - 1];
        }

        //此时所有用户均在黄线内
        //对每个窗口单独计算其队列里各用户的结束时间
        for (int i = 0; i < N; i++)
        {
            curr_time = win_list[i]->end_time - process_time_list[win_list[i]->que.front() - 1];
            while (!win_list[i]->que.empty())
            {
                user_id = win_list[i]->que.front();
                user_list[user_id - 1] = curr_time + process_time_list[user_id - 1];
                curr_time = user_list[user_id - 1];
                win_list[i]->que.pop();
            }
        }

    }
    else  //所有人都在黄线内
    {
        for (int i = 0; i < K; i++)  //把黄线内的人安排好
            win_list[i % N]->que.push(i + 1);

        for (int i = 0; i < N && i < K; i++)  // 初始化第一波用户的事务结束时间
            win_list[i]->end_time = process_time_list[i];

        int user_id;
        int curr_time;
        //对每个窗口单独计算其队列里各用户的结束时间
        for (int i = 0; i < N; i++)
        {
            curr_time = 0;
            while (!win_list[i]->que.empty())
            {
                user_id = win_list[i]->que.front();
                user_list[user_id - 1] = curr_time + process_time_list[user_id - 1];
                curr_time = user_list[user_id - 1];
                win_list[i]->que.pop();
            }
        }

    }

    pair<int, int> time;
    for (int i = 0; i < query_list.size(); i++)
    {
        time = convertEndTime(query_list[i], user_list[query_list[i] - 1], process_time_list);
        if (time.first == -1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", time.first, time.second);
    }

    return 0;
}
