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
    vector<int> count(10001, 0);
    vector<int> nums;
    int buf;
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        nums.push_back(buf);
        count[buf]++;
    }

    bool flag = false;
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (count[nums[i]] == 1)
        {
            flag = true;
            res = nums[i];
            break;
        }
    }

    if (flag)
        cout << res << endl;
    else
        cout << "None" << endl;


    return 0;
}
