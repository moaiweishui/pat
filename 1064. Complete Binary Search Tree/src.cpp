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

void inOrder(int node, vector<int>& inOrder_vec, int N)
{
    if (node <= N)
    {
        inOrder(2 * node, inOrder_vec, N);
        inOrder_vec.push_back(node - 1);
        inOrder(2 * node + 1, inOrder_vec, N);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> vec;
    int buf;

    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        vec.push_back(buf);
    }
    sort(vec.begin(), vec.end());
    int root_index = 1;
    vector<int> inOrder_vec;
    inOrder(root_index, inOrder_vec, N);

    vector<int> tree(N, 0);
    for (int i = 0; i < N; i++)
    {
        tree[inOrder_vec[i]] = vec[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            cout << tree[i];
        else
            cout << ' '<<tree[i];
    }

    return 0;
}
双击代码区域可以查
