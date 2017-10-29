#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node{
    long long id;
    int level;
    Node(long long id) :id(id), level(0){}
};

int main() 
{
    int N;
    double P, r;

    cin >> N >> P >> r;

    

    vector<vector<long long>> chain(N);

    vector<long long> product(N, 0);

    int downstream_num;
    long long buf;

    vector<Node*> node_list;
    Node* new_node = NULL;

    for (int i = 0; i < N; i++)
    {
        new_node = new Node(i);
        node_list.push_back(new_node);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> downstream_num;

        if (downstream_num == 0)
        {
            cin >> buf;
            product[i] = buf;
        }
        else
        {
            for (int j = 0; j < downstream_num; j++)
            {
                cin >> buf;
                chain[i].push_back(buf);
            }
        }
    }

    queue<Node*> q;
    q.push(node_list[0]);

    double sum = 0;
    double price;

    while (!q.empty())
    {
        Node* node = q.front();

        if (chain[node->id].empty()) //retailer
        {
            price = P * pow(1 + r / 100, node->level);
            sum += price * product[node->id];
        }
        else
        {
            for (int i = 0; i < chain[node->id].size(); i++)
            {
                node_list[chain[node->id][i]]->level = node->level + 1;
                q.push(node_list[chain[node->id][i]]);
            }
        }

        q.pop();
    }


    printf("%.1lf", sum);

    return 0;
}
