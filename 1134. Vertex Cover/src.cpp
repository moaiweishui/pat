#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isValidCover(vector<pair<int, int>> edges, vector<bool> cover)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (cover[edges[i].first] == false && cover[edges[i].second] == false)
            return false;
    }

    return true;
}

int main()
{
    int vertex_num, edge_num;
    cin >> vertex_num;
    cin >> edge_num;

    int buf1, buf2;
    vector<pair<int, int>> edges;

    for (int i = 0; i < edge_num; i++)
    {
        cin >> buf1;
        cin >> buf2;
        edges.push_back(make_pair(buf1, buf2));
    }

    int set_num, set_size;
    cin >> set_num;

    vector<string> res;

    for (int i = 0; i < set_num; i++)
    {
        cin >> set_size;
        vector<bool> cover(vertex_num, false);
        int vertex_index;
        for (int j = 0; j < set_size; j++)
        {
            cin >> vertex_index;
            cover[vertex_index] = true;
        }

        if (isValidCover(edges, cover))
            res.push_back("Yes");
        else
            res.push_back("No");

    }

    for (int i = 0; i < set_num; i++)
        cout << res[i] << endl;
  
    return 0;
}
