/****************** Solution 1 *******************/
//最后一个测试用例超时了
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

bool cmp(pair<string, pair<int, pair<double, double>>> a, pair<string, pair<int, pair<double, double>>> b)
{
    if (a.second.second.second > b.second.second.second)
        return true;
    else if (a.second.second.second < b.second.second.second)
        return false;
    else
    {
        stringstream ss1;
        stringstream ss2;

        int da, db;

        ss1 << a.first;
        ss2 << b.first;

        ss1 >> da;
        ss2 >> db;

        return da < db;
    }
}

void unionMerge(vector<string>& peoples, unordered_map<string, string>& families, 
    string a, string b, int& family_num)
{
    if (b == "-1")
        return;

    if (families[a] != families[b])
    {
        if (families[a] <= families[b])
        {
            string s = families[b];
            for (auto it = families.begin(); it != families.end(); it++)
            {
                if ((*it).second == s)
                    (*it).second = families[a];
            }
        }
        else
        {
            string s = families[a];
            for (auto it = families.begin(); it != families.end(); it++)
            {
                if ((*it).second == s)
                    (*it).second = families[b];
            }
        }
        family_num--;
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<string> peoples;
    unordered_map<string, string> families;
    unordered_map<string, pair<string, string>> parents;
    unordered_map<string, vector<string>> children;
    unordered_map<string, pair<int, double>> estate;

    vector<pair<int, double>> estate_vec(10000, make_pair(0, 0));

    string buf1, buf2, buf3;
    string child;
    int child_num, esate_num;
    double area;

    for (int i = 0; i < n; i++)
    {
        cin >> buf1;
        cin >> buf2;
        cin >> buf3;
        peoples.push_back(buf1);
        families[buf1] = buf1;
        parents[buf1] = make_pair(buf2, buf3);

        if (buf2 != "-1")
            families[buf2] = buf2;
        if (buf3 != "-1")
            families[buf3] = buf3;

        cin >> child_num;
        vector<string> tmpv;
        for (int i = 0; i < child_num; i++)
        {
            cin >> child;
            tmpv.push_back(child);
            families[child] = child;
        }
        children[buf1] = tmpv;
        cin >> esate_num;
        cin >> area;
        estate[buf1] = make_pair(esate_num, area);
        stringstream ss;
        int people_id;
        ss << buf1;
        ss >> people_id;
        estate_vec[people_id] = make_pair(esate_num, area);
    }

    int family_num = families.size();
    for (int i = 0; i < peoples.size(); i++)
    {
        string p = peoples[i];
        unionMerge(peoples, families, p, parents[p].first, family_num);
        unionMerge(peoples, families, p, parents[p].second, family_num);

        for (int j = 0; j < children[p].size(); j++)
            unionMerge(peoples, families, p, children[p][j], family_num);
    }

    unordered_map<string, pair<int, pair<int, double>>> res;

    string id, family_id;
    int estate_num;
    double estate_area;

    for (auto it = families.begin(); it != families.end(); it++)
    {
        id = (*it).first;
        stringstream ss;
        int people_id;
        ss << id;
        ss >> people_id;

        family_id = (*it).second;

        auto findit = res.find(family_id);

        estate_num = estate_vec[people_id].first;
        estate_area = estate_vec[people_id].second;

        if (findit != res.end())
        {
            res[family_id].first++;
            res[family_id].second.first += estate_num;
            res[family_id].second.second += estate_area;
        }
        else
        {
            res[family_id] = make_pair(1, make_pair(estate_num, estate_area));
        }
    }

    vector<pair<string, pair<int, pair<double, double>>>> output;
    
    for (auto it = res.begin(); it != res.end(); it++)
    {
        output.push_back(make_pair((*it).first, make_pair((*it).second.first, 
            make_pair((*it).second.second.first * 1.0 / (*it).second.first, 
            (*it).second.second.second * 1.0 / (*it).second.first))));
    }

    sort(output.begin(), output.end(), cmp);

    family_num = output.size();
    cout << family_num << endl;
    for (int i = 0; i < family_num; i++)
    {
        cout << output[i].first << ' ' << output[i].second.first<< ' ';
        printf("%.3f ", output[i].second.second.first);
        printf("%.3f\n", output[i].second.second.second);
    }

    return 0;
}
