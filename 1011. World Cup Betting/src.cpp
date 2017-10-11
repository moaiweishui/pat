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

struct Node{
    string status;
    float rate;
    Node(string status, float rate) :status(status), rate(rate){}
};

bool cmp(Node* a, Node* b)
{
    return a->rate > b->rate;
}

int main()
{
    vector<Node*> game1;
    vector<Node*> game2;
    vector<Node*> game3;

    vector<string> vec;
    vec.push_back("W");
    vec.push_back("T");
    vec.push_back("L");

    float buf;

    for (int i = 0; i < 3; i++)
    {
        cin >> buf;
        Node* node = new Node(vec[i], buf);
        game1.push_back(node);
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> buf;
        Node* node = new Node(vec[i], buf);
        game2.push_back(node);
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> buf;
        Node* node = new Node(vec[i], buf);
        game3.push_back(node);
    }

    sort(game1.begin(), game1.end(), cmp);
    sort(game2.begin(), game2.end(), cmp);
    sort(game3.begin(), game3.end(), cmp);

    float profit = (game1[0]->rate * game2[0]->rate * game3[0]->rate * 0.65 - 1.0)*2;
    cout << game1[0]->status << ' ' << game2[0]->status << ' ' << game3[0]->status << ' ';
    printf("%.2f\n", profit);

    return 0;
}
