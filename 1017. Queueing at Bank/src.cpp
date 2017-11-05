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

#define EARLIEST_TIME 8 * 60 * 60
#define LATEST_TIME 17 * 60 * 60

struct Customer{
    string arrive_time_str;
    int arrive_time_sec;
    int process_time;
    int wait_time;
    Customer(string arrive_time_str, int process_time)
        :arrive_time_str(arrive_time_str), process_time(process_time), wait_time(0){}
};

struct Window{
    int end_time;
    queue<Customer*> que;
    Window(int end_time) : end_time(end_time){}
};

int getTime(string time_str)
{
    stringstream ss_h, ss_m, ss_s;
    int h, m, s;
    string s_h, s_m, s_s;
    s_h = time_str.substr(0, 2);
    s_m = time_str.substr(3, 2);
    s_s = time_str.substr(6, 2);

    ss_h << s_h;
    ss_h >> h;

    ss_m << s_m;
    ss_m >> m;

    ss_s << s_s;
    ss_s >> s;

    return h * 60 * 60 + m * 60 + s;
}

bool cmpArriveTime(Customer* a, Customer* b)
{
    return a->arrive_time_sec < b->arrive_time_sec;
}

int findAvailableWin(vector<Window*>& win_list)  //返回空闲窗口编号，若无空闲，则返回-1
{
    for (int i = 0; i < win_list.size(); i++)
    {
        if (win_list[i]->que.empty())
        {
            return i;
        }
    }

    return -1;
}

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

int main() {

    int N, K;
    cin >> N >> K;

    if (N == 0)
    {
        return 0;
    }

    vector<Customer*> customer_list;
    string time_str;
    int process_time;
    int arrive_time;
    Customer* new_cust = NULL;
    for (int i = 0; i < N; i++)
    {
        cin >> time_str >> process_time;
        new_cust = new Customer(time_str, process_time);
        arrive_time = getTime(time_str);
        if (arrive_time <= LATEST_TIME)
        {
            new_cust->arrive_time_sec = arrive_time;

            if (new_cust->process_time > 60)
                new_cust->process_time = 60;
            customer_list.push_back(new_cust);
        }     
    }

    sort(customer_list.begin(), customer_list.end(), cmpArriveTime); //按到达时间排序

    //到达队列
    queue<Customer*> out_que;
    for (int i = 0; i < customer_list.size(); i++)
    {
        if (customer_list[i]->arrive_time_sec < EARLIEST_TIME)
        {
            customer_list[i]->wait_time = EARLIEST_TIME - customer_list[i]->arrive_time_sec;
            customer_list[i]->arrive_time_sec = EARLIEST_TIME;           
        }
        out_que.push(customer_list[i]);
    }

    vector<Window*> win_list;
    for (int i = 0; i < K; i++)
    {
        Window* new_win = new Window(EARLIEST_TIME);
        win_list.push_back(new_win);
    }

    int curr_time = EARLIEST_TIME;
    while (!out_que.empty())
    {
        int empty_win_idx = findAvailableWin(win_list); //空闲窗口编号
        
        if (empty_win_idx == -1)  //此时无空闲窗口
        {
            int first_end_win_idx = findFirstEndWin(win_list); //找到最快结束的那个窗口
            int end_time = win_list[first_end_win_idx]->end_time;

            //时间推进到该窗口结束事务那一刻
            curr_time = end_time;
            //该窗口办理业务的用户结束办理
            win_list[first_end_win_idx]->que.pop();
        }
        else
        {
            //进入该窗口，计算其等待时间，并更新该窗口事务结束时间
            win_list[empty_win_idx]->que.push(out_que.front());
            if (curr_time <= out_que.front()->arrive_time_sec)//当前时间小于用户到达时间，即该用户一到达就开始服务
            {
                curr_time = out_que.front()->arrive_time_sec;
            }
            out_que.front()->wait_time += curr_time - out_que.front()->arrive_time_sec;
            win_list[empty_win_idx]->end_time = curr_time + out_que.front()->process_time * 60;
            
            out_que.pop();
        }

    }
    int total_wait_time_in_sec = 0;
    for (int i = 0; i < customer_list.size(); i++)
        total_wait_time_in_sec += customer_list[i]->wait_time;

    double avg_wait_time_in_minute = total_wait_time_in_sec / 60.0 / customer_list.size();

    printf("%.1lf\n", avg_wait_time_in_minute);

    return 0;
}
