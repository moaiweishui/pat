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
    string id;
    int C,M,E,A;
    int c_rank, m_rank, e_rank, a_rank;
    Student(string id, int c, int m, int e, int a) : id(id), C(c), M(m), E(e), A(a),
        c_rank(0), m_rank(0), e_rank(0), a_rank(0){}
};

int main()
{
    int student_num, query_num;
    cin >> student_num >> query_num;

    unordered_map<string, Student*> hmap;

    vector<int> c_vec;
    vector<int> m_vec;
    vector<int> e_vec;
    vector<int> a_vec;

    string id;
    int c, m, e;
    double a;
    for (int i = 0; i < student_num; i++)
    {
        cin >> id;
        cin >> c >> m >> e;
        a = (c + m + e) / 3.0;
        c_vec.push_back(c);
        m_vec.push_back(m);
        e_vec.push_back(e);
        a_vec.push_back(a);
        Student* student = new Student(id, c, m, e, round(a));
        hmap[id] = student;
    }

    sort(c_vec.begin(), c_vec.end());
    sort(m_vec.begin(), m_vec.end());
    sort(e_vec.begin(), e_vec.end());
    sort(a_vec.begin(), a_vec.end());

    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        int cnt = 1;
        for (int i = c_vec.size() - 1; i >= 0; i--)
        {
            if (c_vec[i] > (*it).second->C)
                cnt++;
            else
                break;
        }
        (*it).second->c_rank = cnt;

        cnt = 1;
        for (int i = m_vec.size() - 1; i >= 0; i--)
        {
            if (m_vec[i] > (*it).second->M)
                cnt++;
            else
                break;
        }
        (*it).second->m_rank = cnt;

        cnt = 1;
        for (int i = e_vec.size() - 1; i >= 0; i--)
        {
            if (e_vec[i] > (*it).second->E)
                cnt++;
            else
                break;
        }
        (*it).second->e_rank = cnt;

        cnt = 1;
        for (int i = a_vec.size() - 1; i >= 0; i--)
        {
            if (a_vec[i] > (*it).second->A)
                cnt++;
            else
                break;
        }
        (*it).second->a_rank = cnt;

    }

    string query_id;
    vector<string> query_vec;

    for (int i = 0; i < query_num; i++)
    {
        cin >> query_id;
        query_vec.push_back(query_id);
    }

    for (int i = 0; i < query_num; i++)
    {
        query_id = query_vec[i];
        auto findit = hmap.find(query_id);
        if (findit == hmap.end())
        {
            cout << "N/A" << endl;
        }
        else
        {
            Student* student = (*findit).second;
            int rank = student->a_rank;
            string status = "A";
            if (student->c_rank < rank)
            {
                rank = student->c_rank;
                status = "C";
            }
            if (student->m_rank < rank)
            {
                rank = student->m_rank;
                status = "M";
            }
            if (student->e_rank < rank)
            {
                rank = student->e_rank;
                status = "E";
            }
            cout << rank << ' ' << status<<endl;
        }
    }


    return 0;
}
