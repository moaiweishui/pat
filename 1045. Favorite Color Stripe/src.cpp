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

int main()
{
    int N;
    cin >> N;
    vector<int> color_index(N + 1, -1);
    int M;
    cin >> M;
    int color;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &color);
        color_index[color] = i;
    }

    vector<int> color_stripe;
    int L;
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        scanf("%d", &color);
        if (color_index[color] != -1)
            color_stripe.push_back(color_index[color]);
    }

    int len = color_stripe.size();
    vector<int> mem(len, 1);
    
    int max_len = 1;

    for (int i = 1; i < len; i++)
    {
        int tmp_max_len = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (color_stripe[i] >= color_stripe[j] && mem[j] + 1 > tmp_max_len)
            {
                tmp_max_len = mem[j] + 1;
            }
        }
        mem[i] = tmp_max_len;

        if (mem[i] > max_len)
            max_len = mem[i];

    }

    cout << max_len<<endl;

    return 0;
}
