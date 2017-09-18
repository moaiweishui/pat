#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <set>
#include <functional>

using namespace std;

int getNum(string s)
{
    string news = s.substr(0, s.length() - 1);
    stringstream ss;
    int res;
    ss << news;
    ss >> res;
    return res;
}

void unionMerge(vector<int>& people, int id1, int id2)
{
    if (people[id1] < people[id2])
    {
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i] == people[id2])
                people[i] = people[id1];
        }
    }
    else if (people[id1] > people[id2])
    {
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i] == people[id1])
                people[i] = people[id2];
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> hobby;
    
    for (int i = 0; i <= 1000; i++)
    {
        vector<int> _v;
        hobby.push_back(_v);
    }

    string string_buf;
    int hobby_num, buf;

    vector<int> people;

    for (int i = 0; i < n; i++)
    {
        people.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> string_buf;
        hobby_num = getNum(string_buf);

        for (int j = 0; j < hobby_num; j++)
        {
            cin >> buf;
            hobby[buf].push_back(i);
        }
    }

    for (int i = 0; i <= 1000; i++)
    {
        if (hobby[i].size() > 1)
        {
            for (int j = 0; j < hobby[i].size() - 1; j++)
            {
                unionMerge(people, hobby[i][j], hobby[i][j + 1]);
            }
        }
    }

    sort(people.begin(), people.end());
    
    vector<int> cluster_size;

    int last = people[0];

    int cnt = 1;

    for (int i = 1; i < people.size(); i++)
    {
        if (people[i] != last)
        {
            cluster_size.push_back(cnt);
            last = people[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    cluster_size.push_back(cnt);

    cout << cluster_size.size() << endl;

    sort(cluster_size.begin(), cluster_size.end(), greater<int>());

    for (int i = 0; i < cluster_size.size(); i++)
    {
        if (i != cluster_size.size() - 1)
            cout << cluster_size[i] << ' ';
        else
            cout << cluster_size[i] << endl;
    }


    return 0;
}
