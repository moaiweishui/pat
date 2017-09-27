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
    int n;
    cin >> n;

    unordered_map<int, int> hmap;

    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int bird;
        int curr_tree_id = 0;

        for (int j = 0; j < num; j++)
        {
            cin >> bird;
            if (j == 0)
                curr_tree_id = bird;

            auto findit = hmap.find(bird);
            if (findit == hmap.end())
            {
                hmap[bird] = curr_tree_id;
            }
            else
            {
                if ((*findit).second != curr_tree_id)
                {
                    if (j == 0)
                        curr_tree_id = (*findit).second;
                    else
                    {
                        int new_id = (*findit).second;
                        for (auto it = hmap.begin(); it != hmap.end(); it++)
                        {
                            if ((*it).second == curr_tree_id)
                                (*it).second = new_id;
                        }
                        curr_tree_id = (*findit).second;
                    }
                    
                }
            }
        }
    }

    int query_num;
    cin >> query_num;
    vector<bool> res;
    int a, b;
    for (int i = 0; i < query_num; i++)
    {
        cin >> a >> b;
        if (hmap[a] == hmap[b])
            res.push_back(true);
        else
            res.push_back(false);

    }

    int bird_num = 0;
   
    unordered_set<int> tree_set;

    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        if ((*it).first > bird_num)
            bird_num = (*it).first;
        tree_set.insert((*it).second);
    }

    cout << tree_set.size() << ' ' << bird_num << endl;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
