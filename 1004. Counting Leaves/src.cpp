/********************** Solution 1 **************************/
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

struct Person{
    int id;
    int level;
    Person(int id) :id(id){}
};

int main() {
    int N, M;
    cin >> N >> M;

    int leaf_num = N - M;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }


    vector<vector<Person*>> pedigree(101);
    vector<Person*> member_list(101);

    Person* new_person = NULL;

    

    int id, child_num, child_id;
    for (int i = 0; i < M; i++)
    {
        cin >> id >> child_num;
        new_person = new Person(id);
        member_list[id] = new_person;

        for (int j = 0; j < child_num; j++)
        {
            scanf("%d", &child_id);
            new_person = new Person(child_id);
            pedigree[id].push_back(new_person);
            member_list[child_id] = new_person;
        }
    }

    int level = 0;
    vector<int> cnt(101);
    int root_id = 1;
    queue<Person*> q;

    Person* p = NULL;
    p = member_list[root_id];
    p->level = 0;
    q.push(p);

    while (!q.empty())
    {
        p = q.front();

        if (pedigree[p->id].empty())
            cnt[p->level]++;
        else
        {
            Person* tmp = NULL;
            for (int i = 0; i < pedigree[p->id].size(); i++)
            {
                tmp = pedigree[p->id][i];
                tmp->level = p->level + 1;
                q.push(tmp);
            }
        }
        level = p->level;
        q.pop();
    }
    int leaf_count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (i == 0)
            cout << cnt[i];
        else
            cout << ' ' << cnt[i];
        leaf_count += cnt[i];
        if (leaf_count == leaf_num)
            break;
    }
    cout << endl;
    return 0;
}


/********************** Solution 2 **************************/
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

#define MAX_SIZE 100

struct Person{
    int id;
    int level;
    vector<int> child_list;
    Person(int id) :id(id), level(0){}
};



int main() {

    int N, M;
    cin >> N >> M;

    if (M == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<Person*> pedigree_tree;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Person* init_person = new Person(0);
        pedigree_tree.push_back(init_person);
    }
    
    

    int parent, child_num, child;

    for (int i = 0; i < M; i++)
    {
        cin >> parent>> child_num;
        pedigree_tree[parent]->id = parent;
        for (int j = 0; j < child_num; j++)
        {
            cin >> child;
            pedigree_tree[parent]->child_list.push_back(child);
        }
    }

    queue<Person*> q;
    q.push(pedigree_tree[1]);
    int max_level = -1;

    vector<int> cnt(MAX_SIZE, 0);

    Person* person = NULL;

    while (!q.empty())
    {
        person = q.front();

        if (person->level > max_level)
            max_level = person->level;

        if (person->child_list.empty())
        {
            cnt[person->level]++;
        }

        for (int i = 0; i < person->child_list.size(); i++)
        {
            pedigree_tree[person->child_list[i]]->id = person->child_list[i];
            pedigree_tree[person->child_list[i]]->level = person->level + 1;
            q.push(pedigree_tree[person->child_list[i]]);
        }

        q.pop();
    }

    for (int i = 0; i <= max_level; i++)
    {
        if (i == 0)
            cout << cnt[i];
        else
            cout << ' ' << cnt[i];
    }
    cout << endl;
    return 0;

}
