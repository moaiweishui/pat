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
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int mid = -1;

void adjust(multiset<int>& sorted_left, multiset<int>& sorted_right)
{
    if (sorted_left.size() == sorted_right.size() + 2) //需要调整
    {
        auto it = sorted_left.end();
        it--;
        sorted_right.insert(*it);
        sorted_left.erase(it);
    }
    else if (sorted_left.size() == sorted_right.size() - 1) //需要调整
    {
        auto it = sorted_right.begin();
        sorted_left.insert(*it);
        sorted_right.erase(it);     
    }

    if (sorted_left.size() > 0)
    {
        auto it = sorted_left.end();
        it--;
        mid = *it;
    }

    return;
}

int pop(stack<int>& st, multiset<int>& sorted_left, multiset<int>& sorted_right)
{
    if (st.empty())
        return -1;

    int res = st.top();
    st.pop();

    if (res > mid)
    {
        auto it = sorted_right.find(res);
        sorted_right.erase(it);
    }
    else
    {
        auto it = sorted_left.find(res);
        sorted_left.erase(it);
    }

    adjust(sorted_left, sorted_right);

    return res;
}

void push(stack<int>& st, multiset<int>& sorted_left, multiset<int>& sorted_right, int val)
{
    st.push(val);
    if (sorted_left.empty())
        sorted_left.insert(val);
    else
    {
        auto it = sorted_left.end();
        it--;
        if (val <= *it)
            sorted_left.insert(val);
        else
            sorted_right.insert(val);
    }

    adjust(sorted_left, sorted_right);

    return;
}

int peekMedian(stack<int>& st, multiset<int>& sorted_left, multiset<int>& sorted_right)
{
    if (st.empty())
        return -1;

    return mid;
}

int getKey(string s)
{
    int key;
    s = s.substr(5, s.length() - 5);
    stringstream ss;
    ss << s;
    ss >> key;
    return key;
}

int main() {

    int N;
    cin >> N;

    stack<int> st;  //栈
    multiset<int> sorted_left;  //前半截有序
    multiset<int> sorted_right; //后半截有序

    char op[20];
    int num; 

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "Pop") == 0) //Pop
        {
            int res = pop(st, sorted_left, sorted_right);
            if (res == -1)
                printf("Invalid\n");
            else
                printf("%d\n", res);
        }
        else if (strcmp(op, "Push") == 0) //Push
        {
            scanf("%d", &num);
            push(st, sorted_left, sorted_right, num);
        }
        else if (strcmp(op, "PeekMedian") == 0) //PeekMedian
        {
            int res = peekMedian(st, sorted_left, sorted_right);
            if (res == -1)
                printf("Invalid\n");
            else
                printf("%d\n", res);
        }
    }

    return 0;
}
