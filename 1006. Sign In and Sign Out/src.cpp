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
    string id;
    int in_time;
    int out_time;
    Record(string id) :id(id){}
};

int convert(string time)
{
    string s_h, s_m, s_s;
    s_h = time.substr(0, 2);
    s_m = time.substr(3, 2);
    s_s = time.substr(6, 2);

    stringstream ss_h, ss_m, ss_s;
    int hh, mm, ss;

    ss_h << s_h;
    ss_h >> hh;

    ss_m << s_m;
    ss_m >> mm;

    ss_s << s_s;
    ss_s >> ss;

    return hh * 60 * 60 + mm * 60 + ss;
}

bool cmp1(Record* a, Record* b)
{
    return a->in_time < b->in_time;
}

bool cmp2(Record* a, Record* b)
{
    return a->out_time > b->out_time;
}

int main() {
    int N;
    cin >> N;

    char id_buf[20];
    char in_time_buf[10];
    char out_time_buf[10];

    vector<Record*> vec;
    Record* new_record = NULL;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %s", id_buf, in_time_buf, out_time_buf);
        new_record = new Record(id_buf);
        new_record->in_time = convert(in_time_buf);
        new_record->out_time = convert(out_time_buf);
        vec.push_back(new_record);
    }

    sort(vec.begin(), vec.end(), cmp1);

    cout << vec[0]->id << ' ';

    sort(vec.begin(), vec.end(), cmp2);
    cout << vec[0]->id << endl;

    return 0;
}
