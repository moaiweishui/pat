#include <stdio.h>
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

void addTitle(string title, string id, unordered_map<string, vector<string>>& title_hmap)
{
    auto it = title_hmap.find(title);
    if (it != title_hmap.end())
    {
        title_hmap[title].push_back(id);
    }
    else
    {
        vector<string> _v;
        _v.push_back(id);
        title_hmap[title] = _v;
    }
}

void addAuthor(string author, string id, unordered_map<string, vector<string>>& author_hmap)
{
    auto it = author_hmap.find(author);
    if (it != author_hmap.end())
    {
        author_hmap[author].push_back(id);
    }
    else
    {
        vector<string> _v;
        _v.push_back(id);
        author_hmap[author] = _v;
    }
}

void addKeywords(string keywords, string id, unordered_map<string, vector<string>>& keyword_hmap)
{
    vector<string> keyword_vec;
    string s = "";
    for (int i = 0; i < keywords.length(); i++)
    {
        if (keywords[i] == ' ')
        {
            keyword_vec.push_back(s);
            s = "";
        }
        else
        {
            s += keywords[i];
        }
    }
    keyword_vec.push_back(s);
    for (int i = 0; i < keyword_vec.size(); i++)
    {
        auto it = keyword_hmap.find(keyword_vec[i]);
        if (it != keyword_hmap.end())
        {
            keyword_hmap[keyword_vec[i]].push_back(id);
        }
        else
        {
            vector<string> _v;
            _v.push_back(id);
            keyword_hmap[keyword_vec[i]] = _v;
        }
    }

}

void addPublisher(string publisher, string id, unordered_map<string, vector<string>>& publisher_hmap)
{
    auto it = publisher_hmap.find(publisher);
    if (it != publisher_hmap.end())
    {
        publisher_hmap[publisher].push_back(id);
    }
    else
    {
        vector<string> _v;
        _v.push_back(id);
        publisher_hmap[publisher] = _v;
    }
}

void addYear(string year, string id, unordered_map<string, vector<string>>& year_hmap)
{
    auto it = year_hmap.find(year);
    if (it != year_hmap.end())
    {
        year_hmap[year].push_back(id);
    }
    else
    {
        vector<string> _v;
        _v.push_back(id);
        year_hmap[year] = _v;
    }
}

vector<string> queryBook(string query, 
    unordered_map<string, vector<string>>& title_hmap,
    unordered_map<string, vector<string>>& author_hmap,
    unordered_map<string, vector<string>>& keyword_hmap,
    unordered_map<string, vector<string>>& publisher_hmap,
    unordered_map<string, vector<string>>& year_hmap)
{
    string index = query.substr(3, query.length() - 3);
    vector<string> no_result;
    if (query[0] == '1')
    {
        auto it = title_hmap.find(index);
        if (it != title_hmap.end())
            return (*it).second;
        else
            return no_result;
    }
    else if (query[0] == '2')
    {
        auto it = author_hmap.find(index);
        if (it != author_hmap.end())
            return (*it).second;
        else
            return no_result;
    }
    else if (query[0] == '3')
    {
        auto it = keyword_hmap.find(index);
        if (it != keyword_hmap.end())
            return (*it).second;
        else
            return no_result;
    }
    else if (query[0] == '4')
    {
        auto it = publisher_hmap.find(index);
        if (it != publisher_hmap.end())
            return (*it).second;
        else
            return no_result;
    }
    else if (query[0] == '5')
    {
        auto it = year_hmap.find(index);
        if (it != year_hmap.end())
            return (*it).second;
        else
            return no_result;
    }

}

int main()
{
    int N;
    cin >> N;

    string id, title, author, keywords, publisher, year;

    unordered_map<string, vector<string>> title_hmap;
    unordered_map<string, vector<string>> author_hmap;
    unordered_map<string, vector<string>> keyword_hmap;
    unordered_map<string, vector<string>> publisher_hmap;
    unordered_map<string, vector<string>> year_hmap;

    getline(cin, id); //remove 1st line /cr

    for (int i = 0; i < N; i++)
    {
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);

        addTitle(title, id, title_hmap);
        addAuthor(author, id, author_hmap);
        addKeywords(keywords, id, keyword_hmap);
        addPublisher(publisher, id, publisher_hmap);
        addYear(year, id, year_hmap);
    }

    int query_num;
    cin >> query_num;
    string query;
    vector<string> query_vec;
    getline(cin, query);

    for (int i = 0; i < query_num; i++)
    {
        getline(cin, query);
        query_vec.push_back(query);
    }

    vector<string> res;

    for (int i = 0; i < query_vec.size(); i++)
    {
        cout << query_vec[i] << endl;

        res = queryBook(query_vec[i], title_hmap, author_hmap, keyword_hmap, publisher_hmap, year_hmap);
        if (res.size() == 0)
            cout << "Not Found" << endl;
        else
        {
            sort(res.begin(), res.end());

            for (int j = 0; j < res.size(); j++)
                cout << res[j] << endl;
        }
    }

    return 0;
}
