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

struct Player{
    int id;
    int val;
    int order;
    int level;
    int rank;
    Player(int id, int val) :id(id), val(val){}
};

bool cmpOrder(Player* a, Player* b)
{
    return a->order < b->order;
}

bool cmpLevel(Player* a, Player* b)
{
    return a->level > b->level;
}

int main() {

    int Np, Ng;
    cin >> Np >> Ng;

    int val;

    vector<Player*> player_list;
    vector<Player*> vec;

    Player* new_player = NULL;

    for (int i = 0; i < Np; i++)
    {
        scanf("%d", &val);
        new_player = new Player(i, val);
        player_list.push_back(new_player);
        vec.push_back(new_player);
    }

    int buf;
    for (int i = 0; i < Np; i++)
    {
        scanf("%d", &buf);
        player_list[buf]->order = i;
    }

    sort(vec.begin(), vec.end(), cmpOrder);
    int turn = 1;
    while (vec.size() > 1)
    {
        vector<Player*> mem;
        for (int i = 0; i < vec.size(); i += Ng)
        {
            int max_index = i;
            for (int j = i + 1; j < i + Ng && j < vec.size(); j++)
            {
                if (vec[j]->val < vec[max_index]->val)
                {
                    vec[j]->level = turn;
                }
                else
                {
                    vec[max_index]->level = turn;
                    max_index = j;
                }
            }

            mem.push_back(vec[max_index]);
        }

        turn++;
        vec.assign(mem.begin(), mem.end());
    }

    vec[0]->level = turn;


    vec.assign(player_list.begin(), player_list.end());
    sort(vec.begin(), vec.end(), cmpLevel);

    int last;
    int rank = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0)
        {
            vec[i]->rank = rank;
            last = vec[i]->level;
        }
        else if (vec[i]->level == last)
        {
            vec[i]->rank = rank;
        }
        else
        {
            rank = i + 1;
            vec[i]->rank = rank;
            last = vec[i]->level;
        }
    }

    for (int i = 0; i < player_list.size(); i++)
    {
        if (i == 0)
            printf("%d", player_list[i]->rank);
        else
            printf(" %d", player_list[i]->rank);
    }
    printf("\n");
    return 0;
}
