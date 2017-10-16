#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Testee{
    string id;
    int grade;
    int loc_num;
    int loc_rank;
    int final_rank;
    Testee(string id, int grade, int loc_num) : id(id), grade(grade), loc_num(loc_num), loc_rank(0), final_rank(0){}
};

bool cmp(Testee* a, Testee* b)
{
    if (a->grade > b->grade)
        return true;
    else if (a->grade < b->grade)
        return false;
    else
        return a->id < b->id;
}

int main()
{
    ios::sync_with_stdio(false);

    int loc_num, k;
    cin >> loc_num;

    vector<Testee*> final_v;
    vector<vector<Testee*>> local_v;

    string id_buf;
    int grade_buf;
    Testee* temp_testee = NULL;

    for (int i = 0; i < loc_num; i++)
    {
        cin >> k;
        vector<Testee*> temp_v;
        for (int j = 0; j < k; j++)
        {
            cin >> id_buf >> grade_buf;
            temp_testee = new Testee(id_buf, grade_buf, i + 1);
            temp_v.push_back(temp_testee);
            final_v.push_back(temp_testee);
        }
        sort(temp_v.begin(), temp_v.end(), cmp);
        
        temp_v[0]->loc_rank = 1;
        for (int j = 1; j < temp_v.size(); j++)
        {
            if (temp_v[j]->grade == temp_v[j - 1]->grade)
            {
                temp_v[j]->loc_rank = temp_v[j - 1]->loc_rank;
            }
            else
            {
                temp_v[j]->loc_rank = j + 1;
            }
        }

        local_v.push_back(temp_v);
    }

    sort(final_v.begin(), final_v.end(), cmp);

  cout << final_v.size()<<endl;
  
    final_v[0]->final_rank = 1;
    cout << final_v[0]->id << ' ' << final_v[0]->final_rank << ' ';
    cout << final_v[0]->loc_num << ' ' << final_v[0]->loc_rank << endl;
 
    for (int i = 1; i < final_v.size(); i++)
    {
        if (final_v[i]->grade == final_v[i - 1]->grade)
        {
            final_v[i]->final_rank = final_v[i - 1]->final_rank;
        }
        else
        {
            final_v[i]->final_rank = i + 1;
        }
        cout << final_v[i]->id << ' ' << final_v[i]->final_rank << ' ';
        cout << final_v[i]->loc_num << ' ' << final_v[i]->loc_rank << endl;
    }

    return 0;
}
