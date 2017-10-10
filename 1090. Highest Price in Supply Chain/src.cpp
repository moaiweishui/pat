#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
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
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    double p, r;
    cin >> p >> r;

    vector<vector<int>> chain(n);

    int buf, root;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        if (buf == -1)
            root = i;
        else
        {
            chain[buf].push_back(i);
        }              
    }

    queue<int> q;
    q.push(root);
    
    vector<int> curr;
    vector<int> next;

    curr.push_back(root);

    int cnt = 0;
    int level = 0;
    
    while (!curr.empty())
    {
        level++;
        cnt = curr.size();
        
        for (int i = 0; i < curr.size(); i++)
        {
            for (int j = 0; j < chain[curr[i]].size(); j++)
            {
                next.push_back(chain[curr[i]][j]);
            }
        }
        swap(curr, next);
        next.clear();
    }

    for (int i = 1; i < level; i++)
        p = p*(1 + r / 100);

    printf("%.2f %d", p, cnt);

    return 0;
}
