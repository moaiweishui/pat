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

int main()
{
    int first_addr;
    cin >> first_addr;

    int node_num;
    cin >> node_num;

    vector<pair<int, int>> node_vec(100000, make_pair(0, 0));

    

    int addr, val, next_addr;
    for (int i = 0; i < node_num; i++)
    {
        cin >> addr >> val >> next_addr;
        node_vec[addr] = make_pair(val, next_addr);
    }

    vector<pair<int, int>> res;
    vector<pair<int, int>> removed;
    set<int> set;

    int p = first_addr;
    
    bool first_node = false;

    while (p != -1)
    {
        int val = node_vec[p].first;
        if (!first_node)
        {
            first_node = true;
            printf("%05d %d ", p, val);
            set.insert(abs(val));
        }
        else
        {
            if (set.count(abs(val)) != 0)
            {
                removed.push_back(make_pair(p, val));
            }
            else
            {
                printf("%05d\n%05d %d ", p, p, val);
                set.insert(abs(val));
            }
        }
        p = node_vec[p].second;
    }

    printf("-1\n");

    for (int i = 0; i < removed.size(); i++)
    {
        if (i == 0)
            printf("%05d %d ", removed[i].first, removed[i].second);
        else
            printf("%05d\n%05d %d ", removed[i].first, removed[i].first, removed[i].second);

        if (i == removed.size() - 1)
            printf("-1\n");
    }


    return 0;
}
