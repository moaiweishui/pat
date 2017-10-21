#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX_SIZE  26 * 26 * 26

int encodeName(string s)
{
    return (s[0] - 'A') * 26 * 26
        + (s[1] - 'A') * 26
        + (s[2] - 'A');
}

string decodeName(int id)
{
    string name = "AAA";
    name[2] += id % 26;
    id = id / 26;
    name[1] += id % 26;
    id = id / 26;
    name[0] += id % 26;

    return name;
}

set<int> nodeSet;
set<int> temp_set;
vector<set<int>> net(MAX_SIZE, temp_set);
vector<int> totalWeight(MAX_SIZE, 0);

vector<bool> vis(MAX_SIZE, false);

int check(vector<int> vec, int k)
{
    if (vec.size() < 3)
        return -1;
    int sum = 0;
    int head;

    int max = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        sum += totalWeight[vec[i]];
        if (totalWeight[vec[i]] > max)
        {
            max = totalWeight[vec[i]];
            head = vec[i];
        }
    }

    if (sum / 2 <= k)
        return -1;
    else
        return head;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int N, K;
    cin >> N >> K;

    char people1[4];
    char people2[4];
    int id1, id2;
    int time;

    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %d", people1, people2, &time);
        id1 = encodeName(people1);
        id2 = encodeName(people2);

        totalWeight[id1] += time;
        totalWeight[id2] += time;

        nodeSet.insert(id1);
        nodeSet.insert(id2);

        net[id1].insert(id2);
        net[id2].insert(id1);
    }

    vector<int> connect;
    vector<vector<int>> res;

    int cnt = 0;

    while (cnt < nodeSet.size())
    {
        connect.clear();

        for (auto it = nodeSet.begin(); it != nodeSet.end(); it++)
        {
            // BFS
            if (vis[*it] == false)
            {
                queue<int> q;
                q.push(*it);
                vis[*it] = true;
                int curr_node;
                while (!q.empty())
                {
                    curr_node = q.front();                    
                    connect.push_back(curr_node);
                    
                    for (auto subit = net[curr_node].begin(); subit != net[curr_node].end(); subit++)
                    {
                        if (vis[*subit] == false)
                        {
                            q.push(*subit);
                            vis[*subit] = true;
                        }
                    }

                    q.pop();
                }
                break;
            }
        }

        res.push_back(connect);
        cnt += connect.size();
    }

    int head;
    vector<pair<int, int>> v;
    for (int i = 0; i < res.size(); i++)
    {
        head = check(res[i], K);
        if (head != -1)
            v.push_back(make_pair(head, res[i].size()));
    }

    if (v.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        printf("%s %d\n", decodeName(v[i].first).c_str(), v[i].second);
    }

    return 0;
}
