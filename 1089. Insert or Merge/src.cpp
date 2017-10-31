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

void display(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
            cout << nums[i];
        else
            cout << ' ' << nums[i];
    }
    cout << endl;
    return;
}

int getIndex(vector<int> nums)
{
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < last)
            return i;
        else
            last = nums[i];
    }
}

void mergeSort(vector<int>& nums, int step)
{
    int end;
    for (int i = 0; i < nums.size(); i += step)
    {
        if (i + step > nums.size())
            end = nums.size();
        else
            end = i + step;

        sort(nums.begin() + i, nums.begin() + end);
    }

    return;
}

bool isSorted(vector<int> nums, int step)
{
    for (int i = 0; i < nums.size(); i += step)
    {
        for (int j = i; j < nums.size() && j < i + step - 1; j++)
        {
            if (nums[j] > nums[j + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    vector<int> nums;
    vector<int> intermedia;

    int buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        nums.push_back(buf);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        intermedia.push_back(buf);
    }

    bool is_insert = true;

    int index = getIndex(intermedia);
    for (int i = index; i < N; i++)
    {
        if (nums[i] != intermedia[i])
        {
            is_insert = false;
            break;
        }
    }

    if (is_insert)
    {
        cout << "Insertion Sort" << endl;
        sort(intermedia.begin(), intermedia.begin() + index + 1);
        display(intermedia);
        return 0;
    }
    else
    {
        cout << "Merge Sort" << endl;
        int step = 2;
        while (isSorted(intermedia, step))
        {
            step *= 2;
        }
        mergeSort(intermedia, step);
        display(intermedia);
        return 0;
    }

    return 0;
}
