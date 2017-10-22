#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Person{
    string name;
    int age;
    int net_worth;
    Person(string name, int age, int net_worth) :name(name), age(age), net_worth(net_worth){}
};

bool cmpAge(Person* a, Person* b)
{
    if (a->age < b->age)
        return true;
    else if (a->age > b->age)
        return false;
    else
    {
        if (a->net_worth > b->net_worth)
            return true;
        else if (a->net_worth < b->net_worth)
            return false;
        else
        {
            return a->name < b->name;
        }
    }
}

bool cmp(Person* a, Person* b)
{
    if (a->net_worth > b->net_worth)
        return true;
    else if (a->net_worth < b->net_worth)
        return false;
    else
    {
        if (a->age < b->age)
            return true;
        else if (a->age > b->age)
            return false;
        else
        {
            return a->name < b->name;
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<Person*> vec;

    vector<int> age_count(200, 0);

    char name[10];
    int age, net_worth;
    Person* person = NULL;

    int min_age = INT_MAX;
    int max_age = -1;

    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", name, &age, &net_worth);
        person = new Person(name, age, net_worth);
        vec.push_back(person);
        if (age < min_age)
            min_age = age;
        if (age > max_age)
            max_age = age;
    }
    sort(vec.begin(), vec.end(), cmp);
    //每个年龄，最多只需要保存100条记录
    vector<Person*> new_vec;
    int curr_age = -1;
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        age_count[vec[i]->age]++;
        if (age_count[vec[i]->age] <= 100)
        {
            new_vec.push_back(vec[i]);
        }
    }

    vector<vector<Person*>> res;
    vector<Person*> subres;
    vector<int> output_size;

    int size, amin, amax;
    for (int i = 0; i < K; i++)
    {
        subres.clear();

        scanf("%d %d %d", &size, &amin, &amax);
        output_size.push_back(size);

        if (amin > max_age || amax < min_age)
        {
            res.push_back(subres);
        }
        else
        {
            int cnt = 0;
            for (int j = 0; j < new_vec.size(); j++)
            {
                if (new_vec[j]->age >= amin && new_vec[j]->age <= amax)
                {
                    subres.push_back(new_vec[j]);
                    cnt++;
                    if (cnt == size)
                        break;
                }
            }
            res.push_back(subres);
        }


    }

    for (int i = 0; i < res.size(); i++)
    {
        printf("Case #%d:\n", i + 1);
        if (res[i].empty())
            printf("None\n");
        else
        {
            //int cnt = 0;
            for (int j = 0; j < res[i].size(); j++)
            {
                printf("%s %d %d\n", res[i][j]->name.c_str(), res[i][j]->age, res[i][j]->net_worth);
                //cnt++;
                //if (cnt == output_size[i])
                //    break;
            }
        }

    }

    return 0;
}
