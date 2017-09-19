#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <unordered_map>
#include <functional>

using namespace std;

struct Item{
    int id;
    int cnt;

    Item(int id, int cnt) : id(id), cnt(cnt){}

    bool operator < (const Item &b) const{
        return (cnt == b.cnt) ? (id < b.id) : (cnt > b.cnt);
    }
};

int main()
{
    int query_num, max_size;
    cin >> query_num;
    cin >> max_size;
    
    int id;

    vector<int> count(query_num + 1, 0);

    set<Item> s;

    for (int i = 0; i < query_num; i++)
    {
        cin >> id;
        
        if (i != 0)
        {
            cout << id << ":";
            int x = max_size;
            for (auto it = s.begin(); it != s.end(); it++)
            {
                cout << ' ' << (*it).id;
                x--;
                if (x == 0)
                    break;
            }
            cout << endl;
        }

        if (count[id] == 0)
        {
            count[id]++;
            s.insert(Item(id, 1));
        }
        else
        { 
            auto it = s.find(Item(id, count[id]));
            s.erase(it);
            count[id]++;
            s.insert(Item(id, count[id]));
        }
    }

    return 0;
}
