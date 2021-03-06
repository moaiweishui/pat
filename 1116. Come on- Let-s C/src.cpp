#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isPrime(int a)
{
    if (a == 2)
        return true;

    for (int i = 2; i < a / 2 + 1; i++)
    {
        if (a % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    
    unordered_map<string, string> map;
    unordered_map<string, bool> check_map;

    string buf;

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        if (i == 0)
            map.insert(make_pair(buf, "Mystery Award"));
        else if (isPrime(i + 1))
            map.insert(make_pair(buf, "Minion"));
        else
            map.insert(make_pair(buf, "Chocolate"));

        check_map.insert(make_pair(buf, false));
    }

    vector<string> query;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        query.push_back(buf);
    }

    for (int i = 0; i < n; i++)
    {
        auto it = map.find(query[i]);
        if (it == map.end())
        {
            cout << query[i] << ": " << "Are you kidding?" << endl;
        }
        else
        {
            if (check_map[query[i]])
            {
                cout << query[i] << ": " << "Checked" << endl;
            }
            else
            {
                cout << query[i] << ": " << map[query[i]] << endl;
                check_map[query[i]] = true;
            }
        }
    }


    return 0;
}
