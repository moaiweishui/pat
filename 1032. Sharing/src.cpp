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

#define MAX_SIZE 100000

int main()
{
    vector<pair<char, int>> linked_list(MAX_SIZE);
    vector<int> vis(MAX_SIZE, 0);

    int root1, root2, N;
    cin >> root1 >> root2 >> N;
    int addr, val, next;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c %d", &addr, &val, &next);
        linked_list[addr] = make_pair(val, next);
    }

    int p = root1;
    while (p != -1)
    {
        vis[p] += 1;
        p = linked_list[p].second;
        
    }

    p = root2;
    //是否存在相同的后缀
    while (p != -1)
    {
        if (vis[p] == 1)
        {
            printf("%05d\n", p);
            return 0;
        }      
        p = linked_list[p].second;
    }

    printf("-1\n");

    return 0;
}
