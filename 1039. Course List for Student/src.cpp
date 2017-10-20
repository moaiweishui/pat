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
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int encodeName(string name)
{
    return (name[0] - 'A') * 26 * 26 * 10 +
        (name[1] - 'A') * 26 * 10 +
        (name[2] - 'A') * 10 +
        (name[3] - '0');
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> course_list(26 * 26 * 26 * 10 + 1, vector<int>());

    int course_index, student_num;
    char name_buf[8];
    int id;

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &course_index, &student_num);      
        for (int j = 0; j < student_num; j++)
        {
            scanf("%s", &name_buf);
            id = encodeName(name_buf);
            course_list[id].push_back(course_index);
        }
      
    }
  
    vector<string> query;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &name_buf);
        query.push_back(name_buf);
    }

    string name;
    for (int i = 0; i < query.size(); i++)
    {
        name = query[i];
        id = encodeName(name);

        if (course_list[id].empty())
        {
            printf("%s 0\n", name.c_str());
        }
        else
        {
            sort(course_list[id].begin(), course_list[id].end());
            printf("%s %d", name.c_str(), course_list[id].size());
            for (int j = 0; j < course_list[id].size(); j++)
                printf(" %d", course_list[id][j]);
            printf("\n");
        }

    }

    return 0;
}
