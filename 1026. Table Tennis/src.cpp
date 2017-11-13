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

#define EARLIEST_TIME 8 * 60 * 60
#define LATEST_TIME 21 * 60 * 60

struct Person{
    string arriving_time;
    int arriving_time_in_sec;
    int playing_time_in_min;
    int is_vip;
    int serving_time_in_sec;
    int wait_time;
    Person(string arriving_time, int playing_time_in_min, int is_vip)
        :arriving_time(arriving_time), playing_time_in_min(playing_time_in_min), is_vip(is_vip), wait_time(0){}
};

struct Table{
    bool is_vip;
    Person* user;
    int free_time_in_sec;
    int serve_cnt;
    Table(bool is_vip, int free_time_in_sec) :is_vip(false), user(NULL), free_time_in_sec(), serve_cnt(0){}
};

int convertTime(string s)
{
    stringstream ss_h, ss_m, ss_s;
    string s_h, s_m, s_s;
    s_h = s.substr(0, 2);
    s_m = s.substr(3, 2);
    s_s = s.substr(6, 2);

    int hour, min, sec;

    ss_h << s_h;
    ss_h >> hour;

    ss_m << s_m;
    ss_m >> min;

    ss_s << s_s;
    ss_s >> sec;

    return hour * 60 * 60 + min * 60 + sec;
}

bool cmp(Person* a, Person* b)
{
    return a->arriving_time_in_sec < b->arriving_time_in_sec;
}

int findAvailableTable(vector<Table*>& table_list)
{
    for (int i = 1; i < table_list.size(); i++)
    {
        if (table_list[i]->user == NULL)
            return i;
    }

    return -1;
}

int findAvailableVipTable(vector<Table*>& table_list)  //找空闲的vip桌，若没有则返回-1
{
    for (int i = 1; i < table_list.size(); i++)
    {
        if (table_list[i]->user == NULL && table_list[i]->is_vip)
            return i;
    }

    return -1;
}

bool cmpServingTime(Person* a, Person* b)
{
    return a->serving_time_in_sec < b->serving_time_in_sec;
}

void insertUser(vector<Table*>& table_list, int empty_table_idx, queue<Person*>& q, int curr_time, vector<Person*>& res)
{
    table_list[empty_table_idx]->user = q.front();
    table_list[empty_table_idx]->serve_cnt++;
    table_list[empty_table_idx]->free_time_in_sec = curr_time + q.front()->playing_time_in_min * 60;

    q.front()->wait_time = curr_time - q.front()->arriving_time_in_sec;
    q.front()->serving_time_in_sec = curr_time;
    res.push_back(q.front());
    q.pop();

    return;
}

void insertVipUser(vector<Table*>& table_list, int empty_table_idx, queue<Person*>& vip_q, int curr_time, vector<Person*>& res)
{
    table_list[empty_table_idx]->user = vip_q.front();
    table_list[empty_table_idx]->serve_cnt++;
    table_list[empty_table_idx]->free_time_in_sec = curr_time + vip_q.front()->playing_time_in_min * 60;

    vip_q.front()->wait_time = curr_time - vip_q.front()->arriving_time_in_sec;
    vip_q.front()->serving_time_in_sec = curr_time;
    res.push_back(vip_q.front());
    vip_q.pop();

    return;
}

int main() {
    
    int N;
    cin >> N;
    char arriving_time[10];
    int playing_time_in_min, vip_tag;

    Person* new_person = NULL;
    vector<Person*> person_list;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", arriving_time, &playing_time_in_min, &vip_tag);
        if (playing_time_in_min > 120)
            playing_time_in_min = 120;
        new_person = new Person(arriving_time, playing_time_in_min, vip_tag);
        new_person->arriving_time_in_sec = convertTime(arriving_time);
        person_list.push_back(new_person);
    }
    sort(person_list.begin(), person_list.end(), cmp);

   
    int K, M;
    cin >> K >> M;
    vector<Table*> table_list;
    Table* table = new Table(false, 0);
    table_list.push_back(table);

    for (int i = 0; i < K; i++)
    {
        table = new Table(false, EARLIEST_TIME);
        table_list.push_back(table);
    }

    int vip_id;
    for (int i = 0; i < M; i++)
    {
        cin >> vip_id;
        table_list[vip_id]->is_vip = true;
    }

    queue<Person*> out_q;
    queue<Person*> q;
    queue<Person*> vip_q;

    for (int i = 0; i < person_list.size(); i++)
    {
        if (person_list[i]->arriving_time_in_sec < EARLIEST_TIME)
        {
            person_list[i]->wait_time = EARLIEST_TIME - person_list[i]->arriving_time_in_sec;
            person_list[i]->arriving_time_in_sec = EARLIEST_TIME;
            if (person_list[i]->is_vip)
                vip_q.push(person_list[i]);
            else
                q.push(person_list[i]);
        }
        else
            out_q.push(person_list[i]);
    }

    vector<Person*> res; //最终得到服务的用户列表

    int curr_time;
    for (int i = EARLIEST_TIME; i < LATEST_TIME; i++)
    {
        curr_time = i;
        //把此时到达的用户加入队列
        while (!out_q.empty() && out_q.front()->arriving_time_in_sec == curr_time)
        {
            if (out_q.front()->is_vip)
                vip_q.push(out_q.front());
            else
                q.push(out_q.front());
            out_q.pop();
        }

        for (int j = 1; j < table_list.size(); j++)
        {
            if (table_list[j]->free_time_in_sec == curr_time)
                table_list[j]->user = NULL;
        }


        while (!q.empty() || !vip_q.empty())  //此刻有用户等待
        {
            int empty_table_idx = findAvailableTable(table_list);
            int empty_vip_table_idx = findAvailableVipTable(table_list);

            if (empty_table_idx == -1) //没有空闲桌子，跳出
                break;
            else if (empty_vip_table_idx == -1) //有空闲桌子，但是只是普通桌，没有vip桌
            {
                if (vip_q.empty())  //无vip
                    insertUser(table_list, empty_table_idx, q, curr_time, res);
                else if (q.empty())  //无普通用户
                    insertVipUser(table_list, empty_table_idx, vip_q, curr_time, res);
                else if (q.front()->arriving_time_in_sec < vip_q.front()->arriving_time_in_sec) //普通用户较早到达
                    insertUser(table_list, empty_table_idx, q, curr_time, res);
                else  //vip用户较早到达
                    insertVipUser(table_list, empty_table_idx, vip_q, curr_time, res);
            }
            else  //有空闲桌子，且其中有vip桌
            {
                if (vip_q.empty())  //无vip
                    insertUser(table_list, empty_table_idx, q, curr_time, res);
                else  //队列中有vip
                    insertVipUser(table_list, empty_vip_table_idx, vip_q, curr_time, res);
            }


        }
    }

    sort(res.begin(), res.end(), cmpServingTime);
    int hh, mm, ss;
    int wait_time_min;
    for (int i = 0; i < res.size(); i++)
    {
        printf("%s ", res[i]->arriving_time.c_str());

        hh = res[i]->serving_time_in_sec / 3600;
        mm = res[i]->serving_time_in_sec % 3600 / 60;
        ss = res[i]->serving_time_in_sec % 3600 % 60;
        printf("%02d:%02d:%02d ", hh, mm, ss);

        wait_time_min = round((res[i]->wait_time + 30) / 60 );

        printf("%d\n", wait_time_min);
    }

    for (int i = 1; i < table_list.size(); i++)
    {
        if (i == 1)
            printf("%d", table_list[i]->serve_cnt);
        else
            printf(" %d", table_list[i]->serve_cnt);
    }

    return 0;
}
