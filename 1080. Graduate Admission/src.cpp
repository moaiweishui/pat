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

struct Student{
    int id;
    int Ge, Gi, sum;
    int rank;
    vector<int> school_list;
    Student(int id, int Ge, int Gi) :id(id), Ge(Ge), Gi(Gi){}
};

struct School{
    int id;
    int quota;
    vector<int> student_list;
    School(int id, int quota) :id(id), quota(quota){}
};

bool cmp(Student* a, Student* b)
{
    if (a->sum > b->sum)
        return true;
    else if (a->sum < b->sum)
        return false;
    else
        return a->Ge > b->Ge;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<School*> schools;
    int quota;
    School* new_school = NULL;
    for (int i = 0; i < M; i++)
    {
        cin >> quota;
        new_school = new School(i, quota);
        schools.push_back(new_school);
    }

    int Ge, Gi;
    int school_id;
    vector<Student*> student_vec;
    vector<Student*> applications;
    Student* new_student = NULL;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &Ge, &Gi);
        new_student = new Student(i, Ge, Gi);
        new_student->sum = Ge + Gi;
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &school_id);
            new_student->school_list.push_back(school_id);
        }
        applications.push_back(new_student);
        student_vec.push_back(new_student);
    }

    sort(applications.begin(), applications.end(), cmp);

    for (int i = 0; i < applications.size(); i++)
    {
        if (i != 0
            && applications[i]->sum == applications[i - 1]->sum
            && applications[i]->Ge == applications[i - 1]->Ge)
            applications[i]->rank = applications[i - 1]->rank;
        else
            applications[i]->rank = i;
    }

    for (int i = 0; i < applications.size(); i++)
    {
        int student_id = applications[i]->id;
        int cho; //志愿学校
        bool admit_flag = false;

        for (int j = 0; j < applications[i]->school_list.size(); j++)
        {
            cho = applications[i]->school_list[j];
            if (schools[cho]->student_list.size() < schools[cho]->quota)
            {
                schools[cho]->student_list.push_back(student_id);
                admit_flag = true;
            }
            else
            {
                int id = schools[cho]->student_list.back();
                if (student_vec[id]->rank == applications[i]->rank)
                {
                    schools[cho]->student_list.push_back(student_id);
                    admit_flag = true;
                }
            }
            if (admit_flag)
                break;
        }

    }

    //output
    for (int i = 0; i < schools.size(); i++)
    {
        if (schools[i]->student_list.empty())
            printf("\n");
        else
        {
            sort(schools[i]->student_list.begin(), schools[i]->student_list.end());
            for (int j = 0; j < schools[i]->student_list.size(); j++)
            {
                if (j == 0)
                    printf("%d", schools[i]->student_list[j]);
                else
                    printf(" %d", schools[i]->student_list[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
