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

struct Record{
    string name;
    string time;
    bool is_online;  //true:on line  false:off line
    Record(string name, string time) : name(name), time(time){}
};

bool cmpTime(Record* a, Record* b)
{
    return a->time < b->time;
}

struct PhoneCall{
    string name;
    string start_time;
    string end_time;
    int duration;
    double charge;
    PhoneCall(string name, string start_time, string end_time) :
        name(name), start_time(start_time), end_time(end_time){}
};

int toInt(string s)
{
    int res;
    stringstream ss;
    ss << s;
    ss >> res;

    return res;
}

int getDurationTime(string start, string end)
{
    int start_in_min, end_in_min;
    int dd, hh, mm;
    dd = toInt(start.substr(3, 2));
    hh = toInt(start.substr(6, 2));
    mm = toInt(start.substr(9, 2));
    start_in_min = dd * 24 * 60 + hh * 60 + mm;

    dd = toInt(end.substr(3, 2));
    hh = toInt(end.substr(6, 2));
    mm = toInt(end.substr(9, 2));
    end_in_min = dd * 24 * 60 + hh * 60 + mm;

    return end_in_min - start_in_min;
}

int currToEnd(int hh, int mm, vector<int>& rate)
{
    int res = 0;
    for (int i = hh; i < 24; i++)
    {
        if (i == hh)
        {
            res += rate[i] * (60 - mm);
        }
        else
            res += rate[i] * 60;
    }
    return res;
}

int startToCurr(int hh, int mm, vector<int>& rate)
{
    int res = 0;
    for (int i = 0; i <= hh; i++)
    {
        if (i == hh)
            res += rate[i] * mm;
        else
            res += rate[i] * 60;
    }
    return res;
}

double getCharge(string start, string end, vector<int>& rate, int rate_sum)
{
    int charge = 0;
    int dd1, hh1, mm1;
    int dd2, hh2, mm2;

    dd1 = toInt(start.substr(3, 2));
    hh1= toInt(start.substr(6, 2));
    mm1 = toInt(start.substr(9, 2));

    dd2 = toInt(end.substr(3, 2));
    hh2 = toInt(end.substr(6, 2));
    mm2 = toInt(end.substr(9, 2));

    if (dd1 != dd2)  //不是同一天
    {
        charge += currToEnd(hh1, mm1, rate);
        for (int i = dd1 + 1; i < dd2; i++)
            charge += rate_sum;
        charge += startToCurr(hh2, mm2, rate);

        double res = charge / 100.0;
        return res;
    }
    else // 同一天
    {
        for (int i = hh1; i <= hh2; i++)
        {
            if (hh1 == hh2)
                charge += rate[i] * (mm2 - mm1);
            else if (i == hh1)
                charge += rate[i] * (60 - mm1);
            else if (i == hh2)
                charge += rate[i] * mm2;
            else
                charge += rate[i] * 60;
        }

        double res = charge / 100.0;
        return res;
    }

}

int main() {

    vector<int> rate;
    int rate_buf;
    int rate_sum = 0;
    for (int i = 0; i < 24; i++)
    {
        cin >> rate_buf;
        rate_sum += rate_buf;
        rate.push_back(rate_buf);
    }
    rate_sum *= 60;

    int N;
    cin >> N;

    unordered_map<string, vector<Record*>> record_map;

    vector<Record*> record_list;
    Record* new_record = NULL;
    char name[21];
    char time[12];
    char status[10];
    string status_str;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %s", name, time, status);
        new_record = new Record(name, time);
        status_str = status;
        if (status_str == "on-line")
            new_record->is_online = true;
        else
            new_record->is_online = false;
        record_map[name].push_back(new_record);
    }

    unordered_map<string, vector<PhoneCall*>> phonecall_map;
    vector<PhoneCall*> phonecall_list;
    PhoneCall* new_phone_call = NULL;
    for (auto it = record_map.begin(); it != record_map.end(); it++)
    {
        sort((*it).second.begin(), (*it).second.end(), cmpTime);
        Record* last_online_record = NULL;
        for (int i = 0; i < (*it).second.size(); i++)
        {
            if (i == 0 && (*it).second[i]->is_online == true)
                last_online_record = (*it).second[i];
            else if (i != 0)
            {
                if ((*it).second[i]->is_online == true)  //这是一条on line信息
                {
                    last_online_record = (*it).second[i];
                }
                else  //这是一条off line信息
                {
                    if (last_online_record != NULL)
                    {
                        new_phone_call = new PhoneCall(
                            (*it).first, last_online_record->time, (*it).second[i]->time
                            );                       
                        new_phone_call->duration = getDurationTime(
                            new_phone_call->start_time, new_phone_call->end_time);
                        new_phone_call->charge = getCharge(
                            new_phone_call->start_time, new_phone_call->end_time, rate, rate_sum);
                        phonecall_map[(*it).first].push_back(new_phone_call);
                        last_online_record = NULL;
                    }
                }
            }

        }
    }

    vector<string> user_list;
    for (auto it = phonecall_map.begin(); it != phonecall_map.end(); it++)
        user_list.push_back((*it).first);

    sort(user_list.begin(), user_list.end());

    string month;
    double total_amount;
    for (int i = 0; i < user_list.size(); i++)
    {
        printf("%s %s\n", user_list[i].c_str(), phonecall_map[user_list[i]][0]->start_time.substr(0, 2).c_str());
        
        total_amount = 0;
        for (int j = 0; j < phonecall_map[user_list[i]].size(); j++)
        {
            printf("%s %s %d $%.2lf\n", 
                phonecall_map[user_list[i]][j]->start_time.substr(3, 8).c_str(),
                phonecall_map[user_list[i]][j]->end_time.substr(3, 8).c_str(),
                phonecall_map[user_list[i]][j]->duration,
                phonecall_map[user_list[i]][j]->charge);
            total_amount += phonecall_map[user_list[i]][j]->charge;
        }
        printf("Total amount: $%.2lf\n", total_amount);
    }

    return 0;
}
