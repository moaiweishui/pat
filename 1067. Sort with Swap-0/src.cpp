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

int main()
{
    int N;
    cin >> N;
    vector<int> num;
    vector<int> index(N, -1);

    int buf;
    int pos;

    int fail_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        num.push_back(buf);
        index[buf] = i;
        if (buf != i && buf != 0)
            fail_cnt++;
    }
    pos = index[0];
    int cnt = 0;
    int target;
    int start_pos = 1;
    while (fail_cnt)
    {
        if (pos != 0)
        {
            num[pos] = pos;
            num[index[pos]] = 0;
            pos = index[pos];
            fail_cnt--;
            cnt++;
        }
        else
        {
            int i;
            for (i = start_pos; i < N; i++)
            {
                if (num[i] != i)
                {
                    start_pos = i;
                    break;
                }
            }
            pos = i;
            num[0] = num[i];
            index[num[i]] = 0;
            num[i] = 0;            
            cnt++;
        }
        
    }
    
    cout << cnt<< endl;

    return 0;
}
