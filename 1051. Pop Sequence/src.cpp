#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
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

bool check(vector<int>& vec, int M)
{
    if (vec[0] > M)
        return false;
    stack<int> st;
    for (int i = 1; i <= vec[0]; i++)
        st.push(i);
    int next = vec[0] + 1;
    int p = 0;
    while (p != vec.size())
    {
        if (!st.empty() && vec[p] == st.top())
        {
            st.pop();
            p++;
        }
        else if (vec[p] == next)
        {
            st.push(next);
            if (st.size() > M)
                return false;
            next++;
            st.pop();
            p++;
        }
        else if (vec[p] > next)
        {
            st.push(next);
            if (st.size() > M)
                return false;
            next++;
        }
        else if (vec[p] < next)
        {
            return false;
        }

        
    }
    return true;
}

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> vec;

    int buf;
    for (int i = 0; i < K; i++)
    {
        vector<int> tmp_v;
        for (int j = 0; j < N; j++)
        {
            cin >> buf;
            tmp_v.push_back(buf);
        }
        vec.push_back(tmp_v);
    }
   
    for (int i = 0; i < K; i++)
    {
        if (check(vec[i], M))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
