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
    int virtue, talent;
    int sum;
    int type;
    Person(int id, int virtue, int talent) :id(id), virtue(virtue), talent(talent), sum(talent + virtue){}
};

bool cmp(Person* a, Person* b)
{
    if (a->type != b->type)
        return a->type < b->type;
    else if (a->sum != b->sum)
        return a->sum > b->sum;
    else if (a->virtue != b->virtue)
        return a->virtue > b->virtue;
    else if (a->id != b->id)
        return a->id < b->id;
}

int main()
{
    int N, L, H;
    cin >> N >> L >> H;

    vector<Person*> vec;
    Person* new_person = NULL;

    int id;
    int virtue, talent;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &id, &virtue, &talent);
        if (talent >= L && virtue >= L)
        {
            new_person = new Person(id, virtue, talent);
            if (virtue >= H && talent >= H) //sage
                new_person->type = 1;
            else if (virtue >= H && talent < H) //nobleman
                new_person->type = 2;
            else if (virtue < H && talent < H && virtue >= talent)  //fool man
                new_person->type = 3;
            else                                  //small man
                new_person->type = 4;

            vec.push_back(new_person);
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    cout << vec.size() << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        printf("%08d %d %d\n", vec[i]->id, vec[i]->virtue, vec[i]->talent);
    }

    return 0;
}
