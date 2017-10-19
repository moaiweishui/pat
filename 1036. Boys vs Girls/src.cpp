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

struct Student{
    string name;
    string gender;
    string ID;
    int grade;
    Student(string name, string gender, string ID, int grade) 
        :name(name), gender(gender), ID(ID), grade(grade){}
};

bool cmpM(Student* a, Student* b)
{
    return a->grade < b->grade;
}

bool cmpF(Student* a, Student* b)
{
    return a->grade > b->grade;
}

int main()
{
    int N;
    cin >> N;

    vector<Student*> male;
    vector<Student*> female;

    string name, gender, id;
    int grade;
    Student* student_buf = NULL;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> gender >> id >> grade;
        student_buf = new Student(name, gender, id, grade);
        if (gender == "M")
            male.push_back(student_buf);
        else
            female.push_back(student_buf);
    }

    if (male.size() && female.size())
    {
        sort(male.begin(), male.end(), cmpM);
        sort(female.begin(), female.end(), cmpF);       
        printf("%s %s\n", female[0]->name.c_str(), female[0]->ID.c_str());
        printf("%s %s\n", male[0]->name.c_str(), male[0]->ID.c_str());
        printf("%d\n", female[0]->grade - male[0]->grade);
    }
    else if (male.size())
    {
        sort(male.begin(), male.end(), cmpM);
        printf("Absent\n");
        printf("%s %s\n", male[0]->name.c_str(), male[0]->ID.c_str());
        printf("NA\n");
    }
    else if (female.size())
    {
        sort(female.begin(), female.end(), cmpF);
        printf("%s %s\n", female[0]->name.c_str(), female[0]->ID.c_str());
        printf("Absent\n");
        printf("NA\n");
    }
    

    return 0;
}
