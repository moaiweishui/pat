#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <float.h>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int total_num, skip_num, index;
    cin >> total_num >> skip_num >> index;

    string buf;
    vector<string> vec;

    for(int i = 0; i < total_num; i++)
    {
        cin >> buf;
        vec.push_back(buf);
    }

    int p = index - 1;

    vector<string> res;
    unordered_set<string> hset;

    for (int i = 0; i < total_num; i++)
    {
        if (i == p)
        {
            string s = vec[i];
            auto it = hset.find(s);
            if (it != hset.end())
            {
                p++;
            }
            else
            {
                res.push_back(s);
                hset.insert(s);
                p += skip_num;
            }
        }
        
    }

    if (res.empty())
        cout << "Keep going..." << endl;
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }

    return 0;
}
