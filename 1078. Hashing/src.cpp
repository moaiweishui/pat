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

bool isPrime(int num)
{
    if (num == 1)
        return false;
    else if (num == 2 || num == 3)
        return true;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() 
{
    int Msize, N;
    cin >> Msize >> N;
    
    while (!isPrime(Msize))
    {
        Msize++;
    }
    
    vector<int> nums;
    int num;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        nums.push_back(num);
    }

    vector<int> hash_table(Msize, -1); //-1:empty
    vector<int> position(Msize, -1); //-1:impossible to insert

    int pos;
    for (int i = 0; i < nums.size(); i++)
    {
        bool insert_succeed = false;
        int step = 0;
        vector<bool> vis(Msize, false);
        
        while (!insert_succeed)
        {
            pos = (nums[i] + step * step) % Msize;
            if (hash_table[pos] == -1)
            {
                hash_table[pos] = nums[i];
                insert_succeed = true;
            }
            else
            {
                if (vis[pos] == false)
                    vis[pos] = true;
                else if (vis[pos])
                    break;
                step++;
            }
        }
        if (insert_succeed)
            position[i] = pos;
        else
            position[i] = -1;
        
    }

    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            cout << ' ';
        if (position[i] == -1)
            cout << '-';
        else
            cout << position[i];

    }
    cout << endl;
    return 0;
}
