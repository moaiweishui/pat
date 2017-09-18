#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

bool cmp(string a, string b)
{
    int x, y;
    stringstream s1, s2;
    s1 << a;
    s2 << b;
    s1 >> x;
    s2 >> y;
    return x < y;
}

int string2int(string s)
{
    int res;
    stringstream ss;
    ss << s;
    ss >> res;

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> couple(100000, -1);
    vector<bool> guests(100000, false);

    int buf1, buf2;

    unordered_map<int, string> id;

    for (int i = 0; i < n; i++)
    {
        cin >> buf1;
        cin >> buf2;
        couple[buf1] = buf2;
        couple[buf2] = buf1;
    }

    int m;
    cin >> m;
    vector<int> people;

    string buf;
    int x;

    for (int i = 0; i < m; i++)
    {
        cin >> buf;
        x = string2int(buf);
        id[x] = buf;
        people.push_back(x);
        guests[x] = true;
    }

    vector<int> res;

    for (int i = 0; i < m; i++)
    {
        if (couple[people[i]] == -1)
            res.push_back(people[i]);
        else if (!guests[couple[people[i]]])
        {
            res.push_back(people[i]);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;

    for (int i = 0; i < res.size(); i++)
    {
        if (i != res.size() - 1)
            cout << id[res[i]] << ' ';
        else
            cout << id[res[i]] << endl;
    }

    return 0;
}
