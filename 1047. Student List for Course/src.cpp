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

string decodeName(int id)
{
    string res = "";
    res += id / (26 * 26 * 10) + 'A';
    id = id % (26 * 26 * 10);
    res += id / (26 * 10) + 'A';
    id = id % (26 * 10);
    res += id / 10 + 'A';
    id = id % 10;
    res += id + '0';
    return res;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> course_list(2501, vector<int>());

    char name[8];
    int course_num, cid;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d", &name, &course_num);
        for (int i = 0; i < course_num; i++)
        {
            scanf("%d", &cid);
            course_list[cid].push_back(encodeName(name));
        }
    }

    for (int i = 1; i <= K; i++)
    {
        printf("%d %d\n", i, course_list[i].size());

        sort(course_list[i].begin(), course_list[i].end());

        for (int j = 0; j < course_list[i].size(); j++)
            printf("%s\n", decodeName(course_list[i][j]).c_str());
    }

    return 0;
}
