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


/****************** Solution 2 *******************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

struct people{
    int id;
    int family_id;
    double estate_num;
    double estate_area;
    people(int id) : id(id), family_id(-1), estate_num(0), estate_area(0){}
};

struct family{
    int family_id;
    int people_num;
    double estate_num;
    double estate_area;
};

bool cmp(family* a, family* b)
{
    if ((a->estate_area / a->people_num) > (b->estate_area / b->people_num))
        return true;
    else if ((a->estate_area / a->people_num) < (b->estate_area / b->people_num))
        return false;
    else
        return a->family_id < b->family_id;
}

void unionMerge(vector<people*>& peoples, vector<int>& people_vec, int id1, int id2)
{
    if (id2 == -1)
        return;

    if (peoples[id1]->family_id < peoples[id2]->family_id)
    {
        int tmp1 = peoples[id2]->family_id;
        int tmp2 = peoples[id1]->family_id;
        for (int i = 0; i < people_vec.size(); i++)
        {
            if (peoples[people_vec[i]]->family_id == tmp1)
                peoples[people_vec[i]]->family_id = tmp2;
        }
    }
    else if (peoples[id1]->family_id > peoples[id2]->family_id)
    {
        int tmp1 = peoples[id1]->family_id;
        int tmp2 = peoples[id2]->family_id;
        for (int i = 0; i < people_vec.size(); i++)
        {
            if (peoples[people_vec[i]]->family_id == tmp1)
                peoples[people_vec[i]]->family_id = tmp2;
        }
    }

    return;
}

int main()
{
    vector<people*> peoples;

    for (int i = 0; i < 10000; i++)
    {
        people* newpeople = new people(i);
        peoples.push_back(newpeople);
    }

    int n;
    cin >> n;

    int buf1, buf2, buf3;
    int child_num, child;
    double num, area;

    vector<int> people_vec;

    for (int i = 0; i < n; i++)
    {
        cin >> buf1;
        people_vec.push_back(buf1);
        if (peoples[buf1]->family_id == -1)
            peoples[buf1]->family_id = buf1;

        cin >> buf2;
        if (buf2 != -1)
        {
            people_vec.push_back(buf2);
            if (peoples[buf2]->family_id == -1)
                peoples[buf2]->family_id = buf2;
            unionMerge(peoples, people_vec, buf1, buf2);
        }

        cin >> buf3;
        if (buf3 != -1)
        {
            people_vec.push_back(buf3);
            if (peoples[buf3]->family_id == -1)
                peoples[buf3]->family_id = buf3;
            unionMerge(peoples, people_vec, buf1, buf3);
        }
        

        cin >> child_num;
        for (int j = 0; j < child_num; j++)
        {
            cin >> child;
            people_vec.push_back(child);
            if (peoples[child]->family_id == -1)
                peoples[child]->family_id = child;
            unionMerge(peoples, people_vec, buf1, child);
        }
        cin >> num;
        cin >> area;
        peoples[buf1]->estate_num = num;
        peoples[buf1]->estate_area = area;
    }
    
    unordered_map<int, family*> hmap;

    for (int i = 0; i < 10000; i++)
    {
        if (peoples[i]->family_id != -1)
        {
            int fid = peoples[i]->family_id;
            auto it = hmap.find(fid);
            if (it != hmap.end())
            {
                hmap[fid]->people_num++;
                hmap[fid]->estate_num += peoples[i]->estate_num;
                hmap[fid]->estate_area += peoples[i]->estate_area;
            }
            else
            {
                family* new_family = new family();
                new_family->family_id = fid;
                new_family->people_num = 1;
                new_family->estate_num = peoples[i]->estate_num;
                new_family->estate_area = peoples[i]->estate_area;
                hmap[fid] = new_family;
            }
        }
    }

    int family_num = hmap.size();

    vector<family*> output;

    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        output.push_back((*it).second);
    }

    sort(output.begin(), output.end(), cmp);

    cout << family_num << endl;

    for (int i = 0; i < family_num; i++)
    {
        printf("%04d %d %.3lf %.3lf\n",
            output[i]->family_id, 
            output[i]->people_num, 
            output[i]->estate_num / output[i]->people_num,
            output[i]->estate_area / output[i]->people_num
            );
    }

    return 0;
}
