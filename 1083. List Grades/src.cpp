#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;


struct Student{
    string name;
    string id;
    int grade;
    Student(string name, string id, int grade) :name(name), id(id), grade(grade){}
};


bool cmp(Student* a, Student* b)
{
    return a->grade > b->grade;
}

int main()
{
    int N;
    cin >> N;

    vector<Student*> vec;

    string name, id;
    int grade;

    for (int i = 0; i < N; i++)
    {
        cin >> name >> id;
        cin >> grade;
        Student* student = new Student(name, id, grade);
        vec.push_back(student);
    }

    sort(vec.begin(), vec.end(), cmp);

    int left, right;
    cin >> left >> right;
    bool flag = false;
    for (auto it = vec.begin(); it != vec.end();it ++)
    {
        if ((*it)->grade <= right && (*it)->grade >= left)
        {
            flag = true;
            cout << (*it)->name << ' ' << (*it)->id << endl;
        }
    }

    if (!flag)
        cout << "NONE" << endl;

    return 0;
}
