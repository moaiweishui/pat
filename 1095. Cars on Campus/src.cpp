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

struct Record{
    string id; //车牌
    string time;
    bool status; //true:in  false:out
    int type;  //1:normal 2:query
    Record(string id, string time, bool status, int type) :id(id), time(time), status(status), type(type){}
};

bool cmpTime(Record* a, Record* b)
{
    if (a->time == b->time)  //保证在时间相同时，query记录要在正常记录之后
        return a->type < b->type;
    else
        return a->time < b->time;
}

int convert(string s)
{
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

int getTime(string a, string b)
{
    int hh_a = convert(a.substr(0, 2));
    int mm_a = convert(a.substr(3, 2));
    int ss_a = convert(a.substr(6, 2));

    int hh_b = convert(b.substr(0, 2));
    int mm_b = convert(b.substr(3, 2));
    int ss_b = convert(b.substr(6, 2));

    return hh_b * 60 * 60 + mm_b * 60 + ss_b - hh_a * 60 * 60 - mm_a * 60 - ss_a;
}

int main() {

    int N, K;
    cin >> N >> K;

    char id_buf[10];
    char time_buf[10];
    char status_buf[4];

    unordered_map<string, vector<Record*>> hmap;

    Record* new_record = NULL;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", &id_buf);
        scanf("%s", &time_buf);
        scanf("%s", &status_buf);

        if (strcmp(status_buf, "in") == 0)
            new_record = new Record(id_buf, time_buf, true, 1);
        else
            new_record = new Record(id_buf, time_buf, false, 1);

        //按车牌分开
        hmap[id_buf].push_back(new_record);
    }

    Record* last_in_record = NULL;

    vector<Record*> valid_record_list;

    //用来存每辆车对应的停车时间
    unordered_map<string, int> longest_map;

    int longest_time = 0;

    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        sort((*it).second.begin(), (*it).second.end(), cmpTime);

        last_in_record = NULL;

        for (int i = 0; i < (*it).second.size(); i++)
        {
            if ((*it).second[i]->status)  //in
            {
                last_in_record = (*it).second[i];
            }
            else //out
            {
                if (last_in_record != NULL)
                {
                    valid_record_list.push_back(last_in_record);
                    valid_record_list.push_back((*it).second[i]);

                    longest_map[last_in_record->id] += getTime(last_in_record->time, (*it).second[i]->time);

                    if (longest_map[last_in_record->id] > longest_time)
                        longest_time = longest_map[last_in_record->id];

                    last_in_record = NULL;
                }
            }
        }
    }

    char query_buf[10];
    //把query也插入记录列表
    for (int i = 0; i < K; i++)
    {
        scanf("%s", query_buf);
        new_record = new Record("query", query_buf, true, 2);
        valid_record_list.push_back(new_record);
    }

    sort(valid_record_list.begin(), valid_record_list.end(), cmpTime);

    int car_num = 0;

    for (int i = 0; i < valid_record_list.size(); i++)
    {
        if (valid_record_list[i]->id == "query") //说明是查询
            printf("%d\n", car_num);
        else
        {
            if (valid_record_list[i]->status)
                car_num++;
            else
                car_num--;
        }
    }

    set<string> id_list;

    for (auto it = longest_map.begin(); it != longest_map.end(); it++)
    {
        if ((*it).second == longest_time)
            id_list.insert((*it).first);
    }

    for (auto it = id_list.begin(); it != id_list.end(); it++)
        printf("%s ", (*it).c_str());

    int hh = longest_time / 3600;
    int mm = (longest_time % 3600) / 60;
    int ss = (longest_time % 3660) % 60;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
