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

struct User{
    int id;
    int perfectly_solved_cnt;
    int rank;
    int total_score;
    bool pass_compiler;
    vector<int> scores;
    User(int id) :id(id){}
};

bool cmp(User* a, User* b)
{
    if (a->total_score > b->total_score)
        return true;
    else if (a->total_score < b->total_score)
        return false;
    else {
        if (a->perfectly_solved_cnt > b->perfectly_solved_cnt)
            return true;
        else if (a->perfectly_solved_cnt < b->perfectly_solved_cnt)
            return false;
        else
            return a->id < b->id;
    }
}

int main() {

    int N, K, M;
    cin >> N >> K >> M;

    vector<User*> user_list(N + 1);
    vector<int> _tmpv(K, -1);  //-1: 没有提交记录
    for (int i = 1; i <= N; i++)
    {
        user_list[i] = new User(i);
        user_list[i]->perfectly_solved_cnt = 0;
        user_list[i]->rank = -1;
        user_list[i]->scores = _tmpv;
        user_list[i]->total_score = -1;
        user_list[i]->pass_compiler = false;
    }

    int id, index, score;
    vector<int> problem_score;

    for (int i = 0; i < K; i++)
    {
        scanf("%d", &score);
        problem_score.push_back(score);
    }
    int old_score;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &id, &index, &score);
        old_score = user_list[id]->scores[index - 1];
        if (old_score == -1) //在这之前这道题没有提交记录
        {
            if (score == -1) //没通过编译
                user_list[id]->scores[index - 1] = 0;
            else
            {
                user_list[id]->scores[index - 1] = score;  //update score
                user_list[id]->pass_compiler = true; //通过编译

                if (score == problem_score[index - 1])
                    user_list[id]->perfectly_solved_cnt++;
            }

        }
        else
        {
            if (score > old_score)
            {
              user_list[id]->pass_compiler = true;
                user_list[id]->scores[index - 1] = score;  //update score
                if (score == problem_score[index - 1])
                    user_list[id]->perfectly_solved_cnt++;
            }

        }

    }
    user_list.erase(user_list.begin());

    for (auto it = user_list.begin(); it != user_list.end();)
    {
        if ((*it)->pass_compiler == false)
        {
            it = user_list.erase(it);
        }
        else
        {
            int sum = 0;
            for (int i = 0; i < (*it)->scores.size(); i++)
            {
                if ((*it)->scores[i] > 0)
                    sum += (*it)->scores[i];
            }
            (*it)->total_score = sum;
            it++;
        }

    }

    sort(user_list.begin(), user_list.end(), cmp);

    int last_score = -1;
    int rank = 0;
    for (int i = 0; i < user_list.size(); i++)
    {
        if (user_list[i]->total_score != last_score)
        {
            rank = i + 1;
            printf("%d %05d %d", rank, user_list[i]->id, user_list[i]->total_score);
            last_score = user_list[i]->total_score;
            for (int j = 0; j < user_list[i]->scores.size(); j++)
            {
                if (user_list[i]->scores[j] == -1)
                    printf(" -");
                else
                    printf(" %d", user_list[i]->scores[j]);
            }
            printf("\n");
        }
        else
        {
            printf("%d %05d %d", rank, user_list[i]->id, user_list[i]->total_score);
            for (int j = 0; j < user_list[i]->scores.size(); j++)
            {
                if (user_list[i]->scores[j] == -1)
                    printf(" -");
                else
                    printf(" %d", user_list[i]->scores[j]);
            }
            printf("\n");
        }

    }

    return 0;
}
