#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
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

struct Student{
    int id;
    char name[10];
    int grade;
};

bool cmpWithID(Student a, Student b)
{
    return a.id < b.id;
}

bool cmpWithName(Student a, Student b)
{
    int flag = strcmp(a.name, b.name);

    if (flag < 0)
        return true;
    else if (flag > 0)
        return false;
    else
        return a.id < b.id;
}

bool cmpWithGrade(Student a, Student b)
{
    if (a.grade < b.grade)
        return true;
    else if (a.grade > b.grade)
        return false;
    else
        return a.id < b.id;
}

int main()
{
    int N, C;
    cin >> N >> C;

    vector<Student> vec;
    Student s;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %d", &s.id, s.name, &s.grade);
        vec.push_back(s);
    }

    if (C == 1)
        sort(vec.begin(), vec.end(), cmpWithID);
    else if (C == 2)
        sort(vec.begin(), vec.end(), cmpWithName);
    else
        sort(vec.begin(), vec.end(), cmpWithGrade);

    for (int i = 0; i < vec.size(); i++)
    {
        printf("%06d %s %d\n", vec[i].id, vec[i].name, vec[i].grade);
    }

    return 0;
}
